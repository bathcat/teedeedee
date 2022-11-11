cc_test(
  name = "test",
  srcs = [
      "drawing_context_tests.cc",
      "drawing_context.h",
      "turtle.h"
  ],
  deps = ["@com_google_googletest//:gtest_main"],
)

cc_binary(
  name = "main",
  srcs = [
      "third_party_library_turtle.h",
      "drawing_context.h",
      "turtle_adapter.h",
      "turtle.h",
      "main.cc"
  ],
)