cc_test(
  name = "test",
  srcs = [
      "drawingcontext_tests.cc",
      "drawingcontext.h",
      "turtle_base.h",
      "c_turtle.h"
  ],
    copts = [
      "-std=c++20"
  ],
  deps = ["@com_google_googletest//:gtest_main"],
)


cc_binary(
  name = "main",
  srcs = [
    "main.cc",
  ],
)