cmake_minimum_required(VERSION 3.25)
project(DelaunayTriangulation LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(CGAL REQUIRED)

if(TARGET Qt6::Core)
	message(STATUS "Qt6::Core found!")
else()
	message(STATUS "Qt6::Core not found!")
endif()

if(TARGET Qt6::Gui)
	message(STATUS "Qt6::Gui found!")
else()
	message(STATUS "Qt6::Gui not found!")
endif()

if(TARGET Qt6::Widgets)
	message(STATUS "Qt6::Widgets found!")
else()
	message(STATUS "Qt6::Widgets not found!")
endif()

if(CGAL_FOUND)
	message(STATUS "CGAL found!")
else()
	message(STATUS "CGAL not found!")
endif()

file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h ${CMAKE_CURRENT_BINARY_DIR}/*.h)
file(GLOB CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB UI_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.ui)
file(GLOB RCC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)

message(STATUS "HEADER_FILES: ${HEADER_FILES}")
message(STATUS "CPP_FILES: ${CPP_FILES}")
message(STATUS "UI_FILES: ${UI_FILES}")
message(STATUS "RCC_FILES: ${RCC_FILES}")

add_executable(${PROJECT_NAME} WIN32 ${HEADER_FILES} ${CPP_FILES} ${UI_FILES} ${RCC_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets CGAL)