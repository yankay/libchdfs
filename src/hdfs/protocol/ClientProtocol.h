/*
 * ClientProtocol.h
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#ifndef CLIENTPROTOCOL_H_
#define CLIENTPROTOCOL_H_

#include <stdlib.h>
#include "ipc/VersionedProtocol.h"

namespace libhadoop {

using namespace std;

class ClientProtocol: public VersionedProtocol {

public:
	ClientProtocol(){
		//TODO
	}
	virtual ~ClientProtocol(){
//TODO
	}

	static const int64_t versionID;

	virtual bool delete_m(const string& src){
		//TODO
	}

	virtual bool delete_m(const string& src, bool recursive){
//TODO
	}

};

} /* namespace libhadoop */
#endif /* CLIENTPROTOCOL_H_ */
