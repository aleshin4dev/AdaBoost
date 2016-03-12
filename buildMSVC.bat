@echo off

rem Build project files for Visual Studio 2010 x64

rem =======================================================
rem ==  Root directories  =================================
set ROOT_DIR=%~dp0
set BUILD_DIR=%ROOT_DIR%build
set INSTALL_DIR=%ROOT_DIR%install
set OPENCV_ROOT_DIR=C:\OpenCV\opencv\install
rem =======================================================

set "PATH=%ROOT_DIR%..\..\cmake-3.5.0-win32-x86\cmake-3.5.0-win32-x86\bin;%PATH%"

rem =======================================================
rem ==  Prepare project files  ============================
mkdir %BUILD_DIR%
cd %BUILD_DIR%
cmake -G "Visual Studio 14 2015 Win64" -DCMAKE_INSTALL_PREFIX=%INSTALL_DIR% %ROOT_DIR%
cd %ROOT_DIR%
rem =======================================================

start "" "%VS140COMNTOOLS%..\IDE\devenv.exe" "%BUILD_DIR%\AdaBoost.sln" &
