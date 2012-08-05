/*
 * RPC.h
 *
 *  Created on: Jul 22, 2012
 *      Author: yank1
 */

#ifndef RPC_H_
#define RPC_H_

#include <string>
#include <memory>
#include <stdlib.h>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <tr1/memory>
#include <sys/time.h>

#include "conf/Configuration.h"
#include "net/InetSocketAddress.h"
#include "hdfs/protocol/ClientProtocol.h"
#include "security/UserGroupInformation.h"
#include "net/SocketFactory.h"
#include "lang/Object.h"
#include "util/Logger.h"

#include "VersionedProtocol.h"
#include "ConnectionId.h"
#include "Client.h"
#include "ClientCache.h"
#include "Invocation.h"
#include "Invoker.h"

using namespace std;
using namespace std::tr1;

namespace libhadoop {


/**
 * A version mismatch for the RPC protocol.
 */
class VersionMismatch: public std::exception {
public:
	VersionMismatch(const string& interfaceName, int64_t clientVersion,
			int64_t serverVersion){
		//TODO
	}

	virtual ~VersionMismatch() throw (){
//TODO
	}
private:
	string interfaceName;
	int64_t clientVersion;
	int64_t serverVersion;
	string msg;

	string init_msg(string interfaceName, int64_t clientVersion,
			int64_t serverVersion) {
		stringstream ss;
		ss << "Protocol " << interfaceName << " version mismatch. (client = "
				<< clientVersion << ", server = " << serverVersion << ")";
		return ss.str();
	}
};
}
#include "ClientProtocolRPC.h"
namespace libhadoop {

class RPC {

public:

	static auto_ptr<VersionedProtocol> getProxy(const string& protocol,
			const int64_t clientVersion, const InetSocketAddress& addr,
			const UserGroupInformation& ticket, const Configuration& conf,
			const SocketFactory& factory) {
		return getProxy(protocol, clientVersion, addr, ticket, conf, factory, 0);
	}

	static auto_ptr<VersionedProtocol> getProxy(const string& protocol,
			const int64_t clientVersion, const InetSocketAddress& addr,
			const UserGroupInformation& ticket, const Configuration& conf,
			const SocketFactory& factory, int32_t rpcTimeout) {
		if (UserGroupInformation::isSecurityEnabled()) {
//			SaslRpcServer.init(conf);
		}
		auto_ptr<VersionedProtocol> proxy = newProxyInstance(protocol,
				Invoker(protocol, addr, ticket, conf, factory, rpcTimeout));
		long serverVersion = proxy->getProtocolVersion(protocol, clientVersion);
		if (serverVersion == clientVersion) {
			return proxy;
		} else {
			throw new VersionMismatch(protocol, clientVersion, serverVersion);
		}
	}

private:
	static auto_ptr<VersionedProtocol> newProxyInstance(const string& protocol,
			const Invoker& invoker);

};

//VersionMismatch::VersionMismatch(const string& interfaceName,
//		int64_t clientVersion, int64_t serverVersion) :
//		interfaceName(interfaceName), clientVersion(clientVersion), serverVersion(
//				serverVersion), msg(
//				init_msg(interfaceName, clientVersion, serverVersion)) {
//}

}
/* namespace libhadoop */
#endif /* RPC_H_ */
