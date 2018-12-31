#include "../includes/status.h"

#include "../third_party/googletest/googletest/include/gtest/gtest.h"

namespace {

  TEST(StatusTest, ConstructDefaultStatusObject) {
    Status state;
    ASSERT_EQ(state.State(), OK);
  }

  TEST(StatusTest, ConstructStatusFromStateAndMessage) {
    Status unimplemented_state(UNIMPLEMENTED, "Not implemented");
    ASSERT_EQ(unimplemented_state.State(), UNIMPLEMENTED);
    ASSERT_EQ(unimplemented_state.Message(), "Not implemented");
  }

  TEST(StatusTest, ConstructStatusFromAnotherStatus) {
    Status unimplemented_state(UNIMPLEMENTED, "Not implemented");
    Status other_state(unimplemented_state);
    ASSERT_EQ(other_state.State(), UNIMPLEMENTED);
    ASSERT_EQ(other_state.Message(), "Not implemented");
  }

  TEST(StatusTest, OkStatusCastsToTrue) {
    Status ok_state;
    ASSERT_TRUE(ok_state);
  }

  TEST(StatusTest, NonOkStatusCastsToFalse) {
    Status non_ok_state(CANCELLED, "Not ok status");
    ASSERT_FALSE(non_ok_state);
  }

  TEST(StatusTest, ConstructAnOkStatusObject) {
    Status ok_state = Status::OkStatus();
    ASSERT_TRUE(ok_state);
    ASSERT_EQ(ok_state.State(), OK);
  }

  TEST(StatusTest, IsOkMethodReturnsTrueWithOkStatus) {
    Status ok_state = Status::OkStatus();
    ASSERT_TRUE(ok_state.IsOk());
    ASSERT_EQ(ok_state.State(), OK);
  }

  TEST(StatusTest, IsOkMethodReturnsFalseWithNonOkStatus) {
    Status nonok_state = Status::CancelledError("Cancelled");
    ASSERT_FALSE(nonok_state.IsOk());
    ASSERT_EQ(nonok_state.State(), CANCELLED);
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
