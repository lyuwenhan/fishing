#!/bin/bash
stty -echo raw
clear
echo -e "loading...\r"
g++ .code/0.0.0to0.2.8/main.cpp -o .run/to1.run -O2 > /dev/null 2>&1
if ! [ $? -eq 0 ];then
	clear
	stty echo cooked
	echo "编译错误，正在显示编译结果"
	g++ .code/0.0.0to0.2.8/main.cpp -o .run/to1.run
	echo "(按enter退出)"
	read
	exit 1
fi
clear
.run/to1.run $*
clear
stty echo cooked