@echo off

rem Build project files for Visual Studio 2010 x64

rem =======================================================
rem ==  Root directories  =================================
set ROOT_DIR=%~dp0
set BUILD_DIR=%STUDIER_ROOT_DIR%build
set INSTALL_DIR=%STUDIER_ROOT_DIR%install
rem =======================================================

rem =======================================================
rem ==  Prepare project files  ============================
mkdir %BUILD_DIR%
cd %BUILD_DIR%
cmake -G "Visual Studio 10 2010 Win64" -DCMAKE_INSTALL_PREFIX=%INSTALL_DIR% %ROOT_DIR%
cd %ROOT_DIR%
rem =======================================================

start "" "%VS100COMNTOOLS%..\IDE\devenv.exe" "%BUILD_DIR%\AdaBoost.sln" &
