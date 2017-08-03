#include "printTree.h"
#include "cog.h"
#include "cogTypes.h"
#include "data.h"
#include <iostream>

using namespace std;

void printTree(cog* it,int depth){
	switch(it->getType()){
		case ARRAY:{
				for (int i = 0; i < depth; ++i){
					cout << "\t";
				}
				cout << "(" << it->getReadcount() << ")" ;
				cout << "ARRAY:" << ((arrayNode<data>*)it)->data->size() << "{" << ((arrayNode<data>*)it)->data->at(0).key;
				for (int i = 1; i < ((arrayNode<data>*)it)->data->size() ; ++i){
					cout << "," << ((arrayNode<data>*)it)->data->at(i).key;
				}
				cout << "}" << endl;
				return;
			}
		case SORTED_ARRAY:{
				for (int i = 0; i < depth; ++i){
					cout << "\t";
				}
				cout << "(" << it->getReadcount() << ")" ;
				cout << "SORTED_ARRAY:" << ((sortedarrayNode<data>*)it)->data->size() << "{" << ((sortedarrayNode<data>*)it)->data->at(0).key;
				for (int i = 1; i < ((sortedarrayNode<data>*)it)->data->size(); ++i){
					cout << "," << ((sortedarrayNode<data>*)it)->data->at(i).key;
				}
				cout << "}" << endl;
				return;
			}
		case BTREE:
			printTree(((btreeNode<data>*)it)->left, depth+1);
			for (int i = 0; i < depth; ++i){
				cout << "\t";
			}
			cout << "(" << it->getReadcount() << ")" ;
			cout << "BTREE:" << ((btreeNode<data>*)it)->getKey().key << "{" << endl;
			printTree(((btreeNode<data>*)it)->right, depth+1);
			return;
		case CONCAT:
			printTree(((concatNode*)it)->left, depth+1);
			for (int i = 0; i < depth; ++i){
				cout << "\t";
			}
			cout << "(" << it->getReadcount() << ")" ;
			cout << "CONCAT:" << "{" <<  endl;
			printTree(((concatNode*)it)->right, depth+1);
			return;
	}
}