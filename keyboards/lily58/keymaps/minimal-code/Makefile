# Makefile for minimal-code keymap

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