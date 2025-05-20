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
#include"base64.h"
#include"variate.h"
#include"function.h"
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
		return s;
	}
	inline string encode(){
		string s = de();
		string gm1 = b1.encode(s);
		string gm2 = b2.encode(gm1);
		string gm3 = b3.encode(gm2);
		return gm3;
	}
	namespace decode_code{
		inline bool decode1(string gm3, bool us){
			string gm2, gm1, s, s_2, gm1_2, gm2_2, gm3_2;
			long long coin;
			int lv, lv2, c, bf, st, sl;
			char autofishing;
			if(b3.encode(gm2 = b3.decode(gm3)) != gm3){
				return false;
			}
			if(b2.encode(gm1 = b2.decode(gm2)) != gm2){
				return false;
			}
			if(b1.encode(s = b1.decode(gm1)) != gm1){
				return false;
			}
			sscanf(s.c_str(), "coin:%lldlv:%dlv2:%dc:%dbf:%dst:%daf:%cslip:%d", &coin, &lv, &lv2, &c, &bf, &st, &autofishing, &sl);
			s_2 += "coin:";
			s_2 += to_string(coin);
			s_2 += "lv:";
			s_2 += to_string(lv);
			s_2 += "lv2:";
			s_2 += to_string(lv2);
			s_2 += "c:";
			s_2 += to_string(c);
			s_2 += "bf:";
			s_2 += to_string(bf);
			s_2 += "st:";
			s_2 += to_string(st);
			s_2 += "af:";
			s_2 += autofishing;
			s_2 += "slip:";
			s_2 += to_string(sl);
			if(s_2 != s){
				return false;
			}
			if((gm1_2 = b1.encode(s_2)) != gm1){
				return false;
			}
			if((gm2_2 = b2.encode(gm1_2)) != gm2){
				return false;
			}
			if((gm3_2 = b3.encode(gm2_2)) != gm3){
				return false;
			}
			if(us){
				variate::money = coin;
				variate::level = lv;
				variate::get_level = lv2;
				variate::cnt = c;
				variate::bf = bf;
				variate::stime = st;
				variate::slip = sl;
			}
			return true;
		}
		inline bool decode2(string gm3, bool us){
			string gm2, gm1, s, s_2, gm1_2, gm2_2, gm3_2;
			long long coin;
			int lv, lv2, c, bf, st, sl, clean;
			char autofishing;
			if(b3.encode(gm2 = b3.decode(gm3)) != gm3){
				return false;
			}
			if(b2.encode(gm1 = b2.decode(gm2)) != gm2){
				return false;
			}
			if(b1.encode(s = b1.decode(gm1)) != gm1){
				return false;
			}
			sscanf(s.c_str(), "coin:%lldlv:%dlv2:%dc:%dbf:%dst:%daf:%cslip:%dclean:%d", &coin, &lv, &lv2, &c, &bf, &st, &autofishing, &sl, &clean);
			s_2 += "coin:";
			s_2 += to_string(coin);
			s_2 += "lv:";
			s_2 += to_string(lv);
			s_2 += "lv2:";
			s_2 += to_string(lv2);
			s_2 += "c:";
			s_2 += to_string(c);
			s_2 += "bf:";
			s_2 += to_string(bf);
			s_2 += "st:";
			s_2 += to_string(st);
			s_2 += "af:";
			s_2 += autofishing;
			s_2 += "slip:";
			s_2 += to_string(sl);
			s_2 += "clean:";
			s_2 += to_string(clean);
			if(s_2 != s){
				return false;
			}
			if((gm1_2 = b1.encode(s_2)) != gm1){
				return false;
			}
			if((gm2_2 = b2.encode(gm1_2)) != gm2){
				return false;
			}
			if((gm3_2 = b3.encode(gm2_2)) != gm3){
				return false;
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
			}
			return true;
		}
		inline bool decode3(string gm3, bool us){
			string gm2, gm1, s, s_2, gm1_2, gm2_2, gm3_2;
			long long coin;
			int lv, lv2, c, bf, st, sl, clean;
			if(b3.encode(gm2 = b3.decode(gm3)) != gm3){
				return false;
			}
			if(b2.encode(gm1 = b2.decode(gm2)) != gm2){
				return false;
			}
			if(b1.encode(s = b1.decode(gm1)) != gm1){
				return false;
			}
			sscanf(s.c_str(), "coin:%lldlv:%dlv2:%dc:%dbf:%dst:%dslip:%dclean:%d", &coin, &lv, &lv2, &c, &bf, &st, &sl, &clean);
			s_2 += "coin:";
			s_2 += to_string(coin);
			s_2 += "lv:";
			s_2 += to_string(lv);
			s_2 += "lv2:";
			s_2 += to_string(lv2);
			s_2 += "c:";
			s_2 += to_string(c);
			s_2 += "bf:";
			s_2 += to_string(bf);
			s_2 += "st:";
			s_2 += to_string(st);
			s_2 += "slip:";
			s_2 += to_string(sl);
			s_2 += "clean:";
			s_2 += to_string(clean);
			if(s_2 != s){
				return false;
			}
			if((gm1_2 = b1.encode(s_2)) != gm1){
				return false;
			}
			if((gm2_2 = b2.encode(gm1_2)) != gm2){
				return false;
			}
			if((gm3_2 = b3.encode(gm2_2)) != gm3){
				return false;
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
			}
			return true;
		}
		inline bool decode4(string gm3, bool us){
			string gm2, gm1, s, s_2, gm1_2, gm2_2, gm3_2, egg;
			long long coin;
			int lv, lv2, c, bf, st, sl, clean;
			if(b3.encode(gm2 = b3.decode(gm3)) != gm3){
				return false;
			}
			if(b2.encode(gm1 = b2.decode(gm2)) != gm2){
				return false;
			}
			if(b1.encode(s = b1.decode(gm1)) != gm1){
				return false;
			}
			stringstream str(s);
			str >> coin >> lv >> lv2 >> c >> bf >> st >> sl >> clean >> egg;
			s_2 += to_string(coin);
			s_2 += " ";
			s_2 += to_string(lv);
			s_2 += " ";
			s_2 += to_string(lv2);
			s_2 += " ";
			s_2 += to_string(c);
			s_2 += " ";
			s_2 += to_string(bf);
			s_2 += " ";
			s_2 += to_string(st);
			s_2 += " ";
			s_2 += to_string(sl);
			s_2 += " ";
			s_2 += to_string(clean);
			s_2 += " ";
			s_2 += egg;
			if(s_2 != s){
				return false;
			}
			if((gm1_2 = b1.encode(s_2)) != gm1){
				return false;
			}
			if((gm2_2 = b2.encode(gm1_2)) != gm2){
				return false;
			}
			if((gm3_2 = b3.encode(gm2_2)) != gm3){
				return false;
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
			}
			return true;
		}
		inline bool decode5(string gm3, bool us){
			string gm2, gm1, s, s_2, gm1_2, gm2_2, gm3_2, egg;
			long long coin;
			int lv, lv2, c, bf, st, sl, clean, gan;
			if(b3.encode(gm2 = b3.decode(gm3)) != gm3){
				return false;
			}
			if(b2.encode(gm1 = b2.decode(gm2)) != gm2){
				return false;
			}
			if(b1.encode(s = b1.decode(gm1)) != gm1){
				return false;
			}
			stringstream str(s);
			str >> coin >> lv >> lv2 >> c >> bf >> st >> sl >> clean >> egg >> gan;
			s_2 += to_string(coin);
			s_2 += " ";
			s_2 += to_string(lv);
			s_2 += " ";
			s_2 += to_string(lv2);
			s_2 += " ";
			s_2 += to_string(c);
			s_2 += " ";
			s_2 += to_string(bf);
			s_2 += " ";
			s_2 += to_string(st);
			s_2 += " ";
			s_2 += to_string(sl);
			s_2 += " ";
			s_2 += to_string(clean);
			s_2 += " ";
			s_2 += egg;
			s_2 += " ";
			s_2 += to_string(gan);
			if(s_2 != s){
				return false;
			}
			if((gm1_2 = b1.encode(s_2)) != gm1){
				return false;
			}
			if((gm2_2 = b2.encode(gm1_2)) != gm2){
				return false;
			}
			if((gm3_2 = b3.encode(gm2_2)) != gm3){
				return false;
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
			}
			return true;
		}
		inline bool decode6(string gm3, bool us){
			string gm2, gm1, s, s_2, gm1_2, gm2_2, gm3_2, egg, can;
			long long coin;
			int lv, lv2, c, bf, st, sl, clean, gan, aqc, aqs[7];
			if(b3.encode(gm2 = b3.decode(gm3)) != gm3){
				return false;
			}
			if(b2.encode(gm1 = b2.decode(gm2)) != gm2){
				return false;
			}
			if(b1.encode(s = b1.decode(gm1)) != gm1){
				return false;
			}
			stringstream str(s);
			str >> coin >> lv >> lv2 >> c >> bf >> st >> sl >> clean >> egg >> gan >> aqc;
			for(int i = 0; i <= 6; i++){
				str >> aqs[i];
			}
			str >> can;
			s_2 += to_string(coin);
			s_2 += " ";
			s_2 += to_string(lv);
			s_2 += " ";
			s_2 += to_string(lv2);
			s_2 += " ";
			s_2 += to_string(c);
			s_2 += " ";
			s_2 += to_string(bf);
			s_2 += " ";
			s_2 += to_string(st);
			s_2 += " ";
			s_2 += to_string(sl);
			s_2 += " ";
			s_2 += to_string(clean);
			s_2 += " ";
			s_2 += egg;
			s_2 += " ";
			s_2 += to_string(gan);
			s_2 += " ";
			s_2 += to_string(aqc);
			for(int i = 0; i <= 6; i++){
				s_2 += " ";
				s_2 += to_string(aqs[i]);
			}
			s_2 += " ";
			s_2 += can;
			if(s_2 != s){
				return false;
			}
			if((gm1_2 = b1.encode(s_2)) != gm1){
				return false;
			}
			if((gm2_2 = b2.encode(gm1_2)) != gm2){
				return false;
			}
			if((gm3_2 = b3.encode(gm2_2)) != gm3){
				return false;
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
				for(int i = 0; i <= 6; i++){
					variate::aqfish_cnt[i] = aqs[i];
				}
			}
			return true;
		}
		inline bool decode7(string gm3, bool us){
			string gm2, gm1, s, s_2, gm1_2, gm2_2, gm3_2, egg, can;
			long long coin;
			int lv, lv2, c, bf, st, sl, clean, gan, aqc, aqs[7], clesb, ty;
			if(b3.encode(gm2 = b3.decode(gm3)) != gm3){
				return false;
			}
			if(b2.encode(gm1 = b2.decode(gm2)) != gm2){
				return false;
			}
			if(b1.encode(s = b1.decode(gm1)) != gm1){
				return false;
			}
			stringstream str(s);
			str >> coin >> lv >> lv2 >> c >> bf >> st >> sl >> clean >> egg >> gan >> aqc;
			for(int i = 0; i <= 6; i++){
				str >> aqs[i];
			}
			str >> can >> ty >> clesb;
			s_2 += to_string(coin);
			s_2 += " ";
			s_2 += to_string(lv);
			s_2 += " ";
			s_2 += to_string(lv2);
			s_2 += " ";
			s_2 += to_string(c);
			s_2 += " ";
			s_2 += to_string(bf);
			s_2 += " ";
			s_2 += to_string(st);
			s_2 += " ";
			s_2 += to_string(sl);
			s_2 += " ";
			s_2 += to_string(clean);
			s_2 += " ";
			s_2 += egg;
			s_2 += " ";
			s_2 += to_string(gan);
			s_2 += " ";
			s_2 += to_string(aqc);
			for(int i = 0; i <= 6; i++){
				s_2 += " ";
				s_2 += to_string(aqs[i]);
			}
			s_2 += " ";
			s_2 += can;
			s_2 += " ";
			s_2 += to_string(ty);
			s_2 += " ";
			s_2 += to_string(clesb);
			if(s_2 != s){
				return false;
			}
			if((gm1_2 = b1.encode(s_2)) != gm1){
				return false;
			}
			if((gm2_2 = b2.encode(gm1_2)) != gm2){
				return false;
			}
			if((gm3_2 = b3.encode(gm2_2)) != gm3){
				return false;
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
			}
			return true;
		}
		inline bool decode8(string gm3, bool us){
			string gm2, gm1, s, s_2, gm1_2, gm2_2, gm3_2;
			long long coin;
			int lv, lv2, c, bf, st, sl, clean, gan, aqc, aqs[7], clesb, ty, sp;
			if(b3.encode(gm2 = b3.decode(gm3)) != gm3){
				return false;
			}
			if(b2.encode(gm1 = b2.decode(gm2)) != gm2){
				return false;
			}
			if(b1.encode(s = b1.decode(gm1)) != gm1){
				return false;
			}
			stringstream str(s);
			str >> coin >> lv >> lv2 >> c >> bf >> st >> sl >> clean >> gan >> aqc;
			for(int i = 0; i <= 6; i++){
				str >> aqs[i];
			}
			str >> ty >> clesb >> sp;
			s_2 += to_string(coin);
			s_2 += " ";
			s_2 += to_string(lv);
			s_2 += " ";
			s_2 += to_string(lv2);
			s_2 += " ";
			s_2 += to_string(c);
			s_2 += " ";
			s_2 += to_string(bf);
			s_2 += " ";
			s_2 += to_string(st);
			s_2 += " ";
			s_2 += to_string(sl);
			s_2 += " ";
			s_2 += to_string(clean);
			s_2 += " ";
			s_2 += to_string(gan);
			s_2 += " ";
			s_2 += to_string(aqc);
			for(int i = 0; i <= 6; i++){
				s_2 += " ";
				s_2 += to_string(aqs[i]);
			}
			s_2 += " ";
			s_2 += to_string(ty);
			s_2 += " ";
			s_2 += to_string(clesb);
			s_2 += to_string(sp);
			if(s_2 != s){
				return false;
			}
			if((gm1_2 = b1.encode(s_2)) != gm1){
				return false;
			}
			if((gm2_2 = b2.encode(gm1_2)) != gm2){
				return false;
			}
			if((gm3_2 = b3.encode(gm2_2)) != gm3){
				return false;
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
				variate::speed = sp;
			}
			return true;
		}
		inline bool decode(string code, bool ec, bool us){
			if(decode1(code, us) || decode2(code, us) || decode3(code, us) || decode4(code, us) || decode5(code, us) || decode6(code, us) || decode7(code, us)){
				if(ec){
					cout << "读取成功" << endl; 
				}
				return true;
			}else{
				if(ec){
					cout << "存档损坏, 请换个文件再试试。具体文件可以去checkpoint/name.txt中查询" << endl;
				}
				return false;
			}
		}
		inline bool decode(string code, bool ec){
			return decode(code, ec, true);
		}
		inline bool decode(string code){
			return decode(code, true, true);
		}
	}
	using decode_code::decode;
	inline void savechpnp(string name, bool b = true){
		system("mkdir checkpoint >/dev/null 2>&1");
		if(!directoryExists("checkpoint")){
			cout << "保存文件夹缺失, 请手动创建名为\"checkpoint\"的文件夹" << endl;
			system("stty echo cooked");
			exit(0);
		}
		ofstream("checkpoint/" + name) << encode() << std::endl;
		system(("echo \"" + name + "\" >> checkpoint/name.txt").c_str());
		system("sort -u -o checkpoint/name.txt checkpoint/name.txt");
		if(b){
			cout << "存档成功。" << endl;
		}
	}
	inline void savechp(string name){
		string ba, ba2;
		cout << "输入你的保存密码, 输入\"exit\"即可退出: ";
		cout.flush();
		getline(ba);
		if(ba == "exit"){
			return;
		}
		cout << "确认你的保存密码, 输入\"exit\"即可退出: ";
		cout.flush();
		getline(ba2);
		if(ba2 == "exit"){
			return;
		}
		if(ba != ba2){
			cout << "两次密码不一样" << endl;
			return;
		}
		base64 base(ba, false);
		system("mkdir checkpoint >/dev/null 2>&1");
		if(!directoryExists("checkpoint")){
			cout << "保存文件夹缺失, 请手动创建名为\"checkpoint\"的文件夹" << endl;
			system("stty echo cooked");
			exit(0);
		}
		string gm4 = base.encode(encode());
		ofstream("checkpoint/" + name) << gm4 << std::endl;
		system(("echo \"" + name + "\" >> checkpoint/name.txt").c_str());
		system("sort -u -o checkpoint/name.txt checkpoint/name.txt");
		cout << "存档成功。" << endl;
	}
	inline bool readchpnp(string name){
		string gm3;
		ifstream in("checkpoint/" + name);
		if(!in.good()){
			cout << "文件名错误, 具体文件可以去checkpoint/name.txt中查询" << endl;
			return false;
		}
		in >> gm3;
		return decode(gm3);
	}
	inline bool readchp(string name){
		string gm4;
		ifstream("checkpoint/" + name) >> gm4;
		string ba, ba2;
		cout << "输入你的读取密码: ";
		cout.flush();
		getline(ba);
		cout << "确认你的读取密码: ";
		cout.flush();
		getline(ba2);
		if(ba != ba2){
			cout << "两次密码不一样" << endl;
			return false;
		}
		clear();
		base64 base(ba, false);
		return decode(base.decode(gm4));
	}
	inline void save(){
		print("1.无密码保存 2.带密码保存 3.退出");
		cout << endl;
		while(true){
			char type = getch();
			if(type == '3'){
				break;
			}
			if(type != '1' && type != '2'){
				continue;
			}
			clear();
			string name;
			while(true){
				cout << "保存文件名(只能有数字和大小写字母和下划线, 重复名称将覆盖。), 输入\"exit\"即可退出: ";
				cout.flush();
				getline(name, true);
				if(name == "exit"){
					return;
				}
				bool b = true;
				for(char i : name){
					if(!(isdigit(i) || islower(i) || isupper(i) || (i == '_'))){
						b = false;
						break;
					}
				}
				if(b){
					break;
				}
				cout << "名称错误" << endl;
				return;
			}
			if(type == '1'){
				savechpnp(name);
				break;
			}else if(type == '2'){
				savechp(name);
				break;
			}
		}
	}
	inline bool read(){
		clear();
		print("1.无密码读取 2.带密码读取 3.退出");
		cout << endl;
		while(true){
			char type = getch();
			if(type == '3'){
				return false;
			}
			if(type != '1' && type != '2'){
				continue;
			}
			clear();
			string name;
			while(true){
				cout << "加载文件(只能有数字和大小写字母和下划线。), 输入\"exit\"即可退出: ";
				cout.flush();
				getline(name, true);
				if(name == "exit"){
					return false;
				}
				bool b = true;
				for(char i : name){
					if(!(isdigit(i) || islower(i) || isupper(i) || (i == '_'))){
						b = false;
						break;
					}
				}
				if(b){
					break;
				}
				cout << "名称错误" << endl;
				return false;
			}
			if(type == '1'){
				return readchpnp(name);
				break;
			}else if(type == '2'){
				return readchp(name);
				break;
			}
		}
		return true;
	}
}
#endif
