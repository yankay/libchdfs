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
#include <tr1/memory>

#include "lang/Object.h"

using namespace std;
using namespace std::tr1;

namespace libhadoop {

class Invocation {
public:
	Invocation(const string& method,const vector< shared_ptr<Object> >& parameters);
};

} /* namespace libhadoop */
#endif /* INVOCATION_H_ */
