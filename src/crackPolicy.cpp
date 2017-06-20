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
						vector<T> left;
						vector<T> right;
						T max =((arrayNode<T>*)node)->data[0];
						T key =((arrayNode<T>*)node)->data[0];
						for(int i = 0; i <((arrayNode<T>*)node)->data.size(); i++){
							if(max <((arrayNode<T>*)node)->data[i]){
								key = max;
								max =((arrayNode<T>*)node)->data[i];
								break;
							}
							else if(((arrayNode<T>*)node)->data[i] < max){
								key =((arrayNode<T>*)node)->data[i];
								break;
							}
						}

						if(key == max){
							return;
						}

						for (int i = 0; i <((arrayNode<T>*)node)->data.size(); i++){
							if(((arrayNode<T>*)node)->data[i] > key){
								right.push_back(((arrayNode<T>*)node)->data[i]);
							}
							else left.push_back(((arrayNode<T>*)node)->data[i]);
						}
						if(left.size() != 0 && right.size() != 0){
							cog* l = new arrayNode<T>(left);
							cog* r = new arrayNode<T>(right);
							delete node;
							node = new btreeNode<T>(key, l, r);
						}
					}
					return;
				}
		// case SORTED_ARRAY:{
		// 			if(((sortedarrayNode<T>*)node)->getSize() >= minSize){
		// 				vector<T>((arrayNode<T>*)node)->data = ((sortedarrayNode<T>*)node)->getData();
		// 				T key =((arrayNode<T>*)node)->data[data.size()/2];
		// 				vector<T> left;
		// 				vector<T> right;
		// 				for (int i = 0; i <((arrayNode<T>*)node)->data.size(); i++){
		// 					if(((arrayNode<T>*)node)->data[i] > key){
		// 						right.push_back(((arrayNode<T>*)node)->data[i]);
		// 					}
		// 					else left.push_back(((arrayNode<T>*)node)->data[i]);
		// 				}
		// 				if(left.size() != 0 && right.size() != 0){
		// 					cog* l = new sortedarrayNode<T>(left);
		// 					cog* r = new sortedarrayNode<T>(right);
		// 					node = new btreeNode<T>(key, l, r);
		// 				}
		// 			}
		// 			return;
		// 		}
	}
}

#endif /* CRACKPOLICY_CPP_ */