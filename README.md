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

# Git Submodules
## Step 0-1: Initialize the project with `git init` in the project's directory
![image](https://github.com/komxun/CMake_Learn/assets/133139057/212771be-3248-46b1-98a4-9a7674bde813)

There are 135 changes in this case, but we don't need a lot of this stuff. Thus, use `git ignore` to ignore these files.

## Step 0-2: Create _.gitignore_ file
Fill the _.gitignore_ file with these commands (together)
- [gitignore for c++](https://github.com/github/gitignore/blob/main/C%2B%2B.gitignore)
- [gitignore for cmake](https://github.com/github/gitignore/blob/main/CMake.gitignore)
- Ignore the _build_ folder and anything called "build" with all capitalization combination:
  > .gitignore file
  > ```
  > build/
  > [Bb][Uu][Ii][Ll][Dd]/
  > ```

`[Bb]` means ignore the capital B or lowercase b

Now, click the **Refresh** button in the VSCode. The number of changes is now reduced to 12 changes.
![image](https://github.com/komxun/CMake_Learn/assets/133139057/38f1abb3-d37d-4ca2-9e84-5282785241b2)

## Step 0-3: `git commit` these changes


## Step 1-1: Create a submodule with `git submodule add`
> Linux or Windows Terminal
> ```
> git submodule add <repo directory>
> ```

Example: GLFW (https://github.com/glfw/glfw)

"GLFW is an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan application development. It provides a simple, platform-independent API for creating windows, contexts and surfaces, reading input, handling events, etc.

GLFW natively supports Windows, macOS and Linux and other Unix-like systems. On Linux both X11 and Wayland are supported."

> Linux or Windows Terminal
> ```
> git submodule add https://github.com/glfw/glfw.git external/glfw
> ```

This will clone the repo into a new folder _external/glfw_
![image](https://github.com/komxun/CMake_Learn/assets/133139057/762417a6-a584-46eb-b2eb-2041d7ed6ef3)

## Step 1-2: `git commit` this submodule addition


