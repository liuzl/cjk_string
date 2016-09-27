licenses(["notice"])

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "cjk_string",
    hdrs = glob(["*.hpp"],),
    srcs = glob(["*.cpp"], exclude = ["main.cpp",]),
)

cc_binary(
    name = "cjktest",
    srcs = ["main.cpp",],
    deps = [":cjk_string",],
)
