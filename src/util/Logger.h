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


#define TRACE  0
#define DEBUG  1
#define WARN  2
#define INFO  3
#define ERROR  4


#define LOG_OS cout
#define LOG_TRACE(name, expression) if(loglevel<=TRACE){ Logger(name).warn() << expression << "\n"; }
#define LOG_DEBUG(name, expression) if(loglevel<=DEBUG){ Logger(name).warn() << expression << "\n"; }
#define LOG_WARN(name, expression) if(loglevel<=WARN){ Logger(name).warn() << expression << "\n"; }
#define LOG_INFO(name, expression) if(loglevel<=INFO){ Logger(name).warn() << expression << "\n"; }
#define LOG_ERROR(name, expression) if(loglevel<=ERROR){ Logger(name).warn() << expression << "\n"; }


namespace libhadoop {

extern int loglevel;

class Logger {

public:

	static bool isDebugEnabled(){
		return loglevel<=DEBUG;
	}


	Logger(const string& name) :
			name(name) {
	}

	Logger() :
			name("anonymity") {
	}

	Logger& warn() {
		cout << "WARN [" << name << "]: ";
		return *this;
	}

	Logger& operator<<(bool val) {
		cout << val;
		return *this;
	}
	Logger& operator<<(short val) {
		cout << val;
		return *this;
	}
	Logger& operator<<(unsigned short val) {
		cout << val;
		return *this;
	}
	Logger& operator<<(int val) {
		cout << val;
		return *this;
	}
	Logger& operator<<(unsigned int val) {
		cout << val;
		return *this;
	}
	Logger& operator<<(long val) {
		cout << val;
		return *this;
	}
	Logger& operator<<(unsigned long val) {
		cout << val;
		return *this;
	}
	Logger& operator<<(float val) {
		cout << val;
		return *this;
	}
	Logger& operator<<(double val) {
		cout << val;
		return *this;
	}
	Logger& operator<<(long double val) {
		cout << val;
		return *this;
	}
	Logger& operator<<(const char* sb) {
		cout << string(sb);
		return *this;
	}

	Logger& operator<<(const string& sb) {
		cout << sb;
		return *this;
	}

private:
	string name;
};

}  // namespace libhadoop


#endif /* LOGGER_H_ */
