
#include <iostream>
#include "Pointer.h"
#include "Bitmap.h"

// Only one of them
//#define ENABLE_WITHOUT_STANDARD_SMART_POINTERS
#define ENABLE_WITH_STANDARD_SMART_POINTERS

int main()
{
#ifdef ENABLE_WITHOUT_STANDARD_SMART_POINTERS
	Pointer<Bitmap> p{ new Bitmap("Smiley.txt") };
	//Pointer<Bitmap> p = new Bitmap("Smiley.txt");  // Error when explicit constructor

	//p.Get()->Load();  // When -> and * no overloaded
	//p.Get()->Display();
	p->Load();  // When -> and * overloaded
	p->Display();
#endif

#ifdef ENABLE_WITH_STANDARD_SMART_POINTERS
	std::unique_ptr<Bitmap> p{ new Bitmap("Smiley.txt") };
	p->Load();
	p->Display();
#endif

}


