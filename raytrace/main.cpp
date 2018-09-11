#include "Imager.h"


int main(int argv, char* argc[])
{
	Imager *img = new Imager();

	img->numThread = 3;
	img->passes = 50;
	img->width = 800;
	img->height = 300;
	img->Render("renderme.ppm");

	delete img;


	return 0;
}