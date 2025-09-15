#!/bin/bash
now=$(stty -g)
trap 'stty "$now"' EXIT
stty sane
stty -echo
cd "$(dirname "$0")"
echo "Compiling..."

build_en=false
build_zh=false

en_suc=0
zh_suc=0

if [[ " $* " == *" -A "* ]]; then
	build_zh=true
	build_en=true
elif [[ " $* " == *" -ZH "* ]]; then
	build_zh=true
elif [[ " $* " == *" -EN "* ]]; then
	build_en=true
else
	build_zh=true
fi

if $build_zh; then
	echo -e "    [ZH] Compiling..."
	err1=$(g++ -fdiagnostics-color=always .code/main.cpp -o main.run -O2 2>&1)
	zh_suc=$?
    if [[ $zh_suc -ne 0 ]]; then
        echo -e "    [ZH] Compilation failed"
		echo -e "$err1"
	else
		echo -e "    [ZH] Compilation successful"
    fi
fi

if $build_en ; then
	echo -e "    [EN] Compiling..."
	err2=$(g++ -fdiagnostics-color=always .code/main.cpp -o mainEN.run -DEN -O2 2>&1)
	en_suc=$?
    if [[ $en_suc -ne 0 ]]; then
        echo -e "    [EN] Compilation failed"
		echo -e "$err2"
	else
		echo -e "    [EN] Compilation successful"
    fi
fi

if [[ $zh_suc -ne 0 || $en_suc -ne 0 ]];then
	stty "$now"
	exit 1
fi
chmod u+x setup.sh
echo "Compilation successful"
stty "$now"
