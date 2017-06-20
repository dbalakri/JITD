#ifndef SORTPOLICY_H_
#define SORTPOLICY_H_

#include "cog.h"
#include "policy.h"
#include "policy.cpp"

template <class T>
class sortPolicy: public policy<T> {
	public:
		void beforeIterator	(cog* &node);
};

#endif /* SORTPOLICY_H_ */