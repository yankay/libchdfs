/*
 * Logger.cc
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#include "Logger.h"

namespace libhadoop {

Logger::Logger() {
	// TODO Auto-generated constructor stub

}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}

void Logger::warn(const std::string& msg) const {
	std::cout << "warn::" << msg << std::endl;
}

} /* namespace libhadoop */

