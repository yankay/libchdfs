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
#include <cctype>

namespace libhadoop {

class StringUtils {
public:
	static std::string trim(const std::string &str) {
		std::string result;
		std::istringstream trimmer(str);
		trimmer >> result;
		return result;
	}

	static std::vector<std::string> getStrings(const std::string& str) {
		std::vector<std::string> v(getStringCollection(str));
		return v;
	}

	static std::vector<std::string> getStringCollection(
			const std::string& str) {
		std::vector<std::string> values;
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

	static std::vector<std::string> getTrimmedStringCollection(
			const std::string& str) {
		std::vector<std::string> values;
		std::istringstream ss(str);
		while (!ss.eof()) {
			std::string result;
			ss >> result;
			values.push_back(result);
		}
		return values;
	}

	static std::string arrayToString(const std::vector<std::string>& strs) {
		std::stringstream ss;
		std::string sep = "";
		for (size_t i = 0; i < strs.size(); ++i) {
			ss << sep << strs[i];
			sep = ",";
		}
		return ss.str();
	}
	static bool equalsIgnoreCase(const std::string& one,
			const std::string& anotherString) {
		return (one == anotherString) ?
				true :
				(anotherString.length() == one.length())
						&& StringUtils::regionMatches(true, one, 0,
								anotherString, 0, one.length());
	}

	static bool regionMatches(bool ignoreCase, const std::string& one,
			int toffset, const std::string& other, int ooffset, int len) {
		std::string ta(one);
		int to = toffset;
		std::string pa(other);
		int po = ooffset;
		// Note: toffset, ooffset, or len might be near -1>>>1.
		if ((ooffset < 0) || (toffset < 0)
				|| (toffset > (long) one.length() - len)
				|| (ooffset > (long) other.length() - len)) {
			return false;
		}
		while (len-- > 0) {
			char c1 = ta[to++];
			char c2 = pa[po++];
			if (c1 == c2) {
				continue;
			}
			if (ignoreCase) {
				char u1 = toupper(c1);
				char u2 = toupper(c2);
				if (u1 == u2) {
					continue;
				}
				if (tolower(u1) == tolower(u2)) {
					continue;
				}
			}
			return false;
		}
		return true;
	}

private:

};

} /* namespace libhadoop */
#endif /* STRINGUTILS_H_ */
