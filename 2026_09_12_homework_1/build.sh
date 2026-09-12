#!/bin/bash
# Скрипт сборки программы "Привет, мир!"

echo "Сборка hello.cpp..."
g++-16 -o hello hello.cpp

if [ $? -eq 0 ]; then
    echo "Готово! Запусти: ./hello"
else
    echo "Ошибка сборки"
fi
