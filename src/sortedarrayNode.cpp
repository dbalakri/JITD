#ifndef SORTEDARRAYNODE_CPP_
#define SORTEDARRAYNODE_CPP_

#include "sortedarrayNode.h"
#include <vector>
#include "cog.h"
#include "cogTypes.h"
#include "itoa.h"

using namespace std;

template <class T>
sortedarrayNode<T>::sortedarrayNode( T* &d, int s)
: cog(SORTED_ARRAY){
	for(int i = 0; i < s; i++){
		data.push_back(d[i]);
	}
}

template <class T>
sortedarrayNode<T>::sortedarrayNode(vector<T> &d)
: cog(SORTED_ARRAY), data(d){}

template <class T>
int sortedarrayNode<T>::getSize(){
	return data.size();
}

#endif // SORTEDARRAYNODE_CPP_
