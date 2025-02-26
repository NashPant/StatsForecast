#include "gtest/gtest.h"

//#pragma warning( disable : C4251);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}