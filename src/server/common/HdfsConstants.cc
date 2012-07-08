/*
 * HdfsConstants.cc
 *
 *  Created on: Jul 6, 2012
 *      Author: yank1
 */

#include "HdfsConstants.h"

namespace libhadoop {
int32_t HdfsConstants::READ_TIMEOUT = 60 * 1000;
int32_t HdfsConstants::READ_TIMEOUT_EXTENSION = 3 * 1000;
int32_t HdfsConstants::WRITE_TIMEOUT = 8 * 60 * 1000;
int32_t HdfsConstants::WRITE_TIMEOUT_EXTENSION = 5 * 1000; //for write pipeline
}
/* namespace libhadoop */
