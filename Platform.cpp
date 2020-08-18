#include "Platform.h"

PrintablePlatform::PrintablePlatform(cl_platform_id platform) : platform(platform)
{
	cl_uint device_count{  };
	clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 0, 0, &device_count);
	auto device_alloc = new cl_device_id[device_count];
	clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, device_count, device_alloc, 0);
	for (cl_uint i = 0; i < device_count; ++i)
	{
		devices.push_back(PrintableDevice(device_alloc[i]));
	}
}

PrintablePlatform::PrintablePlatform()
{
	platform = nullptr;
	devices.reserve(1);
}

void PrintablePlatform::Print()
{
	//std::cout << "Platform: \n\n";
	for (auto& device : devices) 
	{
		device.Print();
	}
}
