
cc_test(
  name = "test",
  srcs = glob( ["*.cc","*.h"],exclude=["main.cc"]),
  deps = [
    "@com_google_googletest//:gtest_main",
    "@cpp_httplib//:cpp-httplib"
  ],
)

cc_binary(
  name = "main",
  srcs = glob( ["*.cc","*.h"],exclude=["*_tests.cc"]),  
  deps = [
    "@cpp_httplib//:cpp-httplib",
    "@nlohmann_json//:nlohmann-json",
  ],
)