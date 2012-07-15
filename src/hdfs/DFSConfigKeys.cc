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
const string DFSConfigKeys::DFS_CLIENT_READ_SHORTCIRCUIT_KEY = "dfs.client.read.shortcircuit";
const bool DFSConfigKeys::DFS_CLIENT_READ_SHORTCIRCUIT_DEFAULT = false;

const string DFSConfigKeys::DFS_CLIENT_USE_DN_HOSTNAME = "dfs.client.use.datanode.hostname";
const bool DFSConfigKeys::DFS_CLIENT_USE_DN_HOSTNAME_DEFAULT = false;
const string DFSConfigKeys::DFS_CLIENT_LOCAL_INTERFACES = "dfs.client.local.interfaces";

} /* namespace libhadoop */
