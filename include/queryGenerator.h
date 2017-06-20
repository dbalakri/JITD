#ifndef QUERYGENERATOR_H_
#define QUERYGENERATOR_H_

#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int,int> > queryGenerator(int seed, int num, int min, int max, int rangeSize, double pData, double pQuery);

#endif /* QUERYGENERATOR_H_ */