cmake_minimum_required (VERSION 3.22)

project (Demo
    DESCRIPTION "Demo project"
    VERSION 1.0.0
    LANGUAGES C CXX )

option(BUILD_TESTS "Build test programs" ON)

if(BUILD_TESTS)
    message("Tests enabled")
    # Enable tests before all test subdirectories have been added
    enable_testing()

    add_subdirectory(test)
endif()

# Main project executalbe
add_executable(Demo)

add_subdirectory(src)

target_sources(Demo PRIVATE
    main.c
)

target_link_libraries(Demo PRIVATE
    Platform_Types
    I2C_driver
    Mem_driver
    Sensor_driver
)

if(BUILD_TESTS)
    # Download and unpack googletest at configure time
    configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
    execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
    )
    execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
    )

    # Prevent GoogleTest from overriding our compiler/linker options
    # when building with Visual Studio
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # Add googletest directly to our build. This adds the following targets:
    # gtest, gtest_main, gmock and gmock_main
    add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                     "${CMAKE_BINARY_DIR}/googletest-build"
    )
endif()