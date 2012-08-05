/*
 * Configured.h
 *
 *  Created on: Aug 5, 2012
 *      Author: yank1
 */

#ifndef CONFIGURED_H_
#define CONFIGURED_H_

#include "Configurable.h"

namespace libhadoop {

class Configured: public Configurable {

public:
	Configured(const Configuration& conf) :
			conf(conf) {
	}

	void setConf(const Configuration& conf) {
		this->conf = conf;
	}

	// inherit javadoc
	Configuration getConf() {
		return conf;
	}

private:
	Configuration conf;

}
;

} /* namespace libhadoop */
#endif /* CONFIGURED_H_ */
