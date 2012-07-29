/*
 * Invocation.h
 *
 *  Created on: Jul 29, 2012
 *      Author: yank1
 */

#ifndef INVOCATION_H_
#define INVOCATION_H_

#include <string>
#include <vector>
#include "lang/Object.h"

using namespace std;

namespace libhadoop {

class Invocation {
public:
	Invocation(const string& method,const vector<Object>& parameters);
};

} /* namespace libhadoop */
#endif /* INVOCATION_H_ */
