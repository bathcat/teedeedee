cc_test(
  name = "test",
  srcs = [
    "fizz_buzz_tests.cc",
    "fizz_buzz.h",
  ],
  copts = [
      "-std=c++20",
  ],
  deps = ["@com_google_googletest//:gtest_main"],
)




cc_binary(
  name = "main",
  srcs = [
    "main.cc",
    "fizz_buzz.h",
  ],
)