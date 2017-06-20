#ifndef READPOLICY_CPP_
#define READPOLICY_CPP_

#include "readPolicy.h"
#include "cog.h"
#include "cogTypes.h"

using namespace std;

template <class T>
void readPolicy<T>::afterIterator (cog* &node){
	switch(node->getType()){
		case ARRAY:
			node->setReadcount(node->getReadcount()+1);
			return;
		case SORTED_ARRAY:
			node->setReadcount(node->getReadcount()+1);
			return;
		case CONCAT:
			node->setReadcount(((concatNode*)node)->getLeft()->getReadcount()+((concatNode*)node)->getRight()->getReadcount());
			return;
		case BTREE:
			node->setReadcount(((btreeNode<T>*)node)->getLeft()->getReadcount()+((btreeNode<T>*)node)->getRight()->getReadcount());
			return;
		}
}

#endif /* READPOLICY_CPP_ */