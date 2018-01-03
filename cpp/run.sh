#!/usr/bin/env bash

id=30
file=hr
c++ ${file}${id}.cpp -o run.o
cat testcase | ./run.o

