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
#include <memory>
#include <tr1/memory>

#include "lang/Object.h"
#include "lang/Class.h"
#include "io/Writable.h"
#include "io/DataInput.h"
#include "io/DataOutput.h"
#include "conf/Configurable.h"

using namespace std;
using namespace std::tr1;

namespace libhadoop {

class ObjectWritable: public Writable, public Configurable {
public:

	ObjectWritable(shared_ptr<Object> instance) {
//		set(instance);
	}

	ObjectWritable(const Class& declaredClass, shared_ptr<Object> instance) :
			declaredClass(declaredClass), instance(instance) {
	}

	void set(shared_ptr<Object> instance) {
//		declaredClass = const_cast<type_info*>(&(typeid(*instance.get())));
//		this->instance = instance;
	}

	shared_ptr<Object> get();
//			{
//		return instance;
//	}

	const Class getDeclaredClass();
//	{
//		return declaredClass;
//	}

	 string toString() {
		stringstream ss;
//		ss << "OW[class=" << declaredClass->name() << ",value=" << "instance"
//				<< "]";
		return ss.str();
	}

	virtual void write(DataOutput& out) {
//		ObjectWritable::writeObject(out, instance, *declaredClass, conf);
	}

	virtual void readFields(DataInput& in) {
//		ObjectWritable::readObject(in, *this, this->conf);
	}

	static void writeObject(DataOutput& out, const Object& instance,
			const type_info& declaredClass, const Configuration& conf);

	static Object readObject(DataInput& in, ObjectWritable& objectWritable,
			const Configuration& conf);
//
	void setConf(const Configuration& conf) {
		this->conf = conf;
	}

	Configuration getConf() {
		return conf;
	}

private:
	Class declaredClass;
	shared_ptr<Object> instance;
	Configuration conf;
};

} /* namespace libhadoop */
#endif /* OBJECTWRITABLE_H_ */
