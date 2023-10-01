# CMake_Learn

My note from 

- [CMake Tutorial](https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&ab_channel=Code%2CTech%2CandTutorials)


> Summarized by Komsun Tamanakijprasart

# makefile
- Create and name a new file _makefile_ in your working directory
- _makefile_ doesn't accept space, use tab instead

Easy example:
```cpp
// makefile
default:
	g++ main.cpp -o out
```
You just need to type `make` in the terminal to execute the _makefile_ (compile and build in this case)
- `make` to execute the _makefile_
- `./out` to run the application
> Linux or Windows terminal
``` cpp
make
./out
```

# CMakeLists.txt
- CMake relies on a top-level file called `CMakeLists.txt' (exact spelling!)

**2 Important points in CMakeList**
- Where your source file is (contain _CMakeLists.txt_)
- Where your build folder is
> Linux terminal
> ```cpp
> cmake -S <path-to-source> -B <path-to-build>
> ```
Example
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

# Example 1
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

Results

![image](https://github.com/komxun/CMake_Learn/assets/133139057/31bf955b-f8ae-43ff-a1f2-c2898ca66935)

![image](https://github.com/komxun/CMake_Learn/assets/133139057/1b9c5f6e-2120-434d-9c7e-6a225bd568ed)


