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

using namespace std;

namespace libhadoop {

class StringUtils {
public:
	static string trim(const string &str) {
		string result;
		istringstream trimmer(str);
		trimmer >> result;
		return result;
	}

	static vector<string> getStrings(const string& str) {
		vector < string > v(getStringCollection(str));
		return v;
	}

	static vector<string> getStringCollection(
			const string& str) {
		vector < string > values;
		if (str.empty())
			return values;
		size_t begin = 0;
		size_t end = 0;
		while ((end = str.find(",", begin)) != string::npos) {
//			cout << end << endl;
			values.push_back(str.substr(begin, end - begin));
			begin = end + 1;
		}
		if (begin < str.length()) {
			values.push_back(str.substr(begin, str.length() - begin));
		}
		return values;
	}

	static vector<string> getTrimmedStringCollection(
			const string& str) {
		vector < string > values;
		istringstream ss(str);
		while (!ss.eof()) {
			string result;
			ss >> result;
			values.push_back(result);
		}
		return values;
	}

	static string arrayToString(const vector<string>& strs) {
		stringstream ss;
		string sep = "";
		for (size_t i = 0; i < strs.size(); ++i) {
			ss << sep << strs[i];
			sep = ",";
		}
		return ss.str();
	}
	static bool equalsIgnoreCase(const string& one,
			const string& anotherString) {
		return (one == anotherString) ?
				true :
				(anotherString.length() == one.length())
						&& StringUtils::regionMatches(true, one, 0,
								anotherString, 0, one.length());
	}

	static bool regionMatches(bool ignoreCase, const string& one,
			int toffset, const string& other, int ooffset, int len) {
		string ta(one);
		int to = toffset;
		string pa(other);
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

	static string replace(const string& src, const string& target,
			const string& replacement) {
		string out = src;
		size_t i;
		while (string::npos != (i=out.find(target))) {
			out.replace(i, target.length(), replacement);
		}
		return out;
	}

private:

};

} /* namespace libhadoop */
#endif /* STRINGUTILS_H_ */
