#ifndef story_defined
#define story_defined
#include"variate.h"
#include"function.h"
inline void story(){
	clear();
	for(string i : vector<string>(story_m)){
		printa(i);
	}
	clear();
}
#endif
