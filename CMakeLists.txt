cmake_minimum_required(VERSION 3.21.1)

project(ExampleQtQMLModuleApp LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_standard_project_setup()

qt_add_executable(
    ExampleQtQMLModuleApp
        src/main.cpp
)

qt_add_resources(
    ExampleQtQMLModuleApp "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

qt_add_qml_module(
    ${CMAKE_PROJECT_NAME}
    URI "Main"
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    NO_PLUGIN
    QML_FILES
        main.qml
)

add_subdirectory(content)
add_subdirectory(imports)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    contentplugin
    ExampleQtQMLModuleplugin
)


target_link_libraries(
    ExampleQtQMLModuleApp
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)
set(QML_IMPORT_PATH ${QT_QML_OUTPUT_DIRECTORY}
    CACHE STRING "Import paths for Qt Creator's code model"
    FORCE
)

include(GNUInstallDirs)

install(
    TARGETS
    ExampleQtQMLModuleApp
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# make IDEs aware of the QML import path
set(QML_IMPORT_PATH ${PROJECT_BINARY_DIR}/qml CACHE PATH
    "Path to the custom QML components defined by the project")
