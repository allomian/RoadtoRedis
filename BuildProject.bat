@echo off 

cd hiredis
mkdir build
cd build
cmake -DBUILD_SHARED_LIBS=OFF --fresh ..
cmake --build .
cd ..\..
mkdir lib
cd hiredis\build
copy Debug\* ..\..\lib
cd ..\..
cd redis-plus-plus
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH="%cd%\..\.." -DREDIS_PLUS_PLUS_BUILD_TEST=OFF -DREDIS_PLUS_PLUS_CXX_STANDARD=17 -DREDIS_PLUS_PLUS_BUILD_SHARED=OFF  -DCMAKE_BUILD_TYPE=Debug --fresh ..
cmake --build . 
copy Debug\* ..\..\lib