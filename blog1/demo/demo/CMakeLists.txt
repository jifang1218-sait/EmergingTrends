cmake_minimum_required(VERSION 3.5)

project(demo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# jifang -- begin
set(CMAKE_PREFIX_PATH "/home/jifang/apps/Qt5/5.14.2")
set(QT_DIR "/home/jifang/apps/Qt5/5.14.2/gcc_64/lib/cmake/Qt5")
set(Qt5_DIR "/home/jifang/apps/Qt5/5.14.2/gcc_64/lib/cmake/Qt5")
set(YOUR_DIRECTORY
"/home/jifang/apps/Qt5/5.14.2/gcc_64/include"
)
# jifang -- end

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

#find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(demo
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(demo SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(demo
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(demo PRIVATE ${YOUR_DIRECTORY}) # jifang
target_link_libraries(demo PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
