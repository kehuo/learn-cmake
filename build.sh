BUILD_DIR=build
mkdir ${BUILD_DIR}

cd ${BUILD_DIR}

cmake .. -DUSE_MYMATH=ON

cmake --build .
