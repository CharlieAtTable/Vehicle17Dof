set(curr_dir ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
    ./include
    ../include
)

aux_source_directory(${curr_dir}/source DIR_HELLO_SRCS)

add_library(steering_system ${DIR_HELLO_SRCS})    # 默认是静态库STATIC
