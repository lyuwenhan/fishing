#!/bin/bash
stty -echo raw
clear
stty echo cooked
echo "loading..."
stty raw -echo
g++ .code/main.cpp -o /dev/null >/dev/null 2>&1
a=$?
clear
stty echo cooked
if [[ $a =~ 1 ]];then
	echo "编译错误"
	g++ .code/main.cpp -o /dev/null
	echo "(按enter退出)"
	read
	exit 1
else
	echo "ok"
fi