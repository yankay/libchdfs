/*
 * Configuration.h
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

namespace hadoop {

class Configuration {
public:
	virtual ~Configuration();
	Configuration();
	Configuration(const bool loadDefaults);

};

} /* namespace hadoop */
#endif /* CONFIGURATION_H_ */
