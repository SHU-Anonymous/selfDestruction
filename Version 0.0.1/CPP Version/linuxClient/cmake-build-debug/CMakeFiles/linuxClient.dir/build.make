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
CMAKE_SOURCE_DIR = "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/linuxClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linuxClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linuxClient.dir/flags.make

CMakeFiles/linuxClient.dir/main.cpp.o: CMakeFiles/linuxClient.dir/flags.make
CMakeFiles/linuxClient.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linuxClient.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linuxClient.dir/main.cpp.o -c "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/main.cpp"

CMakeFiles/linuxClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linuxClient.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/main.cpp" > CMakeFiles/linuxClient.dir/main.cpp.i

CMakeFiles/linuxClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linuxClient.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/main.cpp" -o CMakeFiles/linuxClient.dir/main.cpp.s

CMakeFiles/linuxClient.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/linuxClient.dir/main.cpp.o.requires

CMakeFiles/linuxClient.dir/main.cpp.o.provides: CMakeFiles/linuxClient.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/linuxClient.dir/build.make CMakeFiles/linuxClient.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/linuxClient.dir/main.cpp.o.provides

CMakeFiles/linuxClient.dir/main.cpp.o.provides.build: CMakeFiles/linuxClient.dir/main.cpp.o


CMakeFiles/linuxClient.dir/socketConsume.cpp.o: CMakeFiles/linuxClient.dir/flags.make
CMakeFiles/linuxClient.dir/socketConsume.cpp.o: ../socketConsume.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/linuxClient.dir/socketConsume.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linuxClient.dir/socketConsume.cpp.o -c "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/socketConsume.cpp"

CMakeFiles/linuxClient.dir/socketConsume.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linuxClient.dir/socketConsume.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/socketConsume.cpp" > CMakeFiles/linuxClient.dir/socketConsume.cpp.i

CMakeFiles/linuxClient.dir/socketConsume.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linuxClient.dir/socketConsume.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/socketConsume.cpp" -o CMakeFiles/linuxClient.dir/socketConsume.cpp.s

CMakeFiles/linuxClient.dir/socketConsume.cpp.o.requires:

.PHONY : CMakeFiles/linuxClient.dir/socketConsume.cpp.o.requires

CMakeFiles/linuxClient.dir/socketConsume.cpp.o.provides: CMakeFiles/linuxClient.dir/socketConsume.cpp.o.requires
	$(MAKE) -f CMakeFiles/linuxClient.dir/build.make CMakeFiles/linuxClient.dir/socketConsume.cpp.o.provides.build
.PHONY : CMakeFiles/linuxClient.dir/socketConsume.cpp.o.provides

CMakeFiles/linuxClient.dir/socketConsume.cpp.o.provides.build: CMakeFiles/linuxClient.dir/socketConsume.cpp.o


CMakeFiles/linuxClient.dir/mainClient.cpp.o: CMakeFiles/linuxClient.dir/flags.make
CMakeFiles/linuxClient.dir/mainClient.cpp.o: ../mainClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/linuxClient.dir/mainClient.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linuxClient.dir/mainClient.cpp.o -c "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/mainClient.cpp"

CMakeFiles/linuxClient.dir/mainClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linuxClient.dir/mainClient.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/mainClient.cpp" > CMakeFiles/linuxClient.dir/mainClient.cpp.i

CMakeFiles/linuxClient.dir/mainClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linuxClient.dir/mainClient.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/mainClient.cpp" -o CMakeFiles/linuxClient.dir/mainClient.cpp.s

CMakeFiles/linuxClient.dir/mainClient.cpp.o.requires:

.PHONY : CMakeFiles/linuxClient.dir/mainClient.cpp.o.requires

CMakeFiles/linuxClient.dir/mainClient.cpp.o.provides: CMakeFiles/linuxClient.dir/mainClient.cpp.o.requires
	$(MAKE) -f CMakeFiles/linuxClient.dir/build.make CMakeFiles/linuxClient.dir/mainClient.cpp.o.provides.build
.PHONY : CMakeFiles/linuxClient.dir/mainClient.cpp.o.provides

CMakeFiles/linuxClient.dir/mainClient.cpp.o.provides.build: CMakeFiles/linuxClient.dir/mainClient.cpp.o


CMakeFiles/linuxClient.dir/executioner.cpp.o: CMakeFiles/linuxClient.dir/flags.make
CMakeFiles/linuxClient.dir/executioner.cpp.o: ../executioner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/linuxClient.dir/executioner.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linuxClient.dir/executioner.cpp.o -c "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/executioner.cpp"

CMakeFiles/linuxClient.dir/executioner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linuxClient.dir/executioner.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/executioner.cpp" > CMakeFiles/linuxClient.dir/executioner.cpp.i

CMakeFiles/linuxClient.dir/executioner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linuxClient.dir/executioner.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/executioner.cpp" -o CMakeFiles/linuxClient.dir/executioner.cpp.s

CMakeFiles/linuxClient.dir/executioner.cpp.o.requires:

.PHONY : CMakeFiles/linuxClient.dir/executioner.cpp.o.requires

CMakeFiles/linuxClient.dir/executioner.cpp.o.provides: CMakeFiles/linuxClient.dir/executioner.cpp.o.requires
	$(MAKE) -f CMakeFiles/linuxClient.dir/build.make CMakeFiles/linuxClient.dir/executioner.cpp.o.provides.build
.PHONY : CMakeFiles/linuxClient.dir/executioner.cpp.o.provides

CMakeFiles/linuxClient.dir/executioner.cpp.o.provides.build: CMakeFiles/linuxClient.dir/executioner.cpp.o


# Object files for target linuxClient
linuxClient_OBJECTS = \
"CMakeFiles/linuxClient.dir/main.cpp.o" \
"CMakeFiles/linuxClient.dir/socketConsume.cpp.o" \
"CMakeFiles/linuxClient.dir/mainClient.cpp.o" \
"CMakeFiles/linuxClient.dir/executioner.cpp.o"

# External object files for target linuxClient
linuxClient_EXTERNAL_OBJECTS =

linuxClient: CMakeFiles/linuxClient.dir/main.cpp.o
linuxClient: CMakeFiles/linuxClient.dir/socketConsume.cpp.o
linuxClient: CMakeFiles/linuxClient.dir/mainClient.cpp.o
linuxClient: CMakeFiles/linuxClient.dir/executioner.cpp.o
linuxClient: CMakeFiles/linuxClient.dir/build.make
linuxClient: CMakeFiles/linuxClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable linuxClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linuxClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linuxClient.dir/build: linuxClient

.PHONY : CMakeFiles/linuxClient.dir/build

CMakeFiles/linuxClient.dir/requires: CMakeFiles/linuxClient.dir/main.cpp.o.requires
CMakeFiles/linuxClient.dir/requires: CMakeFiles/linuxClient.dir/socketConsume.cpp.o.requires
CMakeFiles/linuxClient.dir/requires: CMakeFiles/linuxClient.dir/mainClient.cpp.o.requires
CMakeFiles/linuxClient.dir/requires: CMakeFiles/linuxClient.dir/executioner.cpp.o.requires

.PHONY : CMakeFiles/linuxClient.dir/requires

CMakeFiles/linuxClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linuxClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linuxClient.dir/clean

CMakeFiles/linuxClient.dir/depend:
	cd "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient" "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient" "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/cmake-build-debug" "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/cmake-build-debug" "/Users/lixin/GitHub/selfDestruction/Version 0.0.1/CPP Version/linuxClient/cmake-build-debug/CMakeFiles/linuxClient.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/linuxClient.dir/depend

