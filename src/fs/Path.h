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

namespace libhadoop {

class Path {

public:
	/** The directory separator, a slash. */
	static const std::string SEPARATOR;
	static const char SEPARATOR_CHAR;

	static const std::string CUR_DIR;

	Path(const std::string& pathString);
	URI toUri();

private:
	URI uri;                                // a hierarchical uri
	static const bool WINDOWS;

	void checkPathArg( const std::string& path);

	bool hasWindowsDrive(const std::string& path, bool slashed);

	void initialize(const std::string& scheme, const std::string& authority, const std::string& path,
			const std::string& fragment);

	std::string normalizePath(const std::string& path);
};

} /* namespace libhadoop */
#endif /* PATH_H_ */
