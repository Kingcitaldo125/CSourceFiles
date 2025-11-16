#!/bin/bash

cmake -S . -B build --log-level=DEBUG && cmake --build build/ --parallel 1
