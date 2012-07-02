/*
 * NameNode.cc
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#include "NameNode.h"

namespace libhadoop {

NameNode::NameNode() {
	// TODO Auto-generated constructor stub

}

NameNode::~NameNode() {
	// TODO Auto-generated destructor stub
}

libhadoop::InetSocketAddress NameNode::getAddress(
		const libhadoop::Configuration& conf) {
	libhadoop::URI filesystemURI = libhadoop::FileSystem::getDefaultUri(conf);
}

} /* namespace libhadoop */
