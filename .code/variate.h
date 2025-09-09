#ifndef variate_defined
#define variate_defined
#include<string>
#include<vector>
#include<queue>
using std::queue;
using std::vector;
using std::string;
using std::to_string;
namespace variate{
	const int max_level = 25;
	const int mintime[26] = {50, 40, 40, 40, 30, 30, 30, 30, 20, 20, 10, 9, 7, 5, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 1, 1};
	const int maxtime[26] = {100, 100, 90, 80, 80, 70, 60, 50, 50, 40, 40, 40, 40, 40, 40, 35, 30, 25, 20, 10, 5, 4, 4, 3, 3, 2};
	const int cost[26] = {0, 5, 5, 5, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 150, 200, 200, 200, 300, 350, 400, 500, 600, 700, 700};
	const int max_level2 = 29;
	const int maxget[30] = {20, 20, 20, 30, 30, 40, 40, 40, 50, 50, 55, 60, 60, 60, 70, 70, 80, 80, 90, 100, 105, 110, 120, 130, 135, 140, 145, 150, 170, 200};
	const int minget[30] = {10, 12, 15, 15, 20, 20, 25, 30, 35, 40, 40, 40, 45, 50, 60, 60, 60, 70, 80, 85 , 85 , 90 , 95 , 100, 100, 100, 100, 100, 100, 100};
	const int cost2[30] = {0, 20, 20, 20, 30, 40, 50, 60, 70, 80, 80, 80, 80, 90, 100, 150, 200, 200, 200, 300, 350, 400, 500, 600, 700, 700, 700, 700, 700, 700};
	long long ltime = 0, left = 0;
	string name;
	bool fish_man = false;
	int big = 0;
	int diamond = 0;
	const int tools = 4;
	int aqnow = 0;
	int aqother = 0;
	string pwd;
	string to_stringf(double d){
		return to_string((int)d) + "." + to_string(((int)(d * 10)) % 10);
	}

	vector<uint8_t>& write(vector<uint8_t>&v, int a){
		for(int i = 3; i >= 0; i--){
			v.push_back(a >> (i << 3) & 0xff);
		}
		return v;
	}
	int read(queue<uint8_t>& q){
		int b = 0;
		for(int i = 0; !q.empty() && i < 4; i++){
			b = b << 8 | q.front();
			q.pop();
		}
		return b;
	}
	queue<uint8_t>& read(queue<uint8_t>& q, int& a){
		a = read(q);
		return q;
	}
	vector<uint8_t>& writel(vector<uint8_t>&v, long long a){
		for(int i = 7; i >= 0; i--){
			v.push_back(a >> (i << 3) & 0xff);
		}
		return v;
	}
	long long readl(queue<uint8_t>& q){
		long long b = 0;
		for(int i = 0; !q.empty() && i < 8; i++){
			b = b << 8 | q.front();
			q.pop();
		}
		return b;
	}
	queue<uint8_t>& readl(queue<uint8_t>& q, long long& a){
		a = readl(q);
		return q;
	}
	vector<uint8_t>& operator<<(vector<uint8_t>& v, const int& a){
		return write(v, a);
	}
	vector<uint8_t>& operator<<(vector<uint8_t>& v, const long long& a){
		return writel(v, a);
	}
	queue<uint8_t>& operator>>(queue<uint8_t>& q, int& a){
		return read(q, a);
	}
	queue<uint8_t>& operator>>(queue<uint8_t>& q, long long& a){
		return readl(q, a);
	}
	struct svariate{
		//[0,]
		long long money = 20;
		//[0,max_level]
		int level = 0;
		//[0,max_level2]
		int get_level = 0;
		//[0,]
		long long cnt = 0;
		//(0,100]
		int bf = 20;
		//[1,10]
		int stime = 1;
		//[0,100]
		int slip = 50;
		//[0,]
		int cleaning_ball = 0;
		//[1,]
		int cleaning_sub = 1;
		//[0,6]
		int gan = 1;
		//[0,]
		int aqcnt = 0;
		//[1,3]
		int speed = 2;
		//[0,]
		int try_level = 0;
		//[0,]
		int roast = 0;
		//[0,40]
		int hungry = 20;
		//[0,]
		int aqfish_cnt[7] = {};
		int fish[7][2] = {};
		bool simple = false;

		svariate() = default;

		svariate(const std::vector<uint8_t>& s){
			set(s);
		}

		operator std::vector<uint8_t>()const{
			return get();
		}

		inline vector<uint8_t> get()const{
			vector<uint8_t> s;
			s << money << level << get_level << cnt << bf << stime << slip << cleaning_ball << cleaning_sub << gan << aqcnt << try_level << speed << roast << hungry;
			for(int i = 0; i <= 6; i++){
				s << aqfish_cnt[i];
			}
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 7; j++){
					s << fish[j][i];
				}
			}
			write(s, simple);
			return s;
		}

		inline variate::svariate& set(const vector<uint8_t>& s0){
			queue<uint8_t> s;
			for(uint8_t i : s0){
				s.push(i);
			}
			s >> money >> level >> get_level >> cnt >> bf >> stime >> slip >> cleaning_ball >> cleaning_sub >> gan >> aqcnt >> try_level >> speed >> roast >> hungry;
			for(int i = 0; i <= 6; i++){
				s >> aqfish_cnt[i];
			}
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 7; j++){
					s >> fish[j][i];
				}
			}
			simple = read(s);
			return *this;
		}
	}data_saver;
}
#endif
