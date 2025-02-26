#include <gtest/gtest.h>
#include "RollingMedian.h"

TEST(RollingMeanTest, test1) {
    std::string hstr("11pm"), hstr1("11pm");
    EXPECT_EQ(hstr, hstr1);

	const int COUNT = 20;
    const int WIN_LENGTH = 5;
    const int DEST_STRIDE = 1;
    double src[COUNT];
    double *dest =
            new double[OrderedStructs::RollingMedian::dest_size(COUNT, WIN_LENGTH, DEST_STRIDE)];
    int result = 0;

    for (int i = 0; i < COUNT; ++i) {
        src[i] = 2.0 * i;
    }
    // Set
    //result |=  OrderedStructs::RollingMedian::odd_index(src, 1, COUNT, WIN_LENGTH, dest, DEST_STRIDE);

	 // Test
    for (size_t i = 0; i < OrderedStructs::RollingMedian::dest_size(COUNT, WIN_LENGTH, DEST_STRIDE);
         i += DEST_STRIDE) {
        //        std::cout << i << " " << dest[i] << std::endl;
        result |= dest[i] != 4. + 2.0 * i;
    }
    delete[] dest;

   
}