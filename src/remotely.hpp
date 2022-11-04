#ifndef _REMOTELY_
#define _REMOTELY_

#include<string.h>

class Remotely
{
    public:
        void run();
        void stop();
        void setup();
        Remotely();
    private:
        int keyboard_file;
        
};

#endif