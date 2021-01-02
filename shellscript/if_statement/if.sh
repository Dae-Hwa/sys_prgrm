#!/bin/bash

if [ ! -z $1 ] && [ -e $1 ]
then
    echo "file exist"
else
    echo "not exist"
fi