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

	static void readChars(int8_t bytes[], wstringstream& buffer,
			int32_t nBytes) {
		int32_t i = 0;
		int32_t f1 = 0x0000001F;
		int32_t f3 = 0x0000003F;
		int32_t f7 = 0x0000007F;
		int32_t clean = 0x0000ffff;
		while (i < nBytes) {
			int8_t b = bytes[i++];
			if ((b & 0x80) == 0) {
				buffer.put((wchar_t) ((int16_t)((b & f7) & clean)));
			} else if ((b & 0xE0) != 0xE0) {
				buffer.put(
						(wchar_t) ((int16_t)(
								(((b & f1) << 6) | (bytes[i++] & f3))) & clean));
			} else {
				int32_t a = (b & 0x0F) << 12;
				int32_t b = (bytes[i++] & f3) << 6;
				int32_t c = bytes[i++] & f3;
				buffer.put((wchar_t) ((a | b | c) & clean));
			}
		}
	}
}
;

} /* namespace libhadoop */
#endif /* UTF8_H_ */
