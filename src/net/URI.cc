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

URI::URI(const string& scheme, const string& authority,
		const string& path, const string& query,
		const string& fragment) {
	string s = toString(scheme, "", authority, "", "", -1, path, query,
			fragment);
	URI::checkPath(s, scheme, path);
	init(s);
}

URI::URI(const string& str) {
	init(str);
}

void URI::init(const string& str) {
	port = -1;
	size_t p = str.find("://");
	if (string::npos != p) {
		schema = str.substr(0, p);
		p += 3;
	} else if (string::npos == (p = str.find("//"))) {
//		throw invalid_argument("URI init cannot has no //");
		return;
	} else {
		p += 2;
	}
	size_t m = str.find(":", p);
	size_t l = str.find("/", p);
	if (string::npos == m && string::npos == l) {
		host = str.substr(p);
	} else if (string::npos == m && string::npos != l) {
		host = str.substr(p, l - p);
		path = str.substr(l);
	} else if (string::npos != m && string::npos == l) {
		host = str.substr(p, m - p);
		stringstream ss(str.substr(m + 1));
		ss >> port;
	} else {
		if (m < l) {
			host = str.substr(p, m - p);
			stringstream ss(str.substr(m + 1, l - m - 1));
			ss >> port;
			cout << port << endl;
			path = str.substr(l);
		} else {
			host = str.substr(p, l - p);
			path = str.substr(l);
		}
	}
}

string URI::getAuthority() {
	stringstream ss;
	ss << "//" << host;
	if (port >= 0) {
		ss << ":" << port;
	}
	return ss.str();
}
string URI::getScheme() {
	return schema;
}
string URI::getHost() {
	return host;
}
int32_t URI::getPort() {
	return port;
}

URI URI::normalize() {
	return URI(*this);
}

string URI::toString() {
	stringstream ss;
	ss << schema << "://" << host;
	if (port > 0) {
		ss << ":" << port;
	}
	ss << path;
	return ss.str();
}

void URI::appendSchemeSpecificPart(stringstream& sb,
		const string& opaquePart, const string& authority,
		const string& userInfo, const string& host, int32_t port,
		const string& path, const string& query) {
	if (!opaquePart.empty()) {
		/* check if SSP begins with an IPv6 address
		 * because we must not quote a literal IPv6 address
		 */
		if (opaquePart.find("//[") == 0) {
			size_t end = opaquePart.find("]");
			if (end != string::npos
					&& opaquePart.find(":") != string::npos) {
				string doquote, dontquote;
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

void URI::appendAuthority(stringstream& sb, const string& authority,
		const string& userInfo, const string&host, int32_t port) {
	if (!host.empty()) {
		sb << "//";
		if (!userInfo.empty()) {

			sb << quote(userInfo, 0, 0);
			sb << '@';
		}
		bool needBrackets = ((host.find(':') != string::npos)
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
			string doquote = authority, dontquote = "";
			if (end != string::npos
					&& authority.find(":") != string::npos) {
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

void URI::appendFragment(stringstream& sb, const string& fragment) {
	if (!fragment.empty()) {
		sb << "#" << URI::quote(fragment, 0, 0);
	}
}

string URI::quote(const string& s, int64_t lowMask,
		int64_t highMask) {
	return s;
}

string URI::toString(const string& scheme,
		const string& opaquePart, const string& authority,
		const string& userInfo, const string& host, int32_t port,
		const string& path, const string& query,
		const string& fragment) {
	stringstream sb;
	if (!scheme.empty()) {
		sb << scheme << ":";
	}
	appendSchemeSpecificPart(sb, opaquePart, authority, userInfo, host, port,
			path, query);
	appendFragment(sb, fragment);
	return sb.str();
}

void URI::checkPath(const string& s, const string& scheme,
		const string& path) {
	if (scheme != "") {
		if ((path != "") && ((path.length() > 0) && (path[0] != '/'))) {
			stringstream ss;
			ss << s << "Relative path in absolute URI";
			throw invalid_argument(ss.str());
		}
	}
}
}
/* namespace libhadoop */
