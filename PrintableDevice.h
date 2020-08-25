#pragma once
#include <CL/cl.hpp>
#include<iostream>
#include <iomanip>
#include <string>
#include <iostream>


class PrintableDevice 
{
private:
	cl::Device device;
	std::string device_name;
	std::string vendor_name;
	cl_device_type device_type;
	cl_uint compute_units;
	cl_bool support;
public:
	void GetInfo();
	PrintableDevice(cl::Device device);
	void Print();
	std::string FormattedType();
	std::string FormattedComputeUnits();
	std::string FormattedImageSupport();
};



