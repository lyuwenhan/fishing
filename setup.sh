#!/bin/bash
cd "$(dirname "$0")"
stty -echo raw
clear
echo -e "loading...\r"
./main.run
if ! [ $? -eq 0 ];then
    clear
    stty echo cooked
    echo "运行错误"
    exit 1
fi
stty echo cooked