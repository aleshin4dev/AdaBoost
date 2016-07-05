#!/bin/sh

# Create project files for Eclipse

# ===============================================
# ==  Main directories  =========================
export ROOT_DIR=$(pwd)
export BUILD_DIR=${ROOT_DIR}/build
export INSTALL_DIR=${ROOT_DIR}/install
export OPENCV_ROOT_DIR=/OpenCV/opencv
# ===============================================

# ===============================================
# ==  Prepare project files  ====================
mkdir -p ${BUILD_DIR}
cd ${BUILD_DIR}
cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} ${ROOT_DIR}
cd ${ROOT_DIR}
# ===============================================

# ===============================================
# ==  Start Eclipse  ============================
eclipse -Dosgi.locking=none &
# ===============================================
