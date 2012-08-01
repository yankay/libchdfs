/*
 * DataInput.h
 *
 *  Created on: Aug 1, 2012
 *      Author: yank1
 */

#ifndef DATAINPUT_H_
#define DATAINPUT_H_

#include <stdlib.h>
#include <string>

using namespace std;

namespace libhadoop {

class DataInput {

	virtual void readFully(int8_t b[], int32_t len);

	virtual void readFully(int8_t b[], int32_t off, int32_t len);

	virtual int32_t skipBytes(int32_t n);

	virtual bool readBoolean();

	virtual int8_t readByte();

	virtual int8_t readUnsignedByte();

	virtual int16_t readShort();

	virtual int8_t readUnsignedShort();

	virtual int16_t readChar();

	virtual int32_t readInt();

	virtual int64_t readLong();

	virtual float readFloat();

	virtual double readDouble();

	virtual string readLine();

	virtual string readUTF();

};

} /* namespace libhadoop */
#endif /* DATAINPUT_H_ */
