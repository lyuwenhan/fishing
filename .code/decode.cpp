#include<hashtable.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
using std::cin;
using std::cout;
using std::hash;
using std::string;
using std::ostream;
using std::ifstream;
using std::to_string;
#include"variate.h"
#include"function.h"
#include"checkpoint.h"
void disableEcho(){
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty); // 获取当前终端设置

    // 恢复标准模式和回显
    tty.c_lflag |= ICANON | ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &tty); // 立即应用设置
}
void enableEcho(){
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty); // 获取当前终端设置

    // 禁用标准模式（ICANON），禁用回显（ECHO）
    tty.c_lflag &= ~(ICANON | ECHO);

    // 设置最小输入字符数和超时时间，确保可以逐字符读取输入
    tty.c_cc[VMIN] = 1;  // 读取至少1个字符
    tty.c_cc[VTIME] = 0; // 无超时等待

    tcsetattr(STDIN_FILENO, TCSANOW, &tty); // 立即应用设置
}
int main(){
	print("输入文件名");
	string name;
	getline(name, true);
	string s;
	{
		ifstream in("checkpoint/" + name);
		if(!in.good()){
			cout << "file can not found" << endl;
			return 0;
		}
		in >> s;
	}
	if(checkpoint::decode(s, false)){
		cout << "null ok" << endl;
		checkpoint::savechpnp(name);
		checkpoint::check();
		return 0;
	}
	// for(int i = 0; i < variate::tools; i++){
	// 	variate::tool[i] = 1;
	// }
	for(int i = 0; i <= 2106000; i++){
		base64 a(i);
		if(checkpoint::decode(a.decode(s), false)){
			cout << i << " ok" << endl;
			checkpoint::savechpnp(name);
			checkpoint::check();
			return 0;
		}
	}
	cout << "error" << endl;
}