
#include <gtest/gtest.h>
#include "lib.h"

//class Test_valid_version : public ::testing::Test {
//public:
//    Test_valid_version() {/* init protected members here */ }
//    ~Test_valid_version() {/* free protected members here */ }
//    void SetUp() {/* called before every test */ }
//    void TearDown() {/* called after every test */ }

//protected:
    /*  none yet */
//};*/

TEST_F(Test_valid_version, Version) {
   ASSERT_GT(1, 0); 
}

