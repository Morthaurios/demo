cmake_minimum_required (VERSION 3.22)

project (Demo
    DESCRIPTION "Demo project"
    VERSION 1.0.0
    LANGUAGES C )

add_executable(Demo)

target_sources(Demo PRIVATE
    main.c
)

add_subdirectory(src)

target_link_libraries(Demo PRIVATE
    I2C_driver
)