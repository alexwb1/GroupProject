# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/imnie/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/imnie/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/imnie/CLionProjects/GroupProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/imnie/CLionProjects/GroupProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GroupProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GroupProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GroupProject.dir/flags.make

CMakeFiles/GroupProject.dir/main.cpp.o: CMakeFiles/GroupProject.dir/flags.make
CMakeFiles/GroupProject.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/imnie/CLionProjects/GroupProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GroupProject.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GroupProject.dir/main.cpp.o -c /cygdrive/c/Users/imnie/CLionProjects/GroupProject/main.cpp

CMakeFiles/GroupProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GroupProject.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/imnie/CLionProjects/GroupProject/main.cpp > CMakeFiles/GroupProject.dir/main.cpp.i

CMakeFiles/GroupProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GroupProject.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/imnie/CLionProjects/GroupProject/main.cpp -o CMakeFiles/GroupProject.dir/main.cpp.s

CMakeFiles/GroupProject.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/GroupProject.dir/main.cpp.o.requires

CMakeFiles/GroupProject.dir/main.cpp.o.provides: CMakeFiles/GroupProject.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GroupProject.dir/build.make CMakeFiles/GroupProject.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/GroupProject.dir/main.cpp.o.provides

CMakeFiles/GroupProject.dir/main.cpp.o.provides.build: CMakeFiles/GroupProject.dir/main.cpp.o


# Object files for target GroupProject
GroupProject_OBJECTS = \
"CMakeFiles/GroupProject.dir/main.cpp.o"

# External object files for target GroupProject
GroupProject_EXTERNAL_OBJECTS =

GroupProject.exe: CMakeFiles/GroupProject.dir/main.cpp.o
GroupProject.exe: CMakeFiles/GroupProject.dir/build.make
GroupProject.exe: CMakeFiles/GroupProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/imnie/CLionProjects/GroupProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GroupProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GroupProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GroupProject.dir/build: GroupProject.exe

.PHONY : CMakeFiles/GroupProject.dir/build

CMakeFiles/GroupProject.dir/requires: CMakeFiles/GroupProject.dir/main.cpp.o.requires

.PHONY : CMakeFiles/GroupProject.dir/requires

CMakeFiles/GroupProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GroupProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GroupProject.dir/clean

CMakeFiles/GroupProject.dir/depend:
	cd /cygdrive/c/Users/imnie/CLionProjects/GroupProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/imnie/CLionProjects/GroupProject /cygdrive/c/Users/imnie/CLionProjects/GroupProject /cygdrive/c/Users/imnie/CLionProjects/GroupProject/cmake-build-debug /cygdrive/c/Users/imnie/CLionProjects/GroupProject/cmake-build-debug /cygdrive/c/Users/imnie/CLionProjects/GroupProject/cmake-build-debug/CMakeFiles/GroupProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GroupProject.dir/depend

