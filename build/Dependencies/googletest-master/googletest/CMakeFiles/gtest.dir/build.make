# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build

# Include any dependencies generated for this target.
include Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/flags.make

Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/flags.make
Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../Dependencies/googletest-master/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build/Dependencies/googletest-master/googletest && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/Dependencies/googletest-master/googletest/src/gtest-all.cc

Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build/Dependencies/googletest-master/googletest && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/Dependencies/googletest-master/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build/Dependencies/googletest-master/googletest && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/Dependencies/googletest-master/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtest.a: Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtest.a: Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtest.a: Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgtest.a"
	cd /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build/Dependencies/googletest-master/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build/Dependencies/googletest-master/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/build: lib/libgtest.a

.PHONY : Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/build

Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/clean:
	cd /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build/Dependencies/googletest-master/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/clean

Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/depend:
	cd /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2 /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/Dependencies/googletest-master/googletest /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build/Dependencies/googletest-master/googletest /cygdrive/c/Users/josed/Desktop/TP2/Repo/TP2/build/Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Dependencies/googletest-master/googletest/CMakeFiles/gtest.dir/depend

