#ifndef COG_CPP_
#define COG_CPP_

#include "cog.h"

using namespace std;

cog::cog (int t): type(t) {}

const int cog::getType(){
	return type;
}

#endif