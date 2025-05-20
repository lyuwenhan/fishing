#!/bin/bash
stty -echo raw
clear
stty echo cooked
echo "loading..."
stty -echo raw
cd .code
g++ decode.cpp -o decode.run -O2 > /dev/null 2>&1
if ! [ $? -eq 0 ];then
	clear
	stty echo cooked
	echo "编译错误，正在显示编译结果"
	g++ decode.cpp -o decode.run
	cd ../
	echo "(按enter退出)"
	read
	exit 1
fi
clear
cd ../
clear
./.code/decode.run $*
stty echo cooked