/*
 * ObjectWritable.h
 *
 *  Created on: Jul 29, 2012
 *      Author: yank1
 */

#ifndef OBJECTWRITABLE_H_
#define OBJECTWRITABLE_H_

#include "lang/Object.h"

namespace libhadoop {

class ObjectWritable {
public:
	Object get();
};

} /* namespace libhadoop */
#endif /* OBJECTWRITABLE_H_ */
