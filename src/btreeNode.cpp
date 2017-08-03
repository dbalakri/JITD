#ifndef BTREENODE_CPP_
#define BTREENODE_CPP_

#include "btreeNode.h"
#include "cog.h"
#include "cogTypes.h"

using namespace std;

template <class T>
btreeNode<T>::btreeNode( T k, cog* &l, cog* &r )
: cog(BTREE),
key(k),
left(l),
right(r)
{}

template <class T>
T btreeNode<T>::getKey(){
	return key;
}

template <class T>
cog* btreeNode<T>::getLeft(){
	return left;
}

template <class T>
cog* btreeNode<T>::getRight(){
	return right;
}

#endif // BTREENODE_CPP_
