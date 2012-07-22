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
	ClientProtocol();
	virtual ~ClientProtocol();

	static const int64_t versionID;

	virtual bool delete_m(const string& src);

	virtual bool delete_m(const string& src, bool recursive);

};

} /* namespace libhadoop */
#endif /* CLIENTPROTOCOL_H_ */
