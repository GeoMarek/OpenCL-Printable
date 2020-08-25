#define __MAX_DEFAULT_VECTOR_SIZE 128
#include "PlatformPrintable.h"

int main() 
{
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);
    for (auto p : platforms)
    {
        PrintablePlatform prt_platform(p);
        prt_platform.Print();
    }
    getchar();
    return 0;

}