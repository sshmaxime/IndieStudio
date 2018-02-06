#!/usr/bin/env bash

if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
  if [ -d "build" ]; then
    echo "delete build directory"
    rm -rf build
  fi
  echo "create build directory"
  mkdir build
  cd build
  cmake ..
  make
  make install
else
  echo "You have to be on UNIX system to use this script"
fi
