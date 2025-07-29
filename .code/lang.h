#ifndef LANG_MAIN
#define LANG_MAIN
#ifdef ZH
#include"lang/CN.h"
#else
#ifdef EN
#include"lang/EN.h"
#else
#include"lang/CN.h"
#endif
#endif
#endif