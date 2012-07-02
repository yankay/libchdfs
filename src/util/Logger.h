/*
 * Logger.h
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <iostream>

namespace libhadoop {

class Logger {
public:
	Logger();
	virtual ~Logger();
	void warn(const std::string& msg) const;
};

} /* namespace libhadoop */
#endif /* LOGGER_H_ */
