#ifndef checkpoint_defined
#define checkpoint_defined
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using std::cout;
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
	inline string de(){
		ostringstream s;
		s << to_string(variate::money) << ' ' << to_string(variate::level) << ' ' << to_string(variate::get_level) << ' ' << to_string(variate::cnt) << ' ' << to_string(variate::bf) << ' ' << to_string(variate::stime) << ' ' << to_string(variate::slip) << ' ' << to_string(variate::cleaning_ball) << ' ' << to_string(variate::cleaning_sub) << ' ' << to_string(variate::gan) << ' ' << to_string(variate::aqcnt) << ' ' << to_string(variate::try_level) << ' ' << to_string(variate::speed) << ' ' << to_string(variate::roast) << ' ' << to_string(variate::hungry);
		for(int i = 0; i <= 6; i++){
			s << ' ' << to_string(variate::aqfish_cnt[i]);
		}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 7; j++){
				s << ' ' << to_string(variate::fish[j][i]);
			}
		}
		return s.str();
	}
	namespace decode_code{
		inline bool decode1(string s, bool us){
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
			if(us){
				variate::money = coin;
				variate::level = lv;
				variate::get_level = lv2;
				variate::cnt = c;
				variate::bf = bf;
				variate::stime = st;
				variate::slip = sl;
				variate::cleaning_ball = clean;
				variate::cleaning_sub = clesb;
				variate::gan = gan;
				variate::aqcnt = aqc;
				variate::try_level = ty;
				variate::speed = sp;
				variate::roast = ro;
				variate::hungry = hung;
				for(int i = 0; i <= 6; i++){
					variate::aqfish_cnt[i] = aqs[i];
				}
				for(int i = 0; i < 2; i++){
					for(int j = 0; j < 7; j++){
						variate::fish[j][i] = fi[j][i];
					}
				}
			}
			return true;
		}
		inline bool decode(string code, bool ec){
			if(decode1(code, ec)){
				if(ec){
					cout << chp_suc << endl;
				}
				return true;
			}else{
				if(ec){
					cout << chp_err << endl;
				}
				return false;
			}
		}
	}
	using decode_code::decode;
	inline void savechpnp(string name){
		saving::encryptFile("checkpoint/" + name, variate::pwd, de());
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
		if(ifstream((string)"checkpoint/" + name).good() && decode(saving::decryptFile("checkpoint/" + name, variate::pwd), false)){
			sleept(1);
			return decode(saving::decryptFile("checkpoint/" + name, variate::pwd), true);
		}else{
			print(chp_nouser);
			sleept(1);
			return false;
		}
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
