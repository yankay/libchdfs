/*
 * Path.h
 *
 *  Created on: Jul 5, 2012
 *      Author: yank1
 */

#ifndef PATH_H_
#define PATH_H_

#include <string>
#include <iostream>
#include <stdexcept>

#include "net/URI.h"
#include "util/StringUtils.h"

using namespace std;

namespace libhadoop {

class Path {

public:
	/** The directory separator, a slash. */
	static const string SEPARATOR;
	static const char SEPARATOR_CHAR;

	static const string CUR_DIR;

	Path(const string& pathString);
	URI toUri();

private:
	URI uri;                                // a hierarchical uri
	static const bool WINDOWS;

	void checkPathArg( const string& path);

	bool hasWindowsDrive(const string& path, bool slashed);

	void initialize(const string& scheme, const string& authority, const string& path,
			const string& fragment);

	string normalizePath(const string& path);
};

} /* namespace libhadoop */
#endif /* PATH_H_ */
