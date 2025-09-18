#ifndef function_defined
#define function_defined
#include<hashtable.h>
#include<iostream>
#include<string>
#include<queue>
#include<sys/stat.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include"lib/utf8/checked.h"
using std::cin;
using std::cout;
using std::hash;
using std::flush;
using std::queue;
using std::string;
using std::ostream;
using std::to_string;
#include"variate.h"
pair<int, int> getConsoleSize(){
	struct winsize ws;
	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0){
		return {ws.ws_col, ws.ws_row};
	}else{
		return {0, 0};
	}
}
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
inline void clear(){
	cout << "\033c" << flush;
}
ostream& endl(ostream& out) {
	return out << "\r\n" << flush;
}

queue<char> input;
inline char getcharc(){
	char c = getchar();
	if(c == 3){
		clear();
		cout << "\033[?25h^C" << endl;
		exit(0);
	}
	return c;
}
inline void readallin(){
	int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
	cin.clear();
	cout.flush();
	while(cin.peek() != EOF){
		input.push(getcharc());
	}
	fcntl(STDIN_FILENO, F_SETFL, flags);
}
inline char getch(){
	readallin();
	if(input.empty()){
		return getcharc();
	}
	char c = input.front();
	input.pop();
	return c;
}
inline char getch2(){
	readallin();
	if(input.empty()){
		return 0;
	}
	char c = input.front();
	input.pop();
	return c;
}
inline string getch2s(){
	readallin();
	string s;
	while(!input.empty()){
		s.push_back(input.front());
		input.pop();
	}
	return s;
}
inline void clearc(){
	readallin();
	while(!input.empty()){
		input.pop();
	}
}

bool issymbol(char type){
	string symbols = "({[<`~!@#$%^&*-_ +=|;:.?>]})\"'\\/";
	size_t found = symbols.find(type);
	if(found != string::npos){
		return true;
	}else{
		return false;
	}
}
bool isnum(string s){
	for(char i : s){
		if(!isdigit(i)){
			return false;
		}
	}
	return true;
}
long long tonum(string s){
	if(s.length() >= 18 || !isnum(s)){
		return -1;
	}
	long long a = 0;
	for(char i : s){
		a *= 10;
		a += i - '0';
	}
	return a;
}
bool isnumbt(string s, int l, int r){
	long long num = tonum(s);
	return num >= l && num <= r;
}
inline string getline(string &ans, int b = 0){
	ans = "";
	char a = 0;
	while(ans == ""){
		while((a = getch()) != '\r'){
			if(issymbol(a) || isdigit(a) || islower(a) || isupper(a)){
				ans += a;
				if(b == 1){
					cout << a << flush;
				}else if(b == 2){
					cout << '*' << flush;
				}
			}
			if(a == 127 && ans.length()){
				ans.pop_back();
				cout << "\b \b" << flush;
			}
		}
	}
	cout << endl;
	return ans;
}
inline string getlineYe(string &ans, int b = 0){
	ans = "";
	char a = 0;
	while((a = getch()) != '\r'){
		if(issymbol(a) || isdigit(a) || islower(a) || isupper(a)){
			ans += a;
			if(b){
				cout << a << flush;
			}
		}
		if(a == 127 && ans.length()){
			ans.pop_back();
			if(b == 1){
				cout << a << flush;
			}else if(b == 2){
				cout << '*' << flush;
			}
		}
	}
	cout << endl;
	return ans;
}
inline void sleep2(double time){
	usleep(1000000 * time);
}
inline void sleept(double time){
	while(time > 0.1){
		readallin();
		time -= 0.1;
		sleep2(0.1);
	}
	readallin();
	sleep2(time);
	readallin();
}
const int cntm = fi_cntm;
inline void printnl(string s, double time = 0.02){
	cout << "\033[?25l" << flush;
	if(variate::data_saver.speed >= 3){
		cout << s;
	}else{
		auto it = s.begin();
		while(it != s.end()){
			auto p = it;
			for(int i = 1; it != s.end() && i <= cntm; i++){
				utf8::next(it, s.end());
			}
			string ch(p, it);
			cout << ch << flush;
			sleept(time * ch.length() / variate::data_saver.speed);
		}
	}
	cout << "\033[m\033[?25h" << flush;
}
inline void printnlne(string s, double time = 0.02){
	printnl(s, time);
}
inline void print(string s, double time = 0.02){
	printnl(s, time);
	cout << endl;
}
inline void printa(string s = "", double time = 0.02){
	print(s + (s.empty() ? "" : "    ") + press_enter_continue, time);
	while(getch() != '\r');
}
inline bool printYn(string s = "", double time = 0.02){
	print(s + (s.empty() ? "(Y/n)" : " (Y/n)"), time);
	char c;
	while((c = getch()) != 'Y' && c != 'y' && c != 'N' && c != 'n');
	return c == 'Y' || c == 'y';
}
inline int random(int l, int r){
	int len = r - l + 1;
	int re = rand() * 1.0 / RAND_MAX * len + l;
	return re;
}
inline void choose(){
	clear();
	clearc();
	cout << fun_schoose << endl << st_speeds << endl;
	variate::data_saver.speed = 1;
	print(fun_s1);
	printa("test test test test test test test test test test test test test");
	variate::data_saver.speed = 2;
	print(fun_s2);
	printa("test test test test test test test test test test test test test");
	variate::data_saver.speed = 3;
	print(fun_s3);
	print("test test test test test test test test test test test test test");
	variate::data_saver.speed = 2;
	while(true){
		char c = getch();
		if(c >= '1' && c <= '3'){
			variate::data_saver.speed = c - '0';
			break;
		}
	}
	clear();
	for(string i : vector<string>(fun_choose)){
		print(i);
	}
	while(true){
		char c = getch();
		if(c == '1'){
			variate::data_saver.level = 5;
			break;
		}else if(c == '2'){
			variate::data_saver.get_level = 5;
			break;
		}else if(c == '3'){
			variate::data_saver.slip = 10;
			break;
		}else if(c == '4'){
			variate::data_saver.cleaning_ball = 1;
			variate::data_saver.cleaning_sub = 2;
			break;
		}else if(c == '5'){
			variate::data_saver.stime = 2;
			break;
		}else if(c == '6'){
			variate::data_saver.bf = 40;
			break;
		}else if(c == '7'){
			break;
		}
	}
}
#endif