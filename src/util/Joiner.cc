/*
 * Joiner.cc
 *
 *  Created on: Jul 15, 2012
 *      Author: yank1
 */

#include "Joiner.h"

namespace libhadoop {

string Joiner::join(const vector<string>& parts) {
	stringstream ss;
	string s = "";
	for (size_t i = 0; i < parts.size(); i++) {
		ss << s << parts[i];
		s = separator;
	}
	return ss.str();
}

} /* namespace libhadoop */
