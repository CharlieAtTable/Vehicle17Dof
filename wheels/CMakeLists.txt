set(curr_dir ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
    ./include
    ../include
    ../tires/include
)

aux_source_directory(${curr_dir}/source DIR_WORLD_SRCS)

add_library(wheels ${DIR_WORLD_SRCS})   # 默认是静态库STATIC
