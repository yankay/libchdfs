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

using namespace std;

namespace libhadoop {
class FileSystem {
public:
	const static string FS_DEFAULT_NAME_KEY;

	static URI getDefaultUri(const Configuration& conf);

private:
	static string fixName(const string& name);

};

class FileSystemStatistics {

};

}
#endif /* FILESYSTEM_H_ */
