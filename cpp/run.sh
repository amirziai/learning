#!/usr/bin/env bash

file=overload-operators
c++ ${file}.cpp -o run.o
DIFF=$(diff <(cat resources/${file}-input | ./run.o) resources/${file}-output)
if ["$DIFF" == ""]
then
	echo "Success"
else
	echo ""
	echo "Actual output"
	cat resources/${file}-input | ./run.o
fi
