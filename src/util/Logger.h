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


#define LOG_OS std::cout
#define LOG_WARN(name, expression) std::cout << "WARNING [" << name << "]: " << expression << std::endl
#define LOG_ERROR(name, expression) std::cout << "ERROR [" << name << "]: " << expression << std::endl

#endif /* LOGGER_H_ */
