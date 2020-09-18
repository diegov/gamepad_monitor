# gamepad_monitor

A simple tool that detects the "home" button on gamepads. It exits with 0 if the button was pressed.

It uses `gamecontrollerdb.txt` from https://github.com/gabomdq/SDL_GameControllerDB

It's useful as a startup script to start an application automatically when the home button is pressed, eg:

```sh
while ./gamepad_monitor; do
    steam -tenfoot
done
```

## Building

It requires cmake and SDL2 development libraries.

```sh
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## Licence

GPL v3. `gamecontrollerdb.txt` has its own licence, see [LICENCE.gamecontrollerdb.txt](LICENCE.gamecontrollerdb.txt)
