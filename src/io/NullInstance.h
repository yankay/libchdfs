/*
 * NullInstance.h
 *
 *  Created on: Aug 5, 2012
 *      Author: yank1
 */

#ifndef NULLINSTANCE_H_
#define NULLINSTANCE_H_

#include <string>

#include "lang/Object.h"
#include "lang/Class.h"
#include "conf/Configurable.h"
#include "conf/Configured.h"
#include "UTF8.h"
#include "Writable.h"

using namespace std;

namespace libhadoop {
class NullInstance: public Configured, public Writable {
public:
	NullInstance(const string& declaredClass, const Configuration& conf) :
			Configured(conf), declaredClass(declaredClass) {

	}

	void write(DataOutput& out) {
	      UTF8::writeString(out, declaredClass);
	}

	void readFields(DataInput& in) {
		wstring className = UTF8::readString(in);
		if (declaredClass.empty()) {
			string s(className.begin(), className.end());
			declaredClass = s;
		}
	}

private:
	string declaredClass;

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
