#ifndef ARRAYNODE_CPP_
#define ARRAYNODE_CPP_

#include "arrayNode.h"
#include <vector>
#include <string.h>
#include "cog.h"
#include "cogTypes.h"
#include "itoa.h"

using namespace std;

template <class T>
arrayNode<T>::arrayNode( T* &d ,int s)
: cog(ARRAY){
	for(int i = 0; i < s; i++){
		data.push_back(d[i]);
	}
}

template <class T>
arrayNode<T>::arrayNode(vector<T> &d)
: cog(ARRAY), data(d){}

template <class T>
int arrayNode<T>::getSize(){
	return data.size();
}

#endif // ARRAYNODE_CPP_
