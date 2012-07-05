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

namespace libhadoop {

class NetUtils {

public:
	static const std::string LOG_NAME;

	static std::map<std::string, std::string> hostToResolved;

	static std::string getStaticResolution(const std::string& host);

	/**
	 * Util method to build socket addr from either:
	 *   <host>
	 *   <host>:<post>
	 *   <fs>://<host>:<port>/<path>
	 */
	static InetSocketAddress createSocketAddr(const std::string& target,
			int32_t defaultPort);
};

} /* namespace libhadoop */
#endif /* NETUTILS_H_ */
