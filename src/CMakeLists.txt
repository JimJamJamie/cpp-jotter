include(FetchContent)

# FetchContent_Declare(
#   fmt
#   GIT_REPOSITORY https://github.com/fmtlib/fmt
#   GIT_TAG        1be298e1bd68957e4cd352e1f676f00e07dcfb57) # 12.2.0
# FetchContent_MakeAvailable(fmt)

add_executable(helloworld)

target_sources(helloworld PRIVATE helloworld.cpp)
target_compile_features(helloworld PUBLIC cxx_std_17)
# target_link_libraries(helloworld PRIVATE fmt::fmt)

set_target_properties(helloworld PROPERTIES CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)
