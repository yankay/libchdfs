/*
 * VersionedProtocol.h
 *
 *  Created on: Jul 22, 2012
 *      Author: yank1
 */

#ifndef VERSIONEDPROTOCOL_H_
#define VERSIONEDPROTOCOL_H_

#include <string>
#include <stdlib.h>

using namespace std;

namespace libhadoop {

class VersionedProtocol {

public:
	virtual int64_t getProtocolVersion(const string& protocol, int64_t clientVersion){
		//TODO
	}
	virtual ~VersionedProtocol(){
		//TODO
	}
};

} /* namespace libhadoop */
#endif /* VERSIONEDPROTOCOL_H_ */
