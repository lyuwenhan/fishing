#!/bin/bash
stty -echo raw
clear
echo -e "loading...\r"
g++ .code/setup.cpp -o .run/setup.run -O2 > /dev/null 2>&1
if ! [ $? -eq 0 ];then
	clear
	stty echo cooked
	echo "编译错误，正在显示编译结果"
	g++ .code/setup.cpp -o .run/setup.run
	echo "(按enter退出)"
	read
	exit 1
fi
clear
chmod u+x .run/*.sh > /dev/null 2>&1 && chmod u+x .run/*.run > /dev/null 2>&1 && chmod u+x .code/*.sh > /dev/null 2>&1 && chmod u+x .code/*.run > /dev/null 2>&1 && chmod u+x setup.sh > /dev/null 2>&1
./.run/setup.run $*
if ! [ $? -eq 0 ];then
	clear
	stty echo cooked
	echo "运行错误"
	exit 1
fi
stty echo cooked