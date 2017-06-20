#ifndef TESTER_H_
#define TESTER_H_

#include "jitd.h"
#include "data.h"
#include <vector>

using namespace std;

class tester {
	private:
		jitd<data>* myJitd;
		int i_seed;
		int s_seed;
	public:
		vector<unsigned long int> runtimes;
		long int total_time = 0;
		tester(int insert_seed, int scan_seed, jitd<data>* mj);
		void insert(int queryCount, int dataSize, int dataMin, int dataMax);
		void scan(int queryCount, int dataMin, int dataMax, int rangeSize, double hhDataRange, double hhProbability);
		void printJitd();
};


#endif /* TESTER_H_ */