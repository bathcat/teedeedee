cc_test(
  name = "test",
  srcs = [
      "drawing_context_tests.cc",
      "drawing_context.h",
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
      "drawing_context.h",
      "turtle.h",
      "main.cc",
  ],
  copts = [
      "-std=c++20"
  ],
)