#ifndef JITD_CPP_
#define JITD_CPP_

#include "jitd.h"
#include <vector>
#include "cog.h"
#include "cogTypes.h"
#include "policy.h"
#include "binarySearch.h"
#include "binarySearch.cpp"

using namespace std;

template <class T>
jitd<T>::jitd(policy<T>* pl): root(0), p(pl){}

template <class T>
jitd<T>::jitd(cog* &r, policy<T>* pl): root(r), p(pl){}

template <class T>
cog* jitd<T>::getRoot(){
	return root;
}

template <class T>
void jitd<T>::insert(T* &data, int size){
	p->beforeInsert(root);
	vector<T> dataArray;
	for(int i = 0; i < size; i++){
		dataArray.push_back(*(data + i));
	}
	cog* arraynode = new arrayNode<T>(dataArray);
	if(root == 0){
		root = arraynode;
	}
	else {
		cog* concatnode = new concatNode(arraynode, root);
		root = concatnode;
	}
	p->afterInsert(root);
}

template <class T>
void jitd<T>::scan(T low, T high, vector<T> &result){
	if(high < low){
		T temp = low;
		low = high;
		high = temp;
	}
	p->beforeRootIterator(root);
	scan(root, low, high, result);
	return;
}

template <class T>
void jitd<T>::scan(cog* &node, T low, T high, vector<T> &result){
	p->beforeIterator(node);
	switch(node->getType()){
		case ARRAY:{
					for(int i = 0; i < ((arrayNode<T>*)node)->data.size(); i++){
						if((((arrayNode<T>*)node)->data[i] >= low && ((arrayNode<T>*)node)->data[i] < high)||( ((arrayNode<T>*)node)->data[i]==low && low == high )){
							result.push_back(((arrayNode<T>*)node)->data[i]);
						}
					}
					p->afterIterator(node);
					return;
				}
		case SORTED_ARRAY:{
					int n = ((sortedarrayNode<T>*)node)->data.size();
					int l = binarySearch<T>(((sortedarrayNode<T>*)node)->data,0,n,low);
					if(l < n && l >= 0) {
						for(int i = l; i < ((sortedarrayNode<T>*)node)->data.size(); i++){
							if((((sortedarrayNode<T>*)node)->data[i] >= low && ((sortedarrayNode<T>*)node)->data[i] < high)||( ((sortedarrayNode<T>*)node)->data[i]==low && low == high )){
								result.push_back(((sortedarrayNode<T>*)node)->data[i]);
							}
						}
					}
					p->afterIterator(node);
					return;
				}
		case BTREE:{
					const T k = ((btreeNode<T>*)node)->getKey();
					if(k < high && low <= k){
						scan(((btreeNode<T>*)node)->left, low, high, result);
						scan(((btreeNode<T>*)node)->right, low, high, result);
					}
					else if(low > k){
						scan(((btreeNode<T>*)node)->right, low, high, result);
					}
					else{
						scan(((btreeNode<T>*)node)->left, low, high, result);
					}
					p->afterIterator(node);
					return;
				}
		case CONCAT:{
					scan(((concatNode*)node)->left, low, high, result);
					scan(((concatNode*)node)->right, low, high, result);
					p->afterIterator(node);
					return;
				}
	}
}
#endif /* JITD_CPP_ */
