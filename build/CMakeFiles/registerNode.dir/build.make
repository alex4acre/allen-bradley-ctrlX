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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/build"

# Include any dependencies generated for this target.
include CMakeFiles/registerNode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/registerNode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/registerNode.dir/flags.make

CMakeFiles/registerNode.dir/main.cpp.o: CMakeFiles/registerNode.dir/flags.make
CMakeFiles/registerNode.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/registerNode.dir/main.cpp.o"
	aarch64-linux-gnu-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/registerNode.dir/main.cpp.o -c "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/main.cpp"

CMakeFiles/registerNode.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/registerNode.dir/main.cpp.i"
	aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/main.cpp" > CMakeFiles/registerNode.dir/main.cpp.i

CMakeFiles/registerNode.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/registerNode.dir/main.cpp.s"
	aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/main.cpp" -o CMakeFiles/registerNode.dir/main.cpp.s

CMakeFiles/registerNode.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/registerNode.dir/main.cpp.o.requires

CMakeFiles/registerNode.dir/main.cpp.o.provides: CMakeFiles/registerNode.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/registerNode.dir/build.make CMakeFiles/registerNode.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/registerNode.dir/main.cpp.o.provides

CMakeFiles/registerNode.dir/main.cpp.o.provides.build: CMakeFiles/registerNode.dir/main.cpp.o


# Object files for target registerNode
registerNode_OBJECTS = \
"CMakeFiles/registerNode.dir/main.cpp.o"

# External object files for target registerNode
registerNode_EXTERNAL_OBJECTS =

registerNode: CMakeFiles/registerNode.dir/main.cpp.o
registerNode: CMakeFiles/registerNode.dir/build.make
registerNode: ../../../bin/comm.datalayer/linux-gcc-aarch64/release/libcomm_datalayer.so
registerNode: ../../../bin/zmq/linux-gcc-aarch64/release/libzmq.so
registerNode: CMakeFiles/registerNode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable registerNode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/registerNode.dir/link.txt --verbose=$(VERBOSE)
	make install
	cd "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node" && snapcraft --target-arch=arm64
	cd "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node" && snapcraft clean

# Rule to build all files generated by this target.
CMakeFiles/registerNode.dir/build: registerNode

.PHONY : CMakeFiles/registerNode.dir/build

CMakeFiles/registerNode.dir/requires: CMakeFiles/registerNode.dir/main.cpp.o.requires

.PHONY : CMakeFiles/registerNode.dir/requires

CMakeFiles/registerNode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/registerNode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/registerNode.dir/clean

CMakeFiles/registerNode.dir/depend:
	cd "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node" "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node" "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/build" "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/build" "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/build/CMakeFiles/registerNode.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/registerNode.dir/depend

