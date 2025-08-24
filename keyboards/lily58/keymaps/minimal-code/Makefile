# Copyright 2023 Panos Sakkos <panos.sakkos@gmail.com> @le4ker
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR ANY PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.

# Variables
KEYBOARD = lily58
KEYMAP = minimal-code
QMK_ROOT = ../../../..

.PHONY: all compile clean flash json

# Default target
all: compile

# Compile the firmware
compile:
	cd $(QMK_ROOT) && qmk compile -kb $(KEYBOARD) -km $(KEYMAP)

# Clean build artifacts
clean:
	cd $(QMK_ROOT) && qmk clean

# Flash the firmware
flash:
	cd $(QMK_ROOT) && qmk flash -kb $(KEYBOARD) -km $(KEYMAP)

# Generate JSON from keymap.c
json:
	cd $(QMK_ROOT) && qmk c2json -kb $(KEYBOARD) -km $(KEYMAP) -o $(KEYMAP).json
	mv $(QMK_ROOT)/$(KEYMAP).json .
	@echo "Keymap JSON generated at $(KEYMAP).json"
