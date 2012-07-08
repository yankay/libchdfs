/*
 * FileSystem.cc
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#include "FileSystem.h"

namespace libhadoop {

const string FileSystem::FS_DEFAULT_NAME_KEY("fs.default.name");
const string FileSystem::LOG_NAME("FileSystem");

URI FileSystem::getDefaultUri(const Configuration& conf) {
//	cout << FS_DEFAULT_NAME_KEY << endl;
	string name = conf.get(FS_DEFAULT_NAME_KEY, "file:///");
	return URI::create(FileSystem::fixName(name));
}

string FileSystem::fixName(const string& name) {
	stringstream fixed;
	if (name == "local") {
		LOG_WARN(LOG_NAME,
				"\"local\" is a deprecated filesystem name." << " Use \"file:///\" instead.");
		fixed << "file:///";
	} else if (string::npos == name.find("/")) {
		LOG_WARN(LOG_NAME,
				"\"" << name << "\" is a deprecated filesystem name." << " Use \"hdfs://" << name << "/\" instead.");
		fixed << "hdfs://" << name;
	} else {
		fixed << name;
	}
	return fixed.str();
}

}
