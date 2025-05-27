#ifndef setting_defined
#define setting_defined
#include<iostream>
#include<string>
using std::cout;
using std::ostream;
using std::to_string;
#include"variate.h"
#include"function.h"
const string st_output_speed[4] = st_speed;
namespace setting{
	void setting(){
		clear();
		print(st_m);
		print(st_m2 + st_output_speed[(variate::speed < 1 ? 1 : (variate::speed > 3 ? 3 : variate::speed))]);
		while(true){
			char c = getch();
			if(c == '1'){
				clear();
				print(st_speeds);
				char c = getch();
				while(c < '1' || c > '3'){
					c = getch();
				}
				variate::speed = c - '0';
				break;
			}else if(c == '2'){
				break;
			}
		}
	}
}
#endif