#ifndef SPLAYPOLICY_H_
#define SPLAYPOLICY_H_

#include "cog.h"
#include "policy.h"
#include "policy.cpp"

template <class T>
class splayPolicy: public policy<T> {
	private:
		unsigned int nodeReadcount;
	public:
		splayPolicy();
		void afterInsert(cog* &node);
		void beforeIterator	(cog* &node);
};

#endif /* SPLAYPOLICY_H_ */