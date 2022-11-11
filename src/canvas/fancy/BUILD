cc_test(
  name = "test",
  srcs = [
      "drawingcontext_tests.cc",
      "drawingcontext.h",
      "turtle.h"
  ],
  copts = [
      "-std=c++20"
  ],
  deps = ["@com_google_googletest//:gtest_main"],
)


cc_binary(
  name = "main",
  srcs = [
      "third_party_library_turtle.h",
      "drawingcontext.h",
      "turtle.h",
      "main.cc"
  ],
  copts = [
      "-std=c++20"
  ],
)