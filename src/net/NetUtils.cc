/*
 * NetUtils.cc
 *
 *  Created on: Jul 4, 2012
 *      Author: yank1
 */

#include "NetUtils.h"

namespace libhadoop {
std::map<std::string, std::string> NetUtils::hostToResolved;
const std::string NetUtils::LOG_NAME("NetUtils");

std::string NetUtils::getStaticResolution(const std::string& host) {
	return NetUtils::hostToResolved[host];
}

InetSocketAddress NetUtils::createSocketAddr(const std::string& target,
		int32_t defaultPort) {
	if (target.empty()) {
		LOG_ERROR(LOG_NAME, "Target address cannot be null.");
		throw "IllegalArgumentException";
	}
	size_t colonIndex = target.find(":", (size_t) 0);
	if (colonIndex == std::string::npos && defaultPort == -1) {
		LOG_ERROR(LOG_NAME, "Not a host:port pair: " << target);
		throw "RuntimeException";
	}
	std::string hostname;
	int port = -1;
	if (target.find("/") != std::string::npos) {
		if (colonIndex == std::string::npos) {
			hostname = target;
		} else {
			// must be the old style <host>:<port>
			hostname = target.substr(0, colonIndex);
			std::string portStr = target.substr(colonIndex + 1,
					std::string::npos);
			std::istringstream is(portStr);
			is >> port;
		}
	} else {
		// a new uri
		//TODO
//			URI addr = new Path(target)
//			.toUri();
//			hostname = addr.getHost();
//			port = addr.getPort();
	}

	if (port == -1) {
		port = defaultPort;
	}

	if (!getStaticResolution(hostname).empty()) {
		hostname = getStaticResolution(hostname);
	}
	InetSocketAddress isaddress(hostname, port);
	return isaddress;
}
} /* namespace libhadoop */
