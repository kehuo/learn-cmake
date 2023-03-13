BUILD_DIR=build
mkdir ${BUILD_DIR}

cd ${BUILD_DIR}

# use the top-level CMakeLists.txt to generate required files such as:
# MakeFile / CMakeCache, etc.
cmake ..

# Use generated files to build final output of this project.
cmake --build .
