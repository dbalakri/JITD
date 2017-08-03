#ifndef POLICY_H_
#define POLICY_H_

#include "cog.h"

template <class T>
class policy {
	public:
		virtual void beforeInsert (cog* &root);
		virtual void afterInsert (cog* &root);
		virtual void beforeDelete (cog* &root);
		virtual void afterDelete (cog* &root);
		virtual void beforeRootIterator (cog* &root);
		virtual void beforeIterator	(cog* &node);
		virtual void afterIterator	(cog* &node);
		virtual void idle (cog* &root);
};

#endif /* POLICY_H_ */
