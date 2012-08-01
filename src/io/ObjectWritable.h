/*
 * ObjectWritable.h
 *
 *  Created on: Jul 29, 2012
 *      Author: yank1
 */

#ifndef OBJECTWRITABLE_H_
#define OBJECTWRITABLE_H_

#include <typeinfo>
#include <string>
#include <sstream>

#include "lang/Object.h"
#include "io/Writable.h"
#include "io/DataInput.h"
#include "io/DataOutput.h"
#include "conf/Configurable.h"

using namespace std;

namespace libhadoop {

class ObjectWritable: public Writable, public Configurable {
public:

	ObjectWritable(const Object& instance) {
		set(instance);
	}

	ObjectWritable(const type_info& declaredClass, const Object& instance) :
			declaredClass(const_cast<type_info*>(&declaredClass)), instance(
					instance) {
	}

	void set(const Object& instance) {
		declaredClass = const_cast<type_info*>(&(typeid(instance)));
		this->instance = instance;
	}

	Object get() {
		return instance;
	}
	const type_info& getDeclaredClass() {
		return *declaredClass;
	}

	virtual string toString() {
		stringstream ss;
		ss << "OW[class=" << declaredClass->name() << ",value=" << "instance"
				<< "]";
		return ss.str();
	}
	virtual void write(DataOutput& out) {
		ObjectWritable::writeObject(out, instance, *declaredClass, conf);
	}

	virtual void readFields(DataInput& in) {
		ObjectWritable::readObject(in, *this, this->conf);
	}

	static void writeObject(DataOutput& out,const Object& instance,
			const type_info& declaredClass,const Configuration& conf);

	static Object readObject(DataInput& in, ObjectWritable& objectWritable,
			const Configuration& conf);

	virtual void setConf(const Configuration& conf) {
		this->conf = conf;
	}

	virtual Configuration getConf() {
		return conf;
	}

private:
	type_info* declaredClass;
	Object instance;
	Configuration conf;
};

} /* namespace libhadoop */
#endif /* OBJECTWRITABLE_H_ */
