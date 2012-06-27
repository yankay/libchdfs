/*
 * Configuration.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */
#include "Configuration.h"

namespace hadoop {

Configuration::~Configuration() {
}

Configuration::Configuration() {
	Configuration(true);
}

Configuration::Configuration(const bool loadDefaults) {

}

int Configuration::returnOne() {
	return 1;
}

} /* namespace hadoop */
