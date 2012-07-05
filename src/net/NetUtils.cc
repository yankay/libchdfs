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
		throw std::invalid_argument("Target address cannot be null.");
	}
	size_t colonIndex = target.find(":");
	if (colonIndex == std::string::npos && defaultPort == -1) {
		std::stringstream ss;
		ss << "Not a host:port pair: " << target;
		throw std::runtime_error(ss.str());
	}
	std::string hostname;
	int port = -1;
	if (target.find("/") == std::string::npos) {
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
			URI addr = Path(target).toUri();
			hostname = addr.getHost();
			port = addr.getPort();
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
