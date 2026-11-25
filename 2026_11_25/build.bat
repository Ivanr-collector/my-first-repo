@echo off

:: Выбор системы сборки
:: "Ninja" / "Visual Studio 17 2022"
set BUILD_GEN=Ninja
set BUILD_DIR_SUFFIX=ninja

chcp 1251

:: Задаем папки
set TARGET_DIR=build_%BUILD_DIR_SUFFIX%
set SOURCE_CODE=src

if not exist %TARGET_DIR% mkdir %TARGET_DIR%

cd %TARGET_DIR%

cmake -G %BUILD_GEN% ..\%SOURCE_CODE%
cmake --build .

cd ..