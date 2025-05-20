#ifndef tool_defined
#define tool_defined
#include<iostream>
#include<iomanip>
#include<vector>
using std::cout;
using std::min;
#include "variate.h"
#include "checkpoint.h"
namespace tool{
	struct type1{
		string name;
		vector<type1> op;
	};
	void dfs2(string s){
		clear();
		if(s == "鱼竿"){
			const int l = 0, r = 6;
			int a = variate::gan;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << fishing::fish_name[a] << "钓竿" << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::gan = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << fishing::fish_name[a] << "钓竿" << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "金币数量"){
			const int l = 0, r = 1000000;
			int a = variate::money;
			if(a <= 10){
			}else if(a <= 100){
				a /= 10;
				a *= 10;
			}else if(a <= 1000){
				a /= 100;
				a *= 100;
			}else if(a <= 10000){
				a /= 1000;
				a *= 1000;
			}else if(a <= 100000){
				a /= 10000;
				a *= 10000;
			}else if(a <= 1000000){
				a /= 100000;
				a *= 100000;
			}else{
				a = 1000000;
			}
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			while(true){
				char c = getch();
				if(c == 'a' || c == 'A'){
					if(a <= 0){
					}else if(a <= 10){
						a--;
					}else if(a <= 100){
						a -= 10;
					}else if(a <= 1000){
						a -= 100;
					}else if(a <= 10000){
						a -= 1000;
					}else if(a <= 100000){
						a -= 10000;
					}else if(a <= 1000000){
						a -= 100000;
					}
				}else if(c == 'd' || c == 'D'){
					if(a < 10){
						a++;
					}else if(a < 100){
						a += 10;
					}else if(a < 1000){
						a += 100;
					}else if(a < 10000){
						a += 1000;
					}else if(a < 100000){
						a += 10000;
					}else if(a < 1000000){
						a += 100000;
					}
				}else if(c == '\r'){
					variate::money = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "水族馆容量"){
			const int l = 0, r = 30;
			int a = variate::aqcnt;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::aqcnt = a;
					int cnt = variate::aqcnt;
					for(int i = 6; i >= 0; i--){
						variate::aqfish_cnt[i] = min(variate::aqfish_cnt[i], cnt);
						cnt -= variate::aqfish_cnt[i];
					}
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "钓鱼数量"){
			const int l = 0, r = 1000000;
			int a = variate::cnt;
			if(a <= 10){
			}else if(a <= 100){
				a /= 10;
				a *= 10;
			}else if(a <= 1000){
				a /= 100;
				a *= 100;
			}else if(a <= 10000){
				a /= 1000;
				a *= 1000;
			}else if(a <= 100000){
				a /= 10000;
				a *= 10000;
			}else if(a <= 1000000){
				a /= 100000;
				a *= 100000;
			}else{
				a = 1000000;
			}
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			while(true){
				char c = getch();
				if(c == 'a' || c == 'A'){
					if(a <= 0){
					}else if(a <= 10){
						a--;
					}else if(a <= 100){
						a -= 10;
					}else if(a <= 1000){
						a -= 100;
					}else if(a <= 10000){
						a -= 1000;
					}else if(a <= 100000){
						a -= 10000;
					}else if(a <= 1000000){
						a -= 100000;
					}
				}else if(c == 'd' || c == 'D'){
					if(a < 10){
						a++;
					}else if(a < 100){
						a += 10;
					}else if(a < 1000){
						a += 100;
					}else if(a < 10000){
						a += 1000;
					}else if(a < 100000){
						a += 10000;
					}else if(a < 1000000){
						a += 100000;
					}
				}else if(c == '\r'){
					variate::cnt = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "腐烂的鱼数量 (水族馆)"){
			const int l = 0, r = variate::aqcnt;
			int a = variate::aqfish_cnt[0];
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::aqfish_cnt[0] = a;
					int cnt = variate::aqcnt;
					for(int i = 6; i >= 0; i--){
						variate::aqfish_cnt[i] = min(variate::aqfish_cnt[i], cnt);
						cnt -= variate::aqfish_cnt[i];
					}
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "普通的鱼数量 (水族馆)"){
			const int l = 0, r = variate::aqcnt;
			int a = variate::aqfish_cnt[1];
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::aqfish_cnt[1] = a;
					int cnt = variate::aqcnt;
					for(int i = 6; i >= 0; i--){
						variate::aqfish_cnt[i] = min(variate::aqfish_cnt[i], cnt);
						cnt -= variate::aqfish_cnt[i];
					}
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "紫水晶鱼数量 (水族馆)"){
			const int l = 0, r = variate::aqcnt;
			int a = variate::aqfish_cnt[2];
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::aqfish_cnt[2] = a;
					int cnt = variate::aqcnt;
					for(int i = 6; i >= 0; i--){
						variate::aqfish_cnt[i] = min(variate::aqfish_cnt[i], cnt);
						cnt -= variate::aqfish_cnt[i];
					}
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "青金石鱼数量 (水族馆)"){
			const int l = 0, r = variate::aqcnt;
			int a = variate::aqfish_cnt[3];
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::aqfish_cnt[3] = a;
					int cnt = variate::aqcnt;
					for(int i = 6; i >= 0; i--){
						variate::aqfish_cnt[i] = min(variate::aqfish_cnt[i], cnt);
						cnt -= variate::aqfish_cnt[i];
					}
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "金鱼数量 (水族馆)"){
			const int l = 0, r = variate::aqcnt;
			int a = variate::aqfish_cnt[4];
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::aqfish_cnt[4] = a;
					int cnt = variate::aqcnt;
					for(int i = 6; i >= 0; i--){
						variate::aqfish_cnt[i] = min(variate::aqfish_cnt[i], cnt);
						cnt -= variate::aqfish_cnt[i];
					}
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "绿宝石鱼数量 (水族馆)"){
			const int l = 0, r = variate::aqcnt;
			int a = variate::aqfish_cnt[5];
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::aqfish_cnt[5] = a;
					int cnt = variate::aqcnt;
					for(int i = 6; i >= 0; i--){
						variate::aqfish_cnt[i] = min(variate::aqfish_cnt[i], cnt);
						cnt -= variate::aqfish_cnt[i];
					}
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "钻石鱼数量 (水族馆)"){
			const int l = 0, r = variate::aqcnt;
			int a = variate::aqfish_cnt[6];
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::aqfish_cnt[6] = a;
					int cnt = variate::aqcnt;
					for(int i = 6; i >= 0; i--){
						variate::aqfish_cnt[i] = min(variate::aqfish_cnt[i], cnt);
						cnt -= variate::aqfish_cnt[i];
					}
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "上钩速度"){
			const int l = 0, r = variate::max_level;
			int a = variate::level;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << variate::mintime[a] << " ~ " << variate::maxtime[a] << "s" << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::level = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << variate::mintime[a] << " ~ " << variate::maxtime[a] << "s" << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "钓鱼收益"){
			const int l = 0, r = variate::max_level2;
			int a = variate::get_level;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << variate::minget[a] << " ~ " << variate::maxget[a] << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::get_level = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << variate::minget[a] << " ~ " << variate::maxget[a] << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "脱钩概率"){
			const int l = 90, r = 0;
			int a = variate::slip;
			cout << "按 a 增加, d 减少, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			while(true){
				char c = getch();
				if(c == 'a' || c == 'A'){
					if(a >= 90){
					}else if(a >= 10){
						a += 10;
					}else if(a >= 5){
						a = 10;
					}else if(a >= 0){
						a++;
					}
				}else if(c == 'd' || c == 'D'){
					if(a > 10){
						a -= 10;
					}else if(a > 5){
						a = 5;
					}else if(a > 0){
						a--;
					}
				}else if(c == '\r'){
					variate::slip = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 增加, d 减少, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "清洁剂数量"){
			const int l = 0, r = 100;
			int a = variate::cleaning_ball;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::cleaning_ball = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "清洁剂效果"){
			const int l = 1, r = 10;
			int a = variate::cleaning_sub;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::cleaning_sub = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "甩杆倍速"){
			const int l = 1, r = 10;
			int a = variate::stime;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::stime = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "大鱼概率"){
			const int l = 0, r = 100;
			int a = variate::bf;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			while(true){
				char c = getch();
				if(c == 'a' || c == 'A'){
					a -= 5;
					if(a < l){
						a = l;
					}
				}else if(c == 'd' || c == 'D'){
					a += 5;
					if(a > r){
						a = r;
					}
				}else if(c == '\r'){
					variate::bf = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "愚人节彩蛋 (抽奖)"){
			bool a = variate::fish_man;
			cout << "按 空格 切换, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a ? "有" : "无") << endl;
			while(true){
				char c = getch();
				if(c == ' '){
					a = !a;
				}else if(c == '\r'){
					variate::fish_man = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 空格 切换, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a ? "有" : "无") << endl;
			}
		}else if(s == "大鱼诱饵数量 (抽奖)"){
			const int l = 0, r = 100;
			int a = variate::big;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::big = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "钻石鱼数量 (抽奖)"){
			const int l = 0, r = 100;
			int a = variate::diamond;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::diamond = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}else if(s == "饱食度"){
			const int l = 0, r = 40;
			int a = variate::hungry;
			cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
			cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
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
					variate::hungry = a;
					clear();
					return;
				}else if(c == 127){
					clear();
					return;
				}
				clear();
				cout << "按 a 减少, d 增加, 按 enter 保存, 按 backspace 退出" << endl << s << ':' << endl;
				cout << (a == l ? "\033[1;31m" : "\033[1m") << " < \033[m" << a << (a == r ? "\033[1;31m" : "\033[1m") << " > \033[m" << endl;
			}
		}
	}
	void dfss(vector<type1> li){
		clear();
		int cho;
		cout << "按 w, s 选择, 按 enter 进入, 按 backspace 退回" << endl << endl;
		for(int i = 0; i < li.size(); i++){
			if(cho == i){
				cout << "\033[32;1m";
			}
			cout << li[i].name;
			cout << "\033[0m";
			cout << endl;
		}
		while(true){
			char c = getch();
			if(c == 'w' || c == 'W'){
				cho--;
				if(cho < 0){
					cho = 0;
				}
			}else if(c == 's' || c == 'S'){
				cho++;
				if(cho >= li.size()){
					cho = li.size() - 1;
				}
			}else if(c == '\r'){
				if(li[cho].op.empty()){
					dfs2(li[cho].name);
				}else{
					dfss(li[cho].op);
				}
			}else if(c == 127){
				clear();
				return;
			}
			clear();
			cout << "按 w, s 选择, 按 enter 进入, 按 backspace 退回" << endl << endl;
			for(int i = 0; i < li.size(); i++){
				if(cho == i){
					cout << "\033[32;1m";
				}
				cout << li[i].name;
				if(cho == i){
					cout << "\033[0m";
				}
				cout << endl;
			}
		}
	}
	inline void tool(){
		if(!variate::use_tool){
			return;
		}
		clear();
		cout << "开发者模式, 如需使用此功能, 请询问开发者密码。" << endl;
		cout << "请输入密码: " << flush;
		string mi;
		getline(mi);//nothingdone651225$
		if(to_hash(mi) != 6719929333535458606){
			cout << "密码错误, 请重试: " << flush;
			string mi;
			getline(mi);
			if(to_hash(mi) != 6719929333535458606){
				return;
			}
		}
		clear();
		vector<type1> li = {	
	(type1){
		"金币数量", 
		{}
	}, 
	(type1){
		"钓鱼", 
		{
			(type1){
				"钓鱼数量", 
				{}
			}, 
			(type1){
				"鱼竿", 
				{}
			}, 
			(type1){
				"水族馆", 
				{
					(type1){
						"水族馆容量", 
						{}
					}, 
					(type1){
						"腐烂的鱼数量 (水族馆)", 
						{}
					}, 
					(type1){
						"普通的鱼数量 (水族馆)", 
						{}
					}, 
					(type1){
						"紫水晶鱼数量 (水族馆)", 
						{}
					}, 
					(type1){
						"青金石鱼数量 (水族馆)", 
						{}
					}, 
					(type1){
						"金鱼数量 (水族馆)", 
						{}
					}, 
					(type1){
						"绿宝石鱼数量 (水族馆)", 
						{}
					}, 
					(type1){
						"钻石鱼数量 (水族馆)", 
						{}
					}
				}
			}, 
			(type1){
				"鱼竿", 
				{}
			}
		}
	}, 
	(type1){
		"普通商店", 
		{
			(type1){
				"上钩速度", 
				{}
			}, 
			(type1){
				"钓鱼收益", 
				{}
			}, 
			(type1){
				"脱钩概率", 
				{}
			}, 
			(type1){
				"清洁剂数量", 
				{}
			}, 
			(type1){
				"清洁剂效果", 
				{}
			}
		}
	}, 
	(type1){
		"超级商店", 
		{
			(type1){
				"甩杆倍速", 
				{}
			}, 
			(type1){
				"大鱼概率", 
				{}
			}
		}
	}, 
	(type1){
		"抽奖", 
		{
			(type1){
				"愚人节彩蛋 (抽奖)", 
				{}
			}, 
			(type1){
				"大鱼诱饵数量 (抽奖)", 
				{}
			}, 
			(type1){
				"钻石鱼数量 (抽奖)", 
				{}
			}
		}
	}};
		dfss(li);
	}
}
#endif