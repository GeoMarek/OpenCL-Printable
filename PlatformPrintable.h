#pragma once
#include "PrintableDevice.h"
#include <sstream>

class PrintablePlatform 
{
private:
	cl::Platform platform;
	std::vector<PrintableDevice> devices;
	std::string platform_name;
	std::string platform_vendor;
	std::vector<std::string> extensions;
	void InitDevices();
	void GetInfo();
	void GetExtensions();
	void PrintExtensions();
public:
	PrintablePlatform(cl::Platform platform);
	void Print();

};
