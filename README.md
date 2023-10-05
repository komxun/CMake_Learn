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

## Step 0-2: Create _.gitignore_ file and fill with these commands (together)
- [gitignore for c++](https://github.com/github/gitignore/blob/main/C%2B%2B.gitignore)
- [gitignore for cmake](https://github.com/github/gitignore/blob/main/CMake.gitignore)
- Ignore the _build_ folder and anything called "build" with all capitalization combination:
  > .gitignore file
  > ```
  > build/
  > [Bb][Uu][Ii][Ll][Dd]/
  > ```

`[Bb]` means ignore the capital B or lowercase b



