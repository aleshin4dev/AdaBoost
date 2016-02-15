# Project preferences
SET(PROJECT_NAME "AdaBoost")
# Project name and used languages
PROJECT(${PROJECT_NAME} C CXX)
# Project version
SET(PROJECT_VERSION 0.1)

# Minimal requirements
CMAKE_MINIMUM_REQUIRED(VERSION 3.0 FATAL_ERROR)
# Basic settings
SET(CMAKE_INCLUDE_CURRENT_DIR TRUE)

# Application source files
SET(APP_SOURCES
    AdaBoost.cpp
)

SET(APP_HEADERS
)

# Libraries to be linked
SET(APP_LINK_LIBRARIES
)

# Application
ADD_EXECUTABLE(AdaBoost ${APP_SOURCES} ${APP_HEADERS})
TARGET_LINK_LIBRARIES(AdaBoost ${APP_LINK_LIBRARIES})

INSTALL(TARGETS AdaBoost DESTINATION ${CMAKE_INSTALL_PREFIX})
