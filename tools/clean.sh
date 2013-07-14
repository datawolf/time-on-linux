#!/bin/env bash

# detete all the executable file in the parent directory of the current directory.


find ../ -maxdepth 1  -executable -type f -delete
