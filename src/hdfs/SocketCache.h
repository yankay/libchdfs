/*
 * SocketCache.h
 *
 *  Created on: Jul 8, 2012
 *      Author: yank1
 */

#ifndef SOCKETCACHE_H_
#define SOCKETCACHE_H_

#include <string>
#include <stdlib.h>

namespace libhadoop {

class SocketCache {

public:
	SocketCache() :
			capacity(16) {

	}

	SocketCache(int32_t capacity) :
			capacity(capacity) {
	}
private:
	int32_t capacity;
};

}
/* namespace libhadoop */
#endif /* SOCKETCACHE_H_ */
