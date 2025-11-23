#!/usr/bin/env bash

g++ -std=c++17 \
    test_LogManager.cpp \
    test_main.cpp \
    -o test_runner \
    -I../include \
    -I/usr/include \
    -L../ \
    -L/usr/lib \
    -ldragonfly \
    -lgtest
