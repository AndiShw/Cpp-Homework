# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2

# Include any dependencies generated for this target.
include simplevm/CMakeFiles/simplevm_core.dir/depend.make

# Include the progress variables for this target.
include simplevm/CMakeFiles/simplevm_core.dir/progress.make

# Include the compile flags for this target's objects.
include simplevm/CMakeFiles/simplevm_core.dir/flags.make

simplevm/CMakeFiles/simplevm_core.dir/simplevm.cpp.o: simplevm/CMakeFiles/simplevm_core.dir/flags.make
simplevm/CMakeFiles/simplevm_core.dir/simplevm.cpp.o: simplevm/simplevm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object simplevm/CMakeFiles/simplevm_core.dir/simplevm.cpp.o"
	cd /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simplevm_core.dir/simplevm.cpp.o -c /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm/simplevm.cpp

simplevm/CMakeFiles/simplevm_core.dir/simplevm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simplevm_core.dir/simplevm.cpp.i"
	cd /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm/simplevm.cpp > CMakeFiles/simplevm_core.dir/simplevm.cpp.i

simplevm/CMakeFiles/simplevm_core.dir/simplevm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simplevm_core.dir/simplevm.cpp.s"
	cd /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm/simplevm.cpp -o CMakeFiles/simplevm_core.dir/simplevm.cpp.s

# Object files for target simplevm_core
simplevm_core_OBJECTS = \
"CMakeFiles/simplevm_core.dir/simplevm.cpp.o"

# External object files for target simplevm_core
simplevm_core_EXTERNAL_OBJECTS =

simplevm/libsimplevm_core.a: simplevm/CMakeFiles/simplevm_core.dir/simplevm.cpp.o
simplevm/libsimplevm_core.a: simplevm/CMakeFiles/simplevm_core.dir/build.make
simplevm/libsimplevm_core.a: simplevm/CMakeFiles/simplevm_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsimplevm_core.a"
	cd /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm && $(CMAKE_COMMAND) -P CMakeFiles/simplevm_core.dir/cmake_clean_target.cmake
	cd /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simplevm_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
simplevm/CMakeFiles/simplevm_core.dir/build: simplevm/libsimplevm_core.a

.PHONY : simplevm/CMakeFiles/simplevm_core.dir/build

simplevm/CMakeFiles/simplevm_core.dir/clean:
	cd /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm && $(CMAKE_COMMAND) -P CMakeFiles/simplevm_core.dir/cmake_clean.cmake
.PHONY : simplevm/CMakeFiles/simplevm_core.dir/clean

simplevm/CMakeFiles/simplevm_core.dir/depend:
	cd /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2 /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2 /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm /home/andi/Desktop/C++/Cpp-Homework/Sheet02/exercise2/simplevm/CMakeFiles/simplevm_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : simplevm/CMakeFiles/simplevm_core.dir/depend
