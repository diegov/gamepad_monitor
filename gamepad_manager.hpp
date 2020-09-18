#pragma once

#include <unordered_map>
#include <SDL.h>

using namespace std;

namespace input {
    class GamepadManager {
    public:
        GamepadManager(const char *file);
        ~GamepadManager();
        int add(int device_id);
        void remove(int instance_id);
        void life_sign(Uint32 joy_id);
    private:
        unordered_map<int, SDL_GameController*> controllers;
    };
}
