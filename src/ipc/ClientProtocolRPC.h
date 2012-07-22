/*
 * ClientProtocolRPC.h
 *
 *  Created on: Jul 22, 2012
 *      Author: yank1
 */

#ifndef CLIENTPROTOCOLRPC_H_
#define CLIENTPROTOCOLRPC_H_

#include "hdfs/protocol/ClientProtocol.h"
#include "RPC.h"

namespace libhadoop {

class ClientProtocolRPC :public ClientProtocol {

public:
	ClientProtocolRPC(const Invoker& invoker);
	virtual ~ClientProtocolRPC();
};

} /* namespace libhadoop */
#endif /* CLIENTPROTOCOLRPC_H_ */
