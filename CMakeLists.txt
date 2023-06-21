cmake_minimum_required(VERSION 3.21)
project(BallShooter LANGUAGES CXX)

# BallShooter uses C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Compile target
set(SOURCE_FILES
    "src/main.cpp"
    "src/Core/Assets.hpp"
    "src/Core/Assets.cpp"
    "src/Core/Application.hpp"
    "src/Core/Application.cpp"
    "src/Core/Containers/Templates.hpp"
    "src/Core/Containers/Templates.cpp"
    "src/Entity/Base/Entity.hpp"
    "src/Entity/Base/Animation.hpp"
    "src/Entity/Base/Animation.cpp"
    "src/Entity/Base/ParticleEmitter.hpp"
    "src/Entity/Base/ParticleEmitter.cpp"
    "src/Entity/Shapes/SquareShape.hpp"
    "src/Entity/Shapes/SquareShape.cpp"
    "src/Entity/Shapes/StadiumShape.hpp"
    "src/Entity/Shapes/StadiumShape.cpp"
    "src/Entity/Cannon.hpp"
    "src/Entity/Cannon.cpp"
    "src/Entity/NumberSquare.hpp"
    "src/Entity/NumberSquare.cpp"
    "src/Entity/Projectile.hpp"
    "src/Entity/Projectile.cpp"
    "src/State/Base/State.hpp"
    "src/State/Base/State.cpp"
    "src/State/PlayState.hpp"
    "src/State/PlayState.cpp"
    "src/State/OptionsState.hpp"
    "src/State/OptionsState.cpp"
    "src/State/MenuState.hpp"
    "src/State/MenuState.cpp"
    "src/UI/Button.hpp"
    "src/UI/Button.cpp"
    "src/UI/Toggle.hpp"
    "src/UI/Toggle.cpp")
add_executable(BallShooter ${SOURCE_FILES})
target_link_libraries(BallShooter PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_compile_features(BallShooter PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET BallShooter POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:BallShooter> $<TARGET_FILE_DIR:BallShooter> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS BallShooter)
