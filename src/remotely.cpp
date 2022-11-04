#include "remotely.hpp"
#include <iostream>
#include <linux/input.h>
#include <fcntl.h> /* open() */
#include <errno.h> /* errno */
#include <unistd.h> /* read() */

#define NUM_KEYCODES 71

const char *keycodes[] = {
    "RESERVED",
    "ESC",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "0",
    "MINUS",
    "EQUAL",
    "BACKSPACE",
    "TAB",
    "Q",
    "W",
    "E",
    "R",
    "T",
    "Y",
    "U",
    "I",
    "O",
    "P",
    "LEFTBRACE",
    "RIGHTBRACE",
    "ENTER",
    "LEFTCTRL",
    "A",
    "S",
    "D",
    "F",
    "G",
    "H",
    "J",
    "K",
    "L",
    "SEMICOLON",
    "APOSTROPHE",
    "GRAVE",
    "LEFTSHIFT",
    "BACKSLASH",
    "Z",
    "X",
    "C",
    "V",
    "B",
    "N",
    "M",
    "COMMA",
    "DOT",
    "SLASH",
    "RIGHTSHIFT",
    "KPASTERISK",
    "LEFTALT",
    "SPACE",
    "CAPSLOCK",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "NUMLOCK",
    "SCROLLLOCK"
};

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
                if(ev.code > 0 && ev.code < NUM_KEYCODES){
                    if (ev.value == 1){
                        std::cout << "Pressed " << keycodes[ev.code] << std::endl;
                    }
                    else if (ev.value == 0){
                        std::cout << "Released " << keycodes[ev.code] << std::endl;
                    }
                    else if (ev.value == 2){
                        std::cout << "Repeated " << keycodes[ev.code] << std::endl;
                    }
                }
                
            }
            //else if (ev.type == EV_LED){
            //    std::cout << "LED: " + std::to_string(ev.code) << std::endl;   
            //}
            //else if (ev.type == EV_SYN){
            //    std::cout << ev.code << std::endl;   
            //}
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