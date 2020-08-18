#include "Device.h"



std::string PrintableDevice::GetInfo(cl_device_info param)
{
	size_t bytes_count{};
	clGetDeviceInfo(device, param, 0, 0, &bytes_count);
	char* name = new char[bytes_count];
	clGetDeviceInfo(device, param, bytes_count, name, 0);
	return name;
}

void PrintableDevice::PrintMaxComputeUnits()
{
	cl_uint unit_count{};
	clGetDeviceInfo(device, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &unit_count, 0);
	std::cout << "Parallel compute units: " << unit_count << "\n";
	
}

PrintableDevice::PrintableDevice(cl_device_id device) : device(device)
{
	params = { CL_DEVICE_NAME, 
		CL_DEVICE_VERSION,
		CL_DRIVER_VERSION, 
		CL_DEVICE_MAX_COMPUTE_UNITS, 
		CL_DEVICE_VENDOR};
}

void PrintableDevice::Print()
{
	std::cout << "\n";
	for (auto& param : params) 
	{		
		switch (param)
		{
		case CL_DEVICE_MAX_COMPUTE_UNITS:
			PrintMaxComputeUnits();
			break;
		default:
			std::cout << GetInfo(param) << "\n";
			break;
		}
	}

}

