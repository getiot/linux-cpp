#include <iostream>

int main()
{
    int *pi = new int(1024);
    int *pia = new int[24];

    std::cout << "*pi = " << *pi << std::endl;

    delete pi;
    delete [] pia;

    return 0;
}