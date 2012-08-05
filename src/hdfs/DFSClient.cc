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
const int32_t DFSClient::MAX_BLOCK_ACQUIRE_FAILURES = 3;

DFSClient::DFSClient(const Configuration& conf) :
		ugi(UserGroupInformation::getCurrentUser()), clientRunning(true), conf(
				conf) {
	InetSocketAddress nameNodeAddr(NameNode::getAddress(conf));
	init(nameNodeAddr, createRPCNamenode(nameNodeAddr, conf, ugi), conf,
			FileSystemStatistics());
}

DFSClient::DFSClient(const InetSocketAddress& nameNodeAddr,
		const Configuration& conf) :
		ugi(UserGroupInformation::getCurrentUser()), clientRunning(true), conf(
				conf) {
	init(nameNodeAddr, createRPCNamenode(nameNodeAddr, conf, ugi), conf,
			FileSystemStatistics());
}

DFSClient::DFSClient(const InetSocketAddress& nameNodeAddr,
		const Configuration& conf, const FileSystemStatistics& stats) :
		ugi(UserGroupInformation::getCurrentUser()), clientRunning(true), conf(
				conf) {
	init(nameNodeAddr, createRPCNamenode(nameNodeAddr, conf, ugi), conf, stats);
}

void DFSClient::init(const InetSocketAddress& nameNodeAddr,
		shared_ptr<ClientProtocol> rpcNamenode, const Configuration& conf,
		const FileSystemStatistics& stats) {
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

	this->rpcNamenode = rpcNamenode;
	this->namenode = createNamenode(rpcNamenode);

	// read directly from the block file if configured.
	this->shortCircuitLocalReads = conf.getBoolean(
			DFSConfigKeys::DFS_CLIENT_READ_SHORTCIRCUIT_KEY,
			DFSConfigKeys::DFS_CLIENT_READ_SHORTCIRCUIT_DEFAULT);
	LOG_DEBUG("DFSClient", "Short circuit read is " << shortCircuitLocalReads);
	this->connectToDnViaHostname = conf.getBoolean(
			DFSConfigKeys::DFS_CLIENT_USE_DN_HOSTNAME,
			DFSConfigKeys::DFS_CLIENT_USE_DN_HOSTNAME_DEFAULT);
	LOG_DEBUG("DFSClient",
			"Connect to datanode via hostname is "<< connectToDnViaHostname);

	vector < string > localInterfaces = conf.getTrimmedStringCollection(
			DFSConfigKeys::DFS_CLIENT_LOCAL_INTERFACES);
	this->localInterfaceAddrs = DFSClient::getLocalInterfaceAddrs(
			localInterfaces);
	if (0 != localInterfaces.size()) {
		LOG_DEBUG("DFSClient",
				"Using local interfaces ["<< Joiner::on(",").join(localInterfaces) << "] with addresses [" << Joiner::on(",").join(InetSocketAddress::toStrings(localInterfaceAddrs)) + "]");
	}
}

int32_t DFSClient::getMaxBlockAcquireFailures(const Configuration& conf) {
	return conf.getInt("dfs.client.max.block.acquire.failures",
			MAX_BLOCK_ACQUIRE_FAILURES);
}

DFSClient::~DFSClient() {
}

shared_ptr<ClientProtocol> DFSClient::createRPCNamenode(
		const InetSocketAddress& nameNodeAddr, const Configuration& conf,
		const UserGroupInformation& ugi) {
	auto_ptr<VersionedProtocol> vp = RPC::getProxy("ClientProtocol",
			ClientProtocol::versionID, nameNodeAddr, ugi, conf,
			NetUtils::getSocketFactory(conf, "ClientProtocol"));
	ClientProtocol* p = dynamic_cast<ClientProtocol*>(vp.get());
	vp.release();
	return shared_ptr < ClientProtocol > (p);
}

shared_ptr<ClientProtocol> DFSClient::createNamenode(shared_ptr<ClientProtocol> rpcNamenode) { //todo
	return rpcNamenode;
}

vector<InetSocketAddress> DFSClient::getLocalInterfaceAddrs(
		const vector<string>& interfaceNames) { //todo
	vector<InetSocketAddress> v;
	return v;
}

void DFSClient::checkOpen() {
	if (!clientRunning) {
		throw runtime_error("Filesystem closed");
	}
}

bool DFSClient::delete_m(const string& src, bool recursive) {
	checkOpen();
	return namenode->delete_m(src, recursive);
}

} /* namespace libhadoop */
