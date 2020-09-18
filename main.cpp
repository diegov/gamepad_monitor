#include <iostream>
#include <unistd.h>
#include "SDL.h"
#include "gamepad_manager.hpp"

using namespace std;

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK);
    SDL_Event event;

    bool run = true;

    input::GamepadManager pad_manager("gamecontrollerdb.txt");

    const Uint8 HOME_BUTTON = 5;

    while (run) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_CONTROLLERBUTTONDOWN:
                if (event.cbutton.button == HOME_BUTTON) {
                    return 0;
                }
                pad_manager.life_sign(event.cbutton.which);
                break;
            case SDL_CONTROLLERBUTTONUP:
                pad_manager.life_sign(event.cbutton.which);
                break;
            case SDL_CONTROLLERAXISMOTION:
                pad_manager.life_sign(event.caxis.which);
                break;
            case SDL_QUIT:
                run = false;
                break;
            case SDL_JOYDEVICEADDED:
                pad_manager.add(event.cdevice.which);
                break;
            case SDL_JOYDEVICEREMOVED:
                pad_manager.remove(event.cdevice.which);
                break;
            default:
                break;
            }
        }
        
        SDL_Delay(100);
    }

    return 1;
}
