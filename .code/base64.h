#ifndef b64_defined
#define b64_defined
#include<hashtable.h>
#include<string>
using std::hash;
using std::string;
using std::to_string;
class base64{
	private:
		int basedecode[128];
		char baseencode[65];
		char oth;
		bool use[7];
		int ans[7];
		int tot;
		char tb(int n){
			return baseencode[n & 0x3f];
		}
		void quan(int n, int b){
			if(n >= 6){
				tot++;
				return;
			}
			for(int i = 0; i <= 4; i++){
				if(use[i]){
					continue;
				}
				use[i] = true;
				ans[n] = i;
				quan(n + 1, b);
				use[i] = false;
				if(b == tot){
					return;
				}
			}
		}
		string get_password(string s){
			size_t ha = hash<string>{}(s);
			unsigned long long  num = static_cast<unsigned long long>(ha);
			char a[6] = "aA1";
			string list = "({[<`~!@#$%^&*-_+=|;:.?>]})";
			unsigned long long n1 = num / list.length();
			unsigned long long r1 = num % list.length();
			unsigned long long n2 = n1 / (list.length() - 1);
			unsigned long long r2 = n1 % (list.length() - 1);
			unsigned long long n3 = n2 / (list.length() - 2);
			unsigned long long r3 = n2 % (list.length() - 2);
			unsigned long long r4 = n3 % 120;
			a[3] = list[r1];
			list.erase(r1, 1);
			a[4] = list[r2];
			list.erase(r2, 1);
			a[5] = list[r3];
			for(int i = 0; i <= 4; i++){
				use[i] = false;
				ans[i] = 0;
			}
			ans[6] = 5;
			quan(1, r4 + 1);
			string an;
			for(int i = 1; i <= 6; i++){
				an += a[ans[i]];
			}
			return an;
		}
		string get_password(unsigned long long num){
			char a[6] = "aA1";
			string list = "({[<`~!@#$%^&*-_+=|;:.?>]})";
			unsigned long long n1 = num / list.length();
			unsigned long long r1 = num % list.length();
			unsigned long long n2 = n1 / (list.length() - 1);
			unsigned long long r2 = n1 % (list.length() - 1);
			unsigned long long n3 = n2 / (list.length() - 2);
			unsigned long long r3 = n2 % (list.length() - 2);
			unsigned long long n4 = n3 / 120;
			unsigned long long r4 = n3 % 120;
			a[3] = list[r1];
			list.erase(r1, 1);
			a[4] = list[r2];
			list.erase(r2, 1);
			a[5] = list[r3];
			for(int i = 0; i <= 4; i++){
				use[i] = false;
				ans[i] = 0;
			}
			ans[6] = 5;
			quan(1, r4 + 1);
			string an;
			for(int i = 1; i <= 6; i++){
				an += a[ans[i]];
			}
			return an;
		}
		void set_base(string s){
			int i = 0;
			for(int i = 0; i < 64; i++){
				baseencode[i] = '\0';
			}
			for(int i = 0; i < 128; i++){
				basedecode[i] = '\0';
			}
			oth = s[5];
			for(int j = 0; j < 5; j++){
				if(isdigit(s[j])){
					for(int j = 0; j < 10; j++){
						basedecode[j + '0'] = i;
						baseencode[i++] = j + '0';
					}
				}else if(islower(s[j])){
					for(int j = 0; j < 26; j++){
						basedecode[j + 'a'] = i;
						baseencode[i++] = j + 'a';
					}
				}else if(isupper(s[j])){
					for(int j = 0; j < 26; j++){
						basedecode[j + 'A'] = i;
						baseencode[i++] = j + 'A';
					}
				}else{
					basedecode[s[j]] = i;
					baseencode[i++] = s[j];
				}
			}
		}
	public:
		base64(int s){
			set_base(get_password(s));
		}
		base64(string s){
			set_base(s);
		}
		base64(string s, bool salt){
			if(salt){
				set_base(get_password(s + "add_salt"));
			}else{
				set_base(get_password(s + "no_salt"));
			}
		}
		string decode(string in){//jiema
			string ans;
			for(int i = 0; i < in.length(); i += 4){
				ans += (char)((unsigned char)basedecode[in[i]] << 2 | (unsigned char)basedecode[in[i + 1]] >> 4) & 0xff;
				if(in[i + 2] != oth){
					ans += (char)((unsigned char)basedecode[in[i + 1]] << 4 | (unsigned char)basedecode[in[i + 2]] >> 2) & 0xff;
				}
				if(in[i + 3] != oth){
					ans += (char)((unsigned char)basedecode[in[i + 2]] << 6 | (unsigned char)basedecode[in[i + 3]]) & 0xff;
				}
			}
			return ans;
		}
		string encode(string in){//bianma
			string ans;
			for(int i = 0; i < in.length(); i += 3){
				ans += tb(((unsigned char)in[i] >> 2));
				ans += tb(((unsigned char)in[i] << 4) | (i + 1 >= in.length() ? 0 : ((unsigned char)in[i + 1] >> 4)));
				ans += (i + 1 >= in.length()) ? oth : tb(((unsigned char)in[i + 1] << 2) | (i + 2 >= in.length() ? 0 : ((unsigned char)in[i + 2] >> 6)));
				ans += (i + 2 >= in.length()) ? oth : tb(((unsigned char)in[i + 2]));
			}
			while(ans.length() % 4){
				ans += oth;
			}
			return ans;
		}
}b1("a[0]A`"), b2("(0aA);"), b3("|a0+A-");
#endif