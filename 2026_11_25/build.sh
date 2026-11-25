#!/bin/bash

#
# Вид сборки / суффикс в названии каталога сборки
#
# "Ninja" / "ninja"
# "Unix Makefiles" / "make"
#

BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"

BUILD_FOLDER="build_${BUILD_SUFFIX}"
SOURCE_FOLDER="src"

mkdir -p "$BUILD_FOLDER"

cd "$BUILD_FOLDER" || exit 1

cmake -G "$BUILD_TYPE" "../$SOURCE_FOLDER"
cmake --build .

cd ..
