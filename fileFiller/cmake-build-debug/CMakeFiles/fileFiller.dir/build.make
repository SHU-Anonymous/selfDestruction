# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "/Users/lixin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/172.3317.14/CLion 2017.2 EAP.app/Contents/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/Users/lixin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/172.3317.14/CLion 2017.2 EAP.app/Contents/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lixin/GitHub/selfDestruction/fileFiller

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lixin/GitHub/selfDestruction/fileFiller/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fileFiller.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fileFiller.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fileFiller.dir/flags.make

CMakeFiles/fileFiller.dir/main.cpp.o: CMakeFiles/fileFiller.dir/flags.make
CMakeFiles/fileFiller.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lixin/GitHub/selfDestruction/fileFiller/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fileFiller.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fileFiller.dir/main.cpp.o -c /Users/lixin/GitHub/selfDestruction/fileFiller/main.cpp

CMakeFiles/fileFiller.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fileFiller.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lixin/GitHub/selfDestruction/fileFiller/main.cpp > CMakeFiles/fileFiller.dir/main.cpp.i

CMakeFiles/fileFiller.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fileFiller.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lixin/GitHub/selfDestruction/fileFiller/main.cpp -o CMakeFiles/fileFiller.dir/main.cpp.s

CMakeFiles/fileFiller.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/fileFiller.dir/main.cpp.o.requires

CMakeFiles/fileFiller.dir/main.cpp.o.provides: CMakeFiles/fileFiller.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/fileFiller.dir/build.make CMakeFiles/fileFiller.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/fileFiller.dir/main.cpp.o.provides

CMakeFiles/fileFiller.dir/main.cpp.o.provides.build: CMakeFiles/fileFiller.dir/main.cpp.o


# Object files for target fileFiller
fileFiller_OBJECTS = \
"CMakeFiles/fileFiller.dir/main.cpp.o"

# External object files for target fileFiller
fileFiller_EXTERNAL_OBJECTS =

fileFiller: CMakeFiles/fileFiller.dir/main.cpp.o
fileFiller: CMakeFiles/fileFiller.dir/build.make
fileFiller: CMakeFiles/fileFiller.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lixin/GitHub/selfDestruction/fileFiller/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fileFiller"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fileFiller.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fileFiller.dir/build: fileFiller

.PHONY : CMakeFiles/fileFiller.dir/build

CMakeFiles/fileFiller.dir/requires: CMakeFiles/fileFiller.dir/main.cpp.o.requires

.PHONY : CMakeFiles/fileFiller.dir/requires

CMakeFiles/fileFiller.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fileFiller.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fileFiller.dir/clean

CMakeFiles/fileFiller.dir/depend:
	cd /Users/lixin/GitHub/selfDestruction/fileFiller/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lixin/GitHub/selfDestruction/fileFiller /Users/lixin/GitHub/selfDestruction/fileFiller /Users/lixin/GitHub/selfDestruction/fileFiller/cmake-build-debug /Users/lixin/GitHub/selfDestruction/fileFiller/cmake-build-debug /Users/lixin/GitHub/selfDestruction/fileFiller/cmake-build-debug/CMakeFiles/fileFiller.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fileFiller.dir/depend

