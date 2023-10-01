# CMake_Learn

My note from 

- [CMake Tutorial](https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&ab_channel=Code%2CTech%2CandTutorials)


> Summarized by Komsun Tamanakijprasart

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
- CMake relies on a top-level file called `CMakeLists.txt' (exact spelling!)

**2 Important points in CMakeList**
- Where your source file is (contain _CMakeLists.txt_)
- Where your build folder is
> Linux terminal
> ```cpp
> cmake -S <path-to-source> -B <path-to-build>
> ```

# Example 
> Linux terminal
> ```
> cmake -S . -B obj/
> ```
- `-S .` means the source (and CMakeList.txt) is located in the current directory
## Check CMake version
> Linux terminal
> ```
> cmake --version
> ```

# Example 1 : Creating a Project
> CMakeLists.txt
> ```txt
> cmake_minimum_required(VERSION 3.16.3)
> project(myProject)
> add_executable(${PROJECT_NAME} main.cpp)
> ```

> Linux Terminal - at where the makefile is located
> ```
> make
> ```

- `cmake_minimum(VERSION xxxxx)` is required
- `project(projectName)` : Add project
- `add_executable(programName source)` : Build the executable file

Results

![image](https://github.com/komxun/CMake_Learn/assets/133139057/31bf955b-f8ae-43ff-a1f2-c2898ca66935)

![image](https://github.com/komxun/CMake_Learn/assets/133139057/1b9c5f6e-2120-434d-9c7e-6a225bd568ed)

![image](https://github.com/komxun/CMake_Learn/assets/133139057/02e7fa9d-0b5a-47b3-9390-09d6e52a5e12)

# Example 2 : 
## Step 0 : Prepare _main.cpp_
## Step 1 : Create _CMakeLists.txt_ and run `cmake`
> CMakeLists.txt
> ```
> cmake_minimum_required(VERSION 3.16.3)
> project(Trim)
> add_executable(trim main.cpp)
> install(TARGETS trim DESTINATION bin)
> ```

- `install(TARGETS programName DESTINATION xxx)` : specify where to install the executable file (your program), _bin_ is a standard place to install (usually _usr/local/bin/_)
- Usually, we create a separate folder for the built files (in this case, _build_)
> Linux terminal
> ```
> cmake -S ..
> ```
- `-S ..` means the source (and CMakeLists.txt) is in the previous directory

![image](https://github.com/komxun/CMake_Learn/assets/133139057/a272dd15-1615-472c-bc6a-715ae9e2d8e1)

- Now, in _build_, the _makefile_ is created and configured along with many other files
![image](https://github.com/komxun/CMake_Learn/assets/133139057/78b757e8-cc72-4d4f-9404-26a04be2fd80)

## Step 2 : run `make` and your program
![image](https://github.com/komxun/CMake_Learn/assets/133139057/0910e4ff-34d9-438e-bb6f-658bf3c34f3f)


Not sure what to `make`? type `make help`
![image](https://github.com/komxun/CMake_Learn/assets/133139057/e21a02a5-1b42-4679-ac1c-ec8f100eb8b5)


