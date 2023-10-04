# CMake_Learn

My note from 

- [CMake Tutorial](https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&ab_channel=Code%2CTech%2CandTutorials)


> Summarized by Komsun Tamanakijprasart

# Creating Libraries
- You don't need _main.cpp_ to create a library
- Library is a function that you call from your main

- Put into namespace so that your function name doesn't overlap with other existing function

**Step 1:** Prepare `.h` and `.cpp` files for your library

**Step 2:** Create _CMakeLists.txt_ and run `cmake`
- Use `add_library(libraryName file-to-compile)` to create library 
> CMakeLists.txt
> ```cpp
> cmake_minimum_required(VERSION 3.16.3)
> project(komsunmath_project)
> add_library(komsunmath adder.cpp)
> ```

**Step 3:** Run `make`
![image](https://github.com/komxun/CMake_Learn/assets/133139057/6e1b9947-842a-48e5-b732-de152ad00f00)

DONE!! - Your library has been built!

# Calling Libraries
## Method 1: Directly locate the library's directory
Step 1: Prepare _main.cpp_ and include your library with `#include`
https://github.com/komxun/CMake_Learn/blob/82a00fb7680cde5473fc83b8374182dc085ef834/TestSomeLib/main.cpp#L1-L9

Step 2: Create _CMakeLists.txt_ and run `cmake`
> CMakeLists.txt
> ```cpp
> cmake_minimum_required(VERSION 3.13)
> project(TestSomeLib)
> add_executable(TestSomeLib main.cpp)
> target_link_directories(TestSomeLib PRIVATE ${CMAKE_SOURCE_DIR}/../SomeLibDemo/build)
> target_link_libraries(TestSomeLib komsunmath)
> ```

- `target_link_directories(targetName libDirectory)` : link directories and locate your library's location
- `target_link_libraries(targetName libName)`: link the library to the project, just need the library name
- `${CMAKE_SOURCE_DIR}`: default keyword to locate the directory of _makefile_
- [`target_link_directories()`](https://cmake.org/cmake/help/latest/command/target_link_directories.html) is firstly added to the CMake in version 3.13, so the `cmake_minimum_required()` should be this version

## Method 2: Install the Library
More detail about [`add_library(<target> [BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])`](https://cmake.org/cmake/help/latest/command/add_library.html)
  
  "If no type is given explicitly to the library the type is `STATIC` or `SHARED` based on whether the current value of the variable `BUILD_SHARE_LIBS` is `ON` "

![image](https://github.com/komxun/CMake_Learn/assets/133139057/d5e45d58-0639-4937-9703-61f193bed8d1)


