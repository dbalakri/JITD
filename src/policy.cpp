#ifndef POLICY_CPP_
#define POLICY_CPP_

#include "policy.h"
#include "cog.h"

using namespace std;

template <class T>
void policy<T>::beforeInsert (cog* &root){}

template <class T>
void policy<T>::afterInsert (cog* &root){}

template <class T>
void policy<T>::beforeDelete (cog* &root){}

template <class T>
void policy<T>::afterDelete (cog* &root){}

template <class T>
void policy<T>::beforeRootIterator (cog* &root){}

template <class T>
void policy<T>::beforeIterator	(cog* &node){}

template <class T>
void policy<T>::afterIterator	(cog* &node){}

template <class T>
void policy<T>::idle (cog* &root){}

#endif // POLICY_CPP_
