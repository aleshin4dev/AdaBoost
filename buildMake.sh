#!/bin/sh

# Build project with Makefiles

# ===============================================
# ==  Main directories  =========================
export ROOT_DIR=$(pwd)
export BUILD_DIR=${ROOT_DIR}/build
export INSTALL_DIR=${ROOT_DIR}/install
export OPENCV_ROOT_DIR=/OpenCV/opencv
# ===============================================

# ===============================================
# ==  Prepare project files and build them  =====
mkdir -p ${BUILD_DIR}
cd ${BUILD_DIR}
cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} ${ROOT_DIR}

make && make install
cd ${ROOT_DIR}
# ===============================================
