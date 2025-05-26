#!/bin/bash
cd "$(dirname "$0")"
stty -echo raw
stty echo cooked
echo "Compiling..."
stty -echo raw
g++ .code/main.cpp -Wall -o main.run -O2 > /dev/null 2>&1
if [ $? -ne 0 ];then
	stty echo cooked
	echo "编译错误，正在显示编译结果"
	g++ .code/main.cpp -o main.run
	echo "(按enter退出)"
	exit 1
fi
stty echo cooked
echo "Compilation successful"
