# Remotely

Remotely is an home-made tools to control a device remotely.

***

## Usage

### How to build Alemauro.Remotely
    1. mkdir build
    1. cd build
    1. cmake ..
    1. make


### How to run Alemauro.Remotely
    1. sudo ./Alemauro.Remotely

## Roadmap
1. Implement server and client sides for **Unix system**:
    1. Implement **keyboard** usage:
        * Reading keyboard commands;
            * Parsing **input_event struct**. You may find several mapping at */usr/include/linux/input-event-codes.h* 
            * How should I detected **key combinations** such as CTRL-C? Do I have to use *EV_SYN* event type?
        * Packing input from keyboard;
        * Sending packet from server to clients;
        * Receiving packet from server;
        * Applying received keyboard commands
    1. Implement **mouse** usage:
        * Reading mouse commands;
        * Packing input from mouse;
        * Sending packet from server to clients;
        * Receiving packet from server;
        * Applying mouse keyboard commands
    1. Implement **video** feedback:
        * Capturing the screen from the client
        * Compressing the stream
        * Sending to the server
        * Showing the remote screen

## Support

For support, help or new ideas, feel free to open issues on this github. I'll do my best to partecipate in every discussion.

## Contributing


## License
TBD