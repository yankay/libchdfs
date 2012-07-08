/*
 * User.h
 *
 *  Created on: Jul 7, 2012
 *      Author: yank1
 */

#ifndef USER_H_
#define USER_H_

#include <string>
#include <stdlib.h>
#include "AuthenticationMethod.h"

using namespace std;

namespace libhadoop {

class User {
public:
	User();
	void setAuthenticationMethod(AuthenticationMethod authMethod);
	string getName();
	AuthenticationMethod getAuthenticationMethod();

private:
	AuthenticationMethod authMethod;
	string shortName;
	string fullName;

};

} /* namespace libhadoop */
#endif /* USER_H_ */
