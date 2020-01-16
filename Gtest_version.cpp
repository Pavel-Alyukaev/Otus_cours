
#include <gtest/gtest.h>
#include "lib.h"

class Test_valid_version : public ::testing::Test {
public:
    Test_valid_version() {/* init protected members here */ }
    ~Test_valid_version() {/* free protected members here */ }
    void SetUp() {/* called before every test */ }
    void TearDown() {/* called after every test */ }

protected:
    /*  none yet */
};

TEST_F(Test_valid_version, Version) {
   ASSERT_GT(version(), 0); 
}


int main( int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 