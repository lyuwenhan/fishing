#!/bin/bash
now=$(stty -g)
stty sane
cd "$(dirname "$0")"
stty -echo raw
echo -e "Compiling...\r"
err=""

build_en=false
build_zh=false

en_suc=0
zh_suc=0

if [[ " $* " == *" -ZH "* ]]; then
	build_zh=true
elif [[ " $* " == *" -EN "* ]]; then
	build_en=true
elif [[ " $* " == *" -A "* ]]; then
	build_zh=true
	build_en=true
else
	build_zh=true
fi

if $build_zh; then
	err1=$(g++ -fdiagnostics-color=always .code/main.cpp -o main.run -O2 2>&1)
	zh_suc=$?
    if [[ $zh_suc -ne 0 ]]; then
        err+=$'\n[中文编译错误]\n'"$err1"
    fi
fi

if $build_en ; then
	err2=$(g++ -fdiagnostics-color=always .code/main.cpp -o mainEN.run -O2 -DEN 2>&1)
	en_suc=$?
    if [[ $en_suc -ne 0 ]]; then
        err+=$'\n[英文编译错误]\n'"$err2"
    fi
fi

stty echo cooked
if [[ $zh_suc -ne 0 || $en_suc -ne 0 ]];then
	echo "$err"
	exit 1
fi
chmod u+x setup.sh
echo "Compilation successful"
stty "$now"
