#ifndef HYBRIDPOLICY_H_
#define HYBRIDPOLICY_H_

#include <vector>
#include "cog.h"
#include "policy.h"
#include "policy.cpp"

using namespace std;

template <class T>
class hybridPolicy: public policy<T> {
	private:
		vector<policy<T>* > policies;
	public:
		hybridPolicy(vector<policy<T>* > p);
		void beforeInsert (cog* &node);
		void afterInsert (cog* &node);
		void beforeDelete (cog* &node);
		void afterDelete (cog* &node);
		void beforeRootIterator (cog* &node);
		void beforeIterator	(cog* &node);
		void afterIterator	(cog* &node);
		void idle (cog* &node);
};

#endif /* HYBRIDPOLICY_H_ */