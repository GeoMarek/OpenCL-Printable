#pragma once
#include "Device.h"



class PrintablePlatform 
{
private:
	cl_platform_id platform;
	std::vector<PrintableDevice> devices;
public:
	PrintablePlatform(cl_platform_id platform);
	PrintablePlatform();
	void Print();
};
