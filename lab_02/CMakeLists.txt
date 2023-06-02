cmake_minimum_required(VERSION 3.10.0)
project(lab2 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app src/main.cpp "inc/Exception/BaseException.h" "inc/Exception/IteratorException.h" "inc/Exception/VectorException.h" "inc/Iterator/BaseIterator.h" "inc/Vector/BaseVector.h" "inc/Vector/Vector.h" "inc/Vector/Vector.hpp" "inc/Concepts/VectorConcepts.h")

target_include_directories(app PUBLIC inc/Error
                                      inc/Iterator
                                      inc/Vector
									  inc/Concepts)
