#!/usr/bin/env bash

cd ../../../altera/BeMicro_Max10_template/
/opt/intelFPGA_lite/21.1/quartus/bin/quartus_asm --read_settings_files=on --write_settings_files=off BeMicro_MAX10_top -c BeMicro_MAX10_top

