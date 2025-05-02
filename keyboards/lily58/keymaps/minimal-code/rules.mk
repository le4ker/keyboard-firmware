# Copyright 2023 Panos Sakkos <panos.sakkos@gmail.com> @le4ker
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

OLED_ENABLE = yes
EXTRAKEY_ENABLE = yes
NKRO_ENABLE = yes
DEBOUNCE_TYPE = sym_eager_pk

# Disable unused features and enable Link Time Optimization
# to increase matrix scans per second and decrease firmware size.

# Core features explicitly disabled
MOUSEKEY_ENABLE = no
LOCKING_SUPPORT_ENABLE = no
LOCKING_RESYNC_ENABLE = no

# Optional features explicitly disabled
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
COMMAND_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes
LTO_ENABLE = yes

# Debug console
CONSOLE_ENABLE = no
