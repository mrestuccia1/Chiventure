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
include src/libobj/examples/CMakeFiles/obj-example.dir/depend.make

# Include the progress variables for this target.
include src/libobj/examples/CMakeFiles/obj-example.dir/progress.make

# Include the compile flags for this target's objects.
include src/libobj/examples/CMakeFiles/obj-example.dir/flags.make

src/libobj/examples/CMakeFiles/obj-example.dir/obj-example.c.o: src/libobj/examples/CMakeFiles/obj-example.dir/flags.make
src/libobj/examples/CMakeFiles/obj-example.dir/obj-example.c.o: libobj/examples/obj-example.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/libobj/examples/CMakeFiles/obj-example.dir/obj-example.c.o"
	cd /home/maggiex/cs220/chiventure/src/src/libobj/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/obj-example.dir/obj-example.c.o   -c /home/maggiex/cs220/chiventure/src/libobj/examples/obj-example.c

src/libobj/examples/CMakeFiles/obj-example.dir/obj-example.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/obj-example.dir/obj-example.c.i"
	cd /home/maggiex/cs220/chiventure/src/src/libobj/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/src/libobj/examples/obj-example.c > CMakeFiles/obj-example.dir/obj-example.c.i

src/libobj/examples/CMakeFiles/obj-example.dir/obj-example.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/obj-example.dir/obj-example.c.s"
	cd /home/maggiex/cs220/chiventure/src/src/libobj/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/src/libobj/examples/obj-example.c -o CMakeFiles/obj-example.dir/obj-example.c.s

# Object files for target obj-example
obj__example_OBJECTS = \
"CMakeFiles/obj-example.dir/obj-example.c.o"

# External object files for target obj-example
obj__example_EXTERNAL_OBJECTS =

src/libobj/examples/obj-example: src/libobj/examples/CMakeFiles/obj-example.dir/obj-example.c.o
src/libobj/examples/obj-example: src/libobj/examples/CMakeFiles/obj-example.dir/build.make
src/libobj/examples/obj-example: src/action_management/libaction_management.a
src/libobj/examples/obj-example: src/battle/libbattle.a
src/libobj/examples/obj-example: src/cli/libcli.a
src/libobj/examples/obj-example: src/common/libcommon.a
src/libobj/examples/obj-example: src/custom-actions/libcustom-actions.a
src/libobj/examples/obj-example: src/game-state/libgame-state.a
src/libobj/examples/obj-example: src/libobj/liblibobj.a
src/libobj/examples/obj-example: src/quests/libquests.a
src/libobj/examples/obj-example: src/sound/libsound.a
src/libobj/examples/obj-example: src/npc/libnpc.a
src/libobj/examples/obj-example: src/openworld/libopenworld.a
src/libobj/examples/obj-example: src/playerclass/libplayerclass.a
src/libobj/examples/obj-example: src/skilltrees/libskilltrees.a
src/libobj/examples/obj-example: src/ui/libui.a
src/libobj/examples/obj-example: src/wdl/libwdl.a
src/libobj/examples/obj-example: src/custom-scripts/libcustom-scripts.a
src/libobj/examples/obj-example: src/cli/libcli.a
src/libobj/examples/obj-example: src/common/libcommon.a
src/libobj/examples/obj-example: src/game-state/libgame-state.a
src/libobj/examples/obj-example: src/cli/libcli.a
src/libobj/examples/obj-example: src/common/libcommon.a
src/libobj/examples/obj-example: src/game-state/libgame-state.a
src/libobj/examples/obj-example: src/action_management/libaction_management.a
src/libobj/examples/obj-example: src/ui/libui.a
src/libobj/examples/obj-example: /usr/lib/x86_64-linux-gnu/libncursesw.so
src/libobj/examples/obj-example: /usr/lib/x86_64-linux-gnu/libformw.so
src/libobj/examples/obj-example: src/quests/libquests.a
src/libobj/examples/obj-example: src/wdl/libwdl.a
src/libobj/examples/obj-example: src/libobj/liblibobj.a
src/libobj/examples/obj-example: src/npc/libnpc.a
src/libobj/examples/obj-example: src/battle/libbattle.a
src/libobj/examples/obj-example: src/playerclass/libplayerclass.a
src/libobj/examples/obj-example: src/skilltrees/libskilltrees.a
src/libobj/examples/obj-example: /usr/lib/x86_64-linux-gnu/libzip.so
src/libobj/examples/obj-example: /usr/lib/x86_64-linux-gnu/libjson-c.so
src/libobj/examples/obj-example: /usr/lib/x86_64-linux-gnu/liblua5.3.so
src/libobj/examples/obj-example: /usr/lib/x86_64-linux-gnu/libm.so
src/libobj/examples/obj-example: src/libobj/examples/CMakeFiles/obj-example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maggiex/cs220/chiventure/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable obj-example"
	cd /home/maggiex/cs220/chiventure/src/src/libobj/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/obj-example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/libobj/examples/CMakeFiles/obj-example.dir/build: src/libobj/examples/obj-example

.PHONY : src/libobj/examples/CMakeFiles/obj-example.dir/build

src/libobj/examples/CMakeFiles/obj-example.dir/clean:
	cd /home/maggiex/cs220/chiventure/src/src/libobj/examples && $(CMAKE_COMMAND) -P CMakeFiles/obj-example.dir/cmake_clean.cmake
.PHONY : src/libobj/examples/CMakeFiles/obj-example.dir/clean

src/libobj/examples/CMakeFiles/obj-example.dir/depend:
	cd /home/maggiex/cs220/chiventure/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/src/libobj/examples /home/maggiex/cs220/chiventure/src /home/maggiex/cs220/chiventure/src/src/libobj/examples /home/maggiex/cs220/chiventure/src/src/libobj/examples/CMakeFiles/obj-example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/libobj/examples/CMakeFiles/obj-example.dir/depend

