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
CMAKE_COMMAND = /snap/clion/114/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/114/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/sumSquares.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sumSquares.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sumSquares.dir/flags.make

CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.o: CMakeFiles/sumSquares.dir/flags.make
CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.o: ../thread/sumSquares.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.o -c "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/thread/sumSquares.cpp"

CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/thread/sumSquares.cpp" > CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.i

CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/thread/sumSquares.cpp" -o CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.s

# Object files for target sumSquares
sumSquares_OBJECTS = \
"CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.o"

# External object files for target sumSquares
sumSquares_EXTERNAL_OBJECTS =

sumSquares: CMakeFiles/sumSquares.dir/thread/sumSquares.cpp.o
sumSquares: CMakeFiles/sumSquares.dir/build.make
sumSquares: CMakeFiles/sumSquares.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sumSquares"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sumSquares.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sumSquares.dir/build: sumSquares

.PHONY : CMakeFiles/sumSquares.dir/build

CMakeFiles/sumSquares.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sumSquares.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sumSquares.dir/clean

CMakeFiles/sumSquares.dir/depend:
	cd "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles/sumSquares.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/sumSquares.dir/depend

