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
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/client/client.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/client/client.cpp.o: ../client/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Client.dir/client/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/client/client.cpp.o -c "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/client/client.cpp"

CMakeFiles/Client.dir/client/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/client/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/client/client.cpp" > CMakeFiles/Client.dir/client/client.cpp.i

CMakeFiles/Client.dir/client/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/client/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/client/client.cpp" -o CMakeFiles/Client.dir/client/client.cpp.s

CMakeFiles/Client.dir/client/client_utility.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/client/client_utility.cpp.o: ../client/client_utility.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Client.dir/client/client_utility.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/client/client_utility.cpp.o -c "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/client/client_utility.cpp"

CMakeFiles/Client.dir/client/client_utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/client/client_utility.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/client/client_utility.cpp" > CMakeFiles/Client.dir/client/client_utility.cpp.i

CMakeFiles/Client.dir/client/client_utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/client/client_utility.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/client/client_utility.cpp" -o CMakeFiles/Client.dir/client/client_utility.cpp.s

CMakeFiles/Client.dir/common/Functions.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/common/Functions.cpp.o: ../common/Functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Client.dir/common/Functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/common/Functions.cpp.o -c "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/common/Functions.cpp"

CMakeFiles/Client.dir/common/Functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/common/Functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/common/Functions.cpp" > CMakeFiles/Client.dir/common/Functions.cpp.i

CMakeFiles/Client.dir/common/Functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/common/Functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/common/Functions.cpp" -o CMakeFiles/Client.dir/common/Functions.cpp.s

CMakeFiles/Client.dir/client/threads.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/client/threads.cpp.o: ../client/threads.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Client.dir/client/threads.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/client/threads.cpp.o -c "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/client/threads.cpp"

CMakeFiles/Client.dir/client/threads.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/client/threads.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/client/threads.cpp" > CMakeFiles/Client.dir/client/threads.cpp.i

CMakeFiles/Client.dir/client/threads.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/client/threads.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/client/threads.cpp" -o CMakeFiles/Client.dir/client/threads.cpp.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/client/client.cpp.o" \
"CMakeFiles/Client.dir/client/client_utility.cpp.o" \
"CMakeFiles/Client.dir/common/Functions.cpp.o" \
"CMakeFiles/Client.dir/client/threads.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/client/client.cpp.o
Client: CMakeFiles/Client.dir/client/client_utility.cpp.o
Client: CMakeFiles/Client.dir/common/Functions.cpp.o
Client: CMakeFiles/Client.dir/client/threads.cpp.o
Client: CMakeFiles/Client.dir/build.make
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug" "/home/takis/Documents/DI/6ο εξαμηνο/SysPro/Project3/cmake-build-debug/CMakeFiles/Client.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

