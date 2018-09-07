#include "Imager.h"


int main(int argv, char* argc[])
{
	Imager *img = new Imager();

	img->numThread = 3;
	img->passes = 100;
	img->width = 300;
	img->height = 150;
	img->Render("demo.ppm");

	delete img;


	return 0;
}