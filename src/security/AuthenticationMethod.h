/*
 * AuthenticationMethod.h
 *
 *  Created on: Jul 7, 2012
 *      Author: yank1
 */

#ifndef AUTHENTICATIONMETHOD_H_
#define AUTHENTICATIONMETHOD_H_

using namespace std;

namespace libhadoop {
enum AuthenticationMethod {
	SIMPLE, KERBEROS, TOKEN, CERTIFICATE, KERBEROS_SSL, PROXY
};
}

#endif /* AUTHENTICATIONMETHOD_H_ */
