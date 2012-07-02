/*
 * FileSystem.cc
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#include "FileSystem.h"

namespace libhadoop {

const std::string FileSystem::FS_DEFAULT_NAME_KEY = "fs.default.name";
const libhadoop::Logger FileSystem::LOG;

libhadoop::URI FileSystem::getDefaultUri(const libhadoop::Configuration& conf) {
//	std::cout << FS_DEFAULT_NAME_KEY << std::endl;
	std::string name = conf.get(FS_DEFAULT_NAME_KEY, "file:///");
	return libhadoop::URI::create(FileSystem::fixName(name));
}

std::string FileSystem::fixName(const std::string& name) {
	std::stringstream fixed;
	if (name == "local") {
		std::stringstream ss;
		ss << "\"local\" is a deprecated filesystem name."
				<< " Use \"file:///\" instead.";
		LOG.warn(ss.str());
		fixed << "file:///";
	} else if (std::string::npos == name.find("/")) {
		std::stringstream ss;
		ss << "\"" << name << "\" is a deprecated filesystem name."
				<< " Use \"hdfs://" << name << "/\" instead.";
		LOG.warn(ss.str());
		fixed << "hdfs://" << name;
	} else {
		fixed << name;
	}
	return fixed.str();
}

}
