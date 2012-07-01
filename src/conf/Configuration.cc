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
	while (std::string::npos != (b = result.find("${", 0)) && std::string::npos != (e =
			result.find("}", b))) {
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

std::string Configuration::getTrimmed(const std::string& name) {
	std::string value = get(name);
	return libhadoop::StringUtils::trim(value);
}

std::string Configuration::getRaw(const std::string& name) {
	return properties[name];
}

void Configuration::set(const std::string& name, const std::string& value) {
	properties[name] = value;
}

void Configuration::unset(const std::string& name) {
	properties.erase(name);
}
void Configuration::setIfUnset(const std::string& name,
		const std::string& value) {
	if (get(name).empty()) {
		set(name, value);
	}
}

std::string Configuration::get(const std::string& name,
		const std::string& defaultValue) {
	std::string value(get(name));
	if (value.empty())
		value = defaultValue;
	return value;
}

std::string Configuration::getHexDigits(const std::string& exper) {
	return "";
}

int32_t Configuration::getInt(const std::string& name,
		const int32_t defaultValue) {
	return (int32_t) getLong(name, (int64_t) defaultValue);
}

void Configuration::setInt(const std::string& name, const int32_t value) {
	setLong(name, (int64_t) value);
}

int64_t Configuration::getLong(const std::string& name,
		const int64_t defaultValue) {
	std::string valueString = getTrimmed(name);
	if (valueString.empty()) {
		return defaultValue;
	}
	std::string hexString = getHexDigits(valueString);
	std::stringstream ss;
	if (hexString.empty()) {
		ss << valueString;
	} else {
		ss << std::hex << hexString;
	}
	int64_t v;
	ss >> v;
	return v;
}
void Configuration::setLong(const std::string& name, const int64_t value) {
	std::string value_str;
	std::stringstream ss;
	ss << value;
	ss >> value_str;
	set(name, value_str);
}

float Configuration::getFloat(const std::string& name,
		const float defaultValue) {
	std::string valueString = getTrimmed(name);
	if (valueString.empty()) {
		return defaultValue;
	}
	std::stringstream ss;
	ss << valueString;
	float v;
	ss >> v;
	return v;
}
void Configuration::setFloat(const std::string& name, const float value) {
	std::string value_str;
	std::stringstream ss;
	ss << value;
	ss >> value_str;
	set(name, value_str);
}

bool Configuration::getBoolean(const std::string& name,
		const bool defaultValue) {
	std::string valueString = getTrimmed(name);
	if ("true" == valueString)
		return true;
	else if ("false" == valueString)
		return false;
	else
		return defaultValue;
}
void Configuration::setBoolean(const std::string& name, const bool value) {
	if (value) {
		set(name, "true");
	} else {
		set(name, "false");
	}
}

void Configuration::setBooleanIfUnset(const std::string& name, bool value) {
	if (value) {
		setIfUnset(name, "true");
	} else {
		setIfUnset(name, "false");
	}
}

std::vector<std::string> Configuration::getStringCollection(const std::string& name) {
	std::string valueString = get(name);
	return libhadoop::StringUtils::getStringCollection(valueString);
}

std::vector<std::string> Configuration::getTrimmedStringCollection(const std::string& name) {
	std::string valueString = get(name);
	return libhadoop::StringUtils::getTrimmedStringCollection(valueString);
}

void Configuration::setStrings(const std::string& name,
		const std::vector<std::string>& values){
    set(name, libhadoop::StringUtils::arrayToString(values));
}

int32_t Configuration::size(){
	return properties.size();
}
void Configuration::clear(){
	properties.clear();
}

} /* namespace hadoop */
