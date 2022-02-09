enable_testing()

include_directories("../../ext/googletest/googletest/include")
include_directories("../../ext/googletest/googlemock/include")

add_executable(MyFirstTest MyFirstTest.cpp)
target_link_libraries(MyFirstTest gtest_main gmock)
add_test(MyFirstTest MyFirstTest)