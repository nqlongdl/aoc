#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: $0 <year> <day_number>"
    exit 1
fi

YEAR=$1
DAY=$2
SRC_DIR="$YEAR/day_$DAY"
SRC_FILE="$SRC_DIR/main.cpp"
INPUT_FILE="$SRC_DIR/main.inp"
OUTPUT_FILE="main"

if [ ! -f "$SRC_FILE" ]; then
    echo "Source file $SRC_FILE not found!"
    exit 1
fi

if [ ! -f "$INPUT_FILE" ]; then
    echo "Input file $INPUT_FILE not found!"
    exit 1
fi

g++ -std=c++20 "$SRC_FILE" -o "$OUTPUT_FILE"
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

./"$OUTPUT_FILE" < "$INPUT_FILE"