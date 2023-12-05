add_library(advoco_core_day01
    day01.cpp
)

target_include_directories(advoco_core_day01 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input1.txt ${CMAKE_BINARY_DIR}/input1.txt COPYONLY)
