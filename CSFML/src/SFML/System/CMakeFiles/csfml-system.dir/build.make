# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Users/lbenard/.brew/Cellar/cmake/3.13.4/bin/cmake

# The command to remove a file.
RM = /Users/lbenard/.brew/Cellar/cmake/3.13.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lbenard/Desktop/github/wolf3d/CSFML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lbenard/Desktop/github/wolf3d/CSFML

# Include any dependencies generated for this target.
include src/SFML/System/CMakeFiles/csfml-system.dir/depend.make

# Include the progress variables for this target.
include src/SFML/System/CMakeFiles/csfml-system.dir/progress.make

# Include the compile flags for this target's objects.
include src/SFML/System/CMakeFiles/csfml-system.dir/flags.make

src/SFML/System/CMakeFiles/csfml-system.dir/Clock.cpp.o: src/SFML/System/CMakeFiles/csfml-system.dir/flags.make
src/SFML/System/CMakeFiles/csfml-system.dir/Clock.cpp.o: src/SFML/System/Clock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbenard/Desktop/github/wolf3d/CSFML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/SFML/System/CMakeFiles/csfml-system.dir/Clock.cpp.o"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/csfml-system.dir/Clock.cpp.o -c /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Clock.cpp

src/SFML/System/CMakeFiles/csfml-system.dir/Clock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/csfml-system.dir/Clock.cpp.i"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Clock.cpp > CMakeFiles/csfml-system.dir/Clock.cpp.i

src/SFML/System/CMakeFiles/csfml-system.dir/Clock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/csfml-system.dir/Clock.cpp.s"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Clock.cpp -o CMakeFiles/csfml-system.dir/Clock.cpp.s

src/SFML/System/CMakeFiles/csfml-system.dir/Mutex.cpp.o: src/SFML/System/CMakeFiles/csfml-system.dir/flags.make
src/SFML/System/CMakeFiles/csfml-system.dir/Mutex.cpp.o: src/SFML/System/Mutex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbenard/Desktop/github/wolf3d/CSFML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/SFML/System/CMakeFiles/csfml-system.dir/Mutex.cpp.o"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/csfml-system.dir/Mutex.cpp.o -c /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Mutex.cpp

src/SFML/System/CMakeFiles/csfml-system.dir/Mutex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/csfml-system.dir/Mutex.cpp.i"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Mutex.cpp > CMakeFiles/csfml-system.dir/Mutex.cpp.i

src/SFML/System/CMakeFiles/csfml-system.dir/Mutex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/csfml-system.dir/Mutex.cpp.s"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Mutex.cpp -o CMakeFiles/csfml-system.dir/Mutex.cpp.s

src/SFML/System/CMakeFiles/csfml-system.dir/Sleep.cpp.o: src/SFML/System/CMakeFiles/csfml-system.dir/flags.make
src/SFML/System/CMakeFiles/csfml-system.dir/Sleep.cpp.o: src/SFML/System/Sleep.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbenard/Desktop/github/wolf3d/CSFML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/SFML/System/CMakeFiles/csfml-system.dir/Sleep.cpp.o"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/csfml-system.dir/Sleep.cpp.o -c /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Sleep.cpp

src/SFML/System/CMakeFiles/csfml-system.dir/Sleep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/csfml-system.dir/Sleep.cpp.i"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Sleep.cpp > CMakeFiles/csfml-system.dir/Sleep.cpp.i

src/SFML/System/CMakeFiles/csfml-system.dir/Sleep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/csfml-system.dir/Sleep.cpp.s"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Sleep.cpp -o CMakeFiles/csfml-system.dir/Sleep.cpp.s

src/SFML/System/CMakeFiles/csfml-system.dir/Thread.cpp.o: src/SFML/System/CMakeFiles/csfml-system.dir/flags.make
src/SFML/System/CMakeFiles/csfml-system.dir/Thread.cpp.o: src/SFML/System/Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbenard/Desktop/github/wolf3d/CSFML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/SFML/System/CMakeFiles/csfml-system.dir/Thread.cpp.o"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/csfml-system.dir/Thread.cpp.o -c /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Thread.cpp

src/SFML/System/CMakeFiles/csfml-system.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/csfml-system.dir/Thread.cpp.i"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Thread.cpp > CMakeFiles/csfml-system.dir/Thread.cpp.i

