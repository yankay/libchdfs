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
}
//TODO with replace ${ENV}
std::string Configuration::substituteVars(const std::string& expr) {
	if (expr.empty())
		return expr;
	std::string result(expr);
	size_t b, e = 0;
	while (-1 != (b = result.find("${", 0)) && -1 != (e = result.find("}", b))) {
//		std::cout << b << "," << e << std::endl;
		std::string var = result.substr(b + 2, e - b - 2);
//		std::cout << var << std::endl;
		var = getenv(var.c_str());
//		std::cout << var << std::endl;
		result.replace(b, e - b + 1, var);
	}
	return result;
}

std::string Configuration::get(const std::string& name) {
	return substituteVars(properties[name]);
}

void Configuration::set(const std::string& name, const std::string& value) {
	properties[name] = value;
}

} /* namespace hadoop */
