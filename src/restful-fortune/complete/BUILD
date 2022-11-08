cc_test(
  name = "test",
  srcs = [
      "fortune_tests.cc",
      "fortune.h",
  ],
  deps = [
    "@com_google_googletest//:gtest_main",
    "@cpp_httplib//:cpp-httplib"
  ],
)

cc_binary(
  name = "main",
  srcs = [
    "main.cc",
    "fortune_generator.h",
    "http_client.h",
    "http_client_adapter.h"
  ],
  deps = [
    "@cpp_httplib//:cpp-httplib",
    "@nlohmann_json//:nlohmann-json",
  ],
)