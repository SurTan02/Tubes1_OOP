cmake_minimum_required(VERSION 3.10)
project(brisupremacy)

set(CMAKE_CXX_STANDARD 11)

add_executable(brisupremacy
        src/Container.cpp
        src/CraftingTable.cpp
        src/exportFile.cpp
        src/InventoryMain.cpp
        src/Item.cpp
        src/NonTool.cpp
        src/readFile.cpp
        src/Recipe.cpp
        src/Tool.cpp)

target_include_directories(brisupremacy PRIVATE src)