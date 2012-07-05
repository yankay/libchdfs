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
#include <stdint.h>
#include <stdexcept>

namespace libhadoop {

class URI {
public:
	URI();
	URI(const std::string& str);
	URI(const std::string& scheme, const std::string& authority,
			const std::string& path, const std::string& query,
			const std::string& fragment);

	std::string getAuthority();
	std::string getScheme();
	std::string getHost();
	int32_t getPort();
	std::string toString();
	URI normalize();

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

	std::string toString(const std::string& scheme,
			const std::string& opaquePart, const std::string& authority,
			const std::string& userInfo, const std::string& host, int32_t port,
			const std::string& path, const std::string& query,
			const std::string& fragment);

	static void checkPath(const std::string& s, const std::string& scheme,
			const std::string& path);
	void appendSchemeSpecificPart(std::stringstream& sb,
			const std::string& opaquePart, const std::string& authority,
			const std::string& userInfo, const std::string& host, int32_t port,
			const std::string& path, const std::string& query);

	void appendFragment(std::stringstream& sb, const std::string& fragment);

	void appendAuthority(std::stringstream& sb, const std::string& authority,
			const std::string& userInfo, const std::string&host, int32_t port);

	std::string quote(const std::string& s, int64_t lowMask, int64_t highMask);


};
} /* namespace libhadoop */
#endif /* URI_H_ */
