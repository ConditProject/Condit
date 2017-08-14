## Description:
## Condit is a status-tracking type for C++ binaries.

cc_library(
  name = "status",
  srcs = ["status.cc"],
  hdrs = ["status.h", "state.h"],
)

cc_test(
  name = "status_test",
  srcs = ["status_test.cc"],
  deps = [
    "@gtest_repo//:gtest",
    ":status",
  ],
)