add_library(
    Json
    src/Json/String.h   
    src/Json/String.cpp
    src/Json/Json.h
    src/Json/Json.cpp
    src/Json/JsonData.cpp
    src/Json/JsonData.h
)

target_include_directories(Json PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_definitions(Json PUBLIC JSON_VERSION=1)