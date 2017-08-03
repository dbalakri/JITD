#ifndef ARRAYNODE_H_
#define ARRAYNODE_H_

#include <vector>
#include "cog.h"

using namespace std;

template <class T>
class arrayNode: public cog {
	public:
		vector<T>* data;
		arrayNode( T* &d, int s);
		arrayNode(vector<T> &d);
		int getSize();
};

#endif /* ARRAYNODE_H_ */
