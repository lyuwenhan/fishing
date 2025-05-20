#include<iostream>
#include<sys/stat.h>
#include"variate.h"
#include"color.h"
#include"base64.h"
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
int main(int argc, char* argv[]){
	srand(time(0));
	clear();
	system("mkdir -p checkpoint >/dev/null 2>&1");
	if(!directoryExists("checkpoint")){
		print("保存文件夹缺失, 请手动创建名为\"checkpoint\"的文件夹");
		system("stty echo cooked");
		exit(0);
	}
	bool readok = false;
	int nspeed = 0;
	for(int i = 1; i < argc; i++){
		if(i + 1 < argc && (string)argv[i] == "-chp" && checkpoint::check_name(argv[i + 1])){
			variate::name = argv[i + 1];
			string gm3;
			ifstream in((string)"checkpoint/" + argv[i + 1]);
			if(!in.good()){
				continue;
			}
			in >> gm3;
			readok = checkpoint::decode(gm3);
		}
		if(i + 1 < argc && (string)argv[i] == "-speed" && isnumbt(argv[i + 1], 1, 1000)){
			nspeed = tonum(argv[i + 1]);
		}
		if((string)argv[i] == "-tool"){
			variate::use_tool = true;
		}
	}
	if(nspeed){
		variate::speed = nspeed;
	}
	if(!readok){
		story();
		if(!variate::name.empty() || checkpoint::chp()){
			sleept(1);
			choose();
		}
		sleept(1);
		checkpoint::savechpnp(variate::name, false);
	}
	if(nspeed){
		variate::speed = nspeed;
	}
	while(true){
		clear();
		print("1.开始钓鱼, 2.进入商店, 3.存档, 4.读档, 5.设置自动保存, 6.设置, 7.抽奖, 8.退出, 9.挑战, 其他输入无效。");
		while(true){
			char type = getch();
			if(!islower(type) && !isupper(type) && !isdigit(type) && !issymbol(type) && type != '\r' && type != 127 && type != 27){
				continue;
			}
			if(type == '1'){
				fishing::fishing_setup();
				break;
			}else if(type == '2'){
				clear();
				shop::shop();
				break;
			}else if(type == '3'){
				clear();
				checkpoint::save();
				break;
			}else if(type == '4'){
				clear();
				checkpoint::read();
				break;
			}else if(type == '5'){
				clear();
				checkpoint::set_auto_save();
				break;
			}else if(type == '6'){
				clear();
				setting::setting();
				break;
			}else if(type == '7'){
				clear();
				spin::spin();
				break;
			}else if(type == '8'){
				clear();
				return 0;
			}else if(type == '9'){
				clear();
				if(variate::try_level == 0){
					parkour::main();
				}else if(variate::try_level == 1){
					beat::main();
				}else{
					printa("已完成挑战");
				}
				break;
			}else if(variate::use_tool && type == 127){
				tool::tool();
				break;
			}
		}
		checkpoint::auto_save();
		checkpoint::savechpnp(variate::name, false);
		sleept(0.5);
	}
}
