#!/bin/bash

echo "Building..."
make clean
make

echo "----------------------------------------------------------------------------------------------------------------------"
echo "Starting Simulation"
./run