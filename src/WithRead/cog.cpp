#ifndef COG_CPP_
#define COG_CPP_

#include "cog.h"

using namespace std;

cog::cog (int t): type(t), readcount(0) {}

cog::cog (int t, unsigned int r): type(t), readcount(r) {}

unsigned int cog::getReadcount(){
	return readcount;
}

void cog::setReadcount(unsigned int x){
	readcount = x;
}

const int cog::getType(){
	return type;
}

#endif