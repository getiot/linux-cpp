cmake_minimum_required(VERSION 3.12)
project(Cpp_Call_Python)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Eigen3
find_package(Eigen3 REQUIRED)
if(Eigen3_FOUND)
    include_directories(${EIGEN3_INCLUDE_DIR})

    message("-------- Eigen --------")
    message("${EIGEN3_INCLUDE_DIR}")
    message("-----------------------")
endif()

# Boost
find_package(Boost REQUIRED COMPONENTS system python numpy)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})

    message("-------- Boost --------")
    message("${Boost_INCLUDE_DIRS}")
    message("${Boost_LIBRARY_DIRS}")
    message("${Boost_LIBRARIES}")
    message("-----------------------")
endif()

# Python
find_package(Python3 REQUIRED COMPONENTS Development)
if(Python3_FOUND)
    include_directories(${Python3_INCLUDE_DIRS})
    link_directories(${Python3_LIBRARY_DIRS})

    message("-------- Python --------")
    message("${Python3_INCLUDE_DIRS}")
    message("${Python3_LIBRARY_DIRS}")
    message("${Python3_LIBRARIES}")
    message("------------------------")
endif()

add_executable(eigenArrayToNumpy eigenArrayToNumpy.cpp)
target_link_libraries(eigenArrayToNumpy ${Boost_LIBRARIES} ${Python3_LIBRARIES})
set_target_properties(eigenArrayToNumpy PROPERTIES SUFFIX .exe)

add_executable(runPythonFromFile runPythonFromFile.cpp)
target_link_libraries(runPythonFromFile ${Boost_LIBRARIES} ${Python3_LIBRARIES})
set_target_properties(runPythonFromFile PROPERTIES SUFFIX .exe)

file(GLOB PY_FILES ${CMAKE_SOURCE_DIR}/*.py)
file(COPY ${PY_FILES} DESTINATION ${CMAKE_BINARY_DIR})