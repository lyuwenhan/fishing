#ifndef shop_defined
#define shop_defined
#include<iostream>
#include<string>
using std::string;
using std::to_string;
#include"variate.h"
#include"function.h"
#include"tool.h"
namespace shop{
	inline void shop0(){
		while(true){
			clear();
			if(variate::aqcnt > 30){
				variate::aqcnt = 30;
			}
			print("1.升级上钩速度, 2.升级钓鱼收益, 3.脱钩概率, 4.购买清洁剂, 5.升级清洁剂, 6.升级水族馆容量, 7.购买烤箱, 8.返回。");
			print("上钩速度: ");
			if(variate::level == variate::max_level){
				print("    等级已满");
			}else{
				print("    当前平均时间: " + to_string((variate::mintime[variate::level] + variate::maxtime[variate::level]) >> 1) + (((variate::mintime[variate::level] + variate::maxtime[variate::level]) & 1) ? ".5" : "") + ", 升级后平均时间: " + to_string((variate::mintime[variate::level + 1] + variate::maxtime[variate::level + 1]) >> 1) + (((variate::mintime[variate::level + 1] + variate::maxtime[variate::level + 1]) & 1) ? ".5" : ""));
				print("    升级花费: $" + to_string(variate::cost[variate::level + 1]) + ", 当前金币数量: $" + to_string(variate::money));
			}
			print("钓鱼收益: ");
			if(variate::get_level == variate::max_level2){
				print("    等级已满");
			}else{
				print("    当前平均收益: " + to_string((variate::minget[variate::get_level] + variate::maxget[variate::get_level]) >> 1) + (((variate::minget[variate::get_level] + variate::maxget[variate::get_level]) & 1) ? ".5" : "") + ", 升级后平均收益: " + to_string((variate::minget[variate::get_level + 1] + variate::maxget[variate::get_level + 1]) >> 1) + (((variate::minget[variate::get_level + 1] + variate::maxget[variate::get_level + 1]) & 1) ? ".5" : ""));
				print("    升级花费: $" + to_string(variate::cost2[variate::get_level + 1]) + ", 当前金币数量: $" + to_string(variate::money));
			}
			print("脱钩概率: ");
			if(variate::slip == 0){
				print("    等级已满");
			}else{
				if(variate::slip > 10){
					variate::slip /= 10;
					variate::slip *= 10;
					print("    当前脱钩概率: " + to_string(variate::slip) + "%, 升级后脱钩概率: " + to_string(variate::slip - 10) + "%");
					print("    升级花费: $100, 当前金币数量: $" + to_string(variate::money));
				}else if(variate::slip > 5){
					variate::slip = 10;
					print("    当前脱钩概率: 10%, 升级后脱钩概率: 5%");
					print("    升级花费: $100, 当前金币数量: $" + to_string(variate::money));
				}else if(variate::slip > 1){
					print("    当前脱钩概率: " + to_string(variate::slip) + "%, 升级后脱钩概率: " + to_string(variate::slip - 1) + "%");
					print("    升级花费: $100, 当前金币数量: $" + to_string(variate::money));
				}else{
					print("    当前脱钩概率: 1%, 升级后脱钩概率: 0%");
					print("    升级花费: $500, 当前金币数量: $" + to_string(variate::money));
				}
			}
			print("清洁剂: ");
			print("    当前清洁剂个数: " + to_string(variate::cleaning_ball));
			print("    购买花费: $10, 当前金币数量: $" + to_string(variate::money));
			print("清洁效率: ");
			if(variate::cleaning_sub >= 10){
				print("    等级已满");
			}else{
				print("    当前清洁效率: 一次降低" + to_string(variate::cleaning_sub) + "级, 升级后清洁效率: 一次降低" + to_string(variate::cleaning_sub + 1) + "级");
				print("    购买花费: $30, 当前金币数量: $" + to_string(variate::money));
			}
			print("水族馆容量: ");
			if(variate::aqcnt >= 30){
				print("    等级已满");
			}else{
				print("    当前水族馆容量: " + to_string(variate::aqcnt) + "只, 升级后水族馆容量: " + to_string(variate::aqcnt + 2) + "只");
				print("    购买花费: $" + to_string((variate::aqcnt + 2) * 100) + ", 当前金币数量: $" + to_string(variate::money));
			}
			print("烤箱数量: ");
			if(variate::roast >= 3){
				print("    数量已满");
			}else{
				print("    当前烤箱数量: " + to_string(variate::roast));
				if(variate::roast < 1){
					print("    购买花费: $50, 当前金币数量: $" + to_string(variate::money));
				}else if(variate::roast == 1){
					print("    购买花费: $1000, 当前金币数量: $" + to_string(variate::money));
				}else{
					print("    购买花费: $2000, 当前金币数量: $" + to_string(variate::money));
				}
			}
			char type = 0;
			while(true){
				type = getch();
				if(type == '1'){
					if(variate::level == variate::max_level){
						print("等级已满");
						sleept(0.5);
						break;
					}else if(variate::money < variate::cost[variate::level + 1]){
						print("金钱不够");
						sleept(0.5);
						break;
					}else{
						variate::money -= variate::cost[++variate::level];
						print("购买成功");
						sleept(0.5);
						break;
					}
				}else if(type == '2'){
					if(variate::get_level == variate::max_level2){
						print("等级已满");
						sleept(0.5);
						break;
					}else if(variate::money < variate::cost2[variate::get_level + 1]){
						print("金钱不够");
						sleept(0.5);
						break;
					}else{
						variate::money -= variate::cost2[++variate::get_level];
						print("购买成功");
						sleept(0.5);
						break;
					}
				}else if(type == '3'){
					if(variate::slip == 0){
						print("等级已满");
						sleept(0.5);
						break;
					}else if(variate::slip == 1){
						if(variate::money < 500){
							print("金钱不够");
							sleept(0.5);
							break;
						}else{
							variate::money -= 500;
							variate::slip = 0;
							print("购买成功");
							sleept(0.5);
							break;
						}
					}else{
						if(variate::money < 100){
							print("金钱不够");
							sleept(0.5);
							break;
						}else{
							variate::money -= 100;
							if(variate::slip > 10){
								variate::slip -= 10;
							}else if(variate::slip > 5){
								variate::slip = 5;
							}else if(variate::slip > 0){
								variate::slip -= 1;
							}
							print("购买成功");
							sleept(0.5);
							break;
						}
					}
				}else if(type == '4'){
					if(variate::money < 10){
						print("金钱不够");
						sleept(0.5);
						break;
					}else{
						variate::cleaning_ball++;
						print("购买成功");
						variate::money -= 10;
						break;
					}
				}else if(type == '5'){
					if(variate::cleaning_sub == 10){
						print("等级已满");
						sleept(0.5);
						break;
					}else if(variate::money < 30){
						print("金钱不够");
						sleept(0.5);
						break;
					}else{
						variate::money -= 30;
						variate::cleaning_sub++;
						print("购买成功");
						sleept(0.5);
						break;
					}
				}else if(type == '6'){
					if(variate::aqcnt == 30){
						print("等级已满");
						sleept(0.5);
						break;
					}else if(variate::money < (variate::aqcnt + 2) * 100){
						print("金钱不够");
						sleept(0.5);
						break;
					}else{
						variate::money -= (variate::aqcnt + 2) * 100;
						variate::aqcnt += 2;
						print("购买成功");
						sleept(0.5);
						break;
					}
				}else if(type == '7'){
					if(variate::roast >= 3){
						print("    数量已满");
						sleept(0.5);
						break;
					}else{
						if(variate::roast < 1){
							if(variate::money < 50){
								print("金钱不够");
								sleept(0.5);
								break;
							}else{
								variate::money -= 50;
								variate::roast = 1;
								print("购买成功");
								sleept(0.5);
								break;
							}
						}else if(variate::roast == 1){
							if(variate::money < 1000){
								print("金钱不够");
								sleept(0.5);
								break;
							}else{
								variate::money -= 1000;
								variate::roast = 2;
								print("购买成功");
								sleept(0.5);
								break;
							}
						}else{
							if(variate::money < 2000){
								print("金钱不够");
								sleept(0.5);
								break;
							}else{
								variate::money -= 2000;
								variate::roast = 3;
								print("购买成功");
								sleept(0.5);
								break;
							}
						}
					}
				}else if(type == '8'){
					return;
				}
			}
		}
	}
	inline void shop1(){
		clear();
		printa("这里是超级商店, 可以买一些特殊的商品。");
		while (true){
			clear();
			print("1.甩杆倍速, 2.升级大鱼概率, 3.返回。");
			print("甩杆倍速: ");
			if(variate::stime >= 10){
				print("    等级已满");
			}else{
				print("    当前倍速: " + to_string(variate::stime) + ", 升级后游戏倍速: " + to_string(variate::stime + 1));
				print("    升级花费: $1000, 当前金币数量: $" + to_string(variate::money));
			}
			print("大鱼概率: ");
			if(variate::bf >= 60){
				print("    等级已满");
			}else{
				print("    当前大鱼概率: " + to_string(variate::bf) + ", 升级后大鱼概率" + to_string(variate::bf + 5));
				print("    升级花费: $1000, 当前金币数量: $" + to_string(variate::money));
			}
			char type;
			while(true){
				type = getch();
				if(type == '1'){
					if(variate::stime >= 10){
						print("等级已满");
						sleept(0.5);
						break;
					}else if(variate::money < 1000){
						print("金钱不够");
						sleept(0.5);
						break;
					}else{
						variate::money -= 1000;
						variate::stime++;
						print("购买成功");
						sleept(0.5);
						break;
					}
				}else if(type == '2'){
					if(variate::bf >= 60){
						print("等级已满");
						sleept(0.5);
						break;
					}else if(variate::money < 1000){
						print("金钱不够");
						sleept(0.5);
						break;
					}else{
						variate::money -= 1000;
						variate::bf += 5;
						print("购买成功");
						sleept(0.5);
						break;
					}
				}else if(type == '3'){
					sleept(0.5);
					return;
				}
			}
		}
	}
	inline void shop(){
		while (true){
			clear();
			print("1.普通商店, 2.超级商店, 3.退出。");
			char type;
			while(true){
				type = getch();
				if(type == '1'){
					shop0();
					break;
				}else if(type == '2'){
					shop1();
					break;
				}else if(type == '3'){
					return;
				}
			}
		}
	}
}
#endif
