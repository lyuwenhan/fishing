#ifndef function_defined
#define function_defined
#include<hashtable.h>
#include<iostream>
#include<string>
#include<sys/stat.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include"utf8/checked.h"
using std::cin;
using std::cout;
using std::hash;
using std::flush;
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
	return out << "\n\r" << flush;
}
inline char getch(){
	char c = getchar();
	if(c == 3){
		clear();
		cout << "\033[?25h^C" << endl;
		exit(0);
	}
	return c;
}
inline char getch2(){
	int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
	cin.clear();
	cout.flush();
	if(cin.peek() == EOF){
		fcntl(STDIN_FILENO, F_SETFL, flags);
		return 0;
	}
	char c = getch();
	fcntl(STDIN_FILENO, F_SETFL, flags);
	return c;
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
inline string getline(string &ans, bool b = false){
	ans = "";
	char a = 0;
	while(ans == ""){
		while((a = getch()) != '\r'){
			if(issymbol(a) || isdigit(a) || islower(a) || isupper(a)){
				ans += a;
				if(b){
					cout << a << flush;
				}
			}
			if(a == 127 && ans.length()){
				ans.pop_back();
				if(b){
					cout << "\b \b" << flush;
				}
			}
		}
	}
	cout << endl;
	return ans;
}
inline unsigned long long to_hash(string s){
	return static_cast<unsigned long long>(hash<string>{}(s));
}
inline void sleept(double time){
	while(getch2());
	while(time > 0.1){
		while(getch2());
		cout.flush();
		time -= 0.1;
		usleep(100000);
	}
	while(getch2());
	usleep(1000000 * time);
	while(getch2());
}
inline void sleep2(double time){
	usleep(1000000 * time);
}
inline void printnl(string s, double time = 0.02){
	cout << "\033[?25l" << flush;
	if(variate::speed == 1000){
		cout << s;
	}else{
        auto it = s.begin();
        while (it != s.end()) {
            auto p = it;
            utf8::next(it, s.end());
            string ch(p, it);
            cout << ch << flush;
            sleept(time * ch.length() / variate::speed);
        }
	}
	cout << "\033[m\033[?25h" << flush;
}
inline void print(string s, double time = 0.02){
    printnl(s, time);
    cout << endl;
}
inline void printa(string s, double time = 0.02){
	print(s + (s.empty() ? "(按enter继续)" : "    (按enter继续)"), time);
	while(getch() != '\r');
}
inline bool printYn(string s, double time = 0.02){
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
	print("请选择开局技能");
	print("1.美味诱饵, 2.稀世珍宝, 3.牢靠安全绳, 4.强效清洁剂, 5.大力水手, 6.放长线钓大鱼, 7.孤苦人家");
	print("美味诱饵:");
	print("    上钩速度变为原先的1.5倍");
	print("稀世珍宝:");
	print("    鱼的价格变为原先的2倍");
	print("牢靠安全绳:");
	print("    脱钩概率由50%变为10%");
	print("强效清洁剂:");
	print("    初始获得1个清洁剂, 并且清洁剂效果翻倍");
	print("大力水手:");
	print("    甩杆倍速由1倍变为2倍");
	print("放长线钓大鱼:");
	print("    大鱼概率由20%变为40%");
	print("孤苦人家:");
	print("    无");
	while(true){
		char c = getch();
		if(c == '1'){
			variate::level = 5;
			break;
		}else if(c == '2'){
			variate::get_level = 5;
			break;
		}else if(c == '3'){
			variate::slip = 10;
			break;
		}else if(c == '4'){
			variate::cleaning_ball = 1;
			variate::cleaning_sub = 2;
			break;
		}else if(c == '5'){
			variate::stime = 2;
			break;
		}else if(c == '6'){
			variate::bf = 40;
			break;
		}else if(c == '7'){
			break;
		}
	}
}
#endif