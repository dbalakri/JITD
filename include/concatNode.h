#ifndef CONCATNODE_H_
#define CONCATNODE_H_

#include "cog.h"

class concatNode: public cog {
	public:
		cog* left;
		cog* right;
		concatNode( cog* &l, cog* &r );
		cog* getLeft();
		cog* getRight();
		void setLeft(cog* &l);
		void setRight(cog* &r);
};

#endif /* CONCATNODE_H_ */
