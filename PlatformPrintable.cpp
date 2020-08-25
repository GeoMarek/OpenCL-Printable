#include "PlatformPrintable.h"

void PrintablePlatform::InitDevices()
{
	std::vector<cl::Device> cl_devices;
	platform.getDevices(CL_DEVICE_TYPE_ALL, &cl_devices);
	for (auto cl_device : cl_devices)
	{
		devices.push_back(PrintableDevice(cl_device));
	}
}

void PrintablePlatform::GetInfo()
{
	platform.getInfo((cl_platform_info)CL_PLATFORM_NAME, &platform_name);
	platform.getInfo((cl_platform_info)CL_PLATFORM_VENDOR, &platform_vendor);
}

void PrintablePlatform::GetExtensions()
{
	std::string not_formatted;
	platform.getInfo((cl_platform_info)CL_PLATFORM_EXTENSIONS, &not_formatted);

	std::istringstream stream(not_formatted);
	for (std::string word; stream >> word;) 
	{
		extensions.push_back(word);
	}
}

void PrintablePlatform::PrintExtensions()
{
	using std::setw;
	for (size_t i = 0; i < extensions.size()-1; i += 2) 
	{
		std::cout << "\t" << std::left << setw(40) << extensions[i] << setw(40) << extensions[i + 1] << "\n";
		//std::cout << extensions[i] << " " << extensions[i + 1] << "\n";
	}
}

PrintablePlatform::PrintablePlatform(cl::Platform platform) : platform(platform)
{
	this->InitDevices();
	this->GetInfo();
	this->GetExtensions();
}

void PrintablePlatform::Print()
{
	using std::cout;
	using std::endl;

	cout << endl << std::setfill('*') << std::setw(80) << "" << endl << std::setfill(' ') << endl;
	cout << "Platform name: " << platform_name << endl;
	cout << "Platform vendor: " << platform_vendor << endl << endl;

	cout << std::setfill('-') << std::setw(80) << "" << endl;
	cout << std::setfill(' ');
	cout << "Platform Extensions: " << endl;
	PrintExtensions();
	cout << std::setfill('-') << std::setw(80) << "" << endl;
	cout << std::setfill(' ');
	
	for (auto& device : devices) 
	{
		cout << "Platform Device" << endl;
		device.Print();
		cout << std::setfill('-') << std::setw(80) << "" << endl;
		cout << std::setfill(' ');
	}
}
