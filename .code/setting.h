#ifndef setting_defined
#define setting_defined
#include<iostream>
#include<string>
using std::cout;
using std::ostream;
using std::to_string;
#include"variate.h"
#include"function.h"
namespace setting{
	void setting(){
		print("1.更改输出倍速, 2.退出");
		print("当前输出倍速: " + to_string(variate::speed) + "(最大1000)");
		while(true){
			char c = getch();
			if(c == '1'){
				int s = 0;
				while(true){
					char d = getch();
					if(isdigit(d)){
						s *= 10;
						s += d ^ '0';
						if(s > 1000){
							s = 1000;
						}
						cout << "\r          \r" << s << flush;
					}else if(d == 127){
						s /= 10;
						cout << "\r          \r" << s << flush;
					}else if(d == '\r'){
						break;
					}
				}
				variate::speed = s;
				return;
			}else if(c == '2'){
				return;
			}
		}
	}
}
#endif