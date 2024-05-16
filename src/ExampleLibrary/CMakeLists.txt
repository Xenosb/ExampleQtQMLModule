set(MODULE_NAME "ExampleLibrary")

qt_add_library(
    ${MODULE_NAME}
    STATIC
)

qt_add_qml_module(
    ${MODULE_NAME}
    URI "ExampleLibrary"
    VERSION 1.0
    SOURCES
        backendObject.cpp
        backendObject.h
        backendService.cpp
        backendService.h
)

target_link_libraries(
    ${MODULE_NAME}
    PUBLIC
        Qt::Gui
)

target_include_directories(
    ${MODULE_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
