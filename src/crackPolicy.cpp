#ifndef CRACKPOLICY_CPP_
#define CRACKPOLICY_CPP_

#include "crackPolicy.h"
#include <vector>
#include "cog.h"
#include "cogTypes.h"

using namespace std;

template <class T>
crackPolicy<T>::crackPolicy(int s): minSize(s) {}

template <class T>
void crackPolicy<T>::beforeIterator (cog* &node){
	switch(node->getType()){
		case ARRAY:{
					if(((arrayNode<T>*)node)->getSize() >= minSize){
						T max =((arrayNode<T>*)node)->data->at(0);
						T key =((arrayNode<T>*)node)->data->at(0);
						for(typename vector<T>::iterator it = ((arrayNode<T>*)node)->data->begin(); it != ((arrayNode<T>*)node)->data->end(); it++){
							if(max < *it){
								key = max;
								max = *it;
								break;
							}
							else if(*it < max){
								key = *it;
								break;
							}
						}

						if(key == max){
							return;
						}
						vector<T>* left = new vector<T>(((arrayNode<T>*)node)->data->size());
						vector<T>* right = new vector<T>(((arrayNode<T>*)node)->data->size());
						
						for(typename vector<T>::iterator it = ((arrayNode<T>*)node)->data->begin(); it != ((arrayNode<T>*)node)->data->end(); it++){
							if(*it > key){
								right->push_back(*it);
							}
							else left->push_back(*it);
						}
						if(left->size() != 0 && right->size() != 0){
							cog* l = new arrayNode<T>(*left);
							cog* r = new arrayNode<T>(*right);
							// delete ((arrayNode<T>*)node)->data;
							delete node;
							node = new btreeNode<T>(key, l, r);
						}
					}
					return;
				}
	}
}

#endif /* CRACKPOLICY_CPP_ */