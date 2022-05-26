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
include src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/depend.make

# Include the progress variables for this target.
include src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/progress.make

# Include the compile flags for this target's objects.
include src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/flags.make

src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.o: src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/flags.make
src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.o: skilltrees/examples/skilltrees_demo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.o"
	cd /home/maggiex/cs220/chiventure/src/src/skilltrees/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.o   -c /home/maggiex/cs220/chiventure/src/skilltrees/examples/skilltrees_demo.c

src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.i"
	cd /home/maggiex/cs220/chiventure/src/src/skilltrees/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/src/skilltrees/examples/skilltrees_demo.c > CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.i

src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.s"
	cd /home/maggiex/cs220/chiventure/src/src/skilltrees/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/src/skilltrees/examples/skilltrees_demo.c -o CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.s

# Object files for target skilltrees_demo
skilltrees_demo_OBJECTS = \
"CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.o"

# External object files for target skilltrees_demo
skilltrees_demo_EXTERNAL_OBJECTS =

src/skilltrees/examples/skilltrees_demo: src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/skilltrees_demo.c.o
src/skilltrees/examples/skilltrees_demo: src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/build.make
src/skilltrees/examples/skilltrees_demo: src/action_management/libaction_management.a
src/skilltrees/examples/skilltrees_demo: src/battle/libbattle.a
src/skilltrees/examples/skilltrees_demo: src/cli/libcli.a
src/skilltrees/examples/skilltrees_demo: src/common/libcommon.a
src/skilltrees/examples/skilltrees_demo: src/custom-actions/libcustom-actions.a
src/skilltrees/examples/skilltrees_demo: src/game-state/libgame-state.a
src/skilltrees/examples/skilltrees_demo: src/libobj/liblibobj.a
src/skilltrees/examples/skilltrees_demo: src/quests/libquests.a
src/skilltrees/examples/skilltrees_demo: src/sound/libsound.a
src/skilltrees/examples/skilltrees_demo: src/npc/libnpc.a
src/skilltrees/examples/skilltrees_demo: src/openworld/libopenworld.a
src/skilltrees/examples/skilltrees_demo: src/playerclass/libplayerclass.a
src/skilltrees/examples/skilltrees_demo: src/skilltrees/libskilltrees.a
src/skilltrees/examples/skilltrees_demo: src/ui/libui.a
src/skilltrees/examples/skilltrees_demo: src/wdl/libwdl.a
src/skilltrees/examples/skilltrees_demo: src/custom-scripts/libcustom-scripts.a
src/skilltrees/examples/skilltrees_demo: src/cli/libcli.a
src/skilltrees/examples/skilltrees_demo: src/common/libcommon.a
src/skilltrees/examples/skilltrees_demo: src/game-state/libgame-state.a
src/skilltrees/examples/skilltrees_demo: src/cli/libcli.a
src/skilltrees/examples/skilltrees_demo: src/common/libcommon.a
src/skilltrees/examples/skilltrees_demo: src/game-state/libgame-state.a
src/skilltrees/examples/skilltrees_demo: src/action_management/libaction_management.a
src/skilltrees/examples/skilltrees_demo: src/ui/libui.a
src/skilltrees/examples/skilltrees_demo: /usr/lib/x86_64-linux-gnu/libncursesw.so
src/skilltrees/examples/skilltrees_demo: /usr/lib/x86_64-linux-gnu/libformw.so
src/skilltrees/examples/skilltrees_demo: src/quests/libquests.a
src/skilltrees/examples/skilltrees_demo: src/wdl/libwdl.a
src/skilltrees/examples/skilltrees_demo: src/libobj/liblibobj.a
src/skilltrees/examples/skilltrees_demo: src/npc/libnpc.a
src/skilltrees/examples/skilltrees_demo: src/battle/libbattle.a
src/skilltrees/examples/skilltrees_demo: src/playerclass/libplayerclass.a
src/skilltrees/examples/skilltrees_demo: src/skilltrees/libskilltrees.a
src/skilltrees/examples/skilltrees_demo: /usr/lib/x86_64-linux-gnu/libzip.so
src/skilltrees/examples/skilltrees_demo: /usr/lib/x86_64-linux-gnu/libjson-c.so
src/skilltrees/examples/skilltrees_demo: /usr/lib/x86_64-linux-gnu/liblua5.3.so
src/skilltrees/examples/skilltrees_demo: /usr/lib/x86_64-linux-gnu/libm.so
src/skilltrees/examples/skilltrees_demo: src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maggiex/cs220/chiventure/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable skilltrees_demo"
	cd /home/maggiex/cs220/chiventure/src/src/skilltrees/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/skilltrees_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/build: src/skilltrees/examples/skilltrees_demo

.PHONY : src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/build

src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/clean:
	cd /home/maggiex/cs220/chiventure/src/src/skilltrees/examples && $(CMAKE_COMMAND) -P CMakeFiles/skilltrees_demo.dir/cmake_clean.cmake
.PHONY : src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/clean

src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/depend:
	cd /home/maggiex/cs220/chiventure/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/src/skilltrees/examples /home/maggiex/cs220/chiventure/src /home/maggiex/cs220/chiventure/src/src/skilltrees/examples /home/maggiex/cs220/chiventure/src/src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/skilltrees/examples/CMakeFiles/skilltrees_demo.dir/depend
