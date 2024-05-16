cmake_minimum_required(VERSION 3.21.1)

project(
    ExampleQtQMLModuleApp
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(
    QML_IMPORT_PATH
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/view
        ${CMAKE_SOURCE_DIR}/src
    CACHE STRING "" FORCE
)

find_package(
    Qt6 6.5
    REQUIRED
    COMPONENTS
        Core
        Gui
        Qml
        Quick
)

qt_standard_project_setup(
    REQUIRES 6.5
)

add_subdirectory(view)
add_subdirectory(src)

qt_add_executable(
    ${CMAKE_PROJECT_NAME}
        src/main.cpp
)

qt_add_qml_module(
    ${CMAKE_PROJECT_NAME}
    URI "Main"
    RESOURCE_PREFIX ":/qt/qml"
    VERSION 1.0
    NO_PLUGIN
    QML_FILES
        Main.qml
        Screen01.ui.qml
)

qt_add_resources(
    ${CMAKE_PROJECT_NAME} "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        ExampleQMLLibraryplugin
        ExampleLibraryplugin
)

install(
    TARGETS
    ${CMAKE_PROJECT_NAME}
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
