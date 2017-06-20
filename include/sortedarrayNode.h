#ifndef SORTEDARRAYNODE_H_
#define SORTEDARRAYNODE_H_

#include <vector>
#include "cog.h"

using namespace std;

template <class T>
class sortedarrayNode: public cog {
	public:
		vector<T> data;
		sortedarrayNode( T* &d, int s);
		sortedarrayNode( vector<T> &d);
		int getSize();
};

#endif /* SORTEDARRAYNODE_H_ */
