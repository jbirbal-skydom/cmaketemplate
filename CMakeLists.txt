cmake_minimum_required(VERSION 3.24)




project(SimpleCmake VERSION 1.0)

#add a config file for versions and options
configure_file(headerconfig.h.in headerconfig.h)


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


#  Add Debug
option(BUGGER "debug and use experimental features." OFF)

if (WITH_DEBUG)
    MESSAGE(STATUS "WITH_DEBUG")
    add_definitions(-DUSE_DEBUG)
endif()





# To run unit tests produced here, we only need to run:
#   make test
# or
#   ctest
# In case your tests are printing to console, you can view their output to
# stdout with:
#   ctest -V
# Enable testing via CTest

enable_testing()
ADD_SUBDIRECTORY(tests)









# help with the include on C projects


#route all the output libraries and binary to the proper location
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out/run")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out/bin")

add_library(${PROJECT_NAME} SHARED ${CMakeDemo_SRC} ${CMakeDemo_INC})

# Add the library CMakeDemo as a target, with the contents of src/ and include/  as dependencies.
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

target_link_libraries(readerApp ${PROJECT_NAME})


