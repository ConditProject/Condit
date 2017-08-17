#include "status.h"
#include "gtest/gtest.h"

namespace {

  TEST(StatusTest, ConstructAnOkStatusObject) {
    Status state;
    ASSERT_TRUE(state);
  }

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
