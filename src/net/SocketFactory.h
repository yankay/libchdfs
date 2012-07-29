/*
 * SocketFactory.h
 *
 *  Created on: Jul 6, 2012
 *      Author: yank1
 */

#ifndef SOCKETFACTORY_H_
#define SOCKETFACTORY_H_

using namespace std;

namespace libhadoop {

class SocketFactory {

public:
	static SocketFactory getDefault(){
		return SocketFactory();
	}
};

} /* namespace libhadoop */
#endif /* SOCKETFACTORY_H_ */
