/*
 * InetSocketAddress.cc
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */
#include "InetSocketAddress.h"

namespace libhadoop {

InetSocketAddress::InetSocketAddress(const string& hostname, int32_t port) :
		hostname(hostname), port(port) {
}


string InetSocketAddress::toString() {
	stringstream ss;
	ss << hostname << ":" << port;
	return ss.str();
}
}
