#include "Computer.h"


int main()
{
    
    PrintableComputer* myComp = new PrintableComputer();
    myComp->Print();
    delete myComp;
    std::cin.get();
    return 0;
}