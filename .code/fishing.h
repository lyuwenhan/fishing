#ifndef fishing_defined
#define fishing_defined
#include<hashtable.h>
#include<iostream>
#include<iomanip>
#include<vector>
using std::to_string;
using std::ostream;
using std::string;
using std::vector;
using std::hash;
using std::pair;
using std::cout;
using std::setw;
using std::min;
using std::max;
#include"error.h"
#include"variate.h"
#include"function.h"
#include"checkpoint.h"
namespace fishing{
/*
\033[1;31m腐烂的 * 0   1%
\033[1;37m普通   * 1   80%
\033[1;35m紫水晶 * 2   14%
\033[1;34m青金石 * 5   4%
\033[1;33m金     * 10  0.9%
\033[1;32m绿宝石 * 50  0.09%
\033[1;36m钻石   * 100 0.01%
*/
	const int fish_gai[7][7] = {
{0, 8100, 1400, 400, 90, 9, 1},
{100, 8000, 1400, 400, 90, 9, 1},
{300, 7500, 1700, 400, 90, 9, 1},
{500, 7000, 1700, 700, 90, 9, 1},
{700, 6500, 1700, 700, 390, 9, 1},
{900, 6000, 1700, 700, 390, 309, 1},
{0, 6600, 1700, 700, 390, 309, 301},
	};
	const int aqua_get[7] = {-20, 10, 20, 30, 40, 50, 100};
	const char old[15][45] = {
	"                                            ",
	"                                            ",
	"                                            ",
	"                                            ",
	"                                            ",
	"                                            ",
	"                                            ",
	"                                            ",
	"                         o                  ",
	"                        /|\\--------         ",
	"                        /_\\___              ",
	"~~~~~~~~~~~~~~~~~~~~~~~|      |~~~~~~~~~~~~|",
	"                              |            |",
	"                              |            |",
	"                              |____________|"};
	int la = 0;
	double la2 = 0;
	const string wea[6] = {"雨    ", "雪    ", "晴      ", "阴      ", "多云    ", "雾      "};//wea[0]:level-5s*weather.second,wea[1]:level+5s*weather.second,wea[5]:slip+10;
	const string ty[4] = {"", "小", "中", "大"};
	const string weatherpcr[3][4] = {{
	"     \033[33;1m_____\033[m                                  ",
	"    \033[33;1m|     |\033[m                                 ",
	"    \033[33;1m|     |\033[m                                 ",
	"    \033[33;1m|_____|\033[m                                 "},
	{"         _______      ___________           ",
	"     ___/       \\____/           \\___       ",
	"    (                                )      ",
	"     \\______________________________/       "},
	{"         \033[33;1m_____\033[m       ___________            ",
	"     ___\033[33;1m|_____|\033[m_____/           \\____       ",
	"    (                                )      ",
	"     \\______________________________/       "}};
	const int macnt[4] = {0, 10, 20, 40};
	const char fu[6] = {'.', '*', ' ', ' ', ' ', ' '};
	const string fucolor[6] = {"\033[1;34m", "\033[1;36m", "", "", "", ""};
	pair<int, int> weather = {-1, 0};
	int lw = 0;
	vector<pair<int, int>> weapoint;
	char paint[15][45] = {};
	char last[15][45] = {};
	string color[15][45];
	vector<int> fish[7];
	int dirty = 0;
	const string fish_name[7] = {"腐烂的", "普通的", "紫水晶", "青金石", "金", "绿宝石", "钻石"};
	const string fish_color[7] = {"\033[1;31m", "\033[1;37m", "\033[1;35m", "\033[1;34m", "\033[1;33m", "\033[1;32m", "\033[1;36m"};
	const int fish_add[7] = {0, 1, 2, 5, 10, 50, 100};
	pair<int, int> ter_big;
	pair<int, int> change(pair<int, int>wea){
		if(wea.first < 0 || wea.first > 5 || wea.second < 0 || wea.second > 3){
			return {3, 0};
		}
		if(wea.first == 0 || wea.first == 1){
			if(wea.second < 2){
				int ra = random(1, 20); 
				if(ra <= 9){
					return wea;
				}else if(ra <= 15){
					return {wea.first, random(1, 3)};
				}else if(ra <= 17){
					return {random(0, 1), wea.second};
				}else{
					return {random(2, 4), 0};
				}
			}else{
				int ra = random(1, 2);
				if(ra <= 1){
					return {wea.first, random(1, 3)};
				}else if(ra <= 15){
					return wea;
				}
			}
		}else if(wea.first == 2 || wea.first == 3 || wea.first == 4){
			int ra = random(1, 10);
			if(ra <= 1){
				return {5, wea.second};
			}else if(ra <= 3){
				return {random(0, 1), random(1, 2)};
			}else if(ra <= 6){
				return {random(2, 4), wea.second};
			}else{
				return wea;
			}
		}else{
			int ra = random(1, 10);
			if(ra <= 3){
				return {random(2, 4), wea.second};
			}else{
				return wea;
			}
		}
		return wea;
	}
	inline int rand_time(int l = variate::level){
		return random(variate::mintime[l], variate::maxtime[l]);
	}
	inline int gr(int l = variate::get_level, int bei = 1){
		return random(bei * variate::minget[l], bei * variate::maxget[l]);
	}
	inline int gettype(){
		int ty = random(1, 10000);
		for(int i = 0; i <= 6; i++){
			ty -= fish_gai[variate::gan][i];
			if(ty <= 0){
				return i;
			}
		}
		return 0;
	}
	inline void get(bool is_big, int type){
		clear();
		if(variate::hungry <= 2){
			printa((string)"你钓到了一条" + fish_color[type] + fish_name[type] + (is_big ? "大" : "") + "鱼\033[m, 因饥饿已食用");
			variate::hungry += type + 3;
			return;
		}
		int pri = gr(variate::get_level, (is_big + 1) * fish_add[type]);
		if(type == 4 && is_big){
			clear();
			printa((string)"你钓到了一条" + fish_color[type] + "鸡蛋鱼\033[m, 价值$" + to_string(pri));
		}else{
			printa((string)"你钓到了一条" + fish_color[type] + fish_name[type] + (is_big ? "大" : "") + "鱼\033[m, 价值$" + to_string(pri));
		}
		int cnt = 0;
		for(int i = 0; i <= 6; i++){
			cnt += variate::aqfish_cnt[i];
		}
		int i;
		for(i = 0; i < type; i++){
			if(variate::aqfish_cnt[i]){
				break;
			}
		}
		if(variate::aqcnt && (cnt < variate::aqcnt || !variate::aqfish_cnt[i] || i == type)){
			if(printYn("是否放入水族馆")){
				variate::aqfish_cnt[type]++;
				if(cnt >= variate::aqcnt){
					variate::aqfish_cnt[i]--;
				}
				return;
			}
		}
		fish[type].push_back(10);
		variate::cnt++;
	}
	inline void draw(){
		bool wcg = false;
		const int now = time(0);
		while(now - la > 10){
			auto nweather = change(weather);
			if(nweather != weather){
				wcg = true;
			}
			weather = nweather;
			if(weather.first <= 1){
				lw = weather.first;
			}
			la += 10;
		}
		while(la2 > 0.2){
			la2 -= 0.2;
			for(int i = 0; i < weapoint.size();i++){
				weapoint[i].first += 1;
			}
			for(int i = 0; i < weapoint.size();i++){
				if(weapoint[i].first > 10){
					swap(weapoint[i], weapoint[weapoint.size() - 1]);
					weapoint.pop_back();
				}
			}
			if(weapoint.size() < macnt[weather.second] && random(1, 2) <= 2){
				weapoint.push_back({0, random(0, 44)});
			}
		}
		int start = 0;
		auto nowsize = getConsoleSize();
		if(nowsize.second < 17 || nowsize.first < 44){
			cout << "\033c\033[?25l" << flush;
			if(nowsize.second < 17){
				cout << "屏幕高度需至少为17行" << endl;
				cout << "当前为 " << nowsize.second << " 行" << endl;
			}
			if(nowsize.first < 44){
				cout << "屏幕宽度需至少为44行" << endl;
				cout << "当前为 " << nowsize.first << " 列" << endl;
			}
			while(nowsize.second < 17 || nowsize.first < 44){
				auto newsize = getConsoleSize();
				if(newsize.second >= 17 && newsize.first >= 44){
					nowsize = newsize;
					break;
				}
				if(newsize != nowsize){
					cout << "\033c\033[?25l" << flush;
					if(newsize.second < 17){
						cout << "屏幕高度需至少为17行" << endl;
						cout << "当前为 " << newsize.second << " 行" << endl;
					}
					if(newsize.first < 44){
						cout << "屏幕宽度需至少为44行" << endl;
						cout << "当前为 " << newsize.first << " 列" << endl;
					}
				}
				nowsize = newsize;
				sleept(0.1);
			}
			cout << "\033c\033[?25l" << flush;
		}
		if(ter_big != nowsize){
			ter_big = nowsize;
			cout << "\033c\033[?25l" << flush;
		}else{
			bool isEqual = (std::memcmp(paint, last, sizeof(paint)) == 0);
			if(!std::memcmp(paint, last, sizeof(paint))){
				return;
			}
			std::memcpy(last, paint, sizeof(paint));
			cout << "\033[H" << flush;
		}
		if(weather.first == 3 || weather.first == 4 || weather.first == 2){
			start = 4;
			for(int i = 0; i < 4; i++){
				cout << weatherpcr[weather.first - 2][i] << endl;
			}
		}
		for(int i = start; i < 15; i++){
			for(int j = 0; j < 45; j++){
				bool b = false;
				for(auto p : weapoint){
					if(p.first == i && p.second == j){
						b = true;
						break;
					}
				}
				if(paint[i][j] == ' ' && b){
					cout << "\033[m" << fucolor[lw] << fu[lw];
				}else{
					cout << "\033[m" << color[i][j] << paint[i][j];
				}				
			}
			cout << endl;
		}
		cout << "累计钓鱼数量: " << variate::cnt << " 当前天气: " << ty[weather.second] << wea[weather.first] << endl;
	}
	void slep(double s){
		if(s < 0.01){
			s = 0.01;
		}
		while(s > 0.1){
			sleept(0.1);
			draw();
			s -= 0.1;
			la2 += 0.1;
		}
		sleept(s);
		draw();
		la2 += s;
	}
	inline void fishing(bool is_big, int type){
		const double hung_speed = (variate::hungry < 5 ? 3 : (variate::hungry < 10 ? 2 : (variate::hungry < 30 ? 1 : variate::hungry < 35 ? 0.8 : 0.5)));
		cout << "\033[?25l" << flush;
		color[11][18] = "\033[1;34m";
		paint[11][18] = '~';
		color[10][19] = fish_color[type];
		paint[11][19] = '^';
		paint[10][19] = 'O';
		slep(0.5 * hung_speed * (is_big + 1) / variate::stime);
		color[11][19] = "\033[1;34m";
		paint[11][19] = '~';
		color[9][19] = fish_color[type];
		paint[10][19] = '^';
		paint[9][19] = 'O';
		slep(0.5 * hung_speed * (is_big + 1) / variate::stime);
		for(int i = 8; i >= 5; i--){
			color[i + 2][19] = "";
			paint[i + 2][19] = ' ';
			color[i][19] = fish_color[type];
			paint[i + 1][19] = '^';
			paint[i][19] = 'O';
			slep(0.5 * hung_speed * (is_big + 1) / variate::stime);
		}
		paint[9][24] = paint[8][24] = paint[7][24] = paint[6][24] = '|';
		paint[8][23] = paint[7][22] = paint[6][21] = paint[5][20] = paint[5][19] = paint[6][19] = ' ';
		color[5][19] = color[6][19] = "";
		paint[5][23] = '>';
		paint[5][24] = 'O';
		color[5][23] = color[5][24] = fish_color[type];
		slep(0.5 * hung_speed * (is_big + 1) / variate::stime);
		paint[9][26] = 'V';
		paint[8][24] = paint[7][24] = paint[6][24] = paint[5][23] = paint[5][24] = ' ';
		color[5][23] = color[5][24] = "";
		paint[9][26] = paint[8][26] = paint[7][26] = paint[6][26] = '|';
		paint[9][24] = '/';
		paint[5][25] = '>';
		paint[5][26] = 'O';
		color[5][25] = color[5][26] = fish_color[type];
		slep(0.5 * hung_speed * (is_big + 1) / variate::stime);
		paint[9][26] = paint[8][27] = paint[7][28] = paint[6][29] = '/';
		color[5][25] = color[5][26] = "";
		paint[8][26] = paint[7][26] = paint[6][26] = paint[5][25] = paint[5][26] = ' ';
		paint[5][29] = '>';
		paint[5][30] = 'O';
		color[5][29] = color[5][30] = fish_color[type];
		slep(0.5 * hung_speed * (is_big + 1) / variate::stime);
		paint[8][27] = paint[7][28] = paint[6][29] = paint[5][29] = paint[5][30] = ' ';
		paint[9][26] = '\\';
		paint[9][27] = paint[9][28] = paint[9][29] = paint[9][30] = paint[9][31] = paint[9][32] = paint[9][33] = paint[9][34] = '-';
		paint[8][35] = 'V';
		paint[9][35] = 'O';
		color[9][35] = color[8][35] = fish_color[type];
		color[5][29] = color[5][30] = "";
		slep(0.5 * hung_speed * (is_big + 1) / variate::stime);
		paint[10][35] = 'O';
		paint[8][35] = ' ';
		paint[9][35] = 'V';
		color[10][35] = fish_color[type];
		color[8][35] = "";
		slep(0.5 * (is_big + 1) / variate::stime);
		paint[11][34] = '\\';
		paint[11][36] = '/';
		for(int i = 11; i <= 12; i++){
			paint[i][35] = 'O';
			paint[i - 2][35] = ' ';
			paint[i - 1][35] = 'V';
			color[i][35] = fish_color[type];
			color[i - 2][35] = "";
			slep(0.5 * (is_big + 1) / variate::stime);
		}
		paint[11][34] = paint[11][35] = paint[11][36] = '~';
		paint[13][35] = 'O';
		paint[12][35] = 'V';
		color[13][35] = fish_color[type];
		color[11][35] = "\033[1;34m";
		slep(0.5 * (is_big + 1) / variate::stime);
		paint[13][36] = 'O';
		paint[12][35] = ' ';
		paint[13][35] = '>';
		color[13][36] = fish_color[type];
		color[12][35] = "";
		slep(0.5 * (is_big + 1) / variate::stime);
		for(int i = 37; i <= 38; i++){
			paint[13][i] = 'O';
			paint[13][i - 2] = ' ';
			paint[13][i - 1] = '>';
			color[13][i] = fish_color[type];
			color[13][i - 2] = "";
			slep(0.5 * (is_big + 1) / variate::stime);
		}
		paint[13][38] = paint[13][37] = ' ';
		color[13][38] = color[13][37] = "";
		cout << "\033[?25h" << flush;
		get(is_big, type);
	}
	inline void fishingslip(bool is_big, int type){
		const double hung_speed = (variate::hungry < 5 ? 3 : (variate::hungry < 10 ? 2 : (variate::hungry < 30 ? 1 : variate::hungry < 35 ? 0.8 : 0.5)));
		cout << "\033[?25l" << flush;
		color[11][18] = "\033[1;34m";
		paint[11][18] = '~';
		color[10][19] = fish_color[type];
		paint[11][19] = '^';
		paint[10][19] = 'O';
		slep(0.3 * hung_speed * (is_big + 1) / variate::stime);
		color[11][19] = "\033[1;34m";
		paint[11][19] = '~';
		color[10][19] = "";
		paint[10][19] = ' ';
		paint[10][20] = '^';
		paint[9][19] = 'O';
		color[10][20] = color[9][19] = fish_color[type];
		slep(0.3 * hung_speed * (is_big + 1) / variate::stime);
		paint[10][20] = paint[9][19] = ' ';
		color[10][20] = color[9][19] = "";
		paint[9][18] = '^';
		paint[8][19] = 'O';
		color[9][18] = color[8][19] = fish_color[type];
		slep(0.3 * hung_speed * (is_big + 1) / variate::stime);
		paint[9][18] = paint[8][19] = ' ';
		color[9][18] = color[8][19] = "";
		paint[8][20] = '^';
		paint[7][19] = 'O';
		color[8][20] = color[7][19] = fish_color[type];
		slep(0.3 * hung_speed * (is_big + 1) / variate::stime);
		paint[6][19] = 'j';
		color[8][20] = "";
		paint[8][20] = ' ';
		color[7][20] = fish_color[type];
		paint[7][20] = '<';
		slep(0.3 * hung_speed * (is_big + 1) / variate::stime);
		color[7][20] = "";
		paint[5][19] = 'j';
		paint[7][20] = paint[6][19] = ' ';
		color[8][19] = fish_color[type];
		paint[7][19] = 'V';
		paint[8][19] = 'O';
		slep(0.5 * (is_big + 1) / variate::stime);
		color[7][19] = "";
		color[9][19] = fish_color[type];
		paint[7][19] = ' ';
		paint[8][19] = 'V';
		paint[9][19] = 'O';
		slep(0.5 * (is_big + 1) / variate::stime);
		color[8][19] = "";
		color[10][19] = fish_color[type];
		paint[8][19] = ' ';
		paint[9][19] = 'V';
		paint[10][19] = 'O';
		slep(0.5 * (is_big + 1) / variate::stime);
		paint[11][18] = '\\';
		paint[11][20] = '/';
		for(int i = 11; i <= 12; i++){
			color[i - 2][19] = "";
			color[i][19] = fish_color[type];
			paint[i - 2][19] = ' ';
			paint[i - 1][19] = 'V';
			paint[i][19] = 'O';
			slep(0.5 / (is_big + 1) / variate::stime);
		}
		paint[11][18] = paint[11][20] = paint[11][19] = '~';
		color[11][19] = "\033[1;34m";
		color[13][19] = fish_color[type];
		paint[12][19] = 'V';
		paint[13][19] = 'O';
		slep(0.5 / (is_big + 1) / variate::stime);
		paint[12][19] = ' ';
		color[12][19] = "";
		color[14][19] = fish_color[type];
		paint[13][19] = 'V';
		paint[14][19] = 'O';
		slep(0.5 / (is_big + 1) / variate::stime);
		paint[13][19] = ' ';
		color[13][19] = "";
		paint[14][19] = 'V';
		slep(0.5 / (is_big + 1) / variate::stime);
		paint[14][19] = ' ';
		color[14][19] = "";
		slep(0.5 / (is_big + 1) / variate::stime);
		paint[8][23] = paint[7][22] = paint[6][21] = paint[5][20] = paint[5][19] = ' ';
		paint[9][24] = '/';
		cout << "\033[?25h" << flush;
	}
	inline void front_fishing(bool is_big, int type){
		std::memset(last, 0, sizeof(last));
		ter_big = {0, 0};
		
		const double hung_speed = (variate::hungry < 5 ? 3 : (variate::hungry < 10 ? 2 : (variate::hungry < 30 ? 1 : variate::hungry < 35 ? 0.8 : 0.5)));
		cout << "\033[?25l" << flush;
		for(int i = 0; i < 15; i++){
			for(int j = 0; j < 45; j++){
				color[i][j] = "";
				paint[i][j] = old[i][j];
			}
		}
		for(int i = 0; i <= 22; i++){
			color[11][i] = "\033[1;34m";
		}
		for(int i = 31; i <= 42; i++){
			color[11][i] = "\033[1;34m";
		}
		if(variate::fish_man){
			paint[8][25] = ' ';
			paint[9][25] = 'O';
			color[9][25] = color[10][24] = color[10][26] = fish_color[6];
			variate::fish_man = false;
		}
		slep(0.5 * hung_speed / variate::stime);
		for(int i = 27; i <= 34; i++){
			paint[9][i] = ' ';
		}
		paint[9][26] = 'V';
		paint[8][27] = paint[7][28] = paint[6][29] = paint[5][30] = '/';
		slep(0.5 * hung_speed / variate::stime);
		paint[8][27] = paint[7][28] = paint[6][29] = paint[5][30] = ' ';
		paint[9][26] = paint[8][26] = paint[7][26] = paint[6][26] = paint[5][26] = '|';
		slep(0.5 * hung_speed / variate::stime);
		paint[9][26] = '\\';
		paint[8][26] = paint[7][26] = paint[6][26] = paint[5][26] = ' ';
		paint[9][24] = paint[8][24] = paint[7][24] = paint[6][24] = paint[5][24] = '|';
		slep(0.5 * hung_speed / variate::stime);
		paint[8][24] = paint[7][24] = paint[6][24] = paint[5][24] = ' ';
		paint[9][24] = 'V';
		paint[8][23] = paint[7][22] = paint[6][21] = paint[5][20] = '\\';
		slep(0.5 * hung_speed / variate::stime);
		paint[5][19] = 'j';
		slep(0.5 * hung_speed / variate::stime);
		for(int i = 6; i <= 10; i++){
			paint[i - 1][19] = '|';
			paint[i][19] = 'j';
			slep(0.5 * hung_speed / variate::stime);
		}
		paint[10][19] = '|';
		paint[11][19] = 'j';
		color[11][19] = "";
		int stime = rand_time();
		if(weather.first == 0){
			stime = max(0, stime - 5 * weather.second);
		}
		if(weather.first == 1){
			stime = max(0, stime + 5 * weather.second);
		}
		slep(stime);
		color[11][0] = fish_color[type];
		paint[11][0] = 'O';
		slep(0.5 * (is_big + 1) / variate::stime);
		color[11][1] = fish_color[type];
		paint[11][0] = '>';
		paint[11][1] = 'O';
		slep(0.5 * (is_big + 1) / variate::stime);
		for(int i = 2; i <= 19; i++){
			color[11][i - 2] = "\033[1;34m";
			paint[11][i - 2] = '~';
			color[11][i] = fish_color[type];
			paint[11][i - 1] = '>';
			paint[11][i] = 'O';
			slep(0.5 * (is_big + 1) / variate::stime);
		}
		cout << "\033[?25h" << flush;
		bool slip = (random(1, 100) <= (variate::slip + (weather.first == 5) * 10));
		if(slip){
			fishingslip(is_big, type);
		}else{
			fishing(is_big, type);
		}
		while(!weapoint.empty()){
			weapoint.pop_back();
		}
	}
	inline void fishing_choose(){
		bool b = (random(1, 100) <= variate::bf);
		if(variate::big){
			b = true;
			variate::big--;
		}
		int type = gettype();
		if(variate::diamond){
			type = 6;
			variate::diamond--;
		}
		front_fishing(b, type);
	}
	inline double fresh(int a){
		if(a >= 8){
			return 1.25;
		}else if(a <= 2){
			return 0.8;
		}else{
			return 1;
		}
	}
	inline void get_gan(){
		clear();
		print("鱼竿兑换");
		print("当前鱼竿: " + fish_name[variate::gan] + "鱼竿");
		bool b[8] = {};
		string s = "";
		for(int i = 0; i <= 6; i++){
			b[i] = !fish[i].empty();
			if(b[i]){
				s += to_string(i);
				s += ". ";
				s += fish_name[i];
				s += "鱼竿";
				s += ", ";
			}
		}
		b[7] = true;
		if(s.empty()){
			print("暂无");
			return;
		}
		s += "7. 退出";
		print(s);
		int d;
		while(true){
			int c = getch();
			c -= '0';
			if(c >= 0 && c <= 7){
				if(b[c]){
					d = c;
					break;
				}
			}
		}
		if(d == 7){
			return;
		}
		if(!fish[d].empty()){
			fish[d].pop_back();
		}
		variate::gan = d;
	}
	void aqua(){
		{	
			int cnt = 0;
			for(int i = 0; i <= 6; i++){
				cnt += variate::aqfish_cnt[i];
			}
			for(int i = 6; i >= 1 && cnt > 0; i--){
				if(variate::aqfish_cnt[i]){
					variate::aqfish_cnt[i]--;
				}
			}
		}
		clear();
		print("水族馆");
		print("提示: 只有在水族馆里才能获得水族馆的收益");
		print("1.退出");
		variate::aqnow = time(0);
		for(int i = 0; i <= 6; i++){
			cout << fishing::fish_color[i] << fishing::fish_name[i] + "鱼: " << variate::aqfish_cnt[i] << "只\033[m" << endl;
		}
		while(getch() != '1');
		int cnt = 0;
		for(int i = 0; i <= 6; i++){
			cnt += aqua_get[i] * variate::aqfish_cnt[i];
		}
		variate::aqother += time(0) - variate::aqnow;
		variate::aqnow = 0;
		cnt *= variate::aqother / 60;
		variate::aqother %= 60;
		variate::money += cnt;
		print("你共获得 " + to_string(cnt) + "$ 的收益");
	}
	void make_food(){
		while(true){
			clear();
			print("生鱼肉");
			print("当前数量: ");
			bool b[8] = {};
			string s = "";
			for(int i = 0; i <= 6; i++){
				b[i] = !fish[i].empty();
				if(b[i]){
					s += to_string(i);
					s += ". ";
					s += fish_name[i];
					s += "鱼";
					s += ", ";
				}
			}
			b[7] = true;
			if(s.empty()){
				print("暂无");
				sleept(0.5);
				return;
			}
			s += "7. 退出";
			for(int i = 1; i <= 6; i++){
				cout << fish_color[i] << fish_name[i] + "鱼:" << "\033[m" << endl;
				if(fish[i].size()){
					cout << "    鱼池: " << fish[i].size() << " 只" << endl;
				}
				if(variate::fish[i][0]){
					cout << "    生鱼: " << variate::fish[i][0] << " 只" << endl;
				}
				if(variate::fish[i][1]){
					cout << "    烤鱼: " << variate::fish[i][1] << " 只" << endl;
				}
				if(fish[i].empty() && !variate::fish[i][0] && !variate::fish[i][1]){
					cout << "    暂无\033[m" << endl;
				}
			}
			cout << endl;
			print(s);
			int d;
			while(true){
				int c = getch();
				c -= '0';
				if(c >= 0 && c <= 7){
					if(b[c]){
						d = c;
						break;
					}
				}
			}
			if(d == 7){
				break;
			}
			if(fish[d].empty()){
				continue;
			}
			fish[d].pop_back();
			variate::fish[d][0]++;
		}
	}
	void roast_food(){
		clear();
		print("制作烤鱼");
		print("当前数量: ");
		bool b[8] = {};
		string s = "";
		for(int i = 0; i <= 6; i++){
			b[i] = variate::fish[i][0];
			if(b[i]){
				s += to_string(i);
				s += ". ";
				s += fish_name[i];
				s += "鱼";
				s += ", ";
			}
		}
		b[7] = true;
		if(s.empty()){
			print("暂无");
			sleept(0.5);
			return;
		}
		s += "7. 退出";
		for(int i = 1; i <= 6; i++){
			cout << fish_color[i] << fish_name[i] + "鱼:" << "\033[m" << endl;
			if(fish[i].size()){
				cout << "    鱼池: " << fish[i].size() << " 只" << endl;
			}
			if(variate::fish[i][0]){
				cout << "    生鱼: " << variate::fish[i][0] << " 只" << endl;
			}
			if(variate::fish[i][1]){
				cout << "    烤鱼: " << variate::fish[i][1] << " 只" << endl;
			}
			if(fish[i].empty() && !variate::fish[i][0] && !variate::fish[i][1]){
				cout << "    暂无\033[m" << endl;
			}
		}
		cout << endl;
		print(s);
		int d;
		while(true){
			int c = getch();
			c -= '0';
			if(c >= 0 && c <= 7){
				if(b[c]){
					d = c;
					break;
				}
			}
		}
		if(d == 7){
			sleept(0.5);
			return;
		}
		if(!variate::fish[d][0]){
			return;
		}
		const int l = 0, r = variate::fish[d][0];
		int a = 0;
		clear();
		cout << "按 a 减少, d 增加, 按 enter 制作, 按 backspace 退出" << endl << "制作熟鱼肉: " << fish_color[d] << fish_name[d] + "鱼:" << "\033[m" << endl;
		cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << " 只" << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
		while(true){
			char c = getch();
			if(c == 'a' || c == 'A'){
				a--;
				if(a < l){
					a = l;
				}
			}else if(c == 'd' || c == 'D'){
				a++;
				if(a > r){
					a = r;
				}
			}else if(c == '\r'){
				if(a > variate::fish[d][0] || a < 0 || !variate::roast){
					clear();
					return;
				}
				variate::fish[d][0] -= a;
				variate::fish[d][1] += a;
				clear();
				int time = (a + variate::roast - 1) / variate::roast;
				for(int i = 0; i < time; i++){
					for(int j = 0; j < 20; j++){
						clear();
						cout << "烤制中" << endl;
						int ok = i * 20 + j, all = time;
						int done = int((double)ok / all * 3);
						bool d2 = done & 1;
						done >>= 1;
						for(int k = 1; k <= done; k++){
							cout << "\033[32;1m=\033[m";
						}
						if(done < 30){
							cout << (d2 ? "\033[32;1m-\033[m" : "\033[31;1m=\033[m");
						}
						for(int k = done + 1; k < 30; k++){
							cout << "\033[31;1m=\033[m";
						}
						cout << endl;
						cout << i * variate::roast << "/" << a << " 完成" << endl;
						sleept(0.5);
					}
				}
				clear();
				cout << "烤制完成" << endl;
				for(int k = 0; k < 30; k++){
					cout << "\033[32;1m=\033[m";
				}
				cout << endl;
				cout << a << "/" << a << " 完成" << endl;
				sleept(1);
				return;
			}else if(c == 127){
				clear();
				return;
			}
			clear();
			cout << "按 a 减少, d 增加, 按 enter 制作, 按 backspace 退出" << endl << "制作熟鱼肉: " << fish_color[d] << fish_name[d] + "鱼:" << "\033[m" << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << " 只" << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
		}
	}
	void eat_food(){
		while(true){
			clear();
			print("食用生鱼肉");
			printnl("当前饱食度: ");
			cout << (variate::hungry < 10 ? "\033[31;1m" : (variate::hungry < 30 ? "" : variate::hungry < 35 ? "\033[32m" : "\033[32;1m")) << variate::hungry << "\033[m" << endl;
			print("当前数量: ");
			bool b[8] = {};
			string s = "";
			for(int i = 0; i <= 6; i++){
				b[i] = variate::fish[i][0];
				if(b[i]){
					s += to_string(i);
					s += ". ";
					s += fish_name[i];
					s += "生鱼";
					s += ", ";
				}
			}
			b[7] = true;
			if(s.empty()){
				print("暂无");
				sleept(0.5);
				return;
			}
			s += "7. 退出";
			for(int i = 1; i <= 6; i++){
				cout << fish_color[i] << fish_name[i] + "鱼:" << "\033[m" << endl;
				if(variate::fish[i][0]){
					cout << "    生鱼: " << variate::fish[i][0] << " 只 +" << i + 3 << endl;
				}
				if(!variate::fish[i][0] && !variate::fish[i][1]){
					cout << "    暂无\033[m" << endl;
				}
			}
			cout << endl;
			print(s);
			int d;
			while(true){
				int c = getch();
				c -= '0';
				if(c >= 0 && c <= 7){
					if(b[c]){
						d = c;
						break;
					}
				}
			}
			if(d == 7){
				sleept(0.5);
				return;
			}
			if(variate::fish[d][0] < 1){
				sleept(0.5);
				return;
			}
			variate::fish[d][0]--;
			variate::hungry += d + 3;
			variate::hungry = min(variate::hungry, 40);
			sleept(0.5);
		}
	}
	void eat_food_roast(){
		while(true){
			clear();
			print("食用熟鱼肉");
			printnl("当前饱食度: ");
			cout << (variate::hungry < 10 ? "\033[31;1m" : (variate::hungry < 30 ? "" : variate::hungry < 35 ? "\033[32m" : "\033[32;1m")) << variate::hungry << "\033[m" << endl;
			print("当前数量: ");
			bool b[8] = {};
			string s = "";
			for(int i = 0; i <= 6; i++){
				b[i] = variate::fish[i][1];
				if(b[i]){
					s += to_string(i);
					s += ". ";
					s += fish_name[i];
					s += "熟鱼";
					s += ", ";
				}
			}
			b[7] = true;
			if(s.empty()){
				print("暂无");
				sleept(0.5);
				return;
			}
			s += "7. 退出";
			for(int i = 1; i <= 6; i++){
				cout << fish_color[i] << fish_name[i] + "鱼:" << "\033[m" << endl;
				if(variate::fish[i][1]){
					cout << "    烤鱼: " << variate::fish[i][1] << " 只 +" << i + 7 << endl;
				}
				if(!variate::fish[i][0] && !variate::fish[i][1]){
					cout << "    暂无\033[m" << endl;
				}
			}
			cout << endl;
			print(s);
			int d;
			while(true){
				int c = getch();
				c -= '0';
				if(c >= 0 && c <= 7){
					if(b[c]){
						d = c;
						break;
					}
				}
			}
			if(d == 7){
				sleept(0.5);
				return;
			}
			if(variate::fish[d][1] < 1){
				return;
			}
			variate::fish[d][1]--;
			variate::hungry += d + 7;
			variate::hungry = min(variate::hungry, 40);
			sleept(0.5);
		}
	}
	void no_roast(){
		while(true){
			clear();
			print("1.制作食物, 2.食用生鱼肉, 3.退出");
			printnl("当前饱食度: ");
			cout << (variate::hungry < 10 ? "\033[31;1m" : (variate::hungry < 30 ? "" : variate::hungry < 35 ? "\033[32m" : "\033[32;1m")) << variate::hungry << "\033[m" << endl;
			print("当前数量: ");
			for(int i = 1; i <= 6; i++){
				cout << fish_color[i] << fish_name[i] + "鱼:" << "\033[m" << endl;
				if(fish[i].size()){
					cout << "    鱼池: " << fish[i].size() << " 只" << endl;
				}
				if(variate::fish[i][0]){
					cout << "    生鱼: " << variate::fish[i][0] << " 只" << endl;
				}
				if(variate::fish[i][1]){
					cout << "    烤鱼: " << variate::fish[i][1] << " 只" << endl;
				}
				if(fish[i].empty() && !variate::fish[i][0] && !variate::fish[i][1]){
					cout << "    暂无\033[m" << endl;
				}
			}
			while(true){
				char c = getch();
				if(c == '1'){
					make_food();
					break;
				}else if(c == '2'){
					eat_food();
					break;
				}else if(c == '3'){
					return;
				}
			}
			sleept(0.5);
		}
	}
	void roast(){
		if(!variate::roast){
			no_roast();
			return;
		}
		while(true){
			clear();
			print("1.制作食物, 2.烤制食物, 3.食用生鱼肉, 4.食用熟鱼肉, 5.退出");
			printnl("当前饱食度: ");
			cout << (variate::hungry < 10 ? "\033[31;1m" : (variate::hungry < 30 ? "" : variate::hungry < 35 ? "\033[32m" : "\033[32;1m")) << variate::hungry << "\033[m" << endl;
			print("当前数量: ");
			for(int i = 1; i <= 6; i++){
				cout << fish_color[i] << fish_name[i] + "鱼:" << "\033[m" << endl;
				if(fish[i].size()){
					cout << "    鱼池: " << fish[i].size() << " 只" << endl;
				}
				if(variate::fish[i][0]){
					cout << "    生鱼: " << variate::fish[i][0] << " 只" << endl;
				}
				if(variate::fish[i][1]){
					cout << "    烤鱼: " << variate::fish[i][1] << " 只" << endl;
				}
				if(fish[i].empty() && !variate::fish[i][0] && !variate::fish[i][1]){
					cout << "    暂无\033[m" << endl;
				}
			}
			cout << endl;
			while(true){
				char c = getch();
				if(c == '1'){
					make_food();
					break;
				}else if(c == '2'){
					roast_food();
					break;
				}else if(c == '3'){
					eat_food();
					break;
				}else if(c == '4'){
					eat_food_roast();
					break;
				}else if(c == '5'){
					return;
				}
			}
			sleept(0.5);
		}
	}
	inline void fishing_setup(){
		while(true){
			clear();
			if(dirty >= 10){
				cout << "\033[31m";
				print("当前污染等级已满, 大部分鱼因病死亡\033[m");
				print("1.清理鱼池");
				for(int i = 0; i <= 6; i++){
					while(!fish[i].empty()){
						fish[i].pop_back();
					}
					variate::aqfish_cnt[i] = 0;
				}
				checkpoint::savechpnp(variate::name);
				while(getch() == '1'){
					variate::money -= 1000;
				}
			}
			print("1.开始钓鱼, 2.清理鱼池, 3.购买钓竿, 4.查看水族馆, 5.制作食物, 6.全部卖出, 7.全部卖出并退出");
			printnl("当前饱食度: ");
			cout << (variate::hungry < 10 ? "\033[31;1m" : (variate::hungry < 30 ? "" : variate::hungry < 35 ? "\033[32m" : "\033[32;1m")) << variate::hungry << "\033[m" << endl;
			print("当前鱼竿: " + fish_name[variate::gan] + "鱼竿");
			print("当前污染等级: " + to_string(dirty));
			for(int i = 0; i <= 6; i++){
				cout << fish_color[i] << fish_name[i] + "鱼:" << "\033[m" << endl;
				for(int j = 0; j < fish[i].size(); j++){
					if(fish[i][j] >= 8){
						cout << "\033[1;32m";
					}else if(fish[i][j] <= 2){
						cout << "\033[1;31m";
					}else{
						cout << "\033[1m";
					}
					cout << "    新鲜度:" << fish[i][j] << "\033[m" << endl;
				}
				if(fish[i].empty()){
					cout << "    暂无\033[m" << endl;
				}
			}
			while(true){
				char c = getch();
				if(c == '1'){
					for(int i = 0; i <= 6; i++){
						for(int j = 0; j < fish[i].size(); j++){
							fish[i][j] -= dirty + 1;
							if(fish[i][j] <= 0){
								if(i == 0){
									dirty++;
								}else{
									fish[i - 1].push_back(10);
								}
								for(int k = j + 1; k < fish[i].size(); k++){
									fish[i][k - 1] = fish[i][k];
								}
								fish[i].pop_back();
								j--;
							}
						}
					}
					fishing_choose();
					variate::hungry--;
					break;
				}else if(c == '2'){
					clear();
					if(!dirty){
						cout << "无需清理" << endl;
						break;
					}
					while(true){
						if(variate::cleaning_ball){
							print("1.清理, 2.退出");
							print("当前污染等级: " + to_string(variate::cleaning_ball));
							print("当前清洁剂个数: " + to_string(variate::cleaning_ball));
							char c = 0;
							while(true){
								c = getch();
								if(c == '1' || c == '2'){
									break;
								}
							}
							if(c == '1'){
								variate::cleaning_ball--;
								dirty -= variate::cleaning_sub;
								if(dirty < 0){
									dirty = 0;
								}
							}else{
								break;
							}
						}else{
							print("1.购买清洁剂并清理, 2.退出");
							print("当前污染等级: " + to_string(variate::cleaning_ball));
							print("清洁剂: ");
							print("    购买花费: $20, 当前金币数量: $" + to_string(variate::money));
							char c = 0;
							while(true){
								c = getch();
								if(c == '1' || c == '2'){
									break;
								}
							}
							if(c == '1'){
								if(variate::money < 20){
									cout << "金钱不够" << endl;
									break;
								}else{
									variate::money -= 20;
									dirty -= variate::cleaning_sub;
									if(dirty < 0){
										dirty = 0;
									}
								}
							}else{
								break;
							}
						}
						if(!dirty){
							cout << "清理完成" << endl;
							break;
						}
					}
					break;
				}else if(c == '3'){
					get_gan();
					sleept(1);
					break;
				}else if(c == '4'){
					if(variate::aqcnt){
						aqua();
						sleept(1);
					}else{
						print("请在购买水族馆后在来查看");
						sleept(0.5);
					}
					break;
				}else if(c == '5'){
					roast();
					break;
				}else if(c == '6'){
					for(int i = 0; i <= 6; i++){
						for(int j = 0; j < fish[i].size(); j++){
							variate::money += (int)(gr() * (1 - 0.02 * dirty) * fresh(fish[i][j]));
						}
						while(!fish[i].empty()){
							fish[i].pop_back();
						}
					}
					clear();
					break;
				}else if(c == '7'){
					for(int i = 0; i <= 6; i++){
						for(int j = 0; j < fish[i].size(); j++){
							variate::money += (int)(gr() * (1 - 0.02 * dirty) * fresh(fish[i][j]));
						}
						while(!fish[i].empty()){
							fish[i].pop_back();
						}
					}
					return;
				}
			}
			sleept(1);
		}
	}
}
#endif
