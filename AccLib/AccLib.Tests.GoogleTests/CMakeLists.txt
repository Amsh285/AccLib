cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    string_tests
    string_tests.cpp
    ../AccLib/stringhelper.cpp
    ../AccLib/String.cpp
)

add_executable(
    vector_tests
    vector_tests.cpp
)

add_executable(
    unique_pointer_tests
    unique_pointer_tests.cpp  
)

add_executable(
    stringhelper_tests
    stringhelper_tests.cpp
    ../AccLib/stringhelper.cpp
)

target_link_libraries(
    string_tests
    gtest_main
)

target_link_libraries(
    vector_tests
    gtest_main
)

target_link_libraries(
    unique_pointer_tests
    gtest_main
)

target_link_libraries(
    stringhelper_tests
    gtest_main
)

include(GoogleTest)

gtest_discover_tests(string_tests)
gtest_discover_tests(vector_tests)
gtest_discover_tests(unique_pointer_tests)
gtest_discover_tests(stringhelper_tests)
