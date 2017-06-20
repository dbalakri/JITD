#ifndef RANDUNIFORM_H_
#define RANDUNIFORM_H_

#include <random>

using namespace std;

class randUniform {
	private:
		default_random_engine generator;
		uniform_int_distribution<int> distribution;
		int min;
		int max;
	public:
	    randUniform(int seed, int x, int y);
	    int getRand();
	    
};

#endif /* RANDUNIFORM_H_ */
