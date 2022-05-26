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

# Include any dependencies generated for this target.
include src/game-state/examples/CMakeFiles/stats_example.dir/depend.make

# Include the progress variables for this target.
include src/game-state/examples/CMakeFiles/stats_example.dir/progress.make

# Include the compile flags for this target's objects.
include src/game-state/examples/CMakeFiles/stats_example.dir/flags.make

src/game-state/examples/CMakeFiles/stats_example.dir/stats_example.c.o: src/game-state/examples/CMakeFiles/stats_example.dir/flags.make
src/game-state/examples/CMakeFiles/stats_example.dir/stats_example.c.o: game-state/examples/stats_example.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/game-state/examples/CMakeFiles/stats_example.dir/stats_example.c.o"
	cd /home/maggiex/cs220/chiventure/src/src/game-state/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stats_example.dir/stats_example.c.o   -c /home/maggiex/cs220/chiventure/src/game-state/examples/stats_example.c

src/game-state/examples/CMakeFiles/stats_example.dir/stats_example.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stats_example.dir/stats_example.c.i"
	cd /home/maggiex/cs220/chiventure/src/src/game-state/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/src/game-state/examples/stats_example.c > CMakeFiles/stats_example.dir/stats_example.c.i

src/game-state/examples/CMakeFiles/stats_example.dir/stats_example.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stats_example.dir/stats_example.c.s"
	cd /home/maggiex/cs220/chiventure/src/src/game-state/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/src/game-state/examples/stats_example.c -o CMakeFiles/stats_example.dir/stats_example.c.s

# Object files for target stats_example
stats_example_OBJECTS = \
"CMakeFiles/stats_example.dir/stats_example.c.o"

# External object files for target stats_example
stats_example_EXTERNAL_OBJECTS =

src/game-state/examples/stats_example: src/game-state/examples/CMakeFiles/stats_example.dir/stats_example.c.o
src/game-state/examples/stats_example: src/game-state/examples/CMakeFiles/stats_example.dir/build.make
src/game-state/examples/stats_example: src/action_management/libaction_management.a
src/game-state/examples/stats_example: src/battle/libbattle.a
src/game-state/examples/stats_example: src/cli/libcli.a
src/game-state/examples/stats_example: src/common/libcommon.a
src/game-state/examples/stats_example: src/custom-actions/libcustom-actions.a
src/game-state/examples/stats_example: src/game-state/libgame-state.a
src/game-state/examples/stats_example: src/libobj/liblibobj.a
src/game-state/examples/stats_example: src/quests/libquests.a
src/game-state/examples/stats_example: src/sound/libsound.a
src/game-state/examples/stats_example: src/npc/libnpc.a
src/game-state/examples/stats_example: src/openworld/libopenworld.a
src/game-state/examples/stats_example: src/playerclass/libplayerclass.a
src/game-state/examples/stats_example: src/skilltrees/libskilltrees.a
src/game-state/examples/stats_example: src/ui/libui.a
src/game-state/examples/stats_example: src/wdl/libwdl.a
src/game-state/examples/stats_example: src/custom-scripts/libcustom-scripts.a
src/game-state/examples/stats_example: src/cli/libcli.a
src/game-state/examples/stats_example: src/common/libcommon.a
src/game-state/examples/stats_example: src/game-state/libgame-state.a
src/game-state/examples/stats_example: src/cli/libcli.a
src/game-state/examples/stats_example: src/common/libcommon.a
src/game-state/examples/stats_example: src/game-state/libgame-state.a
src/game-state/examples/stats_example: src/action_management/libaction_management.a
src/game-state/examples/stats_example: src/ui/libui.a
src/game-state/examples/stats_example: /usr/lib/x86_64-linux-gnu/libncursesw.so
src/game-state/examples/stats_example: /usr/lib/x86_64-linux-gnu/libformw.so
src/game-state/examples/stats_example: src/quests/libquests.a
src/game-state/examples/stats_example: src/wdl/libwdl.a
src/game-state/examples/stats_example: src/libobj/liblibobj.a
src/game-state/examples/stats_example: src/npc/libnpc.a
src/game-state/examples/stats_example: src/battle/libbattle.a
src/game-state/examples/stats_example: src/playerclass/libplayerclass.a
src/game-state/examples/stats_example: src/skilltrees/libskilltrees.a
src/game-state/examples/stats_example: /usr/lib/x86_64-linux-gnu/libzip.so
src/game-state/examples/stats_example: /usr/lib/x86_64-linux-gnu/libjson-c.so
src/game-state/examples/stats_example: /usr/lib/x86_64-linux-gnu/liblua5.3.so
src/game-state/examples/stats_example: /usr/lib/x86_64-linux-gnu/libm.so
src/game-state/examples/stats_example: src/game-state/examples/CMakeFiles/stats_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maggiex/cs220/chiventure/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable stats_example"
	cd /home/maggiex/cs220/chiventure/src/src/game-state/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stats_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/game-state/examples/CMakeFiles/stats_example.dir/build: src/game-state/examples/stats_example

.PHONY : src/game-state/examples/CMakeFiles/stats_example.dir/build

src/game-state/examples/CMakeFiles/stats_example.dir/clean:
	cd /home/maggiex/cs220/chiventure/src/src/game-state/examples && $(CMAKE_COMMAND) -P CMakeFiles/stats_example.dir/cmake_clean.cmake
.PHONY : src/game-state/examples/CMakeFiles/stats_example.dir/clean

src/game-state/examples/CMakeFiles/stats_example.dir/depend:
	cd /home/maggiex/cs220/chiventure/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/src/game-state/examples /home/maggiex/cs220/chiventure/src /home/maggiex/cs220/chiventure/src/src/game-state/examples /home/maggiex/cs220/chiventure/src/src/game-state/examples/CMakeFiles/stats_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/game-state/examples/CMakeFiles/stats_example.dir/depend

