# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bakerlm/CPPProjects/ImageProcessing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bakerlm/CPPProjects/ImageProcessing/build

# Include any dependencies generated for this target.
include CMakeFiles/ImageProcessing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ImageProcessing.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageProcessing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageProcessing.dir/flags.make

CMakeFiles/ImageProcessing.dir/src/main.cpp.o: CMakeFiles/ImageProcessing.dir/flags.make
CMakeFiles/ImageProcessing.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/ImageProcessing.dir/src/main.cpp.o: CMakeFiles/ImageProcessing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bakerlm/CPPProjects/ImageProcessing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ImageProcessing.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ImageProcessing.dir/src/main.cpp.o -MF CMakeFiles/ImageProcessing.dir/src/main.cpp.o.d -o CMakeFiles/ImageProcessing.dir/src/main.cpp.o -c /home/bakerlm/CPPProjects/ImageProcessing/src/main.cpp

CMakeFiles/ImageProcessing.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageProcessing.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bakerlm/CPPProjects/ImageProcessing/src/main.cpp > CMakeFiles/ImageProcessing.dir/src/main.cpp.i

CMakeFiles/ImageProcessing.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageProcessing.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bakerlm/CPPProjects/ImageProcessing/src/main.cpp -o CMakeFiles/ImageProcessing.dir/src/main.cpp.s

# Object files for target ImageProcessing
ImageProcessing_OBJECTS = \
"CMakeFiles/ImageProcessing.dir/src/main.cpp.o"

# External object files for target ImageProcessing
ImageProcessing_EXTERNAL_OBJECTS =

ImageProcessing: CMakeFiles/ImageProcessing.dir/src/main.cpp.o
ImageProcessing: CMakeFiles/ImageProcessing.dir/build.make
ImageProcessing: CMakeFiles/ImageProcessing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bakerlm/CPPProjects/ImageProcessing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ImageProcessing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageProcessing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageProcessing.dir/build: ImageProcessing
.PHONY : CMakeFiles/ImageProcessing.dir/build

CMakeFiles/ImageProcessing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageProcessing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageProcessing.dir/clean

CMakeFiles/ImageProcessing.dir/depend:
	cd /home/bakerlm/CPPProjects/ImageProcessing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bakerlm/CPPProjects/ImageProcessing /home/bakerlm/CPPProjects/ImageProcessing /home/bakerlm/CPPProjects/ImageProcessing/build /home/bakerlm/CPPProjects/ImageProcessing/build /home/bakerlm/CPPProjects/ImageProcessing/build/CMakeFiles/ImageProcessing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ImageProcessing.dir/depend