src/SFML/System/CMakeFiles/csfml-system.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/csfml-system.dir/Thread.cpp.s"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Thread.cpp -o CMakeFiles/csfml-system.dir/Thread.cpp.s

src/SFML/System/CMakeFiles/csfml-system.dir/Time.cpp.o: src/SFML/System/CMakeFiles/csfml-system.dir/flags.make
src/SFML/System/CMakeFiles/csfml-system.dir/Time.cpp.o: src/SFML/System/Time.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbenard/Desktop/github/wolf3d/CSFML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/SFML/System/CMakeFiles/csfml-system.dir/Time.cpp.o"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/csfml-system.dir/Time.cpp.o -c /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Time.cpp

src/SFML/System/CMakeFiles/csfml-system.dir/Time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/csfml-system.dir/Time.cpp.i"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Time.cpp > CMakeFiles/csfml-system.dir/Time.cpp.i

src/SFML/System/CMakeFiles/csfml-system.dir/Time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/csfml-system.dir/Time.cpp.s"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/Time.cpp -o CMakeFiles/csfml-system.dir/Time.cpp.s

# Object files for target csfml-system
csfml__system_OBJECTS = \
"CMakeFiles/csfml-system.dir/Clock.cpp.o" \
"CMakeFiles/csfml-system.dir/Mutex.cpp.o" \
"CMakeFiles/csfml-system.dir/Sleep.cpp.o" \
"CMakeFiles/csfml-system.dir/Thread.cpp.o" \
"CMakeFiles/csfml-system.dir/Time.cpp.o"

# External object files for target csfml-system
csfml__system_EXTERNAL_OBJECTS =

lib/libcsfml-system.2.4.0.dylib: src/SFML/System/CMakeFiles/csfml-system.dir/Clock.cpp.o
lib/libcsfml-system.2.4.0.dylib: src/SFML/System/CMakeFiles/csfml-system.dir/Mutex.cpp.o
lib/libcsfml-system.2.4.0.dylib: src/SFML/System/CMakeFiles/csfml-system.dir/Sleep.cpp.o
lib/libcsfml-system.2.4.0.dylib: src/SFML/System/CMakeFiles/csfml-system.dir/Thread.cpp.o
lib/libcsfml-system.2.4.0.dylib: src/SFML/System/CMakeFiles/csfml-system.dir/Time.cpp.o
lib/libcsfml-system.2.4.0.dylib: src/SFML/System/CMakeFiles/csfml-system.dir/build.make
lib/libcsfml-system.2.4.0.dylib: /Users/lbenard/Desktop/github/wolf3d/SFML/lib/libsfml-system.dylib
lib/libcsfml-system.2.4.0.dylib: src/SFML/System/CMakeFiles/csfml-system.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lbenard/Desktop/github/wolf3d/CSFML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library ../../../lib/libcsfml-system.dylib"
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/csfml-system.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../lib/libcsfml-system.2.4.0.dylib ../../../lib/libcsfml-system.2.4.dylib ../../../lib/libcsfml-system.dylib

lib/libcsfml-system.2.4.dylib: lib/libcsfml-system.2.4.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libcsfml-system.2.4.dylib

lib/libcsfml-system.dylib: lib/libcsfml-system.2.4.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libcsfml-system.dylib

# Rule to build all files generated by this target.
src/SFML/System/CMakeFiles/csfml-system.dir/build: lib/libcsfml-system.dylib

.PHONY : src/SFML/System/CMakeFiles/csfml-system.dir/build

src/SFML/System/CMakeFiles/csfml-system.dir/clean:
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System && $(CMAKE_COMMAND) -P CMakeFiles/csfml-system.dir/cmake_clean.cmake
.PHONY : src/SFML/System/CMakeFiles/csfml-system.dir/clean

src/SFML/System/CMakeFiles/csfml-system.dir/depend:
	cd /Users/lbenard/Desktop/github/wolf3d/CSFML && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lbenard/Desktop/github/wolf3d/CSFML /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System /Users/lbenard/Desktop/github/wolf3d/CSFML /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System /Users/lbenard/Desktop/github/wolf3d/CSFML/src/SFML/System/CMakeFiles/csfml-system.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/SFML/System/CMakeFiles/csfml-system.dir/depend

