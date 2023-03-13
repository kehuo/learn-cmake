BUILD_DIR=build
mkdir ${BUILD_DIR}

cd ${BUILD_DIR}

cmake .. -DUSE_MYMATH=ON

# Basic use of install.
cmake --install .

# For multi-configuration tools, we can use the --config argument to specify the configuration.
# cmake --install . --config Release

# For IDE, simply build the INSTALL target.
# cmake --build . --target install --config Debug

# use --prefix to determine the root of where the files will be installed.
# cmake --install . --prefix "/home/myuser/installdir"

