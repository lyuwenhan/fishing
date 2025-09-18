#ifndef checkpoint_defined
#define checkpoint_defined
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
using std::min;
using std::cout;
using std::queue;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::istringstream;
using std::ostringstream;
using std::to_string;
#include"variate.h"
#include"function.h"
#include"parkour.h"
namespace checkpoint{
	bool auto_save_type = false;
	int timestamp = 0;
	string save_name;
	inline bool check_name(const std::string& name) {
		for (char c : name) {
			if (!std::isalnum(c) && c != '_' && c != '-') {
				return false;
			}
		}
		return true;
	}

	bool cmp(const std::vector<uint8_t>& v1, const std::vector<uint8_t>& v2){
		if(v1.size() != v2.size()){
			return false;
		}
		for(int i = 0; i < v1.size(); i++){
			if(v1[i] != v2[i]){
				return false;
			}
		}
		return true;
	}

	namespace decode_code{
		inline bool decode1(const vector<uint8_t> s0){
			std::string s(s0.begin(), s0.end());
			long long coin, c;
			int lv, lv2, bf, st, sl, clean, gan, aqc, aqs[7], clesb, ty, sp, fi[7][2], ro, hung;
			istringstream str(s);
			str >> coin >> lv >> lv2 >> c >> bf >> st >> sl >> clean >> clesb >> gan >> aqc >> ty >> sp >> ro >> hung;
			for(int i = 0; i <= 6; i++){
				str >> aqs[i];
			}
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 7; j++){
					str >> fi[j][i];
				}
			}
			if(coin < 0 || lv < 0 || lv > variate::max_level || lv2 < 0 || lv2 > variate::max_level2 || c < 0 || bf <= 0 || bf > 100 || bf <= 0 ||
			st < 1 || st > 100 || sl < 0 || sl > 100 || clean < 0 || clesb < 1 || gan < 0 || gan > 6 || aqc < 0 || ty < 0 || ro < 0 || hung < 0){
				return false;
			}
			ostringstream s_2;
			s_2 << to_string(coin) << ' ' << to_string(lv) << ' ' << to_string(lv2) << ' ' << to_string(c) << ' ' << to_string(bf) << ' ' << to_string(st) << ' ' << to_string(sl) << ' ' << to_string(clean) << ' ' << to_string(clesb) << ' ' << to_string(gan) << ' ' << to_string(aqc) << ' ' << to_string(ty) << ' ' << to_string(sp) << ' ' << to_string(ro) << ' ' << to_string(hung);
			for(int i = 0; i <= 6; i++){
				s_2 << ' ' << to_string(aqs[i]);
			}
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 7; j++){
					s_2 << ' ' << to_string(fi[j][i]);
				}
			}
			if(s_2.str() != s){
				return false;
			}
			if(sp > 3){
				sp = 3;
			}
			if(sp < 1){
				sp = 1;
			}
			variate::data_saver.money = coin;
			variate::data_saver.level = lv;
			variate::data_saver.get_level = lv2;
			variate::data_saver.cnt = c;
			variate::data_saver.bf = bf;
			variate::data_saver.stime = st;
			variate::data_saver.slip = sl;
			variate::data_saver.cleaning_ball = clean;
			variate::data_saver.cleaning_sub = clesb;
			variate::data_saver.gan = gan;
			variate::data_saver.aqcnt = aqc;
			variate::data_saver.try_level = ty;
			variate::data_saver.speed = sp;
			variate::data_saver.roast = ro;
			variate::data_saver.hungry = hung;
			for(int i = 0; i <= 6; i++){
				variate::data_saver.aqfish_cnt[i] = aqs[i];
			}
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 7; j++){
					variate::data_saver.fish[j][i] = fi[j][i];
				}
			}
			return true;
		}
		
		inline bool decode2(const vector<uint8_t>& s){
			variate::svariate temp(s);
			if(temp.money < 0 || temp.level < 0 || temp.level > variate::max_level || temp.get_level < 0 || temp.get_level > variate::max_level2 || temp.cnt < 0 || temp.bf < 0 || temp.bf > 100 || temp.stime < 1 || temp.stime > 10 || temp.slip < 0 || temp.slip > 100 || temp.cleaning_ball < 0 || temp.cleaning_sub < 1 || temp.gan < 0 || temp.gan > 6 || temp.aqcnt < 0 || temp.try_level < 0 || temp.roast < 0 || temp.hungry < 0){
				return false;
			}
			const vector<uint8_t> v = temp;
			variate::data_saver.set(v);
			return cmp(v, variate::data_saver.get());
		}
		inline bool decode(vector<uint8_t> code){
			if(decode1(code) || decode2(code)){
				cout << chp_suc << endl;
				return true;
			}else{
				return false;
			}
		}
	}
	using decode_code::decode;
	inline void savechpnp(string name){
		saving::encryptFile("checkpoint/" + name, variate::pwd, variate::data_saver.get());
	}
	inline bool login(){
		string name, pwd;
		clear();
		printnl(chp_login);
		cout << endl;
		printnlne(chp_un);
		getline(name, 1);
		if(!check_name(name)){
			print(chp_invalid);
			sleept(1);
			return false;
		}
		printnlne(chp_pwd);
		getline(pwd, 2);
		variate::name = name;
		variate::pwd = pwd;
		clear();
		bool ok;
		if(!(ok = (ifstream((string)"checkpoint/" + name).good() && decode(saving::decryptFile("checkpoint/" + name, variate::pwd))))){
			print(chp_nouser);
		}
		sleept(1);
		return ok;
	}
	inline bool regi(){
		string name, pwd, pwd2;
		clear();
		printnl(chp_regi);
		cout << endl;
		printnl(chp_un);
		getline(name, 1);
		if(!check_name(name)){
			print(chp_invalid);
			sleept(1);
			return false;
		}
		printnlne(chp_pwd);
		getline(pwd, 2);
		printnlne(chp_repwd);
		getline(pwd2, 2);
		if(pwd != pwd2){
			print(chp_pwdng);
			sleept(1);
			return false;
		}
		variate::name = name;
		variate::pwd = pwd;
		clear();
		if(ifstream((string)"checkpoint/" + name).good()){
			print(chp_yesuser);
			sleept(1);
			return false;
		}else{
			print(chp_regigood);
			return true;
		}
	}
	inline bool chp(){
		string name;
		while(true){
			clear();
			print(chp_main);
			char c = getch();
			while(c != '1' && c != '2' && c != '3'){
				c = getch();
			}
			if(c == '3'){
				clear();
				exit(0);
			}
			if(c == '1' ? login() : regi()){
				return c == '1';
			}
		}
	}
}
#endif
