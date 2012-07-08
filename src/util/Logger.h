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

using namespace std;


#define LOG_OS cout
#define LOG_WARN(name, expression) LOG_OS << "WARNING [" << name << "]: " << expression << endl
#define LOG_ERROR(name, expression) LOG_OS << "ERROR [" << name << "]: " << expression << endl
#define LOG_DEBUG(name, expression) LOG_OS << "DEBUG [" << name << "]: " << expression << endl

#endif /* LOGGER_H_ */
