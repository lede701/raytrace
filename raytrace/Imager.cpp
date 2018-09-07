#include "Imager.h"
#define _USE_MATH_DEFINES
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <process.h>
#include <queue>
#include <time.h>
#include <Windows.h>



Imager::Imager()
{
	x = 0;
	y = 0;
	width = 800;
	height = 500;
	passes = 50;
	numThread = 2;
}


Imager::~Imager()
{
}

Vec3 Imager::Color(const Ray& r, Hitable* world, int depth)
{
	HitRecord hit;
	//float hit = hit_sphere(Vec3(0, 0, -1), 0.5f, r);
	if (world->hit(r, 0.001f, sizeof(float), hit))
	{
		Ray scattered;
		Vec3 attenuation;
		if (depth < 50 && hit.pMat->Scatter(r, hit, attenuation, scattered))
		{
			return attenuation * Color(scattered, world, depth + 1);
		}
		else
		{
			return Vec3(0.0f, 0.0f, 0.0f);
		}
	}
	else
	{
		Vec3 ud = unit_vector(r.direction());
		float t = 0.5f*(ud.y() + 1.0f);
		return Lerp(t, Vec3(1.0f, 1.0f, 1.0f), Vec3(0.5f, 0.7f, 1.0f));
	}
}

Vec3 Imager::Lerp(float t, Vec3 v1, Vec3 v2)
{
	return (1.0f - t) * v1 + t * v2;
}

Hitable* Imager::RandomScene(int size)
{
	Entity **list = new Entity*[size + 4];
	int i = 0;

	list[i++] = new Sphere(Vec3(0.0f, -1000.5f, 0.0f), 1000, new Lambertian(Vec3(0.5f, 0.5f, 0.5f)));
	for (int a = -11; a < 11; ++a)
	{
		for (int b = -11; b < 11; ++b)
		{
			float material = drand48();
			Vec3 center(a + 1.2f*drand48(), 0.2f, b + 1.2f*drand48());
			if ((center - Vec3(4.0f, 0.2f, 0.0f)).length() > 0.9) 
			{
				float r = 1.0f*drand48();
				if (material < 0.8f)
				{
					list[i++] = new Sphere(center, r, new Lambertian(Vec3(drand48()*drand48(), drand48()*drand48(), drand48()*drand48())));
				}
				else if(material < 0.95f)
				{
					list[i++] = new Sphere(center, r, new Metal(Vec3(0.5*(1 + drand48()), 0.5*(1 + drand48()), 0.5*(1 + drand48())), 0.5f*drand48()));
				}
				else
				{
					list[i++] = new Sphere(center, r, new Dielectric(1.5));
				}
			}
			if (i >= size) break;
		}
		if (i >= size) break;
	}

	list[i++] = new Sphere(Vec3(0, 1, 0), 1.0f, new Dielectric(1.5f));
	list[i++] = new Sphere(Vec3(-4, 1, 0), 1.0f, new Lambertian(Vec3(0.4f, 0.2f, 0.1f)));
	list[i++] = new Sphere(Vec3(4, 1, 0), 1.0f, new Metal(Vec3(0.7f, 0.6f, 0.5f), 0.0f));

	return new HitList(list, i);
}


void Imager::Render(std::string file)
{
	// Setup timing of render
	auto start = std::chrono::high_resolution_clock::now();

	// Calculate the number of initial rays to create
	int imgCnt = width * height;
	// Setup the color array to store results
	aClr = new Vec3[imgCnt];
	// Make sure the queue is empty
	qVec.empty();

	// Setup the percent of processing calulations
	iComplete = 0;
	nextStep = 2;
	nextComplete = nextStep;

	// Create world list
	world = RandomScene(30);
	// Setup camera
	Vec3 lookFrom(13, 2, 3);
	Vec3 lookAt(0, 1, 0);
	float focalDist = 10.0f;
	float aperture = 0.1f;
	cam = Camera(lookFrom, lookAt, Vec3(0,1,0),20.0f, float(width)/float(height), aperture, focalDist);

	std::cout << "Calculating initial rays" << std::endl;
	for (int iy = height-1; iy >= y; -- iy)
	{
		for (int ix = x; ix < width; ++ix) {
			qVec.push(Vec3(ix, iy, 0));
		}
	}
	std::cout << "Starting render engine" << std::endl;
	// Create multiple threads to render world minus this thread
	for (int t = 1; t < numThread; ++t) 
	{
		_beginthreadex(0, 0, &Imager::ImagerThread, this, 0, 0);
	}
	RenderThread();

	std::cout << "Writting to file" << std::endl;
	std::ofstream fout(file);
	fout << "P3\n" << width << " " << height << "\n255\n";
	for (int i = imgCnt; i > 0; --i)
	{
		Vec3 clr = aClr[i];
		fout << int(clr.x()) << " " << int(clr.y()) << " " << int(clr.z()) << std::endl;
	}
	fout.close();

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Render Time: " << elapsed.count() << std::endl;
	system("PAUSE");
}

void Imager::RenderThread(bool isThread)
{
	while (qVec.size() > 0)
	{
		// Lock queue for usage
		mutex.lock();
		if (qVec.size() > 0)
		{
			Vec3 pos = qVec.front();
			qVec.pop();
			mutex.unlock();
			int ix = int(pos.x());
			int iy = int(pos.y());

			Vec3 clr(0.0f, 0.0f, 0.0f);
			for (int s = 0; s < passes; ++s)
			{
				float u = float(ix + drand48()) / float(width);
				float v = float(iy + drand48()) / float(height);
				Ray r = cam.getRay(u, v);
				Vec3 p = r.point_at_parameter(2.0f);
				clr += Color(r, world, 0);
			}
			clr /= float(passes);
			clr = Vec3(sqrt(clr[0]), sqrt(clr[1]), sqrt(clr[2]));

			int ir = int(255.99 * clr[0]);
			int ig = int(255.99 * clr[1]);
			int ib = int(255.99 * clr[2]);

			int idx = ix + (iy * width);
			aClr[idx] = Vec3(ir, ig, ib);
		}
		else
		{
			mutex.unlock();
		}
		//fout << ir << " " << ig << " " << ib << std::endl;

		if (!isThread)
		{
			// Calculate the amount complete
			int max = width * height;
			mutex.lock();
			float complete = (float(max - qVec.size()) / float(max)) * 100;
			mutex.unlock();

			if (complete > nextComplete)
			{
				int icomp = int(complete);
				std::cout << ".";
				nextComplete += nextStep;
			}
		}
	}
	if (isThread)
	{
		_endthread();
	}
}

unsigned int __stdcall Imager::ImagerThread(void *p_this)
{
	Imager* imgr = static_cast<Imager*>(p_this);
	imgr->RenderThread(true);
	return 0;
}