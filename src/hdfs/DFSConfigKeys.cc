/*
 w * DFSConfigKeys.cc
 *
 *  Created on: Jul 8, 2012
 *      Author: yank1
 */

#include "DFSConfigKeys.h"

namespace libhadoop {
const string DFSConfigKeys::DFS_CLIENT_SOCKET_CACHE_CAPACITY_KEY =
		"dfs.client.socketcache.capacity";
const int32_t DFSConfigKeys::DFS_CLIENT_SOCKET_CACHE_CAPACITY_DEFAULT = 16;
} /* namespace libhadoop */
