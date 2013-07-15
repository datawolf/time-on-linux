#!/bin/env bash

# detete all the executable file in the parent directory of the current directory.



# keep track of the code directory.
TOP_DIR=$(cd  $(dirname "$0") && cd .. &&  pwd)


# find all the executable file and delete them
find $TOP_DIR -maxdepth 1  -executable -type f -delete
