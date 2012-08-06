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
#include <stdexcept>

#include "util/Logger.h"

#include "DataInput.h"
#include "DataOutput.h"


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

	static int32_t writeString(DataOutput& out, string& s) {
		wstring x(s.begin(), s.end());
		return UTF8::writeString(out, x);
	}

	static int32_t writeString(DataOutput& out, wstring& s) {
		if ((int32_t) s.length() > 0xffff / 3) {         // maybe too long
			LOG_WARN("UTF8",
					"truncating long string: " << s.length() << " chars, starting with " );
//			<< s.substr(0, 20)
			s = s.substr(0, 0xffff / 3);
		}

		int32_t len = utf8Length(s);
		if (len > 0xffff)                             // double-check length
			throw range_error("string too long!");

		out.writeShort(len);
		writeChars(out, s, 0, s.length());
		return len;
	}

	/** Returns the number of bytes required to write this. */
	static int32_t utf8Length(const wstring string) {
		int32_t stringLength = string.length();
		int32_t utf8Length = 0;
		for (int32_t i = 0; i < stringLength; i++) {
			wchar_t c = string[i];
			if (c <= 0x007F) {
				utf8Length++;
			} else if (c > 0x07FF) {
				utf8Length += 3;
			} else {
				utf8Length += 2;
			}
		}
		return utf8Length;
	}

//TOTEST
	static void writeChars(DataOutput& out, wstring& s, int32_t start,
			int32_t length) {
		int32_t end = start + length;
		for (int32_t i = start; i < end; i++) {
			int32_t code = s[i];
			if (code <= 0x7F) {
				out.writeByte((int8_t) code);
			} else if (code <= 0x07FF) {
				out.writeByte((int8_t)(0xC0 | ((code >> 6) & 0x1F)));
				out.writeByte((int8_t)(0x80 | (code & 0x3F)));
			} else {
				out.writeByte((int8_t)(0xE0 | ((code >> 12) & 0X0F)));
				out.writeByte((int8_t)(0x80 | ((code >> 6) & 0x3F)));
				out.writeByte((int8_t)(0x80 | (code & 0x3F)));
			}
		}
	}
}
;

} /* namespace libhadoop */
#endif /* UTF8_H_ */
