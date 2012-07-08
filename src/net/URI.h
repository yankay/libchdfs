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

using namespace std;

namespace libhadoop {

class URI {
public:
	URI();
	URI(const string& str);
	URI(const string& scheme, const string& authority,
			const string& path, const string& query,
			const string& fragment);

	string getAuthority();
	string getScheme();
	string getHost();
	int32_t getPort();
	string toString();
	URI normalize();

	static URI create(const string& str) {
		URI uri(str);
		return uri;
	}

private:
	string schema;
	string host;
	int32_t port;
	string path;

	void init(const string& str);

	string toString(const string& scheme,
			const string& opaquePart, const string& authority,
			const string& userInfo, const string& host, int32_t port,
			const string& path, const string& query,
			const string& fragment);

	static void checkPath(const string& s, const string& scheme,
			const string& path);
	void appendSchemeSpecificPart(stringstream& sb,
			const string& opaquePart, const string& authority,
			const string& userInfo, const string& host, int32_t port,
			const string& path, const string& query);

	void appendFragment(stringstream& sb, const string& fragment);

	void appendAuthority(stringstream& sb, const string& authority,
			const string& userInfo, const string&host, int32_t port);

	string quote(const string& s, int64_t lowMask, int64_t highMask);


};
} /* namespace libhadoop */
#endif /* URI_H_ */
