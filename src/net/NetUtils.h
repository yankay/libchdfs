/*
 * NetUtils.h
 *
 *  Created on: Jul 4, 2012
 *      Author: yank1
 */

#ifndef NETUTILS_H_
#define NETUTILS_H_

#include <string>
#include <map>
#include <sstream>
#include "InetSocketAddress.h"
#include "util/Logger.h"

namespace libhadoop {

class NetUtils {

public:
	static const std::string LOG_NAME;

	static std::map<std::string, std::string> hostToResolved;

	static std::string getStaticResolution(const std::string& host);

	static InetSocketAddress createSocketAddr(const std::string& target,
			int32_t defaultPort);
};

} /* namespace libhadoop */
#endif /* NETUTILS_H_ */
