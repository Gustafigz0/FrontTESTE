cmake_minimum_required(VERSION 3.16)
project(TechProductsManager VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Charts)

set(PROJECT_SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.h
    src/LoginDialog.cpp
    src/LoginDialog.h
    src/Product.cpp
    src/Product.h
    src/ProductsManager.cpp
    src/ProductsManager.h
    src/RegionFilterDialog.cpp
    src/RegionFilterDialog.h
    src/ReportDialog.cpp
    src/ReportDialog.h
    src/ChartWidget.cpp
    src/ChartWidget.h
    src/utils/FileUtils.cpp
    src/utils/FileUtils.h
    src/utils/Style.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets Qt6::Charts)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)