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

using namespace std;

namespace libhadoop {

class Configuration {
public:
	string get(const string& name) const;
	string getTrimmed(const string& name) const;
	string getRaw(const string& name) const;
	void set(const string& name, const string& value);
	void unset(const string& name);
	void setIfUnset(const string& name, const string& value);
	string get(const string& name, const string& defaultValue) const;

	int32_t getInt(const string& name, const int32_t defaultValue) const;
	void setInt(const string& name, const int32_t value);
	int64_t getLong(const string& name, const int64_t defaultValue) const;
	void setLong(const string& name, const int64_t value);
	float getFloat(const string& name, const float defaultValue) const;
	void setFloat(const string& name, const float value);
	bool getBoolean(const string& name, const bool defaultValue) const;
	void setBoolean(const string& name, const bool value);
	void setBooleanIfUnset(const string& name, bool value);
	vector<string> getStringCollection(const string& name) const;
	vector<string> getTrimmedStringCollection(const string& name) const;
	void setStrings(const string& name,
			const vector<string>& values);
	int32_t size() const;
	void clear();
// Iterator<Map.Entry<String, String>> iterator() ;
//	string substituteVars(const string& expr);

private:
	map<string, string> properties;
	string substituteVars(const string& expr) const;
	string getHexDigits(const string& exper) const;

};

} /* namespace libhadoop */
#endif /* CONFIGURATION_H_ */
