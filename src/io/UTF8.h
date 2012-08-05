/*
 * UTF8.h
 *
 *  Created on: Aug 5, 2012
 *      Author: yank1
 */

#ifndef UTF8_H_
#define UTF8_H_

#include <string>
#include <sstream>
#include <stdlib.h>

#include "DataInput.h"

using namespace std;

namespace libhadoop {

class UTF8 {
public:
	static wstring readString(DataInput& in) {
		int32_t bytes = in.readUnsignedShort();
		wstringstream buffer;
		readChars(in, buffer, bytes);
		return buffer.str();
	}
	static void readChars(DataInput& in, wstringstream& buffer,
			int32_t nBytes) {
		int8_t bytes[nBytes];
		in.readFully(bytes, nBytes);
		readChars(bytes, buffer, nBytes);
	}

	static void readChars(int8_t bytes[], wstringstream& buffer, int32_t nBytes) {
		int32_t i(0);
		while (i < nBytes) {
			int8_t b = bytes[i++];
			if ((b & 0x80) == 0) {
				buffer.put((wchar_t) ((int32_t) b & 0x7F));
			} else if ((b & 0xE0) != 0xE0) {
				buffer.put(
						(wchar_t) ((((int32_t) b & 0x1F) << 6)
								| ((int32_t) bytes[i++] & 0x3F)));
			} else {
				buffer.put(
						(wchar_t) ((((int32_t) b & 0x0F) << 12)
								| (((int32_t) bytes[i++] & 0x3F) << 6)
								| ((int32_t) bytes[i++] & 0x3F)));
			}
		}
	}
}
;

} /* namespace libhadoop */
#endif /* UTF8_H_ */
