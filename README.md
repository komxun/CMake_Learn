# CMake_Learn

My note from 

- [CMake Tutorial](https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&ab_channel=Code%2CTech%2CandTutorials)

> Summarized by Komsun Tamanakijprasart

Table of contents
=================

<!--ts-->
  * [makefile](#makefile)
  * [CMakeLists](#cmakeliststxt)
      * [`cmake`](#cmake)
  * [Example 1: Creating a project](#example-1-creating-a-project)
  * [Example 2: Installing your program](#example-2-installing-your-program)
  * [`install()`](#install-on-cmakeliststxt)

<!--te-->

# makefile
- Create and name a new file _makefile_ in your working directory
- _makefile_ doesn't accept space, use tab instead

Easy example:
> makefile
> ```cpp
> default:
> 	g++ main.cpp -o out
> ```

You just need to type `make` in the terminal to execute the _makefile_ (compile and build in this case)
- `make` to execute the _makefile_
- `./out` to run the application
> Linux or Windows terminal
> ``` cpp
> make
> ./out
> ```

Results
![image](https://github.com/komxun/CMake_Learn/assets/133139057/41dd09e5-ab08-4d2f-b291-263b21a0b482)


# CMakeLists.txt
- CMake relies on a top-level file called _CMakeLists.txt_ (exact spelling!)

Project Workflow \
Step 1: Prepare your source file `main.cpp` \
Step 2: Create _CMakeLists.txt_, a separate folder for built files, and run `cmake` \
Step 3: Run `make` 

## `cmake`
**2 Important points in CMakeList**
- Where your source file is (contain _CMakeLists.txt_)
- Where your build folder is
> Linux terminal
> ```cpp
> cmake -S <path-to-source> -B <path-to-build>
> ```
 Ex:
> Linux terminal
> ```
> cmake -S . -B build/
> ```
- `-S .` means the source (and CMakeList.txt) is located in the current directory


# Example 1: Creating a Project
## Step 1: Prepare _main.cpp_
https://github.com/komxun/CMake_Learn/blob/eee93c11c3e1c3c0eeef85ce9d187b555718d996/try_CMakeList/main.cpp#L1-L7
## Step 2: Create _CMakeLists.txt_ and run `cmake`
> CMakeLists.txt
> ```
> cmake_minimum_required(VERSION 3.16.3)
> project(myProject)
> add_executable(${PROJECT_NAME} main.cpp)
> ```

What are these lines?
- `cmake_minimum(VERSION xxxxx)` : Minimum required version
- `project(projectName)` : Add a project
- `add_executable(programName source)` : Build the executable file
- `${PROJECT_NAME}` : Built-in keyword to refer to the project name

> Linux Terminal
> ```
> cmake -S . -B obj/
> ```

Result
- _makefile_ is created along with other files
![image](https://github.com/komxun/CMake_Learn/assets/133139057/1b9c5f6e-2120-434d-9c7e-6a225bd568ed)

## Step 3: Run `make` and your program
> Linux Terminal - at where the makefile is located
> ```
> make
> ```



Results

![image](https://github.com/komxun/CMake_Learn/assets/133139057/31bf955b-f8ae-43ff-a1f2-c2898ca66935)

![image](https://github.com/komxun/CMake_Learn/assets/133139057/02e7fa9d-0b5a-47b3-9390-09d6e52a5e12)

Notes:
## Check CMake version
> Linux terminal
> ```
> cmake --version
> ```

# Example 2: Installing your program
## Step 1 : Prepare _main.cpp_
## Step 2 : Create _CMakeLists.txt_ and run `cmake`
> CMakeLists.txt
> ```
> cmake_minimum_required(VERSION 3.16.3)
> project(Trim)
> add_executable(trim main.cpp)
> install(TARGETS trim DESTINATION bin)
> ```

What are these lines?
- `install(TARGETS targetName DESTINATION xxx)` : specify where to install the executable file (or library), _bin_ is a standard place to install (usually _usr/local/bin/_)
- Usually, we create a separate folder for the built files (in this case, _build_)
> Linux terminal
> ```
> cmake -S ..
> ```
- `-S ..` means the source (and CMakeLists.txt) is in the previous directory
- no `-B` means the current directory is used for build

![image](https://github.com/komxun/CMake_Learn/assets/133139057/a272dd15-1615-472c-bc6a-715ae9e2d8e1)

- Now, in _build_, the _makefile_ is created and configured along with many other files
![image](https://github.com/komxun/CMake_Learn/assets/133139057/78b757e8-cc72-4d4f-9404-26a04be2fd80)

## Step 3 : run `make` and your program
![image](https://github.com/komxun/CMake_Learn/assets/133139057/0910e4ff-34d9-438e-bb6f-658bf3c34f3f)


Not sure what to `make`? type `make help`
![image](https://github.com/komxun/CMake_Learn/assets/133139057/e21a02a5-1b42-4679-ac1c-ec8f100eb8b5)

# `install()` on CMakeLists.txt
Install the program, as specified in _CMakeLists.txt_
> Linux terminal
> ```
> sudo make install
> ```
![image](https://github.com/komxun/CMake_Learn/assets/133139057/bbf25479-ac8e-471d-9ffc-78203ef27b75)

Because we `install` the program on the _bin_ already, we can call this program ANYWHERE !! (Don't need to locate the program's directory anymore!)
![image](https://github.com/komxun/CMake_Learn/assets/133139057/8910c358-f6b7-4167-88f8-cc21fc673f14)

