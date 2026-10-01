#!/bin/bash

echo "Linux System Information"
echo "------------------------"

echo "User: $USER"
echo "Home Directory: $HOME"
echo "Current Directory: $(pwd)"
echo "Date and Time: $(date)"
echo "Kernel Information:"
uname -a
