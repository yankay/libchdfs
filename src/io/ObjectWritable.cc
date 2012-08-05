/*
 * ObjectWritable.cc
 *
 *  Created on: Jul 29, 2012
 *      Author: yank1
 */

#include "ObjectWritable.h"

namespace libhadoop {
void ObjectWritable::writeObject(DataOutput& out, shared_ptr<Object> instance,
		Class& declaredClass, const Configuration& conf) {
	if (!instance) {                       // null
		instance.reset(new NullInstance(declaredClass, conf));
		declaredClass = Class(const_cast<type_info*>(&typeid(Writable)));
	}

//	UTF8.writeString(out, declaredClass.getName()); // always write declared
//
//	if (declaredClass.isArray()) {                // array
//		int length = Array.getLength(instance);
//		out.writeInt(length);
//		for (int i = 0; i < length; i++) {
//			writeObject(out, Array.get(instance, i),
//					declaredClass.getComponentType(), conf);
//		}
//
//	} else if (declaredClass == String.class) {   // String
//		UTF8.writeString(out, (String) instance);
//
//	} else if (declaredClass.isPrimitive()) {     // primitive type
//
//		if (declaredClass == Boolean.TYPE) {        // boolean
//			out.writeBoolean(((Boolean) instance).booleanValue());
//		} else if (declaredClass == Character.TYPE) { // char
//			out.writeChar(((Character) instance).charValue());
//		} else if (declaredClass == Byte.TYPE) {    // byte
//			out.writeByte(((Byte) instance).byteValue());
//		} else if (declaredClass == Short.TYPE) {   // short
//			out.writeShort(((Short) instance).shortValue());
//		} else if (declaredClass == Integer.TYPE) { // int
//			out.writeInt(((Integer) instance).intValue());
//		} else if (declaredClass == Long.TYPE) {    // long
//			out.writeLong(((Long) instance).longValue());
//		} else if (declaredClass == Float.TYPE) {   // float
//			out.writeFloat(((Float) instance).floatValue());
//		} else if (declaredClass == Double.TYPE) {  // double
//			out.writeDouble(((Double) instance).doubleValue());
//		} else if (declaredClass == Void.TYPE) {    // void
//		} else {
//			throw new IllegalArgumentException(
//					"Not a primitive: " + declaredClass);
//		}
//	} else if (declaredClass.isEnum()) {         // enum
//		UTF8.writeString(out, ((Enum) instance).name());
//	} else if (Writable.class.isAssignableFrom(declaredClass)) { // Writable
//		UTF8.writeString(out, instance.getClass().getName());
//		((Writable) instance).write(out);
//
//	} else {
//		throw new IOException(
//				"Can't write: " + instance + " as " + declaredClass);
//	}
}

shared_ptr<Object> ObjectWritable::readObject(DataInput& in,
		ObjectWritable& objectWritable, const Configuration& conf) {
	return shared_ptr<Object>();
}
} /* namespace libhadoop */
