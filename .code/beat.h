#ifndef beat_defined
#define beat_defined
#include<unordered_map>
#include<iostream>
#include<iomanip>
#include<vector>
using std::string;
using std::vector;
using std::pair;
using std::cout;
using std::max;
using std::unordered_map;
#include"variate.h"
#include"function.h"
namespace beat{
	int america = 0;
	int sleepcnt = 0, eatcnt = 0, e2 = 0, s2 = 0;
	int temple = 0, romar = 0, headbone = 0, drafood = 0;
	struct be{
		string title;
		vector<string> things;
		vector<string> choose;
		vector<string> cnext;
		vector<int> cnext2;
	}
	things[102] = be_1;
	int now;
	unordered_map<char, int> m1;
	vector<char> m2;
	inline void setup(){
		sleepcnt = eatcnt = temple = romar = america = headbone = e2 = s2 = 0;
		now = 0;
		for(int i = 1; i <= 9; i++){
			m1[i + '0'] = m2.size();
			m2.push_back(i + '0');
		}
		for(int i = 0; i <= 26; i++){
			m1[i + 'a'] = m2.size();
			m2.push_back(i + 'a');
		}
	}
	inline ostream& operator<<(ostream& out, be a){
		auto &title = a.title;
		auto &things = a.things;
		auto &choose = a.choose;
		auto &cnext = a.cnext;
		auto &cnext2 = a.cnext2;
		if(!title.empty()){
			print(title);
			cout << endl;
		}
		for(int i = 0; i < things.size(); i++){
			print(things[i]);
			sleept(0.1);
		}
		cout << endl;

		if(now == 21){
			if(!romar){
				printa(be_2);
				variate::money += 100;
			}
			if(romar == 5){
				printa(be_3);
				variate::money += 100;
			}
			romar++;
		}

		if(now == 22){
			if(!america){
				printa(be_4);
				variate::money += 100;
			}
			if(america == 5){
				printa(be_3);
				variate::money += 100;
			}
			america++;
		}

		if(now == 24){
			if(!headbone){
				printa(be_5);
				variate::money += 100;
			}
			if(headbone == 5){
				printa(be_6);
				variate::money += 100;
			}
			headbone++;
		}
		string s;
		for(int i = 0; i < choose.size(); i++){
			s += m2[i];
			s += "." + choose[i];
			if(i < choose.size() - 1){
				s += ", ";
			}
		}
		print(s);
		char c;
		while(m1.find(c = getch()) == m1.end() || m1[c] >= (int)choose.size());
		if(!cnext[m1[c]].empty()){
			clear();
			printa(cnext[m1[c]]);
		}
		now = cnext2[m1[c]];
		if(now == 13){
			if(!temple){
				printa(be_7);
				variate::money += 100;
			}else if(temple == 5){
				printa(be_8);
				variate::money += 100;
			}
			temple++;
		}

		if(now == 30){
			if(eatcnt >= 30 && !drafood){
				printa(be_9);
				variate::money += 100;
			}
			drafood++;
		}

		if(now == -3){
			if(eatcnt >= 30 && e2 == 0){
				printa(be_10);
				variate::money += 100;
			}else if(eatcnt >= 30 && e2 == 5){
				printa(be_11);
				variate::money += 200;
			}
			e2++;
			now = 1;
		}

		if(now == -4){
			if(sleepcnt >= 30 && s2 == 0){
				printa(be_12);
				variate::money += 100;
			}else if(sleepcnt >= 30 && s2 == 5){
				printa(be_13);
				variate::money += 200;
			}
			s2++;
			now = 1;
		}

		if(now == -1){
			eatcnt++;
			if(eatcnt == 5){
				printa(be_14);
				variate::money += 100;
			}else if(eatcnt == 10){
				printa(be_15);
				variate::money += 100;
			}else if(eatcnt == 30){
				printa(be_16);
				variate::money += 100;
			}
			now = 1;
		}

		if(now == -2){
			sleepcnt++;
			if(sleepcnt == 5){
				printa(be_17);
				variate::money += 100;
			}else if(sleepcnt == 10){
				printa(be_18);
				variate::money += 100;
			}else if(sleepcnt == 30){
				printa(be_19);
				variate::money += 100;
			}
			now = 1;
		}

		sleept(0.5);
		return out;
	}
	inline void main(){
		clear();
		setup();
		while(true){
			clear();
			cout << things[now] << endl;
			if(now == -5){
				printa(be_end);
				variate::try_level++;
				variate::money += 100;
				return;
			}
		}
	}
}
#endif
