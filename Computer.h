#pragma once
#include "Platform.h"

class PrintableComputer 
{
private:
	cl_uint platform_count;
	PrintablePlatform* platforms;
public:
	void Print();
	PrintableComputer();
	~PrintableComputer();

};