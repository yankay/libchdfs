/*
 * Configuration.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */
#include <iostream>
#include "Configuration.h"

namespace hadoop {

Configuration::~Configuration() {
}

Configuration::Configuration() {
	Configuration(true);
}

Configuration::Configuration(const bool loadDefaults) {
	std::cout << loadDefaults << std::endl;
}
} /* namespace hadoop */
