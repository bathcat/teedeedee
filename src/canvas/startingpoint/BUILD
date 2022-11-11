cc_test(
  name = "test",
  srcs = [
      "drawingcontext_tests.cc",
      "drawingcontext.h",
      "third_party_library_turtle.h"
  ],
  deps = ["@com_google_googletest//:gtest_main"],
)

cc_binary(
  name = "main",
  srcs = [
      "third_party_library_turtle.h",
      "drawingcontext.h",
      "main.cc"
  ],
)