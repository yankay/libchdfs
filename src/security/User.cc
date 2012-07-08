/*
 * User.cc
 *
 *  Created on: Jul 7, 2012
 *      Author: yank1
 */

#include "User.h"

namespace libhadoop {

User::User() :
		authMethod(SIMPLE), shortName(getenv("USER")), fullName(getenv("USER")) {
}

string User::getName() {
	return fullName;
}
AuthenticationMethod User::getAuthenticationMethod() {
	return authMethod;
}

void User::setAuthenticationMethod(AuthenticationMethod authMethod) {
	this->authMethod = authMethod;
}

}
/* namespace libhadoop */
