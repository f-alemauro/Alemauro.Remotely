#include "remotely.hpp"
#include<iostream>


void Remotely::run()
{  

    std::cout << "Running\n"<<std::endl;
}

void Remotely::stop()
{
    std::cout << "Stopping\n"<<std::endl;
}

void Remotely::setup()
{
    std::cout << "Setting up\n"<<std::endl;
}

Remotely::Remotely()
{
    std::cout << "Remotely ready\n"<<std::endl;
}
