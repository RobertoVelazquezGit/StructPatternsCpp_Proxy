
#include <iostream>
#include "Bitmap.h"
#include "BitmapProxy.h"

// Only one of the two
//#define ENABLE_USAGE_WITHOUT_PROXY
#define ENABLE_USAGE_WITH_PROXY


int main()
{
#ifdef ENABLE_USAGE_WITHOUT_PROXY
    Image *img = new Bitmap("Smiley.txt");
    img->Load();
    img->Display();
    img->Load("banner.txt");
    img->Display();
    delete img;
#elif defined ENABLE_USAGE_WITH_PROXY
	Image* img = new BitmapProxy{ "banner.txt" };
	img->Load();
	img->Display();
	img->Load("Smiley.txt");
	img->Display();
	img->Display();
	delete img;
#endif
}

