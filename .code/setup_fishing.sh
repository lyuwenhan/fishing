#!/bin/bash
stty -echo raw
clear
stty echo cooked
echo "loading..."
stty -echo raw
g++ .code/main.cpp -Wall -o .run/fishing_main.run -O2 > /dev/null 2>&1
if ! [ $? -eq 0 ];then
	clear
	stty echo cooked
	echo "编译错误，正在显示编译结果"
	g++ .code/main.cpp -o .run/fishing_main.run
	echo "(按enter退出)"
	read
	exit 1
fi
clear
./.run/fishing_main.run $*
stty echo cooked