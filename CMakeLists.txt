cmake_minimum_required(VERSION 3.21)
project(CMakeSFMLProject LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
    add_compile_options(-Werror -Wall -Wextra -Wpedantic -Wshadow)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/WX /W3 /permissive-)
    add_compile_options(/MP)
endif()

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
include(FetchContent)

Set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(ImGui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG v1.88
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(ImGui)

set(IMGUI_DIR "${imgui_SOURCE_DIR}")
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_SFML_IMGUI_DEMO ON)
FetchContent_Declare(ImGui-SFML
    GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml
    GIT_TAG v2.5
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(ImGui-SFML)

# FetchContent_Declare(ImPlot
#     GIT_REPOSITORY https://github.com/epezent/implot
#     GIT_TAG v0.14
#     GIT_PROGRESS TRUE)
# FetchContent_MakeAvailable(ImPlot)

# add_library(ImPlot
#     "${implot_SOURCE_DIR}/implot.cpp"
#     "${implot_SOURCE_DIR}/implot_items.cpp"
#     "${imgui_SOURCE_DIR}/imgui.cpp"
#     "${imgui_SOURCE_DIR}/imgui_draw.cpp"
#     "${imgui_SOURCE_DIR}/imgui_tables.cpp"
#     "${imgui_SOURCE_DIR}/imgui_widgets.cpp")
# add_library(ImPlot::ImPlot ALIAS ImPlot)
# target_include_directories(ImPlot PUBLIC "${implot_SOURCE_DIR}" "${imgui_SOURCE_DIR}")

add_executable(CMakeSFMLProject src/main.cpp)




target_link_libraries(CMakeSFMLProject PRIVATE ImGui-SFML::ImGui-SFML sfml-graphics sfml-system sfml-window)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET CMakeSFMLProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CMakeSFMLProject> $<TARGET_FILE_DIR:CMakeSFMLProject> COMMAND_EXPAND_LISTS)
endif()
install(TARGETS CMakeSFMLProject)
