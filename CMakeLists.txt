cmake_minimum_required(VERSION 3.15)


project(Tutorial VERSION 1.0)


option(USE_MYMATH "Use tutorial provided math implementation" ON)


configure_file(TutorialConfig.h.in TutorialConfig.h)


# Note: tutorial_compiler_flags is a library, but cmake will NOT build an actual library output file (libxxx.a).
# You can simply treat tutorial_compiler_flags as an logic / virtual library.
add_library(tutorial_compiler_flags INTERFACE)
# Note: target_compile_features adds c++11 standard into the tutorial_compiler_flags (logic) library.
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)


if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif()


add_executable(Tutorial tutorial.cxx)


# target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)


target_include_directories(
    Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"
)
