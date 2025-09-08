#ifndef variate_defined
#define variate_defined
#include<string>
using std::string;
using std::to_string;
namespace variate{
	//[0,]
	long long money = 20;
	//[0,max_level]
	int level = 0;
	const int max_level = 25;
	const int mintime[26] = {50, 40, 40, 40, 30, 30, 30, 30, 20, 20, 10, 9, 7, 5, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 1, 1};
	const int maxtime[26] = {100, 100, 90, 80, 80, 70, 60, 50, 50, 40, 40, 40, 40, 40, 40, 35, 30, 25, 20, 10, 5, 4, 4, 3, 3, 2};
	const int cost[26] = {0, 5, 5, 5, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 150, 200, 200, 200, 300, 350, 400, 500, 600, 700, 700};
	//[0,max_level2]
	int get_level = 0;
	const int max_level2 = 29;
	const int maxget[30] = {20, 20, 20, 30, 30, 40, 40, 40, 50, 50, 55, 60, 60, 60, 70, 70, 80, 80, 90, 100, 105, 110, 120, 130, 135, 140, 145, 150, 170, 200};
	const int minget[30] = {10, 12, 15, 15, 20, 20, 25, 30, 35, 40, 40, 40, 45, 50, 60, 60, 60, 70, 80, 85 , 85 , 90 , 95 , 100, 100, 100, 100, 100, 100, 100};
	const int cost2[30] = {0, 20, 20, 20, 30, 40, 50, 60, 70, 80, 80, 80, 80, 90, 100, 150, 200, 200, 200, 300, 350, 400, 500, 600, 700, 700, 700, 700, 700, 700};
	//[0,]
	int aqfish_cnt[7] = {};
	//[0,]
	int aqcnt = 0;
	//(0,100]
	int bf = 20;
	//[0,]
	long long cnt = 0;
	//[1,10]
	int stime = 1;
	string to_stringf(double d){
		return to_string((int)d) + "." + to_string(((int)(d * 10)) % 10);
	}
	long long ltime = 0, left = 0;
	//[1,3]
	int speed = 2;
	//[0,100]
	int slip = 50;
	//[0,]
	int cleaning_ball = 0;
	//[1,]
	int cleaning_sub = 1;
	string name;
	bool fish_man = false;
	int big = 0;
	int diamond = 0;
	//[0,6]
	int gan = 1;
	const int tools = 4;
	int aqnow = 0;
	int aqother = 0;
	//[0,]
	int try_level = 0;
	int fish[7][2] = {};
	//[0,]
	int roast = 0;
	//[0,40]
	int hungry = 20;
	string pwd;
	bool simple = false;
}
#endif
