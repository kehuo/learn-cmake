#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

// after running build.sh, the header file will be in the build/TutorialConfig.h
#include "TutorialConfig.h"

#include "MathFunctions.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        // report version
        std::cout << argv[0] 
            << " Version: " << Tutorial_VERSION_MAJOR 
            << "."
            << Tutorial_VERSION_MINOR 
            << std::endl;

        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    // supported by C++ 11 and above.
    const double inputValue = std::stod(argv[1]);
    
    const double outputValue = mysqrt(inputValue);
    std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
    return 0;
}
