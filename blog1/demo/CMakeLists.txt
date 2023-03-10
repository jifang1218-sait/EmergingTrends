cmake_minimum_required(VERSION 3.5)

project(demo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH $ENV{QT_HOME})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_definitions(-DDEBUG=1 -D_DEBUG=1 -D_USE_CUSTOMIZED_THREAD=1)
set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_NAME "demo")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS 
	Core
	Widgets
	Network
	)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS 
	Core
	Widgets
	Network
	)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
		WeatherManager.h
		WeatherManager.cpp
		WeatherManagerCallbacks.h
		HourItem.h
		HourItem.cpp
		WorkerThread.h
		WorkerThread.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(demo
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET demo APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(demo SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(demo
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(demo PRIVATE 
	Qt${QT_VERSION_MAJOR}::Core
	Qt${QT_VERSION_MAJOR}::Widgets
	Qt${QT_VERSION_MAJOR}::Network
	)

set_target_properties(demo PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS demo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(demo)
endif()

set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )
