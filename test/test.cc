#include "gtest/gtest.h"

#include "util/Logger.h"

int main(int argc, char **argv) {
	libhadoop::loglevel=DEBUG;
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
