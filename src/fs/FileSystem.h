/*
 * FileSystem.h
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include <string>
#include <sstream>

#include "net/URI.h"
#include "util/Logger.h"
#include "conf/Configuration.h"

namespace libhadoop {
class FileSystem {
public:
	const static std::string FS_DEFAULT_NAME_KEY;
	const static std::string LOG_NAME;

	static URI getDefaultUri(const Configuration& conf);

private:
	static std::string fixName(const std::string& name);

};

class FileSystemStatistics {

};
}
#endif /* FILESYSTEM_H_ */
