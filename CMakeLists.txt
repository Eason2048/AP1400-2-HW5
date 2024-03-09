cmake_minimum_required(VERSION 3.13)
project(AP)

set(CMAKE_CXX_STANDARD 20)

set(GTest_ROOT /opt/homebrew/opt/googletest)
find_package(GTest REQUIRED)

include_directories(include/)
include_directories(/opt/homebrew/opt/googletest/include /opt/homebrew/opt/googletest)

include(FetchContent)

FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v5.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(main
        src/main.cpp
        src/unit_test.cpp
        src/espresso_based.cpp
        src/cappuccino.cpp
        src/mocha.cpp
)
target_link_libraries(main
        ftxui::screen
        ftxui::dom
        /opt/homebrew/opt/googletest/lib/libgtest.a
        /opt/homebrew/opt/googletest/lib/libgtest_main.a
        /opt/homebrew/opt/googletest/lib/libgmock.a
        /opt/homebrew/opt/googletest/lib/libgmock_main.a
)