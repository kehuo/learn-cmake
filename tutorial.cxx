#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#include "TutorialConfig.h"

#ifdef USE_MYMATH
#   include "MathFunctions.h"
#endif

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
    
#ifdef USE_MYMATH
    std::cout << "USE_MYMATH=ON, use mysqrt" << std::endl;
    const double outputValue = mysqrt(inputValue);
#else
    std::cout << "USE_MYMATH=OFF, use sqrt" << std::endl;
    const double outputValue = sqrt(inputValue);
#endif

    std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
    return 0;
}
