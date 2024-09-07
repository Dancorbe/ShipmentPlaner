cmake_minimum_required(VERSION 3.16)

project(ProiectCorbean VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        dbmanager.cpp
        dbmanager.h
        order.cpp
        order.h
        suborder.cpp
        suborder.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ProiectCorbean
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        res/logo.png
        order.h
        order.cpp
        suborder.h suborder.cpp
        Dialogs/dlgorders.cpp Dialogs/dlgorders.h Dialogs/dlgorders.ui
        Shipment/planeshipment.cpp Shipment/planeshipment.h Shipment/shipment.cpp Shipment/shipment.h Shipment/shipmentfactory.cpp Shipment/shipmentfactory.h Shipment/trainshipment.cpp Shipment/trainshipment.h
        Dialogs/dlgshipments.cpp Dialogs/dlgshipments.h Dialogs/dlgshipments.ui



    )
else()
    if(ANDROID)
        add_library(ProiectCorbean SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ProiectCorbean
            ${PROJECT_SOURCES}
        )
    endif()
endif()

include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(ProiectCorbean PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_finalize_executable(ProiectCorbean)
endif()
