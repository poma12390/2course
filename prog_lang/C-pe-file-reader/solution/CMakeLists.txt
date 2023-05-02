file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.c
    src/*.h
    include/*.h
)

add_executable(section-extractor ${sources})
target_include_directories(section-extractor PRIVATE src include)
