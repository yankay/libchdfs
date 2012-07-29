/*
 * Client.h
 *
 *  Created on: Jul 22, 2012
 *      Author: yank1
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>

#include "net/SocketFactory.h"
#include "conf/Configuration.h"
#include "io/ObjectWritable.h"

#include "Invocation.h"
#include "ConnectionId.h"

using namespace std;

namespace libhadoop {

class Client {

private:
	string valueClass;
	Configuration conf;
	SocketFactory socketFactory;

public:

	Client(const string& valueClass, const Configuration& conf,
			const SocketFactory& factory) :
			valueClass(valueClass), conf(conf), socketFactory(factory) {
	}

	ObjectWritable call(const Invocation& param, const ConnectionId& remoteId);

	void incCount();
	void decCount();

	bool isZeroReference();

	void stop();

	SocketFactory getSocketFactory();

};

} /* namespace libhadoop */
#endif /* CLIENT_H_ */
