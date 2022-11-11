cc_test(
  name = "test",
  srcs = [
      "drawing_context_tests.cc",
      "drawing_context.h",
      "third_party_library_turtle.h"
  ],
  deps = ["@com_google_googletest//:gtest_main"],
)

cc_binary(
  name = "main",
  srcs = [
      "third_party_library_turtle.h",
      "drawing_context.h",
      "main.cc"
  ],
)