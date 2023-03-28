cmake_minimum_required(VERSION 3.24)

#route all the output libraries and binary to the proper location
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out/run")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out/bin")

add_executable(TestCMakeDemo test_cmake_demo.cpp)
# include headers easier
target_include_directories(TestCMakeDemo PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(TestCMakeDemo ${PROJECT_NAME})



# Add our test as runnable via CTest
add_test(NAME "TestCMakeDemo"  COMMAND "TestCMakeDemo" WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/run)
install(TARGETS TestCMakeDemo DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/out/run)
