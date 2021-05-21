mkdir build
cd build
rm -r ./*
cmake -DCMAKE_BUILD_TYPE=Debug  ..
make -j8