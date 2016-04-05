# Project preferences
SET(PROJECT_NAME "AdaBoost")
# Project name and used languages
PROJECT(${PROJECT_NAME} C CXX)
# Project version
SET(PROJECT_VERSION 0.1)

# Minimal requirements
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)
# Basic settings
SET(CMAKE_INCLUDE_CURRENT_DIR TRUE)

FILE(TO_CMAKE_PATH $ENV{OPENCV_ROOT_DIR} OPENCV_ROOT_DIR)
SET(CMAKE_MODULE_PATH "${OPENCV_ROOT_DIR}" ${CMAKE_MODULE_PATH})

INCLUDE(OpenCVConfig)

INCLUDE_DIRECTORIES(
    ${OpenCV_INCLUDE_DIRS}
)

# Application source files
SET(APP_SOURCES
     Main_Viola-Jones.cpp
     HaarFunctions.cpp
     IntegralImage.cpp
     AdaBoost.cpp
)

SET(APP_HEADERS
     Viola-Jones.h
)

# Libraries to be linked
SET(APP_LINK_LIBRARIES
    ${OpenCV_LIBS}
)

# Application
ADD_EXECUTABLE(AdaBoost ${APP_SOURCES} ${APP_HEADERS})
TARGET_LINK_LIBRARIES(AdaBoost ${APP_LINK_LIBRARIES})

INSTALL(TARGETS AdaBoost DESTINATION ${CMAKE_INSTALL_PREFIX})
