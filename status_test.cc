#include "status.h"
#include "gtest/gtest.h"

TEST(StatusTest, ConstructAnOkStatusObject) {
  Status state;
  ASSERT_TRUE(state);
}
