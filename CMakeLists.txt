cmake_minimum_required(VERSION 3.10)


# project(Tutorial)
project(Tutorial VERSION 1.0)


option(USE_MYMATH "Use tutorial provided math implementation" ON)


configure_file(TutorialConfig.h.in TutorialConfig.h)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(Tutorial tutorial.cxx)


target_include_directories(
    Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"
)


# add_subdirectory(MathFunctions)
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()


# target_link_libraries(Tutorial PUBLIC MathFunctions)
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})


# target_include_directories(Tutorial PUBLIC
#     "${PROJECT_BINARY_DIR}"
#     "${PROJECT_SOURCE_DIR}/MathFunctions"
# )
target_include_directories(Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"
    ${EXTRA_INCLUDES}
)