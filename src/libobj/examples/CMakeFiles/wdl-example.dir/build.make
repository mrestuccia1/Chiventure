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
CMAKE_BINARY_DIR = /home/maggiex/cs220/chiventure

# Include any dependencies generated for this target.
include src/libobj/examples/CMakeFiles/wdl-example.dir/depend.make

# Include the progress variables for this target.
include src/libobj/examples/CMakeFiles/wdl-example.dir/progress.make

# Include the compile flags for this target's objects.
include src/libobj/examples/CMakeFiles/wdl-example.dir/flags.make

src/libobj/examples/CMakeFiles/wdl-example.dir/wdl-example.c.o: src/libobj/examples/CMakeFiles/wdl-example.dir/flags.make
src/libobj/examples/CMakeFiles/wdl-example.dir/wdl-example.c.o: src/libobj/examples/wdl-example.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/libobj/examples/CMakeFiles/wdl-example.dir/wdl-example.c.o"
	cd /home/maggiex/cs220/chiventure/src/libobj/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wdl-example.dir/wdl-example.c.o   -c /home/maggiex/cs220/chiventure/src/libobj/examples/wdl-example.c

src/libobj/examples/CMakeFiles/wdl-example.dir/wdl-example.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wdl-example.dir/wdl-example.c.i"
	cd /home/maggiex/cs220/chiventure/src/libobj/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/src/libobj/examples/wdl-example.c > CMakeFiles/wdl-example.dir/wdl-example.c.i

src/libobj/examples/CMakeFiles/wdl-example.dir/wdl-example.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wdl-example.dir/wdl-example.c.s"
	cd /home/maggiex/cs220/chiventure/src/libobj/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/src/libobj/examples/wdl-example.c -o CMakeFiles/wdl-example.dir/wdl-example.c.s

# Object files for target wdl-example
wdl__example_OBJECTS = \
"CMakeFiles/wdl-example.dir/wdl-example.c.o"

# External object files for target wdl-example
wdl__example_EXTERNAL_OBJECTS =

src/libobj/examples/wdl-example: src/libobj/examples/CMakeFiles/wdl-example.dir/wdl-example.c.o
src/libobj/examples/wdl-example: src/libobj/examples/CMakeFiles/wdl-example.dir/build.make
src/libobj/examples/wdl-example: src/action_management/libaction_management.a
src/libobj/examples/wdl-example: src/battle/libbattle.a
src/libobj/examples/wdl-example: src/cli/libcli.a
src/libobj/examples/wdl-example: src/common/libcommon.a
src/libobj/examples/wdl-example: src/custom-actions/libcustom-actions.a
src/libobj/examples/wdl-example: src/game-state/libgame-state.a
src/libobj/examples/wdl-example: src/libobj/liblibobj.a
src/libobj/examples/wdl-example: src/quests/libquests.a
src/libobj/examples/wdl-example: src/sound/libsound.a
src/libobj/examples/wdl-example: src/npc/libnpc.a
src/libobj/examples/wdl-example: src/openworld/libopenworld.a
src/libobj/examples/wdl-example: src/playerclass/libplayerclass.a
src/libobj/examples/wdl-example: src/skilltrees/libskilltrees.a
src/libobj/examples/wdl-example: src/ui/libui.a
src/libobj/examples/wdl-example: src/wdl/libwdl.a
src/libobj/examples/wdl-example: src/custom-scripts/libcustom-scripts.a
src/libobj/examples/wdl-example: src/cli/libcli.a
src/libobj/examples/wdl-example: src/common/libcommon.a
src/libobj/examples/wdl-example: src/game-state/libgame-state.a
src/libobj/examples/wdl-example: src/cli/libcli.a
src/libobj/examples/wdl-example: src/common/libcommon.a
src/libobj/examples/wdl-example: src/game-state/libgame-state.a
src/libobj/examples/wdl-example: src/action_management/libaction_management.a
src/libobj/examples/wdl-example: src/ui/libui.a
src/libobj/examples/wdl-example: /usr/lib/x86_64-linux-gnu/libncursesw.so
src/libobj/examples/wdl-example: /usr/lib/x86_64-linux-gnu/libformw.so
src/libobj/examples/wdl-example: src/quests/libquests.a
src/libobj/examples/wdl-example: src/wdl/libwdl.a
src/libobj/examples/wdl-example: src/libobj/liblibobj.a
src/libobj/examples/wdl-example: src/npc/libnpc.a
src/libobj/examples/wdl-example: src/battle/libbattle.a
src/libobj/examples/wdl-example: src/playerclass/libplayerclass.a
src/libobj/examples/wdl-example: src/skilltrees/libskilltrees.a
src/libobj/examples/wdl-example: /usr/lib/x86_64-linux-gnu/libzip.so
src/libobj/examples/wdl-example: /usr/lib/x86_64-linux-gnu/libjson-c.so
src/libobj/examples/wdl-example: /usr/lib/x86_64-linux-gnu/liblua5.3.so
src/libobj/examples/wdl-example: /usr/lib/x86_64-linux-gnu/libm.so
src/libobj/examples/wdl-example: src/libobj/examples/CMakeFiles/wdl-example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable wdl-example"
	cd /home/maggiex/cs220/chiventure/src/libobj/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wdl-example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/libobj/examples/CMakeFiles/wdl-example.dir/build: src/libobj/examples/wdl-example

.PHONY : src/libobj/examples/CMakeFiles/wdl-example.dir/build

src/libobj/examples/CMakeFiles/wdl-example.dir/clean:
	cd /home/maggiex/cs220/chiventure/src/libobj/examples && $(CMAKE_COMMAND) -P CMakeFiles/wdl-example.dir/cmake_clean.cmake
.PHONY : src/libobj/examples/CMakeFiles/wdl-example.dir/clean

src/libobj/examples/CMakeFiles/wdl-example.dir/depend:
	cd /home/maggiex/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/src/libobj/examples /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/src/libobj/examples /home/maggiex/cs220/chiventure/src/libobj/examples/CMakeFiles/wdl-example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/libobj/examples/CMakeFiles/wdl-example.dir/depend
