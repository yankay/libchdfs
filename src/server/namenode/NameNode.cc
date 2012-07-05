/*
 * NameNode.cc
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#include "NameNode.h"

namespace libhadoop {

const int32_t NameNode::DEFAULT_PORT = 8020;
const std::string NameNode::LOG_NAME = "NameNode";

InetSocketAddress NameNode::getAddress(const Configuration& conf) {
	URI filesystemURI = FileSystem::getDefaultUri(conf);

	std::string authority = filesystemURI.getAuthority();
	if (authority.empty()) {
		std::stringstream ss;
		ss << "Invalid URI for NameNode address (check "
				<< FileSystem::FS_DEFAULT_NAME_KEY << "): "
				<< filesystemURI.toString() << " has no authority.";
		throw std::invalid_argument(ss.str());

	}
	if (!StringUtils::equalsIgnoreCase(FSConstants::HDFS_URI_SCHEME,
			filesystemURI.getScheme())) {
		std::stringstream ss;
		ss << "Invalid URI for NameNode address (check "
				<< FileSystem::FS_DEFAULT_NAME_KEY << "): "
				<< filesystemURI.toString() << " is not of scheme '"
				<< FSConstants::HDFS_URI_SCHEME << "'.";
		throw std::invalid_argument(ss.str());

	}
	return getAddress(authority);
}

InetSocketAddress NameNode::getAddress(const std::string& address) {
	return NetUtils::createSocketAddr(address, DEFAULT_PORT);
}

} /* namespace libhadoop */
