#include "concatNode.h"
#include "cog.h"
#include "cogTypes.h"

using namespace std;

concatNode::concatNode( cog* &l, cog* &r )
: cog(CONCAT),
left(l),
right(r)
{}

cog* concatNode::getLeft(){
	return left;
}

cog* concatNode::getRight(){
	return right;
}

void concatNode::setLeft(cog* &l){
	left = l;
}

void concatNode::setRight(cog* &r){
	right = r;
}
