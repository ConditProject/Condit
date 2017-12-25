## Description:
## Condit is a status-tracking type for C++ binaries.

package(default_visibility = ["//visibility:public"])

cc_library(
  name = "status",
  srcs = ["src/status.cc"],
  hdrs = ["src/status.h",]
)

cc_test(
  name = "status_test",
  srcs = ["src/status_test.cc"],
  deps = [
    "@com_google_googletest//:gtest",
    ":status",
  ],
)
