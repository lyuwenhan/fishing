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
		if(variate::aqcnt > 30){
			variate::aqcnt = 30;
		}
		clear();
		#ifdef EN
		print("1. Upgrade Hook Speed, 2. Upgrade Fishing Profit, 3. Hook-off Probability, 4. Buy Cleaning Agent, 5. Upgrade Cleaning Agent, 6. Upgrade Aquarium Capacity, 7. Buy Oven, 8. Return.");
		print("Hook Speed: ");
		#else
		print("1.升级上钩速度, 2.升级钓鱼收益, 3.脱钩概率, 4.购买清洁剂, 5.升级清洁剂, 6.升级水族馆容量, 7.购买烤箱, 8.返回。");
		print("上钩速度: ");
		#endif
		if(variate::level == variate::max_level){
			#ifdef EN
			print("    Max Level Reached");
			#else
			print("    等级已满");
			#endif
		}else{
			#ifdef EN
			print("    Current Avg Time: " + to_string((variate::mintime[variate::level] + variate::maxtime[variate::level]) >> 1) + (((variate::mintime[variate::level] + variate::maxtime[variate::level]) & 1) ? ".5" : "") + ", After Upgrade: " + to_string((variate::mintime[variate::level + 1] + variate::maxtime[variate::level + 1]) >> 1) + (((variate::mintime[variate::level + 1] + variate::maxtime[variate::level + 1]) & 1) ? ".5" : ""));
			print("    Cost: $" + to_string(variate::cost[variate::level + 1]) + ", Current Gold: $" + to_string(variate::money));
			#else
			print("    当前平均时间: " + to_string((variate::mintime[variate::level] + variate::maxtime[variate::level]) >> 1) + (((variate::mintime[variate::level] + variate::maxtime[variate::level]) & 1) ? ".5" : "") + ", 升级后平均时间: " + to_string((variate::mintime[variate::level + 1] + variate::maxtime[variate::level + 1]) >> 1) + (((variate::mintime[variate::level + 1] + variate::maxtime[variate::level + 1]) & 1) ? ".5" : ""));
			print("    升级花费: $" + to_string(variate::cost[variate::level + 1]) + ", 当前金币数量: $" + to_string(variate::money));
			#endif
		}
		#ifdef EN
		print("Fishing Profit: ");
		#else
		print("钓鱼收益: ");
		#endif
		if(variate::get_level == variate::max_level2){
			#ifdef EN
			print("    Max Level Reached");
			#else
			print("    等级已满");
			#endif
		}else{
			#ifdef EN
			print("    Current Avg Profit: " + to_string((variate::minget[variate::get_level] + variate::maxget[variate::get_level]) >> 1) + (((variate::minget[variate::get_level] + variate::maxget[variate::get_level]) & 1) ? ".5" : "") + ", After Upgrade: " + to_string((variate::minget[variate::get_level + 1] + variate::maxget[variate::get_level + 1]) >> 1) + (((variate::minget[variate::get_level + 1] + variate::maxget[variate::get_level + 1]) & 1) ? ".5" : ""));
			print("    Cost: $" + to_string(variate::cost2[variate::get_level + 1]) + ", Current Gold: $" + to_string(variate::money));
			#else
			print("    当前平均收益: " + to_string((variate::minget[variate::get_level] + variate::maxget[variate::get_level]) >> 1) + (((variate::minget[variate::get_level] + variate::maxget[variate::get_level]) & 1) ? ".5" : "") + ", 升级后平均收益: " + to_string((variate::minget[variate::get_level + 1] + variate::maxget[variate::get_level + 1]) >> 1) + (((variate::minget[variate::get_level + 1] + variate::maxget[variate::get_level + 1]) & 1) ? ".5" : ""));
			print("    升级花费: $" + to_string(variate::cost2[variate::get_level + 1]) + ", 当前金币数量: $" + to_string(variate::money));
			#endif
		}
		#ifdef EN
		print("Hook-off Probability: ");
		#else
		print("脱钩概率: ");
		#endif
		if(variate::slip == 0){
			#ifdef EN
			print("    Max Level Reached");
			#else
			print("    等级已满");
			#endif
		}else{
			if(variate::slip > 10){
				variate::slip /= 10;
				variate::slip *= 10;
				#ifdef EN
				print("    Current: " + to_string(variate::slip) + "%, After Upgrade: " + to_string(variate::slip - 10) + "%");
				print("    Cost: $100, Current Gold: $" + to_string(variate::money));
				#else
				print("    当前脱钩概率: " + to_string(variate::slip) + "%, 升级后脱钩概率: " + to_string(variate::slip - 10) + "%");
				print("    升级花费: $100, 当前金币数量: $" + to_string(variate::money));
				#endif
			}else if(variate::slip > 5){
				variate::slip = 10;
				#ifdef EN
				print("    Current: 10%, After Upgrade: 5%");
				print("    Cost: $100, Current Gold: $" + to_string(variate::money));
				#else
				print("    当前脱钩概率: 10%, 升级后脱钩概率: 5%");
				print("    升级花费: $100, 当前金币数量: $" + to_string(variate::money));
				#endif
			}else if(variate::slip > 1){
				#ifdef EN
				print("    Current: " + to_string(variate::slip) + "%, After Upgrade: " + to_string(variate::slip - 1) + "%");
				print("    Cost: $100, Current Gold: $" + to_string(variate::money));
				#else
				print("    当前脱钩概率: " + to_string(variate::slip) + "%, 升级后脱钩概率: " + to_string(variate::slip - 1) + "%");
				print("    升级花费: $100, 当前金币数量: $" + to_string(variate::money));
				#endif
			}else{
				#ifdef EN
				print("    Current: 1%, After Upgrade: 0%");
				print("    Cost: $500, Current Gold: $" + to_string(variate::money));
				#else
				print("    当前脱钩概率: 1%, 升级后脱钩概率: 0%");
				print("    升级花费: $500, 当前金币数量: $" + to_string(variate::money));
				#endif
			}
		}
		print(fi_clji);
		#ifdef EN
		print("    Current Quantity: " + to_string(variate::cleaning_ball));
		print("    Cost: $10, Current Gold: $" + to_string(variate::money));
		print("Cleaning Efficiency: ");
		#else
		print("    当前清洁剂个数: " + to_string(variate::cleaning_ball));
		print("    购买花费: $10, 当前金币数量: $" + to_string(variate::money));
		print("清洁效率: ");
		#endif
		if(variate::cleaning_sub >= 10){
			#ifdef EN
			print("    Max Level Reached");
			#else
			print("    等级已满");
			#endif
		}else{
			#ifdef EN
			print("    Current: Reduce " + to_string(variate::cleaning_sub) + " levels per use, After Upgrade: Reduce " + to_string(variate::cleaning_sub + 1) + " levels per use");
			print("    Cost: $30, Current Gold: $" + to_string(variate::money));
			#else
			print("    当前清洁效率: 一次降低" + to_string(variate::cleaning_sub) + "级, 升级后清洁效率: 一次降低" + to_string(variate::cleaning_sub + 1) + "级");
			print("    购买花费: $30, 当前金币数量: $" + to_string(variate::money));
			#endif
		}
		#ifdef EN
		print("Aquarium Capacity: ");
		#else
		print("水族馆容量: ");
		#endif
		if(variate::aqcnt >= 30){
			#ifdef EN
			print("    Max Level Reached");
			#else
			print("    等级已满");
			#endif
		}else{
			#ifdef EN
			print("    Current Capacity: " + to_string(variate::aqcnt) + ", After Upgrade: " + to_string(variate::aqcnt + 2));
			print("    Cost: $" + to_string((variate::aqcnt + 2) * 100) + ", Current Gold: $" + to_string(variate::money));
			#else
			print("    当前水族馆容量: " + to_string(variate::aqcnt) + "只, 升级后水族馆容量: " + to_string(variate::aqcnt + 2) + "只");
			print("    购买花费: $" + to_string((variate::aqcnt + 2) * 100) + ", 当前金币数量: $" + to_string(variate::money));
			#endif
		}
		#ifdef EN
		print("Oven Count: ");
		#else
		print("烤箱数量: ");
		#endif
		if(variate::roast >= 3){
			#ifdef EN
			print("    Max Number Reached");
			#else
			print("    数量已满");
			#endif
		}else{
			#ifdef EN
			print("    Current: " + to_string(variate::roast));
			#else
			print("    当前烤箱数量: " + to_string(variate::roast));
			#endif
			if(variate::roast < 1){
				#ifdef EN
				print("    Cost: $50, Current Gold: $" + to_string(variate::money));
				#else
				print("    购买花费: $50, 当前金币数量: $" + to_string(variate::money));
				#endif
			}else if(variate::roast == 1){
				#ifdef EN
				print("    Cost: $1000, Current Gold: $" + to_string(variate::money));
				#else
				print("    购买花费: $1000, 当前金币数量: $" + to_string(variate::money));
				#endif
			}else{
				#ifdef EN
				print("    Cost: $2000, Current Gold: $" + to_string(variate::money));
				#else
				print("    购买花费: $2000, 当前金币数量: $" + to_string(variate::money));
				#endif
			}
		}
		while(true){
			while(true){
				char type = getch();
				if(type == '1'){
					if(variate::level == variate::max_level){
						#ifdef EN
						print("Max Level Reached");
						#else
						print("等级已满");
						#endif
						sleept(0.5);
						break;
					}else if(variate::money < variate::cost[variate::level + 1]){
						print(fi_mnng);
						sleept(0.5);
						break;
					}else{
						variate::money -= variate::cost[++variate::level];
						#ifdef EN
						print("Purchase Successful");
						#else
						print("购买成功");
						#endif
						sleept(0.5);
						break;
					}
				}else if(type == '2'){
					if(variate::get_level == variate::max_level2){
						#ifdef EN
						print("Max Level Reached");
						#else
						print("等级已满");
						#endif
						sleept(0.5);
						break;
					}else if(variate::money < variate::cost2[variate::get_level + 1]){
						print(fi_mnng);
						sleept(0.5);
						break;
					}else{
						variate::money -= variate::cost2[++variate::get_level];
						#ifdef EN
						print("Purchase Successful");
						#else
						print("购买成功");
						#endif
						sleept(0.5);
						break;
					}
				}else if(type == '3'){
					if(variate::slip == 0){
						#ifdef EN
						print("Max Level Reached");
						#else
						print("等级已满");
						#endif
						sleept(0.5);
						break;
					}else if(variate::slip == 1){
						if(variate::money < 500){
							print(fi_mnng);
							sleept(0.5);
							break;
						}else{
							variate::money -= 500;
							variate::slip = 0;
							#ifdef EN
							print("Purchase Successful");
							#else
							print("购买成功");
							#endif
							sleept(0.5);
							break;
						}
					}else{
						if(variate::money < 100){
							print(fi_mnng);
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
							#ifdef EN
							print("Purchase Successful");
							#else
							print("购买成功");
							#endif
							sleept(0.5);
							break;
						}
					}
				}else if(type == '4'){
					if(variate::money < 10){
						print(fi_mnng);
						sleept(0.5);
						break;
					}else{
						variate::cleaning_ball++;
						#ifdef EN
						print("Purchase Successful");
						#else
						print("购买成功");
						#endif
						variate::money -= 10;
						break;
					}
				}else if(type == '5'){
					if(variate::cleaning_sub == 10){
						#ifdef EN
						print("Max Level Reached");
						#else
						print("等级已满");
						#endif
						sleept(0.5);
						break;
					}else if(variate::money < 30){
						print(fi_mnng);
						sleept(0.5);
						break;
					}else{
						variate::money -= 30;
						variate::cleaning_sub++;
						#ifdef EN
						print("Purchase Successful");
						#else
						print("购买成功");
						#endif
						sleept(0.5);
						break;
					}
				}else if(type == '6'){
					if(variate::aqcnt == 30){
						#ifdef EN
						print("Max Level Reached");
						#else
						print("等级已满");
						#endif
						sleept(0.5);
						break;
					}else if(variate::money < (variate::aqcnt + 2) * 100){
						print(fi_mnng);
						sleept(0.5);
						break;
					}else{
						variate::money -= (variate::aqcnt + 2) * 100;
						variate::aqcnt += 2;
						#ifdef EN
						print("Purchase Successful");
						#else
						print("购买成功");
						#endif
						sleept(0.5);
						break;
					}
				}else if(type == '7'){
					if(variate::roast >= 3){
						#ifdef EN
						print("    Max Number Reached");
						#else
						print("    数量已满");
						#endif
						sleept(0.5);
						break;
					}else{
						if(variate::roast < 1){
							if(variate::money < 50){
								print(fi_mnng);
								sleept(0.5);
								break;
							}else{
								variate::money -= 50;
								variate::roast = 1;
								#ifdef EN
								print("Purchase Successful");
								#else
								print("购买成功");
								#endif
								sleept(0.5);
								break;
							}
						}else if(variate::roast == 1){
							if(variate::money < 1000){
								print(fi_mnng);
								sleept(0.5);
								break;
							}else{
								variate::money -= 1000;
								variate::roast = 2;
								#ifdef EN
								print("Purchase Successful");
								#else
								print("购买成功");
								#endif
								sleept(0.5);
								break;
							}
						}else{
							if(variate::money < 2000){
								print(fi_mnng);
								sleept(0.5);
								break;
							}else{
								variate::money -= 2000;
								variate::roast = 3;
								#ifdef EN
								print("Purchase Successful");
								#else
								print("购买成功");
								#endif
								sleept(0.5);
								break;
							}
						}
					}
				}else if(type == '8'){
					return;
				}
			}
			clear();
			#ifdef EN
			cout << "1. Upgrade Hook Speed, 2. Upgrade Fishing Profit, 3. Hook-off Probability, 4. Buy Cleaning Agent, 5. Upgrade Cleaning Agent, 6. Upgrade Aquarium Capacity, 7. Buy Oven, 8. Return." << endl;
			cout << "Hook Speed: " << endl;
			#else
			cout << "1.升级上钩速度, 2.升级钓鱼收益, 3.脱钩概率, 4.购买清洁剂, 5.升级清洁剂, 6.升级水族馆容量, 7.购买烤箱, 8.返回。" << endl;
			cout << "上钩速度: " << endl;
			#endif
			if(variate::level == variate::max_level){
				#ifdef EN
				cout << "    Max Level Reached" << endl;
				#else
				cout << "    等级已满" << endl;
				#endif
			}else{
				#ifdef EN
				cout << "    Current Avg Time: " << to_string((variate::mintime[variate::level] + variate::maxtime[variate::level]) >> 1) << (((variate::mintime[variate::level] + variate::maxtime[variate::level]) & 1) ? ".5" : "") << ", After Upgrade: " << to_string((variate::mintime[variate::level + 1] + variate::maxtime[variate::level + 1]) >> 1) << (((variate::mintime[variate::level + 1] + variate::maxtime[variate::level + 1]) & 1) ? ".5" : "") << endl;
				cout << "    Cost: $" << to_string(variate::cost[variate::level + 1]) << ", Current Gold: $" << to_string(variate::money) << endl;
				#else
				cout << "    当前平均时间: " << to_string((variate::mintime[variate::level] + variate::maxtime[variate::level]) >> 1) << (((variate::mintime[variate::level] + variate::maxtime[variate::level]) & 1) ? ".5" : "") << ", 升级后平均时间: " << to_string((variate::mintime[variate::level + 1] + variate::maxtime[variate::level + 1]) >> 1) << (((variate::mintime[variate::level + 1] + variate::maxtime[variate::level + 1]) & 1) ? ".5" : "") << endl;
				cout << "    升级花费: $" << to_string(variate::cost[variate::level + 1]) << ", 当前金币数量: $" << to_string(variate::money) << endl;
				#endif
			}
			#ifdef EN
			cout << "Fishing Profit: " << endl;
			#else
			cout << "钓鱼收益: " << endl;
			#endif
			if(variate::get_level == variate::max_level2){
				#ifdef EN
				cout << "    Max Level Reached" << endl;
				#else
				cout << "    等级已满" << endl;
				#endif
			}else{
				#ifdef EN
				cout << "    Current Avg Profit: " << to_string((variate::minget[variate::get_level] + variate::maxget[variate::get_level]) >> 1) << (((variate::minget[variate::get_level] + variate::maxget[variate::get_level]) & 1) ? ".5" : "") << ", After Upgrade: " << to_string((variate::minget[variate::get_level + 1] + variate::maxget[variate::get_level + 1]) >> 1) << (((variate::minget[variate::get_level + 1] + variate::maxget[variate::get_level + 1]) & 1) ? ".5" : "") << endl;
				cout << "    Cost: $" << to_string(variate::cost2[variate::get_level + 1]) << ", Current Gold: $" << to_string(variate::money) << endl;
				#else
				cout << "    当前平均收益: " << to_string((variate::minget[variate::get_level] + variate::maxget[variate::get_level]) >> 1) << (((variate::minget[variate::get_level] + variate::maxget[variate::get_level]) & 1) ? ".5" : "") << ", 升级后平均收益: " << to_string((variate::minget[variate::get_level + 1] + variate::maxget[variate::get_level + 1]) >> 1) << (((variate::minget[variate::get_level + 1] + variate::maxget[variate::get_level + 1]) & 1) ? ".5" : "") << endl;
				cout << "    升级花费: $" << to_string(variate::cost2[variate::get_level + 1]) << ", 当前金币数量: $" << to_string(variate::money) << endl;
				#endif
			}
			#ifdef EN
			cout << "Hook-off Probability: " << endl;
			#else
			cout << "脱钩概率: " << endl;
			#endif
			if(variate::slip == 0){
				#ifdef EN
				cout << "    Max Level Reached" << endl;
				#else
				cout << "    等级已满" << endl;
				#endif
			}else{
				if(variate::slip > 10){
					variate::slip /= 10;
					variate::slip *= 10;
					#ifdef EN
					cout << "    Current: " << to_string(variate::slip) << "%, After Upgrade: " << to_string(variate::slip - 10) << "%" << endl;
					cout << "    Cost: $100, Current Gold: $" << to_string(variate::money) << endl;
					#else
					cout << "    当前脱钩概率: " << to_string(variate::slip) << "%, 升级后脱钩概率: " << to_string(variate::slip - 10) << "%" << endl;
					cout << "    升级花费: $100, 当前金币数量: $" << to_string(variate::money) << endl;
					#endif
				}else if(variate::slip > 5){
					variate::slip = 10;
					#ifdef EN
					cout << "    Current: 10%, After Upgrade: 5%" << endl;
					cout << "    Cost: $100, Current Gold: $" << to_string(variate::money) << endl;
					#else
					cout << "    当前脱钩概率: 10%, 升级后脱钩概率: 5%" << endl;
					cout << "    升级花费: $100, 当前金币数量: $" << to_string(variate::money) << endl;
					#endif
				}else if(variate::slip > 1){
					#ifdef EN
					cout << "    Current: " << to_string(variate::slip) << "%, After Upgrade: " << to_string(variate::slip - 1) << "%" << endl;
					cout << "    Cost: $100, Current Gold: $" << to_string(variate::money) << endl;
					#else
					cout << "    当前脱钩概率: " << to_string(variate::slip) << "%, 升级后脱钩概率: " << to_string(variate::slip - 1) << "%" << endl;
					cout << "    升级花费: $100, 当前金币数量: $" << to_string(variate::money) << endl;
					#endif
				}else{
					#ifdef EN
					cout << "    Current: 1%, After Upgrade: 0%" << endl;
					cout << "    Cost: $500, Current Gold: $" << to_string(variate::money) << endl;
					#else
					cout << "    当前脱钩概率: 1%, 升级后脱钩概率: 0%" << endl;
					cout << "    升级花费: $500, 当前金币数量: $" << to_string(variate::money) << endl;
					#endif
				}
			}
			cout << fi_clji << endl;
			#ifdef EN
			cout << "    Current Quantity: " << to_string(variate::cleaning_ball) << endl;
			cout << "    Cost: $10, Current Gold: $" << to_string(variate::money) << endl;
			cout << "Cleaning Efficiency: " << endl;
			#else
			cout << "    当前清洁剂个数: " << to_string(variate::cleaning_ball) << endl;
			cout << "    购买花费: $10, 当前金币数量: $" << to_string(variate::money) << endl;
			cout << "清洁效率: " << endl;
			#endif
			if(variate::cleaning_sub >= 10){
				#ifdef EN
				cout << "    Max Level Reached" << endl;
				#else
				cout << "    等级已满" << endl;
				#endif
			}else{
				#ifdef EN
				cout << "    Current: Reduce " << to_string(variate::cleaning_sub) << " levels per use, After Upgrade: Reduce " << to_string(variate::cleaning_sub + 1) << " levels per use" << endl;
				cout << "    Cost: $30, Current Gold: $" << to_string(variate::money) << endl;
				#else
				cout << "    当前清洁效率: 一次降低" << to_string(variate::cleaning_sub) << "级, 升级后清洁效率: 一次降低" << to_string(variate::cleaning_sub + 1) << "级" << endl;
				cout << "    购买花费: $30, 当前金币数量: $" << to_string(variate::money) << endl;
				#endif
			}
			#ifdef EN
			cout << "Aquarium Capacity: " << endl;
			#else
			cout << "水族馆容量: " << endl;
			#endif
			if(variate::aqcnt >= 30){
				#ifdef EN
				cout << "    Max Level Reached" << endl;
				#else
				cout << "    等级已满" << endl;
				#endif
			}else{
				#ifdef EN
				cout << "    Current Capacity: " << to_string(variate::aqcnt) << ", After Upgrade: " << to_string(variate::aqcnt + 2) << endl;
				cout << "    Cost: $" << to_string((variate::aqcnt + 2) * 100) << ", Current Gold: $" << to_string(variate::money) << endl;
				#else
				cout << "    当前水族馆容量: " << to_string(variate::aqcnt) << "只, 升级后水族馆容量: " << to_string(variate::aqcnt + 2) << "只" << endl;
				cout << "    购买花费: $" << to_string((variate::aqcnt + 2) * 100) << ", 当前金币数量: $" << to_string(variate::money) << endl;
				#endif
			}
			#ifdef EN
			cout << "Oven Count: " << endl;
			#else
			cout << "烤箱数量: " << endl;
			#endif
			if(variate::roast >= 3){
				#ifdef EN
				cout << "    Max Number Reached" << endl;
				#else
				cout << "    数量已满" << endl;
				#endif
			}else{
				#ifdef EN
				cout << "    Current: " << to_string(variate::roast) << endl;
				#else
				cout << "    当前烤箱数量: " << to_string(variate::roast) << endl;
				#endif
				if(variate::roast < 1){
					#ifdef EN
					cout << "    Cost: $50, Current Gold: $" << to_string(variate::money) << endl;
					#else
					cout << "    购买花费: $50, 当前金币数量: $" << to_string(variate::money) << endl;
					#endif
				}else if(variate::roast == 1){
					#ifdef EN
					cout << "    Cost: $1000, Current Gold: $" << to_string(variate::money) << endl;
					#else
					cout << "    购买花费: $1000, 当前金币数量: $" << to_string(variate::money) << endl;
					#endif
				}else{
					#ifdef EN
					cout << "    Cost: $2000, Current Gold: $" << to_string(variate::money) << endl;
					#else
					cout << "    购买花费: $2000, 当前金币数量: $" << to_string(variate::money) << endl;
					#endif
				}
			}
		}
	}
	inline void shop1(){
		clear();
		#ifdef EN
		printa("Welcome to the Super Shop. You can buy some special items here.");
		clear();
		print("1. Cast Speed Multiplier, 2. Upgrade Big Fish Chance, 3. Return.");
		print("Cast Speed Multiplier: ");
		#else
		clear();
		printa("这里是超级商店, 可以买一些特殊的商品。");
		clear();
		print("1.甩杆倍速, 2.升级大鱼概率, 3.返回。");
		print("甩杆倍速: ");
		#endif
		if(variate::stime >= 10){
			#ifdef EN
			print("    Max Level Reached");
			#else
			print("    等级已满");
			#endif
		}else{
			#ifdef EN
			print("    Current: " + to_string(variate::stime) + "x, After Upgrade: " + to_string(variate::stime + 1) + "x");
			print("    Cost: $1000, Current Gold: $" + to_string(variate::money));
			#else
			print("    当前倍速: " + to_string(variate::stime) + ", 升级后游戏倍速: " + to_string(variate::stime + 1));
			print("    升级花费: $1000, 当前金币数量: $" + to_string(variate::money));
			#endif
		}
		#ifdef EN
		print("Big Fish Chance: ");
		#else
		print("大鱼概率: ");
		#endif
		if(variate::bf >= 60){
			#ifdef EN
			print("    Max Level Reached");
			#else
			print("    等级已满");
			#endif
		}else{
			#ifdef EN
			print("    Current: " + to_string(variate::bf) + "%, After Upgrade: " + to_string(variate::bf + 5) + "%");
			print("    Cost: $1000, Current Gold: $" + to_string(variate::money));
			#else
			print("    当前大鱼概率: " + to_string(variate::bf) + ", 升级后大鱼概率" + to_string(variate::bf + 5) + "%");
			print("    升级花费: $1000, 当前金币数量: $" + to_string(variate::money));
			#endif
		}
		while(true){
			while(true){
				char type = getch();
				if(type == '1'){
					if(variate::stime >= 10){
						#ifdef EN
						print("Max Level Reached");
						#else
						print("等级已满");
						#endif
						sleept(0.5);
						break;
					}else if(variate::money < 1000){
						print(fi_mnng);
						sleept(0.5);
						break;
					}else{
						variate::money -= 1000;
						variate::stime++;
						#ifdef EN
						print("Purchase Successful");
						#else
						print("购买成功");
						#endif
						sleept(0.5);
						break;
					}
				}else if(type == '2'){
					if(variate::bf >= 60){
						#ifdef EN
						print("Max Level Reached");
						#else
						print("等级已满");
						#endif
						sleept(0.5);
						break;
					}else if(variate::money < 1000){
						print(fi_mnng);
						sleept(0.5);
						break;
					}else{
						variate::money -= 1000;
						variate::bf += 5;
						#ifdef EN
						print("Purchase Successful");
						#else
						print("购买成功");
						#endif
						sleept(0.5);
						break;
					}
				}else if(type == '3'){
					sleept(0.5);
					return;
				}
			}
			#ifdef EN
			clear();
			cout << "1. Cast Speed Multiplier, 2. Upgrade Big Fish Chance, 3. Return." << endl;
			cout << "Cast Speed Multiplier: " << endl;
			#else
			clear();
			cout << "1.甩杆倍速, 2.升级大鱼概率, 3.返回。" << endl;
			cout << "甩杆倍速: " << endl;
			#endif
			if(variate::stime >= 10){
				#ifdef EN
				cout << "    Max Level Reached" << endl;
				#else
				cout << "    等级已满" << endl;
				#endif
			}else{
				#ifdef EN
				cout << "    Current: " + to_string(variate::stime) + "x, After Upgrade: " + to_string(variate::stime + 1) + "x" << endl;
				cout << "    Cost: $1000, Current Gold: $" + to_string(variate::money) << endl;
				#else
				cout << "    当前倍速: " + to_string(variate::stime) + ", 升级后游戏倍速: " + to_string(variate::stime + 1) << endl;
				cout << "    升级花费: $1000, 当前金币数量: $" + to_string(variate::money) << endl;
				#endif
			}
			#ifdef EN
			cout << "Big Fish Chance: " << endl;
			#else
			cout << "大鱼概率: " << endl;
			#endif
			if(variate::bf >= 60){
				#ifdef EN
				cout << "    Max Level Reached" << endl;
				#else
				cout << "    等级已满" << endl;
				#endif
			}else{
				#ifdef EN
				cout << "    Current: " + to_string(variate::bf) + "%, After Upgrade: " + to_string(variate::bf + 5) + "%" << endl;
				cout << "    Cost: $1000, Current Gold: $" + to_string(variate::money) << endl;
				#else
				cout << "    当前大鱼概率: " + to_string(variate::bf) + ", 升级后大鱼概率" + to_string(variate::bf + 5) << endl;
				cout << "    升级花费: $1000, 当前金币数量: $" + to_string(variate::money) << endl;
				#endif
			}
		}
	}
	inline void shop(){
		while(true){
			clear();
			#ifdef EN
			print("1. Normal Shop, 2. Super Shop, 3. Exit.");
			#else
			print("1.普通商店, 2.超级商店, 3.退出。");
			#endif
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
