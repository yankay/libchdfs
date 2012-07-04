/*
 * NameNode.h
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#ifndef NAMENODE_H_
#define NAMENODE_H_

#include "net/InetSocketAddress.h"
#include "conf/Configuration.h"
#include "net/URI.h"
#include "fs/FileSystem.h"

namespace libhadoop {

class NameNode {
public:
	static libhadoop::InetSocketAddress getAddress(
			const libhadoop::Configuration& conf);
};

} /* namespace libhadoop */
#endif /* NAMENODE_H_ */
