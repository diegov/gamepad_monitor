#!/usr/bin/env bash

THIS_SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

cd "$THIS_SCRIPT_DIR"

while ./gamepad_monitor; do
    steam
done
