#ifndef HYBRIDPOLICY_CPP_
#define HYBRIDPOLICY_CPP_

#include "hybridPolicy.h"
#include <vector>
#include "cog.h"
#include "policy.h"

using namespace std;

template <class T>
hybridPolicy<T>::hybridPolicy(vector<policy<T>* > p): policies(p){}

template <class T>
void hybridPolicy<T>::beforeInsert (cog* &node){
	for(int it = 0; it < policies.size(); it++){
		policies[it]->beforeInsert(node);
	}
}
template <class T>
void hybridPolicy<T>::afterInsert (cog* &node){
	for(int it = 0; it < policies.size(); it++){
		policies[it]->afterInsert(node);
	}
}
template <class T>
void hybridPolicy<T>::beforeDelete (cog* &node){
	for(int it = 0; it < policies.size(); it++){
		policies[it]->beforeDelete(node);
	}
}
template <class T>
void hybridPolicy<T>::afterDelete (cog* &node){
	for(int it = 0; it < policies.size(); it++){
		policies[it]->afterDelete(node);
	}
}
template <class T>
void hybridPolicy<T>::beforeRootIterator (cog* &node){
	for(int it = 0; it < policies.size(); it++){
		policies[it]->beforeRootIterator(node);
	}
}
template <class T>
void hybridPolicy<T>::beforeIterator	(cog* &node){
	for(int it = 0; it < policies.size(); it++){
		policies[it]->beforeIterator(node);
	}
}
template <class T>
void hybridPolicy<T>::afterIterator	(cog* &node){
	for(int it = 0; it < policies.size(); it++){
		policies[it]->afterIterator(node);
	}
}
template <class T>
void hybridPolicy<T>::idle (cog* &node){
	for(int it = 0; it < policies.size(); it++){
		policies[it]->idle(node);
	}
}

#endif /* HYBRIDPOLICY_CPP_ */