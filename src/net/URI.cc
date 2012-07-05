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

URI::URI(const std::string& scheme, const std::string& authority,
		const std::string& path, const std::string& query,
		const std::string& fragment) {
	std::string s = toString(scheme, "", authority, "", "", -1, path, query,
			fragment);
	URI::checkPath(s, scheme, path);
	init(s);
}

URI::URI(const std::string& str) {
	init(str);
}

void URI::init(const std::string& str) {
	port = -1;
	size_t p = str.find("://");
	if (std::string::npos != p) {
		schema = str.substr(0, p);
		p += 3;
	} else if (std::string::npos == (p = str.find("//"))) {
//		throw std::invalid_argument("URI init cannot has no //");
		return;
	} else {
		p += 2;
	}
	size_t m = str.find(":", p);
	size_t l = str.find("/", p);
	if (std::string::npos == m && std::string::npos == l) {
		host = str.substr(p);
	} else if (std::string::npos == m && std::string::npos != l) {
		host = str.substr(p, l - p);
		path = str.substr(l);
	} else if (std::string::npos != m && std::string::npos == l) {
		host = str.substr(p, m - p);
		std::stringstream ss(str.substr(m + 1));
		ss >> port;
	} else {
		if (m < l) {
			host = str.substr(p, m - p);
			std::stringstream ss(str.substr(m + 1, l - m - 1));
			ss >> port;
			std::cout << port << std::endl;
			path = str.substr(l);
		} else {
			host = str.substr(p, l - p);
			path = str.substr(l);
		}
	}
}

std::string URI::getAuthority() {
	std::stringstream ss;
	ss << "//" << host;
	if (port >= 0) {
		ss << ":" << port;
	}
	return ss.str();
}
std::string URI::getScheme() {
	return schema;
}
std::string URI::getHost() {
	return host;
}
int32_t URI::getPort() {
	return port;
}

URI URI::normalize() {
	return URI(*this);
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

void URI::appendSchemeSpecificPart(std::stringstream& sb,
		const std::string& opaquePart, const std::string& authority,
		const std::string& userInfo, const std::string& host, int32_t port,
		const std::string& path, const std::string& query) {
	if (!opaquePart.empty()) {
		/* check if SSP begins with an IPv6 address
		 * because we must not quote a literal IPv6 address
		 */
		if (opaquePart.find("//[") == 0) {
			size_t end = opaquePart.find("]");
			if (end != std::string::npos
					&& opaquePart.find(":") != std::string::npos) {
				std::string doquote, dontquote;
				if (end == opaquePart.length()) {
					dontquote = opaquePart;
					doquote = "";
				} else {
					dontquote = opaquePart.substr(0, end + 1);
					doquote = opaquePart.substr(end + 1);
				}
				sb << dontquote;
				sb << URI::quote(doquote, 0, 0);
			}
		} else {
			sb << URI::quote(opaquePart, 0, 0);
		}
	} else {
		appendAuthority(sb, authority, userInfo, host, port);
		if (!path.empty())
			sb << URI::quote(path, 0, 0);
		if (!query.empty()) {
			sb << "?";
			sb << URI::quote(query, 0, 0);
		}
	}
}

void URI::appendAuthority(std::stringstream& sb, const std::string& authority,
		const std::string& userInfo, const std::string&host, int32_t port) {
	if (!host.empty()) {
		sb << "//";
		if (!userInfo.empty()) {

			sb << quote(userInfo, 0, 0);
			sb << '@';
		}
		bool needBrackets = ((host.find(':') != std::string::npos)
				&& !host.find("[") == 0 && host.find("]") != host.length() - 1);
		if (needBrackets)
			sb << '[';
		sb << host;
		if (needBrackets)
			sb << ']';
		if (port != -1) {
			sb << ':';
			sb << port;
		}
	} else if (!authority.empty()) {
		sb << "//";
		if (authority.find("[") == 0) {
			// authority should (but may not) contain an embedded IPv6 address
			size_t end = authority.find("]");
			std::string doquote = authority, dontquote = "";
			if (end != std::string::npos
					&& authority.find(":") != std::string::npos) {
				// the authority contains an IPv6 address
				if (end == authority.length()) {
					dontquote = authority;
					doquote = "";
				} else {
					dontquote = authority.substr(0, end + 1);
					doquote = authority.substr(end + 1);
				}
			}
			sb << dontquote;
			sb << quote(doquote, 0, 0);
		} else {
			sb << quote(authority, 0, 0);
		}
	}
}

void URI::appendFragment(std::stringstream& sb, const std::string& fragment) {
	if (!fragment.empty()) {
		sb << "#" << URI::quote(fragment, 0, 0);
	}
}

std::string URI::quote(const std::string& s, int64_t lowMask,
		int64_t highMask) {
	return s;
}

std::string URI::toString(const std::string& scheme,
		const std::string& opaquePart, const std::string& authority,
		const std::string& userInfo, const std::string& host, int32_t port,
		const std::string& path, const std::string& query,
		const std::string& fragment) {
	std::stringstream sb;
	if (!scheme.empty()) {
		sb << scheme << ":";
	}
	appendSchemeSpecificPart(sb, opaquePart, authority, userInfo, host, port,
			path, query);
	appendFragment(sb, fragment);
	return sb.str();
}

void URI::checkPath(const std::string& s, const std::string& scheme,
		const std::string& path) {
	if (scheme != "") {
		if ((path != "") && ((path.length() > 0) && (path[0] != '/'))) {
			std::stringstream ss;
			ss << s << "Relative path in absolute URI";
			throw std::invalid_argument(ss.str());
		}
	}
}
}
/* namespace libhadoop */
