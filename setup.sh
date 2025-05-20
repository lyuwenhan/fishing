#!/bin/bash
for arg in "$@"; do
	if [[ "$arg" == "-h" || "$arg" == "--help" ]]; then
		echo "Fishing. Usage:
./setup.sh [-chp name] [-speed speed]
  The default action is to choose your username and speed
  can include the special name - to compress standard input.
  -chp   change your username when you open
  -speed change the output speed  -h     to show this help page"
		exit 0
	fi
done
stty -echo raw
clear
echo -e "loading...\r"
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