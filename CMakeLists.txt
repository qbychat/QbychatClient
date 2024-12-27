cmake_minimum_required(VERSION 3.19)
project(QbychatClient LANGUAGES CXX)

find_package(Qt6 6.8 REQUIRED COMPONENTS Core Widgets Network NetworkAuth)

qt_standard_project_setup()

qt_add_executable(QbychatClient
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    oauth2/oauth2.h
    oauth2/oauth2.cpp
)

target_link_libraries(QbychatClient
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
        Qt::NetworkAuth
)

include(GNUInstallDirs)

install(TARGETS QbychatClient
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET QbychatClient
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
