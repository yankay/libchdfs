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
#include <ostream>

namespace libhadoop {

class LoggerPtr {
public:
	const std::string name;
	std::ostream* os;

	LoggerPtr(const std::string& name);

};

class Logger {
public:
// Creation & retrieval methods:
	static LoggerPtr getRootLogger() {
		return getLogger("");
	}

	static LoggerPtr getLogger(const std::string& name) {
		LoggerPtr logger(name);
		logger.os = &std::cout;
		return logger;
	}

};

} /* namespace libhadoop */
//WARNING [name]:  fdasfdas
#define LOG_WARN(logger, expression) *(logger.os) << "WARNING [" << logger.name << "]: " << expression<< std::endl

#endif /* LOGGER_H_ */
