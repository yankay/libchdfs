/*
 * ClientCache.h
 *
 *  Created on: Jul 29, 2012
 *      Author: yank1
 */

#ifndef CLIENTCACHE_H_
#define CLIENTCACHE_H_

#include <map>
#include <memory>

#include "ipc/Client.h"
#include "conf/Configuration.h"
#include "net/SocketFactory.h"

using namespace std;

namespace libhadoop {

class ClientCache {
private:
	auto_ptr<Client> client_p;
public:

	static ClientCache CLIENTS;

	/**
	 * Construct & cache an IPC client with the user-provided SocketFactory
	 * if no cached client exists.
	 *
	 * @param conf Configuration
	 * @return an IPC client
	 */
	Client* getClient(const Configuration& conf, const SocketFactory& factory) {
		// Construct & cache client.  The configuration is only used for timeout,
		// and Clients have connection pools.  So we can either (a) lose some
		// connection pooling and leak sockets, or (b) use the same timeout for all
		// configurations.  Since the IPC is usually intended globally, not
		// per-job, we choose (a).
		if (client_p.get() == NULL) {
			auto_ptr<Client> t(new Client("ObjectWritable", conf, factory));
			client_p = t;
		} else {
			client_p->incCount();
		}
		return client_p.get();
	}

	/**
	 * Construct & cache an IPC client with the default SocketFactory
	 * if no cached client exists.
	 *
	 * @param conf Configuration
	 * @return an IPC client
	 */
	Client* getClient(const Configuration& conf) {
		return getClient(conf, SocketFactory::getDefault());
	}

	/**
	 * Stop a RPC client connection
	 * A RPC client is closed only when its reference count becomes zero.
	 */
	void stopClient(Client* client) {
		client->decCount();
		if (client->isZeroReference()) {
			client->stop();
		}
		if (client->isZeroReference()) {
			if (client == client_p.get())
				client_p.reset(NULL);
		}
	}

};

} /* namespace libhadoop */
#endif /* CLIENTCACHE_H_ */
