# CMake_Learn

My note from [CMake Tutorial](https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&ab_channel=Code%2CTech%2CandTutorials)

> [Episode 2](https://youtu.be/DDHCEE_PHOU?si=smf5akXYDzYQzykj) Summarized by Komsun Tamanakijprasart

Table of contents
=================

<!--ts-->
  * [Creating Libraries](#creating-libraries)
  * [Calling Libraries](#calling-libraries)
      * [Method 1: Directly locate the library's directory](#method-1-directly-locate-the-librarys-directory)
      * [Method 2: Install the library](#method-2-install-the-library)
      * [Installing the library](#install-the-library)
      * [Calling the installed library](#calling-the-installed-library)

<!--te-->

# Creating Libraries
- You don't need _main.cpp_ to create a library
- Library is a function that you call from your main

- Put into namespace so that your function name doesn't overlap with other existing function

**Step 1:** Prepare `.h` and `.cpp` files for your library

**Step 2:** Create _CMakeLists.txt_ and run `cmake`
- Use `add_library(libraryName file-to-compile)` to create library 
> CMakeLists.txt of the library
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
**Step 1:** Prepare _main.cpp_ and include your library with `#include "../location/libHeader.h"`
https://github.com/komxun/CMake_Learn/blob/82a00fb7680cde5473fc83b8374182dc085ef834/TestSomeLib/main.cpp#L1-L9

**Step 2:** Create _CMakeLists.txt_ and run `cmake`
> CMakeLists.txt of the main program
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

**Step 3:** Run `make` and your program

## Method 2: Install the Library
More detail about [`add_library(<target> [BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])`](https://cmake.org/cmake/help/latest/command/add_library.html)
  
  "If no type is given explicitly to the library the type is `STATIC` or `SHARED` based on whether the current value of the variable `BUILD_SHARE_LIBS` is `ON` "

![image](https://github.com/komxun/CMake_Learn/assets/133139057/d5e45d58-0639-4937-9703-61f193bed8d1)

DONE! The library has been created and installed on your system (_lib_ folder)
### Install the library
> CMakeLists.txt of the library
> ```
> cmake_minimum_required(VERSION 2.8)
> project(komsunmath2_project)
> add_library(komsunmath2 multiplier.cpp)
> set_target_properties(komsunmath2 PROPERTIES PUBLIC_HEADER multiplier.h)
> install(TARGETS komsunmath2 LIBRARY DESTINATION lib
> PUBLIC_HEADER DESTINATION include)
> ```

What are these lines?
- `set_target_properties(<targetLib> PROPERTIES PUBLIC_HEADER <header_file>)` : You can set various properties for the library, the `PUBLIC_HEADER` has been set to _multiplier.h_ in this case
- `install(... LIBRARY DESTINATION lib`) : Set the install location of the library, in this case: _lib_ folder
- `install(... PUBLIC_HEADER DESTINATION include` : Set the location of the public header to look for, in this case: _include_ folder

See more examples [here](https://cmake.org/cmake/help/latest/command/install.html#:~:text=Consider%20the%20following%20example%3A)

The following table shows the target types with their associated variables and built-in defaults that apply when no destination is given (See [more info](https://cmake.org/cmake/help/latest/command/install.html#:~:text=The%20following%20table%20shows%20the%20target%20types%20with%20their%20associated%20variables%20and%20built%2Din%20defaults%20that%20apply%20when%20no%20destination%20is%20given%3A):
![image](https://github.com/komxun/CMake_Learn/assets/133139057/ee384259-c9f5-4f9f-956e-1890420f75f8)


### Calling the installed library
Since the library has already been installed, we don't need to rely on `target_link_directories()` since Linux already knows the path

**Step 1:** Prepare _main.cpp_ and include your library with `#include "libHeader.h"` (just the header, no need for the location!)
https://github.com/komxun/CMake_Learn/blob/f32269758fa377a57920333eeeb08793c3f47d43/TestSomeLib2/main.cpp#L1-L9

**Step 2:** Create _CMakeLists.txt_ and run `cmake`
> CMakeLists.txt of the main program
> ```cpp
> cmake_minimum_required(VERSION 3.13)
> project(TestSomeLib2)
> add_executable(TestSomeLib2 main.cpp)
> target_link_libraries(TestSomeLib2 komsunmath2)
> ```

**Step 3:** Run `make` and your program

Results
![image](https://github.com/komxun/CMake_Learn/assets/133139057/35ca6506-6337-4b2a-afc9-0e755b2db610)

