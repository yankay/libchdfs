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
#include <iostream>

namespace libhadoop {

class URI {
public:
	URI();
	URI(const std::string& str);
	std::string getAuthority();
	std::string getScheme();
	std::string getHost();
	int32_t getPort();
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

	void init(const std::string& str);
};

} /* namespace libhadoop */
#endif /* URI_H_ */
