#ifndef beat_defined
#define beat_defined
#include<unordered_map>
#include<iostream>
#include<iomanip>
#include<vector>
using std::string;
using std::vector;
using std::pair;
using std::cout;
using std::max;
using std::unordered_map;
#include"variate.h"
#include"function.h"
namespace beat{
	int america = 0;
	int sleepcnt = 0, eatcnt = 0, e2 = 0, s2 = 0;
	int temple = 0, romar = 0, headbone = 0, drafood = 0;
	struct be{
		string title;
		vector<string> things;
		vector<string> choose;
		vector<string> cnext;
		vector<int> cnext2;
	}
	things[102] = {
#ifdef EN
{"Introduction", {"You are the hero of this world.", "You must defeat the evil dragon through your efforts.", "Along the way, you will meet many allies", "And many traps."}, {"Start"}, {""}, {1}},
{"", {"You wake up in your bed.", "What do you want to do?"}, {"Eat breakfast", "Go outside", "Sleep a bit more"}, {"You ate breakfast", "", "You lay back in bed"}, {-1, 2, -2}},
{"", {"You step outside onto the road.", "What do you want to do?"}, {"Go back and eat breakfast", "Go back to sleep", "Go to the blacksmith"}, {"You went back and ate breakfast", "You went back and lay in bed", "You headed to the blacksmith"}, {-1, -2, 3}},
{"Blacksmith", {"You arrive at the blacksmith.", "Blacksmith: I heard you're going to fight the dragon.", "Blacksmith: You’ll need a proper weapon.", "Blacksmith: Tell me what you need.", "Blacksmith: Maybe I can help."}, {"Leave", "Make a weapon"}, {"You left the blacksmith", ""}, {2, 4}},
{"Blacksmith", {"Blacksmith: What kind of weapon do you want?"}, {"A longsword"}, {"You received a longsword"}, {5}},
{"", {"It’s time to set out."}, {"Take the small path east", "Take the wide road west"}, {"", ""}, {6, 14}},
{"", {"You walk eastward", "You encounter an inn."}, {"Go inside to rest", "Leave"}, {"You entered the inn and rested", "You set up a tent and slept on the street"}, {10, 9}},
{"", {"You walk eastward", "You encounter an inn."}, {"Go inside to rest", "Leave"}, {"You entered the inn and rested", ""}, {8, 12}},
{"Died", {"You were assassinated in the inn."}, {"Rebirth"}, {""}, {1}},
{"Died", {"You froze to death on the roadside."}, {"Rebirth"}, {""}, {1}},
{"", {"You continue east", "You meet a merchant."}, {"Buy food", "Leave"}, {"You stocked up on food", ""}, {7, 11}},
{"Died", {"You died of hunger on the roadside."}, {"Rebirth"}, {""}, {1}},
{"", {"You encounter a temple."}, {"Enter", "Leave"}, {"", ""}, {13, 11}},
{"Temple", {"You entered the temple.", "You focused on studying Buddhism.", "Eventually you became a Buddha.", "You forgot your mission."}, {"Rebirth"}, {""}, {1}},
{"", {"You walk west", "You find another inn."}, {"Go inside to rest", "Leave"}, {"You entered the inn and rested", ""}, {15, 11}},
{"Inn", {"You hear voices downstairs."}, {"Eavesdrop", "Sleep"}, {"", ""}, {16, 8}},
{"Inn", {"You overhear the innkeeper plotting to steal your wallet."}, {"Escape through the window", "Fight the innkeeper"}, {"", ""}, {17, 18}},
{"Died", {"You died from the fall."}, {"Rebirth"}, {""}, {1}},
{"Inn", {"You defeated the innkeeper."}, {"Leave"}, {""}, {19}},
{"", {"There are two roads ahead."}, {"Take the southern road", "Take the northern path"}, {"", ""}, {20, 23}},
{"", {"You head down the southern road.", "You find a fork."}, {"Continue south", "Board the ship to the west"}, {"", "You boarded the ship"}, {21, 22}},
{"Rome", {"All roads lead to Rome.", "You’ve arrived in Rome."}, {"Rebirth"}, {""}, {1}},
{"America", {"You set sail on a great voyage.", "You discovered the American continent."}, {"Rebirth"}, {""}, {1}},
{"", {"You take the northern path.", "You discover a cave."}, {"Enter the cave", "Leave"}, {"You entered the cave", ""}, {24, 25}},
{"Cave", {"You find a mound of dirt in the cave.", "You begin digging.", "You discovered the world’s first complete Neanderthal skull."}, {"Rebirth"}, {""}, {1}},
{"", {"You found the dragon's lair."}, {"Enter", "Go home for food", "Go home to sleep"}, {"You entered the dragon’s lair", "", ""}, {26, -3, -4}},
{"Dragon's Lair", {"You arrive at the dragon’s lair."}, {"Fight the dragon", "Go home for food", "Go home to sleep"}, {"You entered the dragon’s lair", "", ""}, {27, -3, -4}},
{"Dragon's Lair", {"You defeated the dragon!"}, {"Look for dragon egg"}, {""}, {28}},
{"Dragon's Lair", {"You found a dragon egg."}, {"Destroy the egg", "Incubate the egg", "Go home for food", "Go home to sleep"}, {"", "", "", ""}, {32, 29, -3, -4}},
{"Dragon's Lair", {"You started incubating the egg.", "A baby dragon hatched."}, {"Eat it", "Let it go"}, {"", ""}, {30, 31}},
{"Dragon's Lair", {"You were killed by the baby dragon."}, {"Rebirth"}, {""}, {1}},
{"Dragon's Lair", {"You completed your mission."}, {"Exit"}, {""}, {-5}},
{"Dragon's Lair", {"You completed your mission."}, {"Exit"}, {""}, {-5}}
#else
{"简介", {"你是这个世界的勇者", "你需要经过你的努力打败恶龙", "过程中你会遇到很多的帮助", "以及很多的陷阱"}, {"开始"}, {""}, {1}},
{"", {"你从你的床上醒来", "你要干什么"}, {"吃早饭", "出去走走", "再睡一会"}, {"你吃了早饭", "", "你躺在了床上"}, {-1, 2, -2}},
{"", {"你来到了屋外的路上", "你要干什么"}, {"回家吃早饭", "回家再睡一会", "去铁匠铺"}, {"你回家吃了早饭", "你回家躺在了床上", "你走向了铁匠铺"}, {-1, -2, 3}},
{"铁匠铺", {"你来到了铁匠铺", "铁匠: 听说你要去迎战恶龙", "铁匠: 你需要准备一把称手的武器", "铁匠: 告诉我你需要什么", "铁匠: 没准我能帮上忙"}, {"离开", "制作武器"}, {"你离开了铁匠铺", ""}, {2, 4}},
{"铁匠铺", {"铁匠: 你想要什么样的武器"}, {"一把长剑"}, {"你获得了一把长剑"}, {5}},
{"", {"是时候该出发了"}, {"沿着东边的小路走", "沿着西边的大路走"}, {"", ""}, {6, 14}},
{"", {"你朝着东边走去", "遇到了一个旅馆"}, {"进入休息", "离开"}, {"你进入了旅馆休息", "你在街头搭帐篷过夜"}, {10, 9}},
{"", {"你朝着东边走去", "遇到了一个旅馆"}, {"进入休息", "离开"}, {"你进入了旅馆休息", ""}, {8, 12}},
{"Died", {"你在旅馆被刺杀了"}, {"重生"}, {""}, {1}},
{"Died", {"你在外留宿后冻死在了路边"}, {"重生"}, {""}, {1}},
{"", {"你朝着东边走去", "遇到了一个商人"}, {"购买食物", "离开"}, {"你补充了充足的食物", ""}, {7, 11}},
{"Died", {"你在由于长时间的饥饿死在了路边"}, {"重生"}, {""}, {1}},
{"", {"你遇到了寺庙"}, {"进入", "离开"}, {"", ""}, {13, 11}},
{"寺庙", {"你进入了寺庙", "一心学习佛法", "逐渐修炼成佛", "忘记了你的目的"}, {"重生"}, {""}, {1}},
{"", {"你朝着西边走去", "遇到了一个旅馆"}, {"进入休息", "离开"}, {"你进入了旅馆休息", ""}, {15, 11}},
{"旅馆", {"你听见楼下有说话的声音"}, {"偷听", "睡觉"}, {"", ""}, {16, 8}},
{"旅馆", {"你听见旅馆老板想抢你的钱包"}, {"跳窗逃走", "与老板战斗"}, {"", ""}, {17, 18}},
{"Died", {"你摔死了"}, {"重生"}, {""}, {1}},
{"旅馆", {"你打赢了老板"}, {"离开"}, {""}, {19}},
{"", {"门外有两条路"}, {"南边的大路", "北边的小路"}, {"", ""}, {20, 23}},//19
{"", {"你朝着南边的大路走去", "遇到了岔路"}, {"南边的大路", "西边的轮船"}, {"", "你走上了轮船"}, {21, 22}},//20
{"罗马", {"条条大路通罗马", "你到达了罗马"}, {"重生"}, {""}, {1}},//21
{"美洲大陆", {"你开始了你的大航海", "发现了美洲大陆"}, {"重生"}, {""}, {1}},//22
{"", {"你朝着北边的小路走去", "发现了山洞"}, {"进入山洞", "直接离开"}, {"你进入了山洞", ""}, {24, 25}},//23
{"山洞", {"你在山洞里发现了一个土堆", "然后开始刨土", "于是你发现了世界上第一块山顶洞人的完整头盖骨"}, {"重生"}, {""}, {1}},//24
{"", {"你找到了龙的巢穴"}, {"进入", "回家吃饭", "回家睡觉"}, {"你进入了龙的巢穴", "", ""}, {26, -3, -4}},//25
{"龙巢", {"你到了龙的巢穴"}, {"与龙战斗", "回家吃饭", "回家睡觉"}, {"你进入了龙的巢穴", "", ""}, {27, -3, -4}},//26
{"龙巢", {"你打败了恶龙"}, {"寻找龙蛋"}, {""}, {28}},//27
{"龙巢", {"你找到了龙蛋"}, {"破坏龙蛋", "孵化龙蛋", "回家吃饭", "回家睡觉"}, {"", "", "", ""}, {32, 29, -3, -4}},//28
{"龙巢", {"你开始孵化龙蛋", "孵化出了小龙"}, {"杀了吃肉", "放生"}, {"", ""}, {30, 31}},//29
{"龙巢", {"你被小龙杀死了"}, {"重生"}, {""}, {1}},//30
{"龙巢", {"你完成了你的任务"}, {"退出"}, {""}, {-5}},//31
{"龙巢", {"你完成了你的任务"}, {"退出"}, {""}, {-5}}//32
#endif
};
	int now;
	unordered_map<char, int> m1;
	vector<char> m2;
	inline void setup(){
		sleepcnt = eatcnt = temple = romar = america = headbone = e2 = s2 = 0;
		now = 0;
		for(int i = 1; i <= 9; i++){
			m1[i + '0'] = m2.size();
			m2.push_back(i + '0');
		}
		for(int i = 0; i <= 26; i++){
			m1[i + 'a'] = m2.size();
			m2.push_back(i + 'a');
		}
	}
	inline ostream& operator<<(ostream& out, be a){
		auto &title = a.title;
		auto &things = a.things;
		auto &choose = a.choose;
		auto &cnext = a.cnext;
		auto &cnext2 = a.cnext2;
		if(!title.empty()){
			print(title);
			cout << endl;
		}
		for(int i = 0; i < things.size(); i++){
			print(things[i]);
			sleept(0.1);
		}
		cout << endl;
		#ifdef EN
		if(now == 21){
			if(!romar){
				printa("Hidden Reward Unlocked: All Roads Lead to Rome");
				variate::money += 100;
			}
			if(romar == 5){
				printa("Hidden Reward Unlocked: Lost on the Way");
				variate::money += 100;
			}
			romar++;
		}

		if(now == 22){
			if(!america){
				printa("Hidden Reward Unlocked: Columbus's Voyage");
				variate::money += 100;
			}
			if(america == 5){
				printa("Hidden Reward Unlocked: Lost on the Way");
				variate::money += 100;
			}
			america++;
		}

		if(now == 24){
			if(!headbone){
				printa("Hidden Reward Unlocked: Pleasant Surprise");
				variate::money += 100;
			}
			if(headbone == 5){
				printa("Hidden Reward Unlocked: Archaeologist");
				variate::money += 100;
			}
			headbone++;
		}
		#else
		if(now == 21){
			if(!romar){
				printa("获得彩蛋: 条条大路通罗马");
				variate::money += 100;
			}
			if(romar == 5){
				printa("获得彩蛋: 误入歧途");
				variate::money += 100;
			}
			romar++;
		}
		if(now == 22){
			if(!america){
				printa("获得彩蛋: 哥伦布大航海");
				variate::money += 100;
			}
			if(america == 5){
				printa("获得彩蛋: 误入歧途");
				variate::money += 100;
			}
			america++;
		}
		if(now == 24){
			if(!headbone){
				printa("获得彩蛋: 意外之喜");
				variate::money += 100;
			}
			if(headbone == 5){
				printa("获得彩蛋: 考古专家");
				variate::money += 100;
			}
			headbone++;
		}
		#endif
		string s;
		for(int i = 0; i < choose.size(); i++){
			s += m2[i];
			s += "." + choose[i];
			if(i < choose.size() - 1){
				s += ", ";
			}
		}
		print(s);
		char c;
		while(m1.find(c = getch()) == m1.end() || m1[c] >= (int)choose.size());
		if(!cnext[m1[c]].empty()){
			clear();
			printa(cnext[m1[c]]);
		}
		now = cnext2[m1[c]];
		#ifdef EN
		if(now == 13){
			if(!temple){
				printa("Hidden Reward Unlocked: Devoted to Buddhism");
				variate::money += 100;
			}
			if(temple == 5){
				printa("Hidden Reward Unlocked: Ascended to Immortality");
				variate::money += 100;
			}
			temple++;
		}
		if(now == 30){
			if(eatcnt >= 30 && !drafood){
				printa("Hidden Reward Unlocked: Delicious Indeed");
				variate::money += 100;
			}
			drafood++;
		}
		if(now == -3){
			if(eatcnt >= 30 && e2 == 0){
				printa("Hidden Reward Unlocked: Stay True to Your Original Aspiration");
				variate::money += 100;
			}
			if(eatcnt >= 30 && e2 == 5){
				printa("Hidden Reward Unlocked: Keep the Mission in Mind");
				variate::money += 200;
			}
			e2++;
			now = 1;
		}
		if(now == -4){
			if(sleepcnt >= 30 && s2 == 0){
				printa("Hidden Reward Unlocked: That Bed is So Soft");
				variate::money += 100;
			}
			if(sleepcnt >= 30 && s2 == 5){
				printa("Hidden Reward Unlocked: Sleeping Feels the Best");
				variate::money += 200;
			}
			s2++;
			now = 1;
		}
		if(now == -1){
			eatcnt++;
			if(eatcnt == 5){
				printa("Hidden Reward Unlocked: Man Lives on Food");
				variate::money += 100;
			}
			if(eatcnt == 10){
				printa("Hidden Reward Unlocked: Escaped from the Starving Ghost Realm");
				variate::money += 100;
			}
			if(eatcnt == 30){
				printa("Hidden Reward Unlocked: What a Virtuous Hui! Eating simply, living in poverty, yet staying joyful.");
				variate::money += 100;
			}
			now = 1;
		}
		if(now == -2){
			sleepcnt++;
			if(sleepcnt == 5){
				printa("Hidden Reward Unlocked: You Need Sleep to Move On");
				variate::money += 100;
			}
			if(sleepcnt == 10){
				printa("Hidden Reward Unlocked: The Bed Feels Great");
				variate::money += 100;
			}
			if(sleepcnt == 30){
				printa("Hidden Reward Unlocked: Blessed by the Sleep God");
				variate::money += 100;
			}
			now = 1;
		}
		#else
		if(now == 13){
			if(!temple){
				printa("获得彩蛋: 学习佛法, 一心向善");
				variate::money += 100;
			}
			if(temple == 5){
				printa("获得彩蛋: 修炼成仙");
				variate::money += 100;
			}
			temple++;
		}
		if(now == 30){
			if(eatcnt >= 30 && !drafood){
				printa("获得彩蛋: 真香");
				variate::money += 100;
			}
			drafood++;
		}
		if(now == -3){
			if(eatcnt >= 30 && e2 == 0){
				printa("获得彩蛋: 不忘初心");
				variate::money += 100;
			}
			if(eatcnt >= 30 && e2 == 5){
				printa("获得彩蛋: 牢记使命");
				variate::money += 200;
			}
			e2++;
			now = 1;
		}
		if(now == -4){
			if(sleepcnt >= 30 && s2 == 0){
				printa("获得彩蛋: 床真软");
				variate::money += 100;
			}
			if(sleepcnt >= 30 && s2 == 5){
				printa("获得彩蛋: 还是睡觉舒服");
				variate::money += 200;
			}
			s2++;
			now = 1;
		}
		if(now == -1){
			eatcnt++;
			if(eatcnt == 5){
				printa("获得彩蛋: 人是铁, 饭是钢, 一顿不吃饿得慌");
				variate::money += 100;
			}
			if(eatcnt == 10){
				printa("获得彩蛋: 饿死鬼脱身");
				variate::money += 100;
			}
			if(eatcnt == 30){
				printa("获得彩蛋: 贤哉, 回也! 一吨食, 一瓢饮, 在陋巷, 人不堪其忧, 回也不改其乐. 贤哉, 回也! ");
				variate::money += 100;
			}
			now = 1;
		}
		if(now == -2){
			sleepcnt++;
			if(sleepcnt == 5){
				printa("获得彩蛋: 睡醒了才能出发");
				variate::money += 100;
			}
			if(sleepcnt == 10){
				printa("获得彩蛋: 床真舒服");
				variate::money += 100;
			}
			if(sleepcnt == 30){
				printa("获得彩蛋: 睡神赋体");
				variate::money += 100;
			}
			now = 1;
		}
		#endif
		sleept(0.5);
		return out;
	}
	inline void main(){
		clear();
		setup();
		while(true){
			clear();
			cout << things[now] << endl;
			if(now == -5){
				#ifdef EN
				printa("Finished");
				#else
				printa("任务完成");
				#endif
				variate::try_level++;
				variate::money += 100;
				return;
			}
		}
	}
}
#endif
