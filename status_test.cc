#include "status.h"
#include "gtest/gtest.h"

namespace {

  TEST(StatusTest, ConstructDefaultStatusObject) {
    Status state;
    ASSERT_TRUE(state);
  }

  TEST(StatusTest, ConstructAnOkStatusObject) {
    Status ok_state = Status::OkStatus();
    ASSERT_TRUE(ok_state);
  }

  TEST(StatusTest, ConstructAnInvalidStatusObject) {
    Status invalid_state = Status::InvalidError();
    ASSERT_FALSE(invalid_state);
  }

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
