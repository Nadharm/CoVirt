#!/bin/bash

make

sudo insmod covirt_module.ko
sudo rmmod covirt_module.ko
