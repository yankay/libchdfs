/*
 * Configurable.h
 *
 *  Created on: Aug 1, 2012
 *      Author: yank1
 */

#ifndef CONFIGURABLE_H_
#define CONFIGURABLE_H_

#include "Configuration.h"

namespace libhadoop {

class Configurable {
	virtual void setConf(const Configuration& conf) = 0;
	virtual Configuration getConf() = 0;
};

} /* namespace libhadoop */
#endif /* CONFIGURABLE_H_ */
