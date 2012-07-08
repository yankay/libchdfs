/*
 * NetUtils.cc
 *
 *  Created on: Jul 4, 2012
 *      Author: yank1
 */

#include "NetUtils.h"

namespace libhadoop {
map<string, string> NetUtils::hostToResolved;
const string NetUtils::LOG_NAME("NetUtils");

string NetUtils::getStaticResolution(const string& host) {
	return NetUtils::hostToResolved[host];
}

InetSocketAddress NetUtils::createSocketAddr(const string& target,
		int32_t defaultPort) {
	if (target.empty()) {
		throw invalid_argument("Target address cannot be null.");
	}
	size_t colonIndex = target.find(":");
	if (colonIndex == string::npos && defaultPort == -1) {
		stringstream ss;
		ss << "Not a host:port pair: " << target;
		throw runtime_error(ss.str());
	}
	string hostname;
	int port = -1;
	if (target.find("/") == string::npos) {
		if (colonIndex == string::npos) {
			hostname = target;
		} else {
			// must be the old style <host>:<port>
			hostname = target.substr(0, colonIndex);
			string portStr = target.substr(colonIndex + 1,
					string::npos);
			istringstream is(portStr);
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

SocketFactory NetUtils::getSocketFactory(const Configuration& conf,
		const string& clazz) {
	return SocketFactory();
}

} /* namespace libhadoop */
