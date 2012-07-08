/*
 * DFSClient.h
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#ifndef DFSCLIENT_H_
#define DFSCLIENT_H_

#include <stdlib.h>

#include "conf/Configuration.h"
#include "net/InetSocketAddress.h"
#include "fs/FileSystem.h"
#include "hdfs/protocol/ClientProtocol.h"
#include "server/namenode/NameNode.h"
#include "server/common/HdfsConstants.h"
#include "net/SocketFactory.h"
#include "security/UserGroupInformation.h"

using namespace std;

namespace libhadoop {

class DFSClient {
public:
	DFSClient(const Configuration& conf);

	DFSClient(const InetSocketAddress& nameNodeAddr, const Configuration& conf);

	DFSClient(const InetSocketAddress& nameNodeAddr, const Configuration& conf,
			const FileSystemStatistics& stats);

	virtual ~DFSClient();

	static const int32_t MAX_BLOCK_ACQUIRE_FAILURES;

private:
	Configuration conf;
	FileSystemStatistics stats;
	int32_t socketTimeout;
	int32_t datanodeWriteTimeout;
	int32_t writePacketSize;
	int32_t maxBlockAcquireFailures;
	SocketFactory socketFactory;
	UserGroupInformation ugi;

	DFSClient();

	void init(const InetSocketAddress& nameNodeAddr,
			const ClientProtocol& rpcNamenode, const Configuration& conf,
			const FileSystemStatistics& stats);

	static int32_t getMaxBlockAcquireFailures(const Configuration& conf);

};

} /* namespace libhadoop */
#endif /* DFSCLIENT_H_ */
