#include "remotely.hpp"
#include <iostream>
#include <linux/input.h>
#include <fcntl.h> /* open() */
#include <errno.h> /* errno */
#include <unistd.h> /* read() */

void Remotely::run()
{
    struct input_event ev;
    std::cout << "Running\n"<<std::endl;
    while(true)
    {
        size_t bytes_read = read(keyboard_file, &ev, sizeof(ev));
        if (bytes_read < sizeof(struct input_event)){
            std::cerr<<"Reading keyboard file failed";
            continue;
        }
        else{
            if (ev.type == EV_KEY){
                std::cout << ev.code << std::endl;
            //std::cout << ev.code << std::endl;
            //std::cout << ev.value << std:endl;
            }
            else if (ev.type == EV_LED){
                std::cout << "LED: "+ev.code << std::endl;   
            }

        }
    }
}

void Remotely::stop()
{
    std::cout << "Stopping\n"<<std::endl;
}

void Remotely::setup()
{
    std::cout << "Setting up\nOpening keyboard stream"<<std::endl;
    try
    {
        keyboard_file = open("/dev/input/event5", O_RDONLY|O_NONBLOCK, O_RDONLY);
        if (keyboard_file > 0)
        {
            std::cout << "File correctly opened"<<std::endl;
            
        }
        else
        {
            std::cerr << "Error in opening file. Errno "<< errno << std::endl;
            throw std::runtime_error("KError in opening file. Errno" + std::to_string(errno));
        }
    }
    catch(const std::exception& e)
    {
        std::cerr<<"Exception in setup"<<std::endl;
        throw e;
    }

}

Remotely::Remotely()
{
    std::cout << "Remotely ready\n"<<std::endl;
}