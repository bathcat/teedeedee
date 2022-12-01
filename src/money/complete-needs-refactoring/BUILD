cc_test(
    name = "test",
    srcs = glob(
        [
            "*.cc",
            "*.h",
        ],
        exclude = ["main.cc"],
    ),
    copts = [
        "-std=c++20",
    ],
    deps = [
        "@com_google_googletest//:gtest_main",
    ],
)

cc_binary(
    name = "main",
    srcs = glob(
        [
            "*.cc",
            "*.h",
        ],
        exclude = ["*_tests.cc"],
    ),
    copts = [
        "-std=c++20",
    ],
)
