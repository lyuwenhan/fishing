#!/bin/bash
stty -echo raw
clear
stty echo cooked
echo "Compiling..."
stty -echo raw
g++ .code/main.cpp -Wall -o main.run -O2 > /dev/null 2>&1
if [ $? -ne 0 ];then
	clear
	stty echo cooked
	echo "编译错误，正在显示编译结果"
	g++ .code/main.cpp -o main.run
	echo "(按enter退出)"
	read
	exit 1
fi
clear
stty echo cooked