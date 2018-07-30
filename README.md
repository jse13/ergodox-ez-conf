## Installation
1. First-time setup: `sudo cp 49-teensy.rules /etc/udev/rules.d`
2. launch the `teensy` executable in the teensy directory
3. Open the hex file to flash in the Teensy GUI
4. Put the keyboard in flashing mode, and (if in a VM), make sure the USB is passing through (when in flashing mode its name
   will start with Van Ooijen), and select the Auto button to have the hex file flashed to the keyboard firmwre

---

To compile the keymap.c file:
1. Download the QMK firmware
2. Make a new directory in keyboards/ergodox_ez/keymaps/<dir name> and copy the keymap.c file into it
3. In the QMK root directory, run `make ergodox_ez:<dir name>`
4. Use the generated .hex file to flash the keyboard using the steps above
