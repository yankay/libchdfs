/*
 * DFSClient.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#include "DFSClient.h"

using namespace std;

namespace libhadoop {

const int64_t DFSClient::DEFAULT_BLOCK_SIZE = 64 * 1024 * 1024;

DFSClient::DFSClient(const Configuration& conf) :
		ugi(UserGroupInformation::getCurrentUser()) {
	init(NameNode::getAddress(conf), ClientProtocol(), conf,
			FileSystemStatistics());
}

DFSClient::DFSClient(const InetSocketAddress& nameNodeAddr,
		const Configuration& conf) :
		ugi(UserGroupInformation::getCurrentUser()) {
	init(nameNodeAddr, ClientProtocol(), conf, FileSystemStatistics());
}

DFSClient::DFSClient(const InetSocketAddress& nameNodeAddr,
		const Configuration& conf, const FileSystemStatistics& stats) :
		ugi(UserGroupInformation::getCurrentUser()) {
	init(nameNodeAddr, ClientProtocol(), conf, stats);
}

void DFSClient::init(const InetSocketAddress& nameNodeAddr,
		const ClientProtocol& rpcNamenode, const Configuration& conf,
		const FileSystemStatistics& stats) {
	this->conf = conf;
	this->stats = stats;
	socketTimeout = conf.getInt("dfs.socket.timeout",
			HdfsConstants::READ_TIMEOUT);
	datanodeWriteTimeout = conf.getInt("dfs.datanode.socket.write.timeout",
			HdfsConstants::WRITE_TIMEOUT);
	socketFactory = NetUtils::getSocketFactory(conf, "ClientProtocol");
	// dfs.write.packet.size is an internal config variable
	writePacketSize = conf.getInt("dfs.write.packet.size", 64 * 1024);
	maxBlockAcquireFailures = DFSClient::getMaxBlockAcquireFailures(conf);

	string taskId = conf.get("mapred.task.id");
	if (!taskId.empty()) {
		string dfsclientStr = "DFSClient_";
		clientName = dfsclientStr + taskId;
	} else {
		stringstream dfsclientStr;
		dfsclientStr << "DFSClient_" << rand() % 65535;
		clientName = dfsclientStr.str();
	}

	defaultBlockSize = conf.getLong("dfs.block.size", DEFAULT_BLOCK_SIZE);
	defaultReplication = (int16_t) conf.getInt("dfs.replication", 3);

	socketCache = SocketCache(
			conf.getInt(DFSConfigKeys::DFS_CLIENT_SOCKET_CACHE_CAPACITY_KEY,
					DFSConfigKeys::DFS_CLIENT_SOCKET_CACHE_CAPACITY_DEFAULT));

//	if (nameNodeAddr != null && rpcNamenode == null) {
//		this.rpcNamenode = createRPCNamenode(nameNodeAddr, conf, ugi);
//		this.namenode = createNamenode(this.rpcNamenode);
//	} else if (nameNodeAddr == null && rpcNamenode != null) {
//		//This case is used for testing.
//		this.namenode = this.rpcNamenode = rpcNamenode;
//	} else {
//		throw new IllegalArgumentException(
//				"Expecting exactly one of nameNodeAddr and rpcNamenode being null: "
//						+ "nameNodeAddr=" + nameNodeAddr + ", rpcNamenode="
//						+ rpcNamenode);
//	}
//	// read directly from the block file if configured.
//	this.shortCircuitLocalReads = conf.getBoolean(
//			DFSConfigKeys.DFS_CLIENT_READ_SHORTCIRCUIT_KEY,
//			DFSConfigKeys.DFS_CLIENT_READ_SHORTCIRCUIT_DEFAULT);
//	if (LOG.isDebugEnabled()) {
//		LOG.debug("Short circuit read is " + shortCircuitLocalReads);
//	}
//	this.connectToDnViaHostname = conf.getBoolean(
//			DFSConfigKeys.DFS_CLIENT_USE_DN_HOSTNAME,
//			DFSConfigKeys.DFS_CLIENT_USE_DN_HOSTNAME_DEFAULT);
//	if (LOG.isDebugEnabled()) {
//		LOG.debug(
//				"Connect to datanode via hostname is "
//						+ connectToDnViaHostname);
//	}
//	String localInterfaces[] = conf.getTrimmedStrings(
//			DFSConfigKeys.DFS_CLIENT_LOCAL_INTERFACES);
//	this.localInterfaceAddrs = getLocalInterfaceAddrs(localInterfaces);
//	if (LOG.isDebugEnabled() && 0 != localInterfaces.length) {
//		LOG.debug(
//				"Using local interfaces ["
//						+ Joiner.on(',').join(localInterfaces)
//						+ "] with addresses ["
//						+ Joiner.on(',').join(localInterfaceAddrs) + "]");
//	}
}
const int32_t DFSClient::MAX_BLOCK_ACQUIRE_FAILURES = 3;

int32_t DFSClient::getMaxBlockAcquireFailures(const Configuration& conf) {
	return conf.getInt("dfs.client.max.block.acquire.failures",
			MAX_BLOCK_ACQUIRE_FAILURES);
}

DFSClient::~DFSClient() {
}

} /* namespace libhadoop */
