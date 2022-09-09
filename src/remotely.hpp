#ifndef _REMOTELY_
#define _REMOTELY_

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