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
CMAKE_SOURCE_DIR = /home/diego/Documents/GameEngineDD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diego/Documents/GameEngineDD/build

# Include any dependencies generated for this target.
include CMakeFiles/GEA.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GEA.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GEA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GEA.dir/flags.make

CMakeFiles/GEA.dir/src/main.cpp.o: CMakeFiles/GEA.dir/flags.make
CMakeFiles/GEA.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/GEA.dir/src/main.cpp.o: CMakeFiles/GEA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Documents/GameEngineDD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GEA.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GEA.dir/src/main.cpp.o -MF CMakeFiles/GEA.dir/src/main.cpp.o.d -o CMakeFiles/GEA.dir/src/main.cpp.o -c /home/diego/Documents/GameEngineDD/src/main.cpp

CMakeFiles/GEA.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GEA.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Documents/GameEngineDD/src/main.cpp > CMakeFiles/GEA.dir/src/main.cpp.i

CMakeFiles/GEA.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GEA.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Documents/GameEngineDD/src/main.cpp -o CMakeFiles/GEA.dir/src/main.cpp.s

CMakeFiles/GEA.dir/src/Game/Game.cpp.o: CMakeFiles/GEA.dir/flags.make
CMakeFiles/GEA.dir/src/Game/Game.cpp.o: ../src/Game/Game.cpp
CMakeFiles/GEA.dir/src/Game/Game.cpp.o: CMakeFiles/GEA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Documents/GameEngineDD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GEA.dir/src/Game/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GEA.dir/src/Game/Game.cpp.o -MF CMakeFiles/GEA.dir/src/Game/Game.cpp.o.d -o CMakeFiles/GEA.dir/src/Game/Game.cpp.o -c /home/diego/Documents/GameEngineDD/src/Game/Game.cpp

CMakeFiles/GEA.dir/src/Game/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GEA.dir/src/Game/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Documents/GameEngineDD/src/Game/Game.cpp > CMakeFiles/GEA.dir/src/Game/Game.cpp.i

CMakeFiles/GEA.dir/src/Game/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GEA.dir/src/Game/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Documents/GameEngineDD/src/Game/Game.cpp -o CMakeFiles/GEA.dir/src/Game/Game.cpp.s

CMakeFiles/GEA.dir/src/Pong/Pong.cpp.o: CMakeFiles/GEA.dir/flags.make
CMakeFiles/GEA.dir/src/Pong/Pong.cpp.o: ../src/Pong/Pong.cpp
CMakeFiles/GEA.dir/src/Pong/Pong.cpp.o: CMakeFiles/GEA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Documents/GameEngineDD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GEA.dir/src/Pong/Pong.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GEA.dir/src/Pong/Pong.cpp.o -MF CMakeFiles/GEA.dir/src/Pong/Pong.cpp.o.d -o CMakeFiles/GEA.dir/src/Pong/Pong.cpp.o -c /home/diego/Documents/GameEngineDD/src/Pong/Pong.cpp

CMakeFiles/GEA.dir/src/Pong/Pong.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GEA.dir/src/Pong/Pong.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Documents/GameEngineDD/src/Pong/Pong.cpp > CMakeFiles/GEA.dir/src/Pong/Pong.cpp.i

CMakeFiles/GEA.dir/src/Pong/Pong.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GEA.dir/src/Pong/Pong.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Documents/GameEngineDD/src/Pong/Pong.cpp -o CMakeFiles/GEA.dir/src/Pong/Pong.cpp.s

CMakeFiles/GEA.dir/src/Scene/Scene.cpp.o: CMakeFiles/GEA.dir/flags.make
CMakeFiles/GEA.dir/src/Scene/Scene.cpp.o: ../src/Scene/Scene.cpp
CMakeFiles/GEA.dir/src/Scene/Scene.cpp.o: CMakeFiles/GEA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Documents/GameEngineDD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GEA.dir/src/Scene/Scene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GEA.dir/src/Scene/Scene.cpp.o -MF CMakeFiles/GEA.dir/src/Scene/Scene.cpp.o.d -o CMakeFiles/GEA.dir/src/Scene/Scene.cpp.o -c /home/diego/Documents/GameEngineDD/src/Scene/Scene.cpp

CMakeFiles/GEA.dir/src/Scene/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GEA.dir/src/Scene/Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Documents/GameEngineDD/src/Scene/Scene.cpp > CMakeFiles/GEA.dir/src/Scene/Scene.cpp.i

CMakeFiles/GEA.dir/src/Scene/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GEA.dir/src/Scene/Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Documents/GameEngineDD/src/Scene/Scene.cpp -o CMakeFiles/GEA.dir/src/Scene/Scene.cpp.s

# Object files for target GEA
GEA_OBJECTS = \
"CMakeFiles/GEA.dir/src/main.cpp.o" \
"CMakeFiles/GEA.dir/src/Game/Game.cpp.o" \
"CMakeFiles/GEA.dir/src/Pong/Pong.cpp.o" \
"CMakeFiles/GEA.dir/src/Scene/Scene.cpp.o"

# External object files for target GEA
GEA_EXTERNAL_OBJECTS =

GEA: CMakeFiles/GEA.dir/src/main.cpp.o
GEA: CMakeFiles/GEA.dir/src/Game/Game.cpp.o
GEA: CMakeFiles/GEA.dir/src/Pong/Pong.cpp.o
GEA: CMakeFiles/GEA.dir/src/Scene/Scene.cpp.o
GEA: CMakeFiles/GEA.dir/build.make
GEA: CMakeFiles/GEA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diego/Documents/GameEngineDD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable GEA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GEA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GEA.dir/build: GEA
.PHONY : CMakeFiles/GEA.dir/build

CMakeFiles/GEA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GEA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GEA.dir/clean

CMakeFiles/GEA.dir/depend:
	cd /home/diego/Documents/GameEngineDD/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diego/Documents/GameEngineDD /home/diego/Documents/GameEngineDD /home/diego/Documents/GameEngineDD/build /home/diego/Documents/GameEngineDD/build /home/diego/Documents/GameEngineDD/build/CMakeFiles/GEA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GEA.dir/depend

