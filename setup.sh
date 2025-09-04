#!/bin/bash
now=$(stty -g)
stty sane
cd "$(dirname "$0")"
stty -echo raw
clear
echo -e "loading...\r"
if [[ " $* " == *" -CN "* ]]; then
	./main.run
elif [[ " $* " == *" -EN "* ]]; then
	./mainEN.run
elif [[ "$FISH_LANG" == "CN" ]]; then
	./main.run
elif [[ "$FISH_LANG" == "EN" ]]; then
	./mainEN.run
else
	./main.run
fi
ok=$?
stty "$now"
if ! [ $ok -eq 0 ];then
	clear
	echo "运行错误"
	exit 1
fi
