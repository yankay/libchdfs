/*
 * NameNode.cc
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#include "NameNode.h"

namespace libhadoop {

InetSocketAddress NameNode::getAddress(const Configuration& conf) {
	URI filesystemURI = FileSystem::getDefaultUri(conf);
	//TODO
	InetSocketAddress address;
	return address;
}

} /* namespace libhadoop */
