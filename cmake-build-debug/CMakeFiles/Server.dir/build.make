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
include CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/server/server.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/server/server.cpp.o: ../server/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.dir/server/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/server/server.cpp.o -c "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/server.cpp"

CMakeFiles/Server.dir/server/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/server/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/server.cpp" > CMakeFiles/Server.dir/server/server.cpp.i

CMakeFiles/Server.dir/server/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/server/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/server.cpp" -o CMakeFiles/Server.dir/server/server.cpp.s

CMakeFiles/Server.dir/server/server_utility.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/server/server_utility.cpp.o: ../server/server_utility.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Server.dir/server/server_utility.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/server/server_utility.cpp.o -c "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/server_utility.cpp"

CMakeFiles/Server.dir/server/server_utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/server/server_utility.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/server_utility.cpp" > CMakeFiles/Server.dir/server/server_utility.cpp.i

CMakeFiles/Server.dir/server/server_utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/server/server_utility.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/server_utility.cpp" -o CMakeFiles/Server.dir/server/server_utility.cpp.s

CMakeFiles/Server.dir/Functions.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Functions.cpp.o: ../Functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Server.dir/Functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/Functions.cpp.o -c "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/Functions.cpp"

CMakeFiles/Server.dir/Functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/Functions.cpp" > CMakeFiles/Server.dir/Functions.cpp.i

CMakeFiles/Server.dir/Functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/Functions.cpp" -o CMakeFiles/Server.dir/Functions.cpp.s

CMakeFiles/Server.dir/server/CircularBuffer.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/server/CircularBuffer.cpp.o: ../server/CircularBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Server.dir/server/CircularBuffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/server/CircularBuffer.cpp.o -c "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/CircularBuffer.cpp"

CMakeFiles/Server.dir/server/CircularBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/server/CircularBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/CircularBuffer.cpp" > CMakeFiles/Server.dir/server/CircularBuffer.cpp.i

CMakeFiles/Server.dir/server/CircularBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/server/CircularBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/CircularBuffer.cpp" -o CMakeFiles/Server.dir/server/CircularBuffer.cpp.s

CMakeFiles/Server.dir/server/thread_functions.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/server/thread_functions.cpp.o: ../server/thread_functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Server.dir/server/thread_functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/server/thread_functions.cpp.o -c "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/thread_functions.cpp"

CMakeFiles/Server.dir/server/thread_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/server/thread_functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/thread_functions.cpp" > CMakeFiles/Server.dir/server/thread_functions.cpp.i

CMakeFiles/Server.dir/server/thread_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/server/thread_functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/server/thread_functions.cpp" -o CMakeFiles/Server.dir/server/thread_functions.cpp.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/server/server.cpp.o" \
"CMakeFiles/Server.dir/server/server_utility.cpp.o" \
"CMakeFiles/Server.dir/Functions.cpp.o" \
"CMakeFiles/Server.dir/server/CircularBuffer.cpp.o" \
"CMakeFiles/Server.dir/server/thread_functions.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/server/server.cpp.o
Server: CMakeFiles/Server.dir/server/server_utility.cpp.o
Server: CMakeFiles/Server.dir/Functions.cpp.o
Server: CMakeFiles/Server.dir/server/CircularBuffer.cpp.o
Server: CMakeFiles/Server.dir/server/thread_functions.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server

.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles/Server.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend

