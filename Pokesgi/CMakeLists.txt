#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(pokesgi)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Define sources and executable
include_directories ("class")
include_directories ("class/scenes")
include_directories ("lib")
include_directories ("lib/RapidXML")

set(pokesgi_SOURCES
    #Class
    class/Attack.cpp
    class/Common.cpp
    class/Hero.cpp
    class/Item.cpp
    class/Person.cpp
    class/Pokemon.cpp
    class/Trainer.cpp
    class/scenes/BattleScene.cpp
    class/scenes/GameScene.cpp
    #Lib
    lib/AnimatedSprite.cpp
    lib/Animation.cpp
    lib/NLTmx/NLTmxMap.cpp
    lib/ResourcePath.hpp
    lib/ResourcePathDefault.cpp
    lib/Settings.cpp
    lib/RapidXML/rapidxml.hpp
    lib/RapidXML/rapidxml_iterators.hpp
    lib/RapidXML/rapidxml_print.hpp
    lib/RapidXML/rapidxml_utils.hpp
    main.cpp)

set(EXECUTABLE_NAME "pokesgi")
add_executable(${EXECUTABLE_NAME} ${pokesgi_SOURCES})

set(CMAKE_CXX_FLAGS "-std=c++0x")

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
install(DIRECTORY lib/RapidXML DESTINATION include/RapidXML FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY lib/NLTmx DESTINATION include/NLTmx FILES_MATCHING PATTERN "*.h")
install(DIRECTORY lib/ DESTINATION include/pokesgi FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h" PATTERN "*.mm")

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)

# Copy resources
add_custom_command(TARGET pokesgi POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "../Pokesgi/res"
        "res")
