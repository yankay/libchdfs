/*
 * InetSocketAddress.h
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#ifndef INETSOCKETADDRESS_H_
#define INETSOCKETADDRESS_H_
#include <string>
#include <stdlib.h>
namespace libhadoop {
class InetSocketAddress {
public:
	InetSocketAddress(const std::string& hostname, int32_t port);

	std::string hostname;
	int32_t port;

};
}
#endif /* INETSOCKETADDRESS_H_ */
