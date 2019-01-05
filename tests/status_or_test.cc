#include "../includes/status_or.h"

#include "../third_party/googletest/googletest/include/gtest/gtest.h"

// Example method that only adds positive integers and returns the sum.
StatusOr<int> PositiveAdder(int a, int b) {
  if (a < 0 || b < 0) {
    return Status::InvalidError("Arguments are negative");
  }
  return a + b;
}

// Used for ASSIGN OR RETURN test
int PosAddWrapper(int a, int b) {
  ASSIGN_OR_RETURN(int sum, PositiveAdder(a, b));
  return sum;
}
Status PosAddWrapperFailing(int a, int b) {
  ASSIGN_OR_RETURN(int sum, PositiveAdder(a, b));
}

namespace {
  TEST(StatusOrTest, ReturnsStatusOnInvalidArgument) {
    StatusOr<int> sum_or_status = PositiveAdder(0, -1);
    EXPECT_FALSE(sum_or_status.IsOk());
    EXPECT_EQ(sum_or_status.GetStatus().State(), INVALID);
  }

  TEST(StatusOrTest, ReturnsValidValue) {
    StatusOr<int> sum_or_status = PositiveAdder(3, 4);
    EXPECT_EQ(sum_or_status.GetValue(), 7);
    EXPECT_TRUE(sum_or_status.IsOk());
    EXPECT_EQ(sum_or_status.GetStatus(), Status::OkStatus());
  }

  TEST(StatusOrTest, AssignOrReturnMacroReturnsValue) {
    int sum = PosAddWrapper(3, 1);
    EXPECT_EQ(sum, 4);
  }

  TEST(StatusOrTest, AssignOrReturnReturnsStatus) {
    Status s = PosAddWrapperFailing(0, -1);
    EXPECT_FALSE(s.IsOk());
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
