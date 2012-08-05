/*
 * Class.h
 *
 *  Created on: Aug 4, 2012
 *      Author: yank1
 */

#ifndef CLASS_H_
#define CLASS_H_

#include <stdio.h>
#include <memory>
#include <string>
#include <typeinfo>

using namespace std;

namespace libhadoop {

class Class {

public:

	Class(type_info* declaredClass) :
			declaredClass(declaredClass) {
	}

	string name() ;
private:
	Class();

	type_info* declaredClass;
};

} /* namespace libhadoop */
#endif /* CLASS_H_ */
