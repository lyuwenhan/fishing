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
		print(sp_1);
		print(sp_2 + to_string(variate::data_saver.cnt) + sp_3 + to_string(variate::data_saver.money));
		print(sp_4);
		print(sp_5);
		print(sp_6);
		while(true){
			while(true){
				char c = getch();
				if(c == '1'){
					if(variate::data_saver.cnt < 100 && variate::data_saver.money < 1000){
						print(sp_7);
						sleept(1);
						break;
					}
					if(variate::data_saver.cnt < 100){
						print(sp_8);
						sleept(1);
						break;
					}
					if(variate::data_saver.money < 1000){
						print(sp_9);
						sleept(1);
						break;
					}

					variate::data_saver.cnt -= 100;
					variate::data_saver.money -= 1000;
					int ran = random(1, 100);
					if(ran <= 20){
						print(sp_10);
						print(sp_11);
						variate::fish_man = true;
					}else if(ran <= 40){
						print(sp_12);
						variate::big++;
					}else if(ran <= 41){
						print(sp_13);
						print(sp_14);
						variate::diamond++;
					}else{
						print(sp_15);
					}
					sleept(1);
					break;
				}else if(c == '2'){
					return;
				}
			}
			clear();
			cout << sp_1 << endl;
			cout << sp_2 << variate::data_saver.cnt << sp_3 << variate::data_saver.money << endl;
			cout << sp_4 << endl;
			cout << sp_5 << endl;
			cout << sp_6 << endl;
		}
	}
}
#endif
