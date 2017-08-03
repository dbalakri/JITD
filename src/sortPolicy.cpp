#ifndef SORTPOLICY_CPP_
#define SORTPOLICY_CPP_

#include "sortPolicy.h"
#include <vector>
#include <algorithm>
#include "cog.h"
#include "cogTypes.h"

using namespace std;

template <class T>
void sortPolicy<T>::beforeIterator (cog* &node){
	switch(node->getType()){
		case ARRAY:{
					vector<T>* v = ((arrayNode<T>*)node)->data;
					delete node;
					sort(v->begin(), v->end());
					node = new sortedarrayNode<T>(*v);
				}
	}
}

#endif /* SORTPOLICY_CPP_ */