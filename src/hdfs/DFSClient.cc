/*
 * DFSClient.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#include "DFSClient.h"

namespace libhadoop {

DFSClient::DFSClient(const Configuration& conf) {
//	this(NameNode.getAddress(conf), conf);
}

DFSClient::DFSClient(const InetSocketAddress& nameNodeAddr,
		const Configuration& conf) {
//	this(nameNodeAddr, conf, null);
}

DFSClient::DFSClient(const InetSocketAddress& nameNodeAddr,
		const Configuration& conf,
		const FileSystemStatistics& stats) {
//	this(nameNodeAddr, null, conf, stats);
}

void init(const InetSocketAddress& nameNodeAddr,
		const ClientProtocol& rpcNamenode,
		const Configuration& conf,
		const FileSystemStatistics& stats) {

}

DFSClient::~DFSClient() {
}

} /* namespace libhadoop */
