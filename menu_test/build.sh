#!/bin/bash

APP_NAME="app"

clang++ -std=c++17 -Wall main.cpp menu_functions.cpp menu_items.cpp -o $APP_NAME

if [ $? -eq 0 ]; then
    ./$APP_NAME
else
    echo "Ошибка компиляции!"
fi