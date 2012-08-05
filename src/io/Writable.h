/*
 * Writable.h
 *
 *  Created on: Aug 1, 2012
 *      Author: yank1
 */

#ifndef WRITABLE_H_
#define WRITABLE_H_

#include "DataOutput.h"
#include "DataInput.h"

#include "lang/Object.h"

namespace libhadoop {

class Writable :public Object{
public:
	virtual void write(DataOutput& out) = 0;

	virtual void readFields(DataInput& in) = 0;

};

} /* namespace libhadoop */
#endif /* WRITABLE_H_ */
