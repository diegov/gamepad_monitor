#include "gamepad_manager.hpp"
#include <iostream>

using namespace std;

namespace input {
    GamepadManager::GamepadManager(const char *file) {
        SDL_GameControllerAddMappingsFromFile(file);
        for (int i = 0; i < SDL_NumJoysticks(); ++i) {
            this->add(i);
        }
    }

    int GamepadManager::add(int device_id) {
        SDL_GameController *ctrl;
        if (SDL_IsGameController(device_id)) {
            ctrl = SDL_GameControllerOpen(device_id);

            SDL_Joystick *joy = SDL_GameControllerGetJoystick(ctrl);
            int instance_id = SDL_JoystickInstanceID(joy);
            if (this->controllers.count(instance_id) == 0) {
                this->controllers[instance_id] = ctrl;
            } else {
                SDL_GameControllerClose(ctrl);
            }
            return instance_id;
        } else {
            const char *name = SDL_JoystickNameForIndex(device_id);
            return -1;
        }
    }

    void GamepadManager::remove(int instance_id) {
        SDL_GameController *ctrl = this->controllers[instance_id];
        SDL_GameControllerClose(ctrl);
        this->controllers.erase(instance_id);
    }

    void GamepadManager::life_sign(Uint32 joy_id) {
    }

    GamepadManager::~GamepadManager() {
        for (auto it = this->controllers.begin(); it != this->controllers.end(); ++it) {
            SDL_GameControllerClose(it->second);        
        }
        this->controllers.clear();
    }
}
