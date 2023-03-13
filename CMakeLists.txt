cmake_minimum_required(VERSION 3.15)


project(Tutorial VERSION 1.0)


set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")


# Note: tutorial_compiler_flags is a library, but cmake will NOT build an actual library output file (libxxx.a).
# You can simply treat tutorial_compiler_flags as an logic / virtual library.
add_library(tutorial_compiler_flags INTERFACE)
# Note: target_compile_features adds c++11 standard into the tutorial_compiler_flags (logic) library.
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)


target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)


option(USE_MYMATH "Use tutorial provided math implementation" ON)


configure_file(TutorialConfig.h.in TutorialConfig.h)


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

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  DESTINATION include
  )
  