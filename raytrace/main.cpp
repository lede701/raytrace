#include <iostream>

#include "Imager.h"


int main(int argv, char* argc[])
{
	Imager *img = new Imager();

	img->numThread = 6;
	img->passes = 200;
	img->Render("demo.ppm");

	delete img;


	return 0;
}