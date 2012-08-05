#ifndef INVOKER_H_
#define INVOKER_H_

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

using namespace std;
using namespace std::tr1;

namespace libhadoop {
class Invoker {
public:
	Invoker(const string& protocol, const InetSocketAddress& address,
			const UserGroupInformation& ticket, const Configuration& conf,
			const SocketFactory& factory, int32_t rpcTimeout) :
			remoteId(
					ConnectionId::getConnectionId(address, protocol, ticket,
							rpcTimeout, conf)), client(
					ClientCache::CLIENTS.getClient(conf, factory)), isClosed(
					false) {
	}

	shared_ptr<Object> invoke(const string& method, const vector< shared_ptr<Object> >& args) {
		bool logDebug = Logger::isDebugEnabled();
		struct timeval startTime;
		if (logDebug) {
			gettimeofday(&startTime, NULL);
		}
		ObjectWritable value = client->call(Invocation(method, args), remoteId);
		if (logDebug) {
			struct timeval endTime;
			gettimeofday(&endTime, NULL);
			long callTime = 1000 * (endTime.tv_sec - startTime.tv_sec)
					+ (endTime.tv_usec - startTime.tv_usec);
			LOG_DEBUG("Invoker", "Call: " << method << " " << callTime);
		}
		return value.get();
	}

	/* close the IPC client that's responsible for this invoker's RPCs */
	void close() {
		if (!isClosed) {
			isClosed = true;
			ClientCache::CLIENTS.stopClient(client);
		}
	}
private:
	ConnectionId remoteId;
	shared_ptr<Client> client;
	bool isClosed;

};
}
/* namespace libhadoop */
#endif /* RPC_H_ */
