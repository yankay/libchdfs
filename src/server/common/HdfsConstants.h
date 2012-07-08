/*
 * HdfsConstants.h
 *
 *  Created on: Jul 6, 2012
 *      Author: yank1
 */

#ifndef HDFSCONSTANTS_H_
#define HDFSCONSTANTS_H_

#include <stdlib.h>
using namespace std;

namespace libhadoop {

class HdfsConstants {

public:
	static int32_t READ_TIMEOUT;
	static int32_t READ_TIMEOUT_EXTENSION;
	static int32_t WRITE_TIMEOUT;
	static int32_t WRITE_TIMEOUT_EXTENSION; //for write pipeline
};

} /* namespace libhadoop */
#endif /* HDFSCONSTANTS_H_ */
