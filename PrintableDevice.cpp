#include "PrintableDevice.h"

void PrintableDevice::GetInfo()
{
	device.getInfo(CL_DEVICE_NAME, &device_name);
	device.getInfo(CL_DEVICE_VENDOR, &vendor_name);
	device.getInfo(CL_DEVICE_TYPE, &device_type);
	device.getInfo(CL_DEVICE_MAX_COMPUTE_UNITS, &compute_units);
	device.getInfo(CL_DEVICE_IMAGE_SUPPORT, &support);
}

PrintableDevice::PrintableDevice(cl::Device device) : device(device)
{
	this->GetInfo();
}

void PrintableDevice::Print()
{
	auto padd_1 = 20;
	auto padd_2 = 10;
	std::cout << std::endl;
	std::cout << std::left << std::setw(padd_2) << "Name:" << std::setw(padd_2) << device_name << std::endl;
	std::cout << std::left << std::setw(padd_2) << "Vendor:" << std::setw(padd_2) << vendor_name << std::endl << std::endl;
	std::cout << std::right << std::setw(padd_1) << "Type of device:"  << std::setw(padd_2) << FormattedType() << std::endl;
	std::cout << std::right << std::setw(padd_1) << "Compute units:" << std::setw(padd_2) << FormattedComputeUnits() << std::endl;
	std::cout << std::right << std::setw(padd_1) << "Image support:" << std::setw(padd_2) << FormattedImageSupport() << std::endl;
}

std::string PrintableDevice::FormattedType()
{
	std::string type_information;

	switch (device_type)
	{
	case CL_DEVICE_TYPE_CPU:
		type_information += "CPU";
		break;
	case CL_DEVICE_TYPE_GPU:
		type_information += "GPU";
		break;
	case CL_DEVICE_TYPE_ACCELERATOR:
		type_information += "ACCELERATOR";
		break;
	default:
		type_information += "no data";
		break;
	}
	return type_information;
}

std::string PrintableDevice::FormattedComputeUnits()
{
	return std::to_string(compute_units);
}

std::string PrintableDevice::FormattedImageSupport()
{
	return support ? "Yes" : "No";
}


