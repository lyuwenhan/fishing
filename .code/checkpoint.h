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
using std::to_string;
#include"variate.h"
#include"function.h"
#include"parkour.h"
namespace checkpoint{
	bool auto_save_type = false;
	int timestamp = 0;
	string save_name;
	inline string de(){
		string s;
		s += to_string(variate::money);
		s += " ";
		s += to_string(variate::level);
		s += " ";
		s += to_string(variate::get_level);
		s += " ";
		s += to_string(variate::cnt);
		s += " ";
		s += to_string(variate::bf);
		s += " ";
		s += to_string(variate::stime);
		s += " ";
		s += to_string(variate::slip);
		s += " ";
		s += to_string(variate::cleaning_ball);
		s += " ";
		s += to_string(variate::gan);
		s += " ";
		s += to_string(variate::aqcnt);
		for(int i = 0; i <= 6; i++){
			s += " ";
			s += to_string(variate::aqfish_cnt[i]);
		}
		s += " ";
		s += to_string(variate::try_level);
		s += " ";
		s += to_string(variate::cleaning_sub);
		s += " ";
		s += to_string(variate::speed);
		s += " ";
		s += to_string(variate::roast);
		s += " ";
		s += to_string(variate::hungry);
		for(int i = 0; i <= 2; i++){
			for(int j = 0; j < 7; j++){
				s += " ";
				s += to_string(variate::fish[j][i]);
			}
		}
		return s;
	}
	inline bool check_name(const std::string& name) {
		for (char c : name) {
			if (!std::isalnum(c) && c != '_' && c != '-') {
				return false;
			}
		}
		return true;
	}
	namespace decode_code{
		inline bool decode1(string s, bool us){
			long long coin;
			int lv, lv2, c, bf, st, sl, clean, gan, aqc, aqs[7], clesb, ty, sp, fi[7][2], ro, hung;
			stringstream str(s);
			str >> coin >> lv >> lv2 >> c >> bf >> st >> sl >> clean >> gan >> aqc;
			for(int i = 0; i <= 6; i++){
				str >> aqs[i];
			}
			str >> ty >> clesb >> sp >> ro >> hung;
			for(int i = 0; i <= 2; i++){
				for(int j = 0; j < 7; j++){
					str >> fi[j][i];
				}
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
				variate::gan = gan;
				variate::aqcnt = aqc;
				variate::try_level = ty;
				variate::cleaning_sub = clesb;
				for(int i = 0; i <= 6; i++){
					variate::aqfish_cnt[i] = aqs[i];
				}
				for(int i = 0; i <= 2; i++){
					for(int j = 0; j < 7; j++){
						variate::fish[j][i] = fi[j][i];
					}
				}
				variate::speed = sp;
				variate::roast = ro;
				variate::hungry = hung;
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
		inline bool decode(string code){
			return decode(code, true);
		}
	}
	using decode_code::decode;
	inline void savechpnp(string name){
		saving::encryptFile("checkpoint/" + name, "nopwd", de());
	}
	inline bool login(){
		string name, pwd;
		clear();
		printnl(chp_login);
		cout << endl;
		printnl(chp_un);
		getline(name, true);
		if(!check_name(name)){
			print(chp_invalid);
			sleept(1);
			return false;
		}
		printnl(chp_pwd);
		getline(pwd);
		variate::name = name;
		clear();
		if(ifstream((string)"checkpoint/" + name).good() && decode(saving::decryptFile("checkpoint/" + name, "nopwd"), false)){
			sleept(1);
			return decode(saving::decryptFile("checkpoint/" + name, "nopwd"));
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
		getline(name, true);
		if(!check_name(name)){
			print(chp_invalid);
			sleept(1);
			return false;
		}
		printnl(chp_pwd);
		getline(pwd);
		printnl(chp_repwd);
		getline(pwd2);
		if(pwd != pwd2){
			print(chp_pwdng);
			sleept(1);
			return false;
		}
		variate::name = name;
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
				exit(0);
			}
			if(c == '1' ? login() : regi()){
				return c == '1';
			}
		}
	}
}
#endif
