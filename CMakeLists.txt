cmake_minimum_required(VERSION 3.16)
project(RecipeManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(SOURCES
    main.cpp
    mainwindow.cpp
    addrecipedialog.cpp
    viewrecipedialog.cpp
    randomrecipedialog.cpp
)

set(HEADERS
    mainwindow.h
    addrecipedialog.h
    viewrecipedialog.h
    randomrecipedialog.h
)

qt6_add_executable(RecipeManager ${SOURCES} ${HEADERS})
target_link_libraries(RecipeManager PRIVATE Qt6::Core Qt6::Widgets)