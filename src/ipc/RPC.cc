/*
 * RPC.cc
 *
 *  Created on: Jul 22, 2012
 *      Author: yank1
 */

#include "RPC.h"

namespace libhadoop {


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
