/*
 * InetSocketAddress.h
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#ifndef INETSOCKETADDRESS_H_
#define INETSOCKETADDRESS_H_

#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

namespace libhadoop {
class InetSocketAddress {
public:
	InetSocketAddress(const string& hostname, int32_t port);
	string toString();

private:
	string hostname;
	int32_t port;

};
}
#endif /* INETSOCKETADDRESS_H_ */
