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

**Step 3:** Run `make`

```cpp
cmake_minimum_required(VERSION 3.16.3)
project(komsunmath_project)
add_library(komsunmath adder.cpp)
```
![image](https://github.com/komxun/CMake_Learn/assets/133139057/6e1b9947-842a-48e5-b732-de152ad00f00)

DONE!! - Your library has been built!

# Calling Libraries

