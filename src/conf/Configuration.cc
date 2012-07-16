/*
 * Configuration.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#include "Configuration.h"

namespace libhadoop {

string Configuration::substituteVars(const string& expr) const {
//	cout << expr << endl;
	if (expr.empty())
		return expr;
	string result(expr);
	size_t b, e = 0;
	while (string::npos != (b = result.find("${", 0)) && string::npos != (e =
			result.find("}", b))) {
//		cout << b << "," << e << endl;
		string var = result.substr(b + 2, e - b - 2);
//		cout << var << endl;
		var = getenv(var.c_str());
//		cout << var << endl;
		result.replace(b, e - b + 1, var);
	}
	return result;
}

string Configuration::get(const string& name) const {
	if (properties.end() == properties.find(name))
		return "";
	return substituteVars(properties.find(name)->second);
}

string Configuration::getTrimmed(const string& name) const {
	string value = get(name);
	return StringUtils::trim(value);
}

string Configuration::getRaw(const string& name) const {
	if (properties.end() == properties.find(name))
		return "";
	return properties.find(name)->second;
}

void Configuration::set(const string& name, const string& value) {
	properties[name] = value;
}

void Configuration::unset(const string& name) {
	properties.erase(name);
}
void Configuration::setIfUnset(const string& name, const string& value) {
	if (get(name).empty()) {
		set(name, value);
	}
}

string Configuration::get(const string& name,
		const string& defaultValue) const {
	string value(get(name));
	if (value.empty())
		value = defaultValue;
	return value;
}

string Configuration::getHexDigits(const string& exper) const {
	return "";
}

int32_t Configuration::getInt(const string& name,
		const int32_t defaultValue) const {
	return (int32_t) getLong(name, (int64_t) defaultValue);
}

void Configuration::setInt(const string& name, const int32_t value) {
	setLong(name, (int64_t) value);
}

int64_t Configuration::getLong(const string& name,
		const int64_t defaultValue) const {
	string valueString = getTrimmed(name);
	if (valueString.empty()) {
		return defaultValue;
	}
	string hexString = getHexDigits(valueString);
	stringstream ss;
	if (hexString.empty()) {
		ss << valueString;
	} else {
		ss << hex << hexString;
	}
	int64_t v;
	ss >> v;
	return v;
}
void Configuration::setLong(const string& name, const int64_t value) {
	string value_str;
	stringstream ss;
	ss << value;
	ss >> value_str;
	set(name, value_str);
}

float Configuration::getFloat(const string& name,
		const float defaultValue) const {
	string valueString = getTrimmed(name);
	if (valueString.empty()) {
		return defaultValue;
	}
	stringstream ss;
	ss << valueString;
	float v;
	ss >> v;
	return v;
}
void Configuration::setFloat(const string& name, const float value) {
	string value_str;
	stringstream ss;
	ss << value;
	ss >> value_str;
	set(name, value_str);
}

bool Configuration::getBoolean(const string& name,
		const bool defaultValue) const {
	string valueString = getTrimmed(name);
	if ("true" == valueString)
		return true;
	else if ("false" == valueString)
		return false;
	else
		return defaultValue;
}
void Configuration::setBoolean(const string& name, const bool value) {
	if (value) {
		set(name, "true");
	} else {
		set(name, "false");
	}
}

void Configuration::setBooleanIfUnset(const string& name, bool value) {
	if (value) {
		setIfUnset(name, "true");
	} else {
		setIfUnset(name, "false");
	}
}

vector<string> Configuration::getStringCollection(const string& name) const {
	string valueString = get(name);
	return StringUtils::getStringCollection(valueString);
}

vector<string> Configuration::getTrimmedStringCollection(
		const string& name) const {
	string valueString = get(name);
	return StringUtils::getTrimmedStringCollection(valueString);
}

void Configuration::setStrings(const string& name,
		const vector<string>& values) {
	set(name, StringUtils::arrayToString(values));
}

int32_t Configuration::size() const {
	return properties.size();
}
void Configuration::clear() {
	properties.clear();
}

} /* namespace libhadoop */
