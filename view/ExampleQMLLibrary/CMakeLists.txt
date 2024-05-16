set(MODULE_NAME "ExampleQMLLibrary")

qt_add_library(
    ${MODULE_NAME}
    STATIC
)

qt_add_qml_module(
    ${MODULE_NAME}
    URI "ExampleQMLLibrary"
    VERSION 1.0
    QML_FILES
        SpecialButton.qml
)
