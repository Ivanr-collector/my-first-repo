#!/bin/bash
clang++ -std=c++17 -Wall main.cpp -o app
if [ $? -eq 0 ]; then
    ./app
fi