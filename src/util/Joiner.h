/*
 * Joiner.h
 *
 *  Created on: Jul 15, 2012
 *      Author: yank1
 */

#ifndef JOINER_H_
#define JOINER_H_

#include <string>
#include <sstream>
#include <vector>
using namespace std;

namespace libhadoop {
class Joiner {
public:
	Joiner(const string& separator) :
			separator(separator) {
	}

	static Joiner on(const string& separator) {
		Joiner j(separator);
		return j;
	}

	string join(const vector<string>& parts);

private:
	string separator;

};

} /* namespace libhadoop */
#endif /* JOINER_H_ */
