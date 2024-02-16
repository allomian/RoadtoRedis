@echo off 

cd hiredis
mkdir build
cd build
cmake ..
cmake --build .
mkdir ..\lib\
copy Debug\* ..\..\lib
cd ..\..
cd redis-plus-plus
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH="%cd%\..\.." -DREDIS_PLUS_PLUS_BUILD_TEST=OFF -DREDIS_PLUS_PLUS_BUILD_SHARED=OFF  ..
cmake --build .
copy Debug\* ..\..\lib