// GDISpyhook.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "GDISpyhook.h"


// This is an example of an exported variable
GDISPYHOOK_API int nGDISpyhook=0;

// This is an example of an exported function.
GDISPYHOOK_API int fnGDISpyhook(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see GDISpyhook.h for the class definition
CGDISpyhook::CGDISpyhook()
{
	return;
}
