/*
 * Path.cc
 *
 *  Created on: Jul 5, 2012
 *      Author: yank1
 */

#include "Path.h"

namespace libhadoop {

const std::string Path::SEPARATOR = "/";
const char Path::SEPARATOR_CHAR = '/';

const std::string Path::CUR_DIR = ".";
const bool Path::WINDOWS = false;

Path::Path(const std::string& pathString) {
	std::string pathS(pathString);
	checkPathArg(pathS);

	// We can't use 'new URI(String)' directly, since it assumes things are
	// escaped, which we don't require of Paths.

	// add a slash in front of paths with Windows drive letters
	if (hasWindowsDrive(pathS, false))
		pathS = "/" + pathS;

	// parse uri components
	std::string scheme;
	std::string authority;

	size_t start = 0;

	// parse uri scheme, if any
	size_t colon = pathS.find(':');
	size_t slash = pathS.find('/');
	if ((colon != std::string::npos)
			&& ((slash == std::string::npos) || (colon < slash))) { // has a scheme
		scheme = pathS.substr(0, colon);
		start = colon + 1;
	}

	// parse uri authority, if any
	if (pathS.find("//", start) == 0 && (pathS.length() - start > 2)) { // has authority
		size_t nextSlash = pathS.find("/", start + 2);
		size_t authEnd = pathS.length();
		if (nextSlash != std::string::npos && nextSlash > 0)
			authEnd = nextSlash;
		authority = pathS.substr(start + 2, authEnd - start - 2);
		start = authEnd;
	}

	// uri path is the rest of the string -- query & fragment not supported

	std::string path;
	if (pathS.length() - start > 0)
		path = pathS.substr(start, pathS.length() - start);
//	std::cout << "authority" << authority << std::endl;
	initialize(scheme, authority, path, "");
}

void Path::checkPathArg(const std::string& path) {
	if (path.empty()) {
		throw std::invalid_argument("Can not create a Path from a null string");
	}
}

bool Path::hasWindowsDrive(const std::string& path, bool slashed) {
	return false;
}

void Path::initialize(const std::string& scheme, const std::string& authority,
		const std::string& path, const std::string& fragment) {
	URI another(scheme, authority, normalizePath(path), "", fragment);
	uri = another.normalize();
}

std::string Path::normalizePath(const std::string& path) {
	// remove double slashes & backslashes
	std::string p = StringUtils::replace(path, "//", "/");
	p = StringUtils::replace(p, "\\", "/");

	// trim trailing slash from non-root path (ignoring windows drive)
	size_t minLength = hasWindowsDrive(p, true) ? 4 : 1;
	if (p.length() > minLength) {
		if (p[p.length() - 1] == '/') {
			p = p.substr(0, p.length() - 1);
		}
	}
	return p;
}
URI Path::toUri() {
	return uri;
}

}
/* namespace libhadoop */
