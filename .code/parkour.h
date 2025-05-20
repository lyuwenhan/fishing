#ifndef parkour_defined
#define parkour_defined
#include<iostream>
#include<iomanip>
#include<vector>
using std::string;
using std::vector;
using std::pair;
using std::cout;
using std::max;
#include"variate.h"
#include"function.h"
namespace parkour{
	const int born1[100][2] = {{1, 30}, {33, 30}, {66, 30}, {98, 11}, {42, 14}};
	int level1 = 0;
	int x;
	int y;
	int sx = 1;
	int sy = 0;
	const int End = 100;
	const string map1[42] = {
"|     | |                                                                                           |",
"|---+ |>|  >   >   >   >   >   >   >   >   >   >   >   >   >   >   >   >   >   >   >   >   >   >  | |",
"|   | | |                                                            |  |                         | |",
"|   | | |                                                       |  | | -   <   <   <   <   <   <   <|",
"|   | | |                  +--------------------+          |  | | -   <                             |",
"|^^^| |^|                  |  finish            |     |  | | -   <                                  |",
"|   | | |                  |                    |   | | -   <                                       |",
"|   | | |                  |                    | +-   <                                            |",
"|   |   |                  |                    |<|                                                 |",
"+^^^+--^-+----+------------+--------------------+-+-------------------------------------------------+",
"|   |    |    |                                                                                 |...|",
"|   |    |    |                                                                                 | |.|",
"|   |    |    |                                                      |                          | |.|",
"|^^^| |--| |--| +-----     ------             |                   +--+      ---                 | |.|",
"|   | |  | |  | |                \\        +---+                   |        |***\\                | |.|",
"|   | |  | |  | |                 \\       |             ZZ        |        |****+--   -------     |.|",
"|     |    |    |                  \\      |                       |        |*****************\\    |.|",
"|^^^---^^-- ^^--|^^^^^----          \\     |******ZZ***********Z***|*****ZZ*|******************\\   |.|",
"+---------------+----------------+---+----+-----------------------+--------+-------------------+--+.|",
"|                                |                          |     |                               |.|",
"|                                |              ---+--+---- |     |                    +---       |.|",
"|                                |                 |  |           |                   /           |.|",
"|                                |       -------   |  |           |                  /            |.|",
"|                         +----+ |                 |           /| |            -----+     |.......|.|",
"|                    -----+    | |                 |  +-------+ | |                       |.......|.|",
"|                              | +--------                      | |      +----+           |.......|.|",
"|             |                | |                              | |     /      \\          |.......|.|",
"|        -----++-----          | |                              | |    /        \\         |.......|.|",
"|              |               | |        -----+                | |   /          \\        |.......|.|",
"|              |               |               |                |    /            \\       |.........|",
"+--------------+---------------+---------------+----------------+---+--------------+------+---------|"
};
	inline bool ty(){//check air
		return map1[y - 1][x] == ' ';
	}
	inline bool die(){//check lava
		return map1[y][x] == '*';
	}
	inline bool fin(int x2, int y2){//finish
		return map1[y2 - 1][x2] == 'f' || map1[y2 - 1][x2] == 'i' || map1[y2 - 1][x2] == 'n' || map1[y2 - 1][x2] == 's' || map1[y2 - 1][x2] == 'h';
	}
	inline bool ok(int x2, int y2){//check air/water
		return map1[y2 - 1][x2] == ' ' || map1[y2 - 1][x2] == '.';
	}
	inline int slide(int x2, int y2){//check can slide
		return (map1[y2 - 1][x2] == '/' ? 1 : (map1[y2 - 1][x2] == '\\' ? -1 : 0));
	}
	inline void show(){
		int a = max(x - 30, 0);
		int b = max(y - 5, 0);
		if(a + 59 > End){
			a = End - 59;
		}
		if(b > 21){
			b = 21;
		}
		cout << "x:" << x << " y:" << y << endl;
		for(int i = b; i < b + 10; i++){
			for(int j = a; j < a + 60; j++){
				if(i == y - 1 && j == x){
					cout << 'O';
				}else{
					if(map1[i][j] == '.'){
						cout << "\033[34;1m#\033[m";
					}else if(map1[i][j] == '*'){
						cout << "\033[31;1m*\033[m";
					}else if(map1[i][j] == 'Z'){
						cout << "\033[32;1mZ\033[m";
					}else if(map1[i][j] == '^'){
						cout << "\033[33;1m^\033[m";
					}else if(map1[i][j] == '>'){
						cout << "\033[33;1m>\033[m";
					}else if(map1[i][j] == '<'){
						cout << "\033[33;1m<\033[m";
					}else if(fin(j, i + 1)){
						cout << "\033[33;1m" << map1[i][j] << "\033[m";
					}else{
						cout << map1[i][j];
					}
				}
			}
			cout << endl;
		}
	}
	inline void tr(int x2, int y2){
		if(x2 <= 0){
			return;
		}
		if(y2 <= 0){
			return;
		}
		if(y2 > 31){
			return;
		}
		if(x2 >= End){
			return;
		}
		if(ok(x2, y2)){
			x = x2;
			y = y2;
		}
	}
	inline void main(){
		if(variate::try_level != 0){
			printa("已完成挑战");
			return;
		}
		x = born1[level1][0];
		y = born1[level1][1];
		clear();
		if(!printYn("是否进入跑酷1")){
			return;
		}
		int swcnt = 0;
		bool ju = false;
		while(true){
			if(x <= 0){
				x = 1;
			}
			if(y <= 0){
				y = 1;
			}
			clear();
			if(x == born1[level1 + 1][0] && y == born1[level1 + 1][1]){
				level1++;
			}
			if(ty()){
				swcnt = 0;
				cout << "使用w或空格进行跳跃, 按r重生, 按backspace退出" << endl;
				show();
				char c;
				bool u = false, di = false;
				while(c = getch2()){
					if(c == 127){
						return;
					}
					if(c == 'w' || c == ' '){
						u = true;
						ju = true;
					}
					if(c == 'r'){
						di = true;
					}
				}
				if(fin(x, y - 1)){
					clear();
					printa("完成挑战, 获得 $500");
					variate::money += 500;
					variate::try_level = 1;
					return;
				}
				if(die()){
					print("你死了");
					if(!printYn("是否重生")){
						return;
					}
					x = born1[level1][0];
					y = born1[level1][1];
					continue;
				}
				if(di){
					x = born1[level1][0];
					y = born1[level1][1];
					continue;
				}
				if(map1[y][x] == '^'){
					sy = 0;
					tr(x, y - 4);
					sleep2(0.1);
					continue;
				}
				if(map1[y][x] == '>'){
					sy = 0;
					tr(x + 4, y);
					sleep2(0.1);
					continue;
				}
				if(map1[y][x] == '<'){
					sy = 0;
					tr(x - 4, y);
					sleep2(0.1);
					continue;
				}
				if(map1[y][x] == 'Z'){
					sy = 3;
				}
				for(int i = 1; i <= sy; i++){
					tr(x, y - 1);
					if(!ty()){
						sy = 0;
						continue;
					}
				}
				if(ok(x, y + 1)){
					sy--;
				}else{
					sy = 0;
				}
				if(sy){
					for(int i = 1; i <= sy; i++){
						tr(x, y - 1);
						if(!ty()){
							sy = 0;
							continue;
						}
					}
					for(int i = 1; i <= -sy; i++){
						tr(x, y + 1);
						if(!ty()){
							sy = 0;
							continue;
						}
					}
				}
				if(!ok(x + sx, y)){
					if((sx == slide(x + sx, y) && ok(x + sx, y - 1)) || (slide(x, y + 1) != 0)){
						tr(x, y - 1);
						if(!ty()){
							sy = 0;
							continue;
						}
					}else{
						sx *= -1;
					}
				}
				tr(x + sx, y);
				if((u || ju) && !sy && !ok(x, y + 1)){
					ju = false;
					sy = 2;
					for(int i = 1; i <= sy; i++){
						tr(x, y - 1);
						if(!ty()){
							sy = 0;
							continue;
						}
					}
				}
				if(!ok(x, y + 1)){
					sy = 0;
				}
				sleep2(0.1);
			}else{
				ju = false;
				cout << "使用wasd进行游泳, 按r重生, 按backspace退出" << endl;
				show();
				swcnt++;
				swcnt %= 5;
				char c;
				bool u = false, d = false, l = false, r = false, di = false;
				while(c = getch2()){
					if(c == 127){
						return;
					}
					if(c == 'r'){
						di = true;
					}
					if(c == 'w'){
						u = true;
					}
					if(c == 'a'){
						l = true;
					}
					if(c == 's'){
						d = true;
					}
					if(c == 'd'){
						r = true;
					}
				}
				if(die()){
					print("你死了");
					if(!printYn("是否重生")){
						return;
					}
					x = born1[level1][0];
					y = born1[level1][1];
					continue;
				}
				if(di){
					x = born1[level1][0];
					y = born1[level1][1];
					continue;
				}
				if(u && !d){
					tr(x, y - 1);
				}
				if(d && !u){
					tr(x, y + 1);
				}
				if(!u && !d && !swcnt){
					tr(x, y + 1);
				}
				if(l && !r){
					tr(x - 1, y);
				}
				if(!l && r){
					tr(x + 1, y);
				}
				sleep2(0.1);
			}
		}
	}
}
#endif
