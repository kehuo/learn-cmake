# learn-cmake

## Tutorial

### Step 1 - A Basic Starting Point 

Where do I start with CMake? This step will provide an introduction to some of CMake's basic syntax, commands, and variables. As these concepts are introduced, we will work through three exercises and create a simple CMake project.

Each exercise in this step will start with some background information. Then, a goal and list of helpful resources are provided. Each file in the Files to Edit section is in the Step1 directory and contains one or more TODO comments. Each TODO represents a line or two of code to change or add. The TODO s are intended to be completed in numerical order, first complete TODO 1 then TODO 2, etc. The Getting Started section will give some helpful hints and guide you through the exercise. Then the Build and Run section will walk step-by-step through how to build and test the exercise. Finally, at the end of each exercise the intended solution is discussed.

Also note that each step in the tutorial builds on the next. So, for example, the starting code for Step2 is the complete solution to Step1.


#### Exercise 1 - Building a Basic Project

##### Overview

The most basic CMake project is an executable built from a single source code file. For simple projects like this, a CMakeLists.txt file with three commands is all that is required.

Note: Although upper, lower and mixed case commands are supported by CMake, lower case commands are preferred and will be used throughout the tutorial.

Any project's top most CMakeLists.txt must start by specifying a minimum CMake version using the cmake_minimum_required() command. This establishes policy settings and ensures that the following CMake functions are run with a compatible version of CMake.

To start a project, we use the project() command to set the project name. This call is required with every project and should be called soon after cmake_minimum_required(). As we will see later, this command can also be used to specify other project level information such as the language or version number.

Finally, the add_executable() command tells CMake to create an executable using the specified source code files.

##### Goal

Understand how to create a simple CMake project.

##### Files to Edit

- CMakeLists.txt


##### Getting Started

The source code for tutorial.cxx is provided in the Help/guide/tutorial/Step1 directory and can be used to compute the square root of a number. This file does not need to be edited in this step.

In the same directory is a CMakeLists.txt file which you will complete. Start with TODO 1 and work through TODO 3.

##### Build and Run


```bash
mkdir build
cd build
cmake ..

cmake --build .
```
