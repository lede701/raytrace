#include "Imager.h"


int main(int argv, char* argc[])
{
	Imager *img = new Imager();

	img->numThread = 3;
	img->passes = 1000;
	img->width = 800*2;
	img->height = 300*2;
	img->Render("renderme.ppm");

	delete img;


	return 0;
}