load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip"],
  strip_prefix = "googletest-609281088cfefc76f9d0ce82e1ff6c30cc3591e5",
  sha256 = "5cf189eb6847b4f8fc603a3ffff3b0771c08eec7dd4bd961bfd45477dd13eb73"
)

http_archive(
  name = "range_v3",
  urls = ["https://github.com/ericniebler/range-v3/archive/refs/tags/0.12.0.zip"],
  strip_prefix = "range-v3-0.12.0",
  sha256 = "cbcb96beda464e71d293c07dec89ef5c0790ca83d37b0e199890893019441044"
)

http_archive(
  name = "cpp_httplib",
  urls = ["https://github.com/yhirose/cpp-httplib/archive/refs/tags/v0.11.2.zip"],
  strip_prefix = "cpp-httplib-0.11.2",
  build_file_content='cc_library(name = "cpp-httplib",srcs = ["httplib.h"],visibility = ["//visibility:public"])',
  sha256 = "afa64d0fbf3912943ed127b4f654d9c977eff7ecf13240341aca879b2e3f981d"
)

http_archive(
  name='nlohmann_json',
  urls=['https://github.com/nlohmann/json/releases/download/v3.11.2/include.zip'],
  strip_prefix = "single_include",
  build_file_content='cc_library(name = "nlohmann-json",srcs = ["nlohmann/json.hpp"],visibility = ["//visibility:public"])',
  sha256 = "e5c7a9f49a16814be27e4ed0ee900ecd0092bfb7dbfca65b5a421b774dccaaed",
)

http_archive(
    name = "hedron_compile_commands",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/ed994039a951b736091776d677f324b3903ef939.tar.gz",
    strip_prefix = "bazel-compile-commands-extractor-ed994039a951b736091776d677f324b3903ef939",
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")
hedron_compile_commands_setup()
