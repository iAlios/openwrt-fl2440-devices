#!/bin/bash
#

BASE=$(dirname $0)
SCRIPTS_DIR=$BASE/qemu-s3c24xx/s3c2410

cd $SCRIPTS_DIR

# 1. QEMU enviroment
. ./env

# 2. creat nand flash image, and write u-boot, kernel, rootfs into it.
if [ ! -e $flash_base -o ! -e $flash_image ]; then
./flash.sh ../..
fi

sleep 1

# 3. run QEMU
./qemu-auto.sh

