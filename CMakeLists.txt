cmake_minimum_required (VERSION 3.8)

project ("TestYOCTO")

set(CXX_STANDARD_REQUIRED 17)

add_executable(${PROJECT_NAME} 
                src/main.cpp
                src/AutocompleteSystem.cpp)
target_include_directories(${PROJECT_NAME} 
                            PUBLIC 
                            ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} -pthread)

install(TARGETS ${PROJECT_NAME})