/*
 * DFSClient.h
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#ifndef DFSCLIENT_H_
#define DFSCLIENT_H_

#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <memory>
#include <tr1/memory>
#include <exception>

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
#include "ipc/RPC.h"
#include "ipc/VersionedProtocol.h"
#include "DFSConfigKeys.h"
#include "SocketCache.h"

using namespace std;
using namespace std::tr1;

namespace libhadoop {

class DFSClient {
public:

	static const int32_t MAX_BLOCK_ACQUIRE_FAILURES;
	static const int64_t DEFAULT_BLOCK_SIZE;

	shared_ptr<ClientProtocol> namenode;
	UserGroupInformation& ugi;
	bool clientRunning;
	string clientName;

	SocketFactory socketFactory;
	SocketCache socketCache;

	DFSClient(const Configuration& conf);

	DFSClient(const InetSocketAddress& nameNodeAddr, const Configuration& conf);

	DFSClient(const InetSocketAddress& nameNodeAddr, const Configuration& conf,
			const FileSystemStatistics& stats);

	bool delete_m(const string& src, bool recursive);

	virtual ~DFSClient();

private:
	shared_ptr<ClientProtocol> rpcNamenode;

	Configuration conf;
	FileSystemStatistics stats;
	int32_t socketTimeout;
	int32_t datanodeWriteTimeout;
	int32_t writePacketSize;
	int32_t maxBlockAcquireFailures;
	int64_t defaultBlockSize;
	int16_t defaultReplication;

	bool shortCircuitLocalReads;
	bool connectToDnViaHostname;

	vector<InetSocketAddress> localInterfaceAddrs;

	DFSClient();

	void init(const InetSocketAddress& nameNodeAddr,
			shared_ptr<ClientProtocol> rpcNamenode, const Configuration& conf,
			const FileSystemStatistics& stats);

	static int32_t getMaxBlockAcquireFailures(const Configuration& conf);

	static shared_ptr<ClientProtocol> createRPCNamenode(
			const InetSocketAddress& nameNodeAddr, const Configuration& conf,
			const UserGroupInformation& ugi);

	static shared_ptr<ClientProtocol> createNamenode(shared_ptr<ClientProtocol> rpcNamenode);

	static vector<InetSocketAddress> getLocalInterfaceAddrs(
			const vector<string>& interfaceNames);

	void checkOpen();
};

} /* namespace libhadoop */
#endif /* DFSCLIENT_H_ */
