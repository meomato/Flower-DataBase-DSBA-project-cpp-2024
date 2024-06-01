cmake_minimum_required(VERSION 3.5)

project(BloomBaze VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    flowercontainer.h flowercontainer.cpp
    flowerlabel.h flowerlabel.cpp
    flowercard.h flowercard.cpp flowercard.ui
    compflow.h compflow.cpp compflow.ui
    gardnerwindow.h gardnerwindow.cpp
    icon_1.qrc
    app_icon.rc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BloomBaze
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(BloomBaze SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(BloomBaze
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(BloomBaze PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.BloomBaze)
endif()

set(APPLICATION_ICON ${CMAKE_SOURCE_DIR}/img/purple_flower_icon_transparent.ico)

if(WIN32)
    set_target_properties(BloomBaze PROPERTIES WIN32_EXECUTABLE TRUE)
    set_target_properties(BloomBaze PROPERTIES RESOURCE "${APPLICATION_ICON}")
elseif(APPLE)
    set_source_files_properties(${APPLICATION_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
    set_target_properties(BloomBaze PROPERTIES MACOSX_BUNDLE_ICON_FILE purple_flower_icon_transparent.ico)
endif()

set_target_properties(BloomBaze PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_NAME "BloomBaze"
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    OUTPUT_NAME "BloomBaze"
)

include(GNUInstallDirs)

install(FILES img/purple_flower_icon_transparent.ico DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/app_icon.rc DESTINATION ${CMAKE_INSTALL_BINDIR})

install(TARGETS BloomBaze
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BloomBaze)
endif()
