#include<hashtable.h>
#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::hash;
using std::string;
using std::ostream;
using std::ifstream;
using std::to_string;
#include"variate.h"
#include"checkpoint.h"
int main(){
	clear();
	if(checkpoint::read()){
		clear();
		checkpoint::save();
		sleep(1);
	}else{
		cout << "读取失败" << endl;
		sleep(1);
	}
}