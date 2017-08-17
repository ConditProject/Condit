#include "gtest/gtest.h"
#include "status.h"

namespace {

  TEST(StatusTest, ConstructDefaultStatusObject) {
    Status state;
    ASSERT_TRUE(state);
  }

  TEST(StatusTest, ConstructAnOkStatusObject) {
    Status ok_state = Status::OkStatus();
    ASSERT_TRUE(ok_state);
    ASSERT_EQ(ok_state.State(), OK);
  }

  TEST(StatusTest, ConstructAnInvalidStatusObject) {
    Status invalid_state =
      Status::InvalidError("This caused an invalid error");
    ASSERT_FALSE(invalid_state);
    ASSERT_EQ(invalid_state.State(), INVALID);
    ASSERT_EQ(invalid_state.Message(), "This caused an invalid error");
  }

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
