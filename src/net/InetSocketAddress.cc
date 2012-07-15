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

string InetSocketAddress::toString() const {
	stringstream ss;
	ss << hostname << ":" << port;
	return ss.str();
}

vector<string> InetSocketAddress::toStrings(
		const vector<InetSocketAddress>& addresses) {
	vector < string > strs;
	for (size_t i = 0; i < addresses.size(); ++i) {
		strs.push_back(addresses[i].toString());
	}
	return strs;
}

}
