#!/usr/bin/env bash

file=attribute-parser
c++ ${file}.cpp -o run.o
DIFF=$(diff <(cat resources/${file}-input | ./run.o) resources/${file}-output)
if ["$DIFF" == ""]
then
	echo "success"
else
	echo ""
	echo "Actual output"
	cat resources/${file}-input | ./run.o
fi
