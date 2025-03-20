cmake_minimum_required (VERSION 3.22)

project (Platform_Types
    DESCRIPTION "Generic platform types"
    VERSION 1.0.0
    LANGUAGES C )

add_library(Platform_Types INTERFACE)

target_include_directories(Platform_Types INTERFACE
    .
)