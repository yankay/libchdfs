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
	DFSClient(const libhadoop::Configuration& conf);

	DFSClient(const libhadoop::InetSocketAddress& nameNodeAddr,
			const libhadoop::Configuration& conf);

	DFSClient(const libhadoop::InetSocketAddress& nameNodeAddr,
			const libhadoop::Configuration& conf,
			const libhadoop::FileSystemStatistics& stats);

	virtual ~DFSClient();

private:
	DFSClient();

	void init(const libhadoop::InetSocketAddress& nameNodeAddr,
			const libhadoop::ClientProtocol& rpcNamenode,
			const libhadoop::Configuration& conf,
			const libhadoop::FileSystemStatistics& stats);

};

} /* namespace libhadoop */
#endif /* DFSCLIENT_H_ */
