/*
 * ConnectionId.cc
 *
 *  Created on: Jul 29, 2012
 *      Author: yank1
 */

#include "ConnectionId.h"

namespace libhadoop {
//const int32_t ConnectionId::PRIME = 16777619;

ConnectionId::ConnectionId(const InetSocketAddress& address,
		const string& protocol, const UserGroupInformation& ticket,
		const int32_t rpcTimeout, const string& serverPrincipal,
		const int32_t maxIdleTime, const int32_t maxRetries,
		const bool tcpNoDelay, const bool doPing, const int32_t pingInterval) :
		address(address), protocol(protocol), ticket(ticket), rpcTimeout(
				rpcTimeout), serverPrincipal(serverPrincipal), maxIdleTime(
				maxIdleTime), maxRetries(maxRetries), tcpNoDelay(tcpNoDelay), doPing(
				doPing), pingInterval(pingInterval) {
}

} /* namespace libhadoop */
