/*
 * DFSClient.h
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#ifndef DFSCLIENT_H_
#define DFSCLIENT_H_

#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include "conf/Configuration.h"
#include "net/InetSocketAddress.h"
#include "fs/FileSystem.h"
#include "hdfs/protocol/ClientProtocol.h"
#include "server/namenode/NameNode.h"
#include "server/common/HdfsConstants.h"
#include "net/SocketFactory.h"
#include "security/UserGroupInformation.h"
#include "util/Logger.h"
#include "util/Joiner.h"
#include "DFSConfigKeys.h"
#include "SocketCache.h"

using namespace std;

namespace libhadoop {

class DFSClient {
public:
	ClientProtocol namenode;

	DFSClient(const Configuration& conf);

	DFSClient(const InetSocketAddress& nameNodeAddr, const Configuration& conf);

	DFSClient(const InetSocketAddress& nameNodeAddr, const Configuration& conf,
			const FileSystemStatistics& stats);

	virtual ~DFSClient();

	static const int32_t MAX_BLOCK_ACQUIRE_FAILURES;
	static const int64_t DEFAULT_BLOCK_SIZE;

private:
	Configuration conf;
	FileSystemStatistics stats;
	int32_t socketTimeout;
	int32_t datanodeWriteTimeout;
	int32_t writePacketSize;
	int32_t maxBlockAcquireFailures;
	int64_t defaultBlockSize;
	int16_t defaultReplication;
	SocketFactory socketFactory;
	SocketCache socketCache;
	UserGroupInformation& ugi;
	string clientName;
	ClientProtocol rpcNamenode;
	bool shortCircuitLocalReads;
	bool connectToDnViaHostname;
	vector<InetSocketAddress> localInterfaceAddrs;

	DFSClient();

	void init(const InetSocketAddress& nameNodeAddr,
			const ClientProtocol& rpcNamenode, const Configuration& conf,
			const FileSystemStatistics& stats);

	static int32_t getMaxBlockAcquireFailures(const Configuration& conf);

	static ClientProtocol createRPCNamenode(
			const InetSocketAddress& nameNodeAddr, const Configuration& conf,
			const UserGroupInformation& ugi);

	static ClientProtocol createNamenode(const ClientProtocol& rpcNamenode);

	static vector<InetSocketAddress> getLocalInterfaceAddrs(
			const vector<string>& interfaceNames);

};

} /* namespace libhadoop */
#endif /* DFSCLIENT_H_ */
