#pragma once
#include <string>
#include<iostream>
#include <CL\cl.h>
#include<CL/cl_platform.h>
#include <vector>


class PrintableDevice 
{
private:
    cl_device_id device;
    std::string GetInfo(cl_device_info param);
    void PrintMaxComputeUnits();
public:
    std::vector<cl_device_info> params;
    PrintableDevice(cl_device_id device);
    void Print();
    
};