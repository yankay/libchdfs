/*
 * NetUtils.h
 *
 *  Created on: Jul 4, 2012
 *      Author: yank1
 */

#ifndef NETUTILS_H_
#define NETUTILS_H_

#include <string>
#include <iostream>
#include <map>
#include <stdexcept>
#include <sstream>
#include "InetSocketAddress.h"
#include "util/Logger.h"
#include "fs/Path.h"
#include "conf/Configuration.h"
#include "net/SocketFactory.h"

using namespace std;

namespace libhadoop {

class NetUtils {

public:
	static const string LOG_NAME;

	static map<string, string> hostToResolved;

	static string getStaticResolution(const string& host);

	/**
	 * Util method to build socket addr from either:
	 *   <host>
	 *   <host>:<post>
	 *   <fs>://<host>:<port>/<path>
	 */
	static InetSocketAddress createSocketAddr(const string& target,
			int32_t defaultPort);

	static SocketFactory getSocketFactory(const Configuration& conf,
			const string& clazz) ;

};

} /* namespace libhadoop */
#endif /* NETUTILS_H_ */
