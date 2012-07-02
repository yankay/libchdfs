/*
 * URI.h
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#ifndef URI_H_
#define URI_H_

#include <string>
#include <sstream>
#include <stdlib.h>

namespace libhadoop {

class URI {
public:
	URI();
	URI(const std::string& str);

	virtual ~URI();

	std::string toString();

	static URI create(const std::string& str) {
		URI uri(str);
		return uri;
	}


private:
	std::string schema;
	std::string host;
	int32_t port;
	std::string path;
};

} /* namespace libhadoop */
#endif /* URI_H_ */
