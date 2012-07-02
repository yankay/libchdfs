/*
 * DFSClient.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#include "DFSClient.h"

namespace libhadoop {

DFSClient::DFSClient(const libhadoop::Configuration& conf) {
//	this(NameNode.getAddress(conf), conf);
}

DFSClient::DFSClient(const libhadoop::InetSocketAddress& nameNodeAddr,
		const libhadoop::Configuration& conf) {
//	this(nameNodeAddr, conf, null);
}

DFSClient::DFSClient(const libhadoop::InetSocketAddress& nameNodeAddr,
		const libhadoop::Configuration& conf,
		const libhadoop::FileSystemStatistics& stats) {
//	this(nameNodeAddr, null, conf, stats);
}

void init(const libhadoop::InetSocketAddress& nameNodeAddr,
		const libhadoop::ClientProtocol& rpcNamenode,
		const libhadoop::Configuration& conf,
		const libhadoop::FileSystemStatistics& stats) {

}

DFSClient::~DFSClient() {
}

} /* namespace libhadoop */
