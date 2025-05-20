#!/bin/bash
stty -echo raw
clear
echo -e "loading...\r"
.run/to1.run 2>/dev/null
if ! [ $? -eq 0 ];then
    clear
    stty echo cooked
    echo "运行错误"
    exit 1
fi
clear
stty echo cooked