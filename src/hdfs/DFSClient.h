/*
 * DFSClient.h
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#ifndef DFSCLIENT_H_
#define DFSCLIENT_H_

#include "conf/Configuration.h"
#include "net/InetSocketAddress.h"
#include "fs/FileSystem.h"
#include "hdfs/protocol/ClientProtocol.h"

namespace libhadoop {

class DFSClient {
public:
	DFSClient(const Configuration& conf);

	DFSClient(const InetSocketAddress& nameNodeAddr,
			const Configuration& conf);

	DFSClient(const InetSocketAddress& nameNodeAddr,
			const Configuration& conf,
			const FileSystemStatistics& stats);

	virtual ~DFSClient();

private:
	DFSClient();

	void init(const InetSocketAddress& nameNodeAddr,
			const ClientProtocol& rpcNamenode,
			const Configuration& conf,
			const FileSystemStatistics& stats);

};

} /* namespace libhadoop */
#endif /* DFSCLIENT_H_ */
