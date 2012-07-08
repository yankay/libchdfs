/*
 * UserGroupInformation.cc
 *
 *  Created on: Jul 7, 2012
 *      Author: yank1
 */

#include "UserGroupInformation.h"

namespace libhadoop {

const string UserGroupInformation::HADOOP_TOKEN_FILE_LOCATION =
		"HADOOP_TOKEN_FILE_LOCATION";

auto_ptr<UserGroupInformation> UserGroupInformation::loginUser;

UserGroupInformation::UserGroupInformation() :
		user() {
}

UserGroupInformation& UserGroupInformation::getCurrentUser() {
	return UserGroupInformation::getLoginUser();
}

bool UserGroupInformation::isSecurityEnabled() {
	return false;
}

void UserGroupInformation::setAuthenticationMethod(
		AuthenticationMethod authMethod) {
	user.setAuthenticationMethod(authMethod);
}

string UserGroupInformation::toString() {
	stringstream ss;
	ss << getUserName() << " (auth:"
			<< authenticationMethodToString(getAuthenticationMethod()) << ")";
	return ss.str();
}

string UserGroupInformation::getUserName() {
	return user.getName();
}

AuthenticationMethod UserGroupInformation::getAuthenticationMethod() {
	return user.getAuthenticationMethod();
}

string UserGroupInformation::authenticationMethodToString(
		AuthenticationMethod authMethod) {
	stringstream ss;
	switch (authMethod) {
	case SIMPLE:
		ss << "SIMPLE";
		break;
	case KERBEROS:
		ss << "KERBEROS";
		break;
	case TOKEN:
		ss << "TOKEN";
		break;
	case CERTIFICATE:
		ss << "CERTIFICATE";
		break;
	case KERBEROS_SSL:
		ss << "KERBEROS_SSL";
		break;
	case PROXY:
		ss << "PROXY";
		break;
	}
	return ss.str();
}

UserGroupInformation& UserGroupInformation::getLoginUser() {
	if (UserGroupInformation::loginUser.get() == NULL) {
//		try {
//			if (UserGroupInformation::isSecurityEnabled()) {
//				login = newLoginContext(
//						HadoopConfiguration.USER_KERBEROS_CONFIG_NAME, subject);
//			} else {
//				login = newLoginContext(HadoopConfiguration.SIMPLE_CONFIG_NAME,
//						subject);
//			}
//			login.login();
		auto_ptr<UserGroupInformation> u(new UserGroupInformation());
		loginUser = u;
//			loginUser.setLogin(login);
		AuthenticationMethod m = isSecurityEnabled() ? KERBEROS : SIMPLE;
		loginUser->setAuthenticationMethod(m);
//			loginUser = new UserGroupInformation(login.getSubject());
		char * fl = getenv(
				UserGroupInformation::HADOOP_TOKEN_FILE_LOCATION.c_str());
		string fileLocation = NULL == fl ? "" : fl;

		if (!fileLocation.empty() && isSecurityEnabled()) {
			// load the token storage file and put all of the tokens into the
			// user.
//				Credentials cred = Credentials.readTokenStorageFile(
//						new Path("file:///" + fileLocation), conf);
//			for (Token<?> token: cred.getAllTokens()) {
//				loginUser.addToken(token);
//			}
		}
//		loginUser.spawnAutoRenewalThreadForUserCreds();
//	} catch (LoginException le) {
//		throw new IOException("failure to login", le);
//	}
		LOG_DEBUG("UserGroupInformation",
				"UGI loginUser:" << loginUser->toString());
	}
	UserGroupInformation * up = loginUser.get();
	return *up;
}
}
/* namespace libhadoop */
