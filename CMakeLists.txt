cmake_minimum_required(VERSION 3.22)
project(game_backend)


set(CMAKE_CXX_STANDARD 20)

add_library(game_backend-lib
        src/AppComponent.hpp
        src/controller/MyController.cpp
        src/controller/MyController.hpp
        src/models/DTOs.hpp
        src/models/buildings/Building.cpp
        src/models/buildings/Building.hpp
        src/models/Tier.hpp
        src/models/state/GoldState.hpp
        src/models/state/ManaState.hpp src/models/state/State.hpp src/models/state/BuildingState.hpp src/utils/ObjectFileMapper.hpp src/models/staff/character.hpp src/models/staff/capacity-effect.hpp src/models/staff/capacity.hpp src/models/staff/character-inventory.hpp src/models/staff/character-stat.hpp src/models/state/CharacterState.hpp)

## link libs
find_package(oatpp)
target_link_libraries(game_backend-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        )

set(JSON_BuildTests OFF CACHE INTERNAL "")
target_include_directories(game_backend-lib PUBLIC src)

## add executables


add_executable(game_backend-exe
        src/main.cpp
        test/app/MyApiTestClient.hpp)

target_link_libraries(game_backend-exe game_backend-lib)
add_dependencies(game_backend-exe game_backend-lib)




add_executable(game_backend-test
        test/Tests.cpp
        test/app/TestComponent.hpp
        test/app/MyApiTestClient.hpp
        test/MyControllerTest.cpp
        test/MyControllerTest.hpp
        )

target_link_libraries(game_backend-test game_backend-lib)
add_dependencies(game_backend-test game_backend-lib)

set_target_properties(game_backend-lib game_backend-exe game_backend-test PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )

enable_testing()
add_test(project-tests game_backend-test)