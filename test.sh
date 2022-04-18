#!/bin/bash

make

sudo insmod svm_check.ko
sudo rmmod svm_check.ko
