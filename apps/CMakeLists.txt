# apps/CMakeLists.txt

add_executable(advoco advoco.cpp)

target_link_libraries(advoco
    PRIVATE
    advoco_core_day01
)
