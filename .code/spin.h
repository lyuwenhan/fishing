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
		#ifdef EN
		print("1. Spin, 2. Exit");
		print("Spin cost: 100 total fish count + 1000 coins. Current fish count: " + to_string(variate::cnt) + " Current coins: " + to_string(variate::money));
		print("Big Fish Bait: 20%");
		print("Diamond Fish: 1%");
		#else
		print("1.转盘, 2.退出");
		print("转盘消耗: 100累积钓鱼数量+1000金币 当前钓鱼数量: " + to_string(variate::cnt) + " 当前金币数量: " + to_string(variate::money));
		print("愚人节彩蛋: 20%");
		print("大鱼诱饵: 20%");
		print("钻石鱼: 1%");
		#endif
		while(true){
			while(true){
				char c = getch();
				if(c == '1'){
					if(variate::cnt < 100 && variate::money < 1000){
						#ifdef EN
						print("Achievement Unlocked: Swindler");
						#else
						print("获得成就: 江湖骗子");
						#endif
						break;
					}
					if(variate::cnt < 100){
						#ifdef EN
						print("Achievement Unlocked: Short Weight");
						#else
						print("获得成就: 缺斤少两");
						#endif
						break;
					}
					if(variate::money < 1000){
						#ifdef EN
						print("Achievement Unlocked: Deadbeat");
						#else
						print("获得成就: 老赖");
						#endif
						break;
					}
					variate::cnt -= 100;
					variate::money -= 1000;
					int ran = random(1, 100);
					#ifndef EN
					if(ran <= 20){
						print("获得愚人节彩蛋*1");
						print("获得成就: 鱼人节快乐");
						variate::fish_man = true;
					}else
					#endif
					if(ran <= 40){
						#ifdef EN
						print("Big Fish Bait *1");
						#else
						print("大鱼诱饵*1");
						#endif
						variate::big++;
					}else if(ran <= 41){
						#ifdef EN
						print("Diamond Fish *1");
						print("Achievement Unlocked: Legendary Fish");
						#else
						print("钻石鱼*1");
						print("获得成就: 传说中的鱼");
						#endif
						variate::diamond++;
					}else{
						#ifdef EN
						print("Thank you for participating");
						#else
						print("谢谢惠顾");
						#endif
					}
					sleept(1);
					break;
				}else if(c == '2'){
					return;
				}
			}
			clear();
			#ifdef EN
			cout << "1. Spin, 2. Exit" << endl;
			cout << "Spin cost: 100 total fish count + 1000 coins. Current fish count: " + to_string(variate::cnt) + " Current coins: " + to_string(variate::money) << endl;
			cout << "Big Fish Bait: 20%" << endl;
			cout << "Diamond Fish: 1%" << endl;
			#else
			cout << "1.转盘, 2.退出" << endl;
			cout << "转盘消耗: 100累积钓鱼数量+1000金币 当前钓鱼数量: " + to_string(variate::cnt) + " 当前金币数量: " + to_string(variate::money) << endl;
			cout << "愚人节彩蛋: 20%" << endl;
			cout << "大鱼诱饵: 20%" << endl;
			cout << "钻石鱼: 1%" << endl;
			#endif
		}
	}
}
#endif
