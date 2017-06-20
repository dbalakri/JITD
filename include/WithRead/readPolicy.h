#ifndef READPOLICY_H_
#define READPOLICY_H_

#include "cog.h"
#include "policy.h"
#include "policy.cpp"

template <class T>
class readPolicy: public policy<T> {
	public:
		void afterIterator (cog* &node);
};


#endif /* READPOLICY_H_ */