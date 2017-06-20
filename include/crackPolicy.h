#ifndef CRACKPOLICY_H_
#define CRACKPOLICY_H_

#include "cog.h"
#include "policy.h"
#include "policy.cpp"

template <class T>
class crackPolicy: public policy<T> {
	private:
		int minSize;
	public:
		crackPolicy(int s);
		void beforeIterator	(cog* &node);
};

#endif /* CRACKPOLICY_H_ */
