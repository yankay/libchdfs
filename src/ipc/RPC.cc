/*
 * RPC.cc
 *
 *  Created on: Jul 22, 2012
 *      Author: yank1
 */

#include "RPC.h"

namespace libhadoop {

Invoker::Invoker(const string& protocol, const InetSocketAddress& address,
		const UserGroupInformation& ticket, const Configuration& conf,
		const SocketFactory& factory, int32_t rpcTimeout) :
		remoteId(
				ConnectionId::getConnectionId(address, protocol, ticket,
						rpcTimeout, conf)), client(
				ClientCache::CLIENTS.getClient(conf, factory)), isClosed(false) {
}

auto_ptr<VersionedProtocol> RPC::newProxyInstance(const string& protocol,
		const Invoker& invoker) {
	if (protocol == "ClientProtocol") {
		ClientProtocolRPC* rpc = new ClientProtocolRPC(invoker);
		return auto_ptr < VersionedProtocol > (rpc);
	} else {
		throw invalid_argument("RPC: protocol not support");
	}
}

//ClientCache RPC::CLIENTS();

} /* namespace libhadoop */
