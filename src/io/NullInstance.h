/*
 * NullInstance.h
 *
 *  Created on: Aug 5, 2012
 *      Author: yank1
 */

#ifndef NULLINSTANCE_H_
#define NULLINSTANCE_H_

#include "lang/Object.h"
#include "lang/Class.h"
#include "conf/Configurable.h"
#include "conf/Configured.h"
#include "Writable.h"

namespace libhadoop {
class NullInstance: public Configured, public Writable {
public:
	NullInstance(const Class& declaredClass, const Configuration& conf) :
			Configured(conf), declaredClass(declaredClass) {

	}

	virtual void write(DataOutput& out) {

	}

	virtual void readFields(DataInput& in) {
//		String className = UTF8.readString(in);
//		declaredClass = PRIMITIVE_NAMES.get(className);
//		if (declaredClass == null) {
//			try {
//				declaredClass = getConf().getClassByName(className);
//			} catch (ClassNotFoundException e) {
//				throw new RuntimeException(e.toString());
//			}
//		}

	}

private:
	Class declaredClass;

};

} /* namespace libhadoop */
#endif /* NULLINSTANCE_H_ */
//   public void readFields(DataInput in) throws IOException {
//     String className = UTF8.readString(in);
//     declaredClass = PRIMITIVE_NAMES.get(className);
//     if (declaredClass == null) {
//       try {
//         declaredClass = getConf().getClassByName(className);
//       } catch (ClassNotFoundException e) {
//         throw new RuntimeException(e.toString());
//       }
//     }
//   }
//   public void write(DataOutput out) throws IOException {
//     UTF8.writeString(out, declaredClass.getName());
//   }
