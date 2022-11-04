cc_test(
  name = "test",
  srcs = [
    "fizz_buzz_tests.cc",
    "fizz_buzz.h",
    "fizz_buzz.cc",
  ],
  deps = ["@com_google_googletest//:gtest_main"],
)


cc_binary(
  name = "main",
  srcs = [
    "main.cc",
    "fizz_buzz.h",
    "fizz_buzz.cc",
  ],
)