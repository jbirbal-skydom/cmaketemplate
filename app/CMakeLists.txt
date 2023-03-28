cmake_minimum_required(VERSION 3.24)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out/run")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out/bin")




add_executable(readerApp reader.cpp )

target_include_directories(readerApp PRIVATE ${PROJECT_SOURCE_DIR}/include)