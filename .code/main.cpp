#include<iostream>
#include<sys/stat.h>
#include"saving.h"
#include"variate.h"
#include"color.h"
#include"fishing.h"
#include"shop.h"
#include"checkpoint.h"
#include"setting.h"
#include"function.h"
#include"story.h"
#include"error.h"
#include"spin.h"
#include"parkour.h"
#include"beat.h"
#include"tool.h"
int main(){
	srand(time(0));
	clear();
	system("mkdir -p checkpoint >/dev/null 2>&1");
	if(!directoryExists("checkpoint")){
		print("保存文件夹缺失, 请手动创建名为\"checkpoint\"的文件夹");
		exit(0);
	}
	bool readok = false;
	if(!readok){
		story();
		if(!checkpoint::chp()){
			sleept(1);
			choose();
		}
		checkpoint::savechpnp(variate::name);
		sleept(1);
	}
	while(true){
		clear();
		print("1.开始钓鱼, 2.进入商店, 3.设置, 4.抽奖, 5.挑战, 6.退出, 其他输入无效。");
		while(true){
			char type = getch();
			if(type == '1'){
				fishing::fishing_setup();
				break;
			}else if(type == '2'){
				clear();
				shop::shop();
				break;
			}else if(type == '3'){
				clear();
				setting::setting();
				break;
			}else if(type == '4'){
				clear();
				spin::spin();
				break;
			}else if(type == '5'){
				clear();
				if(variate::try_level == 0){
					parkour::main();
				}else if(variate::try_level == 1){
					beat::main();
				}else{
					printa("已完成挑战");
				}
				break;
			}else if(type == '6'){
				clear();
				return 0;
			}else if(type == 127){
				tool::tool();
				break;
			}
		}
		checkpoint::savechpnp(variate::name);
		sleept(0.5);
	}
}
