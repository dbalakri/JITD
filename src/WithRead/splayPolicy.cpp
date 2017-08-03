#ifndef SPLAYPOLICY_CPP_
#define SPLAYPOLICY_CPP_

#include "splayPolicy.h"
#include <vector>
#include "cog.h"
#include "cogTypes.h"

using namespace std;


template <class T>
splayPolicy<T>::splayPolicy(){}

template <class T>
void splayPolicy<T>::afterInsert (cog* &node){
	if(node->getType() == CONCAT)
		node->setReadcount(((concatNode*)node)->getLeft()->getReadcount()+((concatNode*)node)->getRight()->getReadcount());
}

template <class T>
void splayPolicy<T>::beforeIterator (cog* &node){
	nodeReadcount = node->getReadcount();
	switch(node->getType()){
		case BTREE:{
					if(((btreeNode<T>*)node)->getLeft()->getReadcount() >= (2/3)*node->getReadcount() && ((btreeNode<T>*)node)->getLeft()->getType() == BTREE){
						btreeNode<T>* lhs = ((btreeNode<T>*)((btreeNode<T>*)node)->getLeft());
						cog* a = lhs->getLeft();
						cog* b = lhs->getRight();
						cog* c = ((btreeNode<T>*)node)->getRight();
						if (a->getReadcount()>2*c->getReadcount()){
							cog* newR = new btreeNode<T>(((btreeNode<T>*)node)->getKey(),b,c);
							newR->setReadcount(b->getReadcount()+c->getReadcount());
							delete node;
							node = new btreeNode<T>(lhs->getKey(), a, newR);
							node->setReadcount(newR->getReadcount()+a->getReadcount());
						}
						
					}
					else if(((btreeNode<T>*)node)->getRight()->getReadcount() >= (2/3)*node->getReadcount() && ((btreeNode<T>*)node)->getRight()->getType() == BTREE){
						btreeNode<T>* rhs = ((btreeNode<T>*)((btreeNode<T>*)node)->getRight());
						cog* a = ((btreeNode<T>*)node)->getLeft();
						cog* b = rhs->getLeft();
						cog* c = rhs->getRight();
						if (c->getReadcount()>2*a->getReadcount()){
							
							cog* newL = new btreeNode<T>(((btreeNode<T>*)node)->getKey(),a,b);
							newL->setReadcount(a->getReadcount()+b->getReadcount());
							delete node;
							node = new btreeNode<T>(rhs->getKey(), newL, c);
							node->setReadcount(newL->getReadcount()+c->getReadcount());
						}
					}
					return;
				}
	}
}

#endif /* SPLAYPOLICY_CPP_ */