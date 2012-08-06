/*
 * DataOutput.h
 *
 *  Created on: Aug 1, 2012
 *      Author: yank1
 */

#ifndef DATAOUTPUT_H_
#define DATAOUTPUT_H_

#include <stdlib.h>
#include <string>

using namespace std;

namespace libhadoop {

class DataOutput {
public:
	virtual void write(int32_t b);

	virtual void write(int8_t b[], int32_t len);

	virtual void write(int8_t b[], int32_t off, int32_t len);

	virtual void writeBoolean(bool v);

	virtual void writeByte(int32_t v);

	virtual void writeShort(int32_t v);

	virtual void writeChar(int32_t v);

	virtual void writeInt(int32_t v);

	virtual void writeLong(int64_t v);

	virtual void writeFloat(float v);

	virtual void writeDouble(double v);

	virtual void writeBytes(string s);

	virtual void writeChars(string s);

	virtual void writeUTF(string s);

};

} /* namespace libhadoop */
#endif /* DATAOUTPUT_H_ */
