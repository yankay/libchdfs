/*
 * InetSocketAddress.cc
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */
#include "InetSocketAddress.h"

namespace libhadoop {

InetSocketAddress::InetSocketAddress(const std::string& hostname, int32_t port) :
		hostname(hostname), port(port) {
}


std::string InetSocketAddress::toString() {
	std::stringstream ss;
	ss << hostname << ":" << port;
	return ss.str();
}
}
