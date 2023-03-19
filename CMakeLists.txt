cmake_minimum_required(VERSION 3.24)




project(SimpleCmake)

#set language
set(CMAKE_CXX_STANDARD 23)


## enable unit testing via "make test" once the code has been compiled.
#include(CTest)

# Function to prepend the subdirectory to source files in subdirectories
function(PREPEND var )
    set(listVar "")
    foreach(f ${${var}})
        list(APPEND listVar "${CMAKE_CURRENT_SOURCE_DIR}/${f}")
    endforeach(f)
    set(${var} "${listVar}" PARENT_SCOPE)
endfunction(PREPEND)




# Include source code and headers. This runs the CMakeLists.txt in each subdirectory.
# These can define their own libraries, executables, etc. as targets,
# but here we define all exportable targets in the root CMakeLists.txt.
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(app)



# Add the test directory. It is optional and can be disabled during with
#   cmake -DBUILD_TESTING=OFF ..
# To run unit tests produced here, we only need to run:
#   make test
# or
#   ctest
# In case your tests are printing to console, you can view their output to
# stdout with:
#   ctest -V



# Add the library CMakeDemo as a target, with the contents of src/ and include/
# as dependencies.




# help with the include on C projects


#route all the output libraries and binary to the proper location
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out/run")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out/bin")

add_library(demo_library SHARED ${CMakeDemo_SRC} ${CMakeDemo_INC})
target_include_directories(demo_library PRIVATE include)

target_link_libraries(readerApp demo_library)

