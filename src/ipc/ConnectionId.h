/*
 * ConnectionId.h
 *
 *  Created on: Jul 29, 2012
 *      Author: yank1
 */

#ifndef CONNECTIONID_H_
#define CONNECTIONID_H_

#include <string>

#include <stdlib.h>

#include "net/InetSocketAddress.h"
#include "security/UserGroupInformation.h"
#include "conf/Configuration.h"

using namespace std;

namespace libhadoop {

class ConnectionId {

private:
	InetSocketAddress address;
	string protocol;
	UserGroupInformation ticket;
	int32_t rpcTimeout;
	string serverPrincipal;
	int32_t maxIdleTime; // connections will be culled if it was idle
						 // for
	// maxIdleTime msecs

	int32_t maxRetries; // the max. no. of retries for socket
						// connections
	bool tcpNoDelay; // if T then disable Nagle's Algorithm
	bool doPing; // do we need to send ping message
	int32_t pingInterval; // how often sends ping to the server in msecs

	static const int32_t PRIME = 16777619;
	static const int32_t DEFAULT_PING_INTERVAL = 60000;

public:

	ConnectionId(const InetSocketAddress& address, const string& protocol,
			const UserGroupInformation& ticket, const int32_t rpcTimeout,
			const string& serverPrincipal, const int32_t maxIdleTime,
			const int32_t maxRetries, const bool tcpNoDelay, const bool doPing,
			const int32_t pingInterval) :
				address(address), protocol(protocol), ticket(ticket), rpcTimeout(
						rpcTimeout), serverPrincipal(serverPrincipal), maxIdleTime(
						maxIdleTime), maxRetries(maxRetries), tcpNoDelay(tcpNoDelay), doPing(
						doPing), pingInterval(pingInterval){

	}

//	ConnectionId::ConnectionId(const InetSocketAddress& address,
//			const string& protocol, const UserGroupInformation& ticket,
//			const int32_t rpcTimeout, const string& serverPrincipal,
//			const int32_t maxIdleTime, const int32_t maxRetries,
//			const bool tcpNoDelay, const bool doPing, const int32_t pingInterval) :
//			address(address), protocol(protocol), ticket(ticket), rpcTimeout(
//					rpcTimeout), serverPrincipal(serverPrincipal), maxIdleTime(
//					maxIdleTime), maxRetries(maxRetries), tcpNoDelay(tcpNoDelay), doPing(
//					doPing), pingInterval(pingInterval) {
//	}


	static ConnectionId getConnectionId(const InetSocketAddress& addr,
			const string& protocol, const UserGroupInformation& ticket,
			const int32_t rpcTimeout, const Configuration conf) {
		string remotePrincipal = getRemotePrincipal(conf, addr, protocol);
		bool doPing = conf.getBoolean("ipc.client.ping", true);
		return ConnectionId(addr, protocol, ticket, rpcTimeout, remotePrincipal,
				conf.getInt("ipc.client.connection.maxidletime", 10000), // 10s
				conf.getInt("ipc.client.connect.max.retries", 10),
				conf.getBoolean("ipc.client.tcpnodelay", false), doPing,
				(doPing ?
						conf.getInt("ipc.ping.interval",
								DEFAULT_PING_INTERVAL) :
						0));
	}

	static string getRemotePrincipal(const Configuration conf,
			const InetSocketAddress& addr, const string& protocol) {
		return "";
	}

	InetSocketAddress getAddress() {
		return address;
	}

	string getProtocol() {
		return protocol;
	}

	UserGroupInformation getTicket() {
		return ticket;
	}

	int32_t getRpcTimeout() {
		return rpcTimeout;
	}

	string getServerPrincipal() {
		return serverPrincipal;
	}

	int32_t getMaxIdleTime() {
		return maxIdleTime;
	}

	int32_t getMaxRetries() {
		return maxRetries;
	}

	bool getTcpNoDelay() {
		return tcpNoDelay;
	}

	bool getDoPing() {
		return doPing;
	}

	int32_t getPingInterval() {
		return pingInterval;
	}
};

} /* namespace libhadoop */
#endif /* CONNECTIONID_H_ */
