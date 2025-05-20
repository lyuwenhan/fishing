#ifndef color_defined
#define color_defined
#include<string>
using std::string;
namespace color{
	string NONE = "\033[m";
	string RED = "\033[0;32;31m";
	string LIGHT_RED = "\033[1;31m";
	string GREEN = "\033[0;32;32m";
	string LIGHT_GREEN = "\033[1;32m";
	string BLUE = "\033[0;32;34m";
	string LIGHT_BLUE = "\033[1;34m";
	string DARY_GRAY = "\033[1;30m";
	string CYAN = "\033[0;36m";
	string LIGHT_CYAN = "\033[1;36m";
	string PURPLE = "\033[0;35m";
	string LIGHT_PURPLE = "\033[1;35m";
	string BROWN = "\033[0;33m";
	string YELLOW = "\033[1;33m";
	string LIGHT_GRAY = "\033[0;37m";
	string WHITE = "\033[1;37m";
	string SHINE = "\033[5m";       //闪烁
	string DASH = "\033[9m";        //中间一道横线
	string QUICKSHINE = "\033[6m";  //快闪
	string FANXIAN = "\033[7m";     //反显
	string XIAOYIN = "\033[8m";     //消隐, 消失隐藏
}
#endif