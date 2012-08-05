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

class ClientProtocolRPC: public ClientProtocol {

public:
	ClientProtocolRPC(const Invoker& invoker){
//TODO
	}
	virtual ~ClientProtocolRPC(){
//TODO
	}

//	bool delete_m(const string& src);
//
//	bool delete_m(const string& src, bool recursive);
//
//	int64_t getProtocolVersion(const string& protocol, int64_t clientVersion);

};

} /* namespace libhadoop */
#endif /* CLIENTPROTOCOLRPC_H_ */
