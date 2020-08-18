#include "Computer.h"

void PrintableComputer::Print()
{
	for (cl_uint i = 0; i < platform_count; ++i)
	{
		std::cout << "Platform number: " << i + 1 << "\n";
		platforms[i].Print();
		std::cout << "\n";
	}
}

PrintableComputer::PrintableComputer()
{
	// get number of platforms
	if (clGetPlatformIDs(0, 0, &platform_count)) 
	{
		throw "Exception - wrong count of platforms!\n";
	}
	cl_platform_id* cl_platforms = new cl_platform_id[platform_count];
	platforms = new PrintablePlatform[platform_count];

	// get platforms
	if (clGetPlatformIDs(platform_count, cl_platforms, 0)) 
	{
		throw "Exception - wrong pointer to platforms!\n";
	}

	// get printable
	for (cl_uint i = 0; i < platform_count; ++i) 
	{
		platforms[i] = PrintablePlatform(cl_platforms[i]);
	}
	delete[] cl_platforms;

}

PrintableComputer::~PrintableComputer()
{
	delete[] platforms;
}
