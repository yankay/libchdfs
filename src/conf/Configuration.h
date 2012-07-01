/*
 * Configuration.h
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <map>
#include <vector>
#include <string>
#include <stdint.h>
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <sstream>

#include <util/StringUtils.h>

namespace hadoop {

class Configuration {
public:
	virtual ~Configuration();
	Configuration();

	std::string get(const std::string& name);
	std::string getTrimmed(const std::string& name);
	std::string getRaw(const std::string& name);
	void set(const std::string& name, const std::string& value);
	void unset(const std::string& name);
	void setIfUnset(const std::string& name, const std::string& value);
	std::string get(const std::string& name, const std::string& defaultValue);

	int32_t getInt(const std::string& name, const int32_t defaultValue);
	void setInt(const std::string& name, const int32_t value);
	int64_t getLong(const std::string& name, const int64_t defaultValue);
	void setLong(const std::string& name, const int64_t value);
	float getFloat(const std::string& name, const float defaultValue);
	void setFloat(const std::string& name, const float value);
	bool getBoolean(const std::string& name, const bool defaultValue);
	void setBoolean(const std::string& name, const bool value);
	void setBooleanIfUnset(const std::string& name, bool value);
	std::vector<std::string> getStrings(const std::string& name);
	std::vector<std::string> getTrimmeds(const std::string& name);
	void setStrings(const std::string& name,
			const std::vector<std::string>& values);
	int size();
	void clear();
// Iterator<Map.Entry<String, String>> iterator() ;
//	std::string substituteVars(const std::string& expr);

private:
	std::map<std::string, std::string> properties;
	std::string substituteVars(const std::string& expr);
	std::string getHexDigits(const std::string& exper);

};

} /* namespace hadoop */
#endif /* CONFIGURATION_H_ */
