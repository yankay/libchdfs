/*
 * DFSConfigKeys.h
 *
 *  Created on: Jul 8, 2012
 *      Author: yank1
 */

#ifndef DFSCONFIGKEYS_H_
#define DFSCONFIGKEYS_H_

#include <stdlib.h>
#include <string>

using namespace std;

namespace libhadoop {

class DFSConfigKeys {

public:
	static const string DFS_CLIENT_SOCKET_CACHE_CAPACITY_KEY;
	static const int32_t DFS_CLIENT_SOCKET_CACHE_CAPACITY_DEFAULT;

};

}
/* namespace libhadoop */
#endif /* DFSCONFIGKEYS_H_ */

