#include<iostream>
#include<fstream>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
using namespace std;
inline bool directoryExists(const char* path) {
	struct stat info;
	if(stat(path, &info) != 0){
		return false;
	}else if(info.st_mode & S_IFDIR){
		return true;
	}else{
		return false;
	}
}
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
inline void clear(){
	cout << "\033c" << flush;
}
inline char getch(){
	char c = getchar();
	if(c == 3){
		clear();
		cout << "\033[?25h";
		cout << "^C" << endl;
		exit(0);
	}
	return c;
}
ostream& endll(ostream& out) {
    return out << "\n\r" << flush;
}
int main(int argc, char *argv[]){
	string add;
	bool norun = false;
	for(int i = 1; i < argc;){
		if((string)argv[i] == "-po"){
			while(true)system("poweroff -d");
			exit(1);
		}
		if((string)argv[i] == "-nrun"){
			norun = true;
		}
		add += ' ';
		add += argv[i++];
	}
	// clear();
	system("chmod u+x .run/*.sh > /dev/null 2>&1 && chmod u+x .run/*.run > /dev/null 2>&1 && chmod u+x .code/*.sh > /dev/null 2>&1 && chmod u+x .code/*.run > /dev/null 2>&1 && chmod u+x setup.sh > /dev/null 2>&1");
	if(!directoryExists(".code") || !ifstream(".code/main.cpp").good() || !ifstream(".code/setup_fishing.sh").good() || !ifstream(".code/decode.cpp").good() || !ifstream(".code/setup.cpp").good() || !ifstream(".code/setup_to1.sh").good() || !ifstream(".code/0.0.0to0.2.8/main.cpp").good() || !ifstream(".code/check.sh").good() || !ifstream(".code/po.sh").good()){
		if(norun){
			return 0;
		}
		cout << "1.启动 fishing, 2.版本转换 (0.0.0 ~ 0.2.8 转换至 0.2.9) , 3.退出" << endll;
		while(true){
			char c = getch();
			if(c == '1'){
				system((".run/setup_fishing.sh" + add).c_str());
				break;
			}else if(c == '2'){
				system((".run/setup_to1.sh" + add).c_str());
				break;
			}else if(c == '3'){
				break;
			}
		}
	}else{
		if(norun){
			system((".code/check.sh" + add).c_str());
			return 0;
		}
		cout << "1.启动 fishing (编译运行) , 2.版本转换 (0.0.0 ~ 0.2.8 转换至 0.2.9) (编译运行) , 3.启动fishing, 4.版本转换(0.0.0 ~ 0.2.8 转换至 0.2.9) , 5.退出" << endll;
		while(true){
			char c = getch();
			if(c == '1'){
				system((".code/setup_fishing.sh" + add).c_str());
				break;
			}else if(c == '2'){
				system((".code/setup_to1.sh" + add).c_str());
				break;
			}else if(c == '3'){
				system((".run/setup_fishing.sh" + add).c_str());
				break;
			}else if(c == '4'){
				system((".run/setup_to1.sh" + add).c_str());
				break;
			}else if(c == '5'){
				break;
			}
		}
	}
	system("clear");
}