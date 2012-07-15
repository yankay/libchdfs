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
#include <sstream>

using namespace std;

namespace libh {

class Logger {


public:
	enum loglevel {
		WARN, DEBUG, ERROR
	};


	Logger(const string& name, loglevel level) :
			name(name), level(level) {
	}

	Logger warn(loglevel level) {
		this->level = level;
		return *this;
	}


private:
	string name;
	loglevel level;
};

}  // namespace libhadoop

#define LOG_OS cout
#define LOG_WARN(name, expression) LOG_OS << "WARN [" << name << "]: " << expression << endl
#define LOG_ERROR(name, expression) LOG_OS << "ERROR [" << name << "]: " << expression << endl
#define LOG_DEBUG(name, expression) LOG_OS << "DEBUG [" << name << "]: " << expression << endl

#endif /* LOGGER_H_ */
