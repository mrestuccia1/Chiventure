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
CMAKE_SOURCE_DIR = /home/maggiex/cs220/chiventure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maggiex/cs220/chiventure/src

# Utility rule file for battle-examples.

# Include the progress variables for this target.
include src/battle/examples/CMakeFiles/battle-examples.dir/progress.make

src/battle/examples/CMakeFiles/battle-examples: src/battle/examples/battle_command_example
src/battle/examples/CMakeFiles/battle-examples: src/battle/examples/battle_flow_example
src/battle/examples/CMakeFiles/battle-examples: src/battle/examples/battle_cli_example


battle-examples: src/battle/examples/CMakeFiles/battle-examples
battle-examples: src/battle/examples/CMakeFiles/battle-examples.dir/build.make

.PHONY : battle-examples

# Rule to build all files generated by this target.
src/battle/examples/CMakeFiles/battle-examples.dir/build: battle-examples

.PHONY : src/battle/examples/CMakeFiles/battle-examples.dir/build

src/battle/examples/CMakeFiles/battle-examples.dir/clean:
	cd /home/maggiex/cs220/chiventure/src/src/battle/examples && $(CMAKE_COMMAND) -P CMakeFiles/battle-examples.dir/cmake_clean.cmake
.PHONY : src/battle/examples/CMakeFiles/battle-examples.dir/clean

src/battle/examples/CMakeFiles/battle-examples.dir/depend:
	cd /home/maggiex/cs220/chiventure/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/src/battle/examples /home/maggiex/cs220/chiventure/src /home/maggiex/cs220/chiventure/src/src/battle/examples /home/maggiex/cs220/chiventure/src/src/battle/examples/CMakeFiles/battle-examples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/battle/examples/CMakeFiles/battle-examples.dir/depend

