/*
 * URI.cc
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#include "URI.h"

namespace libhadoop {

URI::URI() {
	init("");
}

URI::URI(const std::string& str) {
	init(str);
}

void URI::init(const std::string& str) {
	port = -1;
	size_t p = str.find("://");
	if (std::string::npos == p)
		return;
	schema = str.substr(0, p);
	size_t m = str.find(":", p + 3);
	size_t l = str.find("/", p + 3);
	if (std::string::npos == m && std::string::npos == l) {
		host = str.substr(p + 3);
	} else if (std::string::npos == m && std::string::npos != l) {
		host = str.substr(p + 3, l - p - 3);
		path = str.substr(l);
	} else if (std::string::npos != m && std::string::npos == l) {
		host = str.substr(p + 3, m - p - 3);
		std::stringstream ss(str.substr(m + 1));
		ss >> port;
	} else {
		if (m < l) {
			host = str.substr(p + 3, m - p - 3);
			std::stringstream ss(str.substr(m + 1, l - m - 1));
			ss >> port;
			std::cout << port << std::endl;
			path = str.substr(l);
		} else {
			host = str.substr(p + 3, l - p - 3);
			path = str.substr(l);
		}
	}
}

std::string URI::toString() {
	std::stringstream ss;
	ss << schema << "://" << host;
	if (port > 0) {
		ss << ":" << port;
	}
	ss << path;
	return ss.str();
}

} /* namespace libhadoop */
