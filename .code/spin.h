#ifndef spin_defined
#define spin_defined
#include<iostream>
#include<string>
using std::string;
using std::to_string;
#include"variate.h"
#include"function.h"
namespace spin{
	void spin(){
		clear();
		print("1.转盘, 2.退出");
		print("转盘消耗: 100累积钓鱼数量+1000金币 当前钓鱼数量: " + to_string(variate::cnt) + " 当前金币数量: " + to_string(variate::money));
		print("愚人节彩蛋: 20%");
		print("大鱼诱饵: 20%");
		print("钻石鱼: 1%");
		while(true){
			while(true){
				char c = getch();
				if(c == '1'){
					if(variate::cnt < 100 && variate::money < 1000){
						print("获得成就: 江湖骗子");
						break;
					}
					if(variate::cnt < 100){
						print("获得成就: 缺斤少两");
						break;
					}
					if(variate::money < 1000){
						print("获得成就: 老赖");
						break;
					}
					variate::cnt -= 100;
					variate::money -= 1000;
					int ran = random(1, 100);
					if(ran <= 20){
						print("获得愚人节彩蛋*1");
						print("获得成就: 鱼人节快乐");
						variate::fish_man = true;
					}else if(ran <= 40){
						print("大鱼诱饵*1");
						variate::big++;
					}else if(ran <= 41){
						print("钻石鱼*1");
						print("获得成就: 传说中的鱼");
						variate::diamond++;
					}else{
						print("谢谢惠顾");
					}
					sleept(1);
					break;
				}else if(c == '2'){
					return;
				}
			}
			clear();
			cout << "1.转盘, 2.退出" << endl;
			cout << "转盘消耗: 100累积钓鱼数量+1000金币 当前钓鱼数量: " + to_string(variate::cnt) + " 当前金币数量: " + to_string(variate::money) << endl;
			cout << "愚人节彩蛋: 20%" << endl;
			cout << "大鱼诱饵: 20%" << endl;
			cout << "钻石鱼: 1%" << endl;
		}
	}
}
#endif
