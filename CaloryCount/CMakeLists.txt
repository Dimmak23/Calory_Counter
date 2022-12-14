cmake_minimum_required(VERSION 3.5)

project(CaloryCount VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(
	PROJECT_SOURCES
	main.cpp
	calculus.cpp
	calculus.h
	calculus.ui
	person.h
)

qt_add_resources(
	PROJECT_SOURCES
	res.qrc
)

qt_add_executable(
	CaloryCount
	MANUAL_FINALIZATION
	${PROJECT_SOURCES}
)

target_link_libraries(CaloryCount PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(CaloryCount PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS CaloryCount
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CaloryCount)
endif()
