set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(PLUGIN "PamAuthentication")


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")
find_package(PAM REQUIRED)

set(
    SRC
    plugin.cpp
    pamauthentication.cpp
)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PAM_INCLUDE_DIR}
)

set(CMAKE_AUTOMOC ON)

add_library(${PLUGIN} MODULE ${SRC})
set_target_properties(${PLUGIN} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PLUGIN})
qt5_use_modules(${PLUGIN} Qml Quick DBus)
target_link_libraries(${PLUGIN} ${PAM_LIBRARIES})

execute_process(
    COMMAND dpkg-architecture -qDEB_HOST_MULTIARCH
    OUTPUT_VARIABLE ARCH_TRIPLET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(QT_IMPORTS_DIR "/lib/${ARCH_TRIPLET}")

install(TARGETS ${PLUGIN} DESTINATION ${QT_IMPORTS_DIR}/${PLUGIN}/)
install(FILES qmldir DESTINATION ${QT_IMPORTS_DIR}/${PLUGIN}/)


file(GLOB QML_FILES *.qml)
install(FILES ${QML_FILES} DESTINATION ${QT_IMPORTS_DIR}/${PLUGIN}/)
