/*
 * StringUtils.h
 *
 *  Created on: Jul 1, 2012
 *      Author: yank1
 */

#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

namespace libhadoop {

class StringUtils {
public:
	StringUtils();
	virtual ~StringUtils();

	static std::string trim(const std::string &str) {
		std::string result;
		std::stringstream trimmer;
		trimmer << str;
		trimmer >> result;
		return result;
	}

	static std::vector<std::string> getStrings(const std::string& str) {
		return getStringCollection(str);;
	}

	static std::vector<std::string> getStringCollection(
			const std::string& str) {
		std::vector < std::string > values;
		if (str.empty())
			return values;
		size_t begin = 0;
		size_t end = 0;
		while ((end = str.find(",", begin)) != std::string::npos) {
//			std::cout << end << std::endl;
			values.push_back(str.substr(begin, end - begin));
			begin = end + 1;
		}
		if (begin < str.length()) {
			values.push_back(str.substr(begin, str.length() - begin));
		}
		return values;
	}

private:

};

} /* namespace libhadoop */
#endif /* STRINGUTILS_H_ */
