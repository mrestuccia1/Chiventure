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
include tests/ui/CMakeFiles/test-ui.dir/depend.make

# Include the progress variables for this target.
include tests/ui/CMakeFiles/test-ui.dir/progress.make

# Include the compile flags for this target's objects.
include tests/ui/CMakeFiles/test-ui.dir/flags.make

tests/ui/CMakeFiles/test-ui.dir/test_coordinate.c.o: tests/ui/CMakeFiles/test-ui.dir/flags.make
tests/ui/CMakeFiles/test-ui.dir/test_coordinate.c.o: tests/ui/test_coordinate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/ui/CMakeFiles/test-ui.dir/test_coordinate.c.o"
	cd /home/maggiex/cs220/chiventure/tests/ui && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-ui.dir/test_coordinate.c.o   -c /home/maggiex/cs220/chiventure/tests/ui/test_coordinate.c

tests/ui/CMakeFiles/test-ui.dir/test_coordinate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-ui.dir/test_coordinate.c.i"
	cd /home/maggiex/cs220/chiventure/tests/ui && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/ui/test_coordinate.c > CMakeFiles/test-ui.dir/test_coordinate.c.i

tests/ui/CMakeFiles/test-ui.dir/test_coordinate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-ui.dir/test_coordinate.c.s"
	cd /home/maggiex/cs220/chiventure/tests/ui && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/ui/test_coordinate.c -o CMakeFiles/test-ui.dir/test_coordinate.c.s

tests/ui/CMakeFiles/test-ui.dir/main.c.o: tests/ui/CMakeFiles/test-ui.dir/flags.make
tests/ui/CMakeFiles/test-ui.dir/main.c.o: tests/ui/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/ui/CMakeFiles/test-ui.dir/main.c.o"
	cd /home/maggiex/cs220/chiventure/tests/ui && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-ui.dir/main.c.o   -c /home/maggiex/cs220/chiventure/tests/ui/main.c

tests/ui/CMakeFiles/test-ui.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-ui.dir/main.c.i"
	cd /home/maggiex/cs220/chiventure/tests/ui && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/ui/main.c > CMakeFiles/test-ui.dir/main.c.i

tests/ui/CMakeFiles/test-ui.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-ui.dir/main.c.s"
	cd /home/maggiex/cs220/chiventure/tests/ui && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/ui/main.c -o CMakeFiles/test-ui.dir/main.c.s

# Object files for target test-ui
test__ui_OBJECTS = \
"CMakeFiles/test-ui.dir/test_coordinate.c.o" \
"CMakeFiles/test-ui.dir/main.c.o"

# External object files for target test-ui
test__ui_EXTERNAL_OBJECTS =

tests/ui/test-ui: tests/ui/CMakeFiles/test-ui.dir/test_coordinate.c.o
tests/ui/test-ui: tests/ui/CMakeFiles/test-ui.dir/main.c.o
tests/ui/test-ui: tests/ui/CMakeFiles/test-ui.dir/build.make
tests/ui/test-ui: /usr/lib/libcriterion.so
tests/ui/test-ui: src/action_management/libaction_management.a
tests/ui/test-ui: src/battle/libbattle.a
tests/ui/test-ui: src/cli/libcli.a
tests/ui/test-ui: src/common/libcommon.a
tests/ui/test-ui: src/custom-actions/libcustom-actions.a
tests/ui/test-ui: src/game-state/libgame-state.a
tests/ui/test-ui: src/libobj/liblibobj.a
tests/ui/test-ui: src/quests/libquests.a
tests/ui/test-ui: src/sound/libsound.a
tests/ui/test-ui: src/npc/libnpc.a
tests/ui/test-ui: src/openworld/libopenworld.a
tests/ui/test-ui: src/playerclass/libplayerclass.a
tests/ui/test-ui: src/skilltrees/libskilltrees.a
tests/ui/test-ui: src/ui/libui.a
tests/ui/test-ui: src/wdl/libwdl.a
tests/ui/test-ui: src/custom-scripts/libcustom-scripts.a
tests/ui/test-ui: src/cli/libcli.a
tests/ui/test-ui: src/common/libcommon.a
tests/ui/test-ui: src/game-state/libgame-state.a
tests/ui/test-ui: src/cli/libcli.a
tests/ui/test-ui: src/common/libcommon.a
tests/ui/test-ui: src/game-state/libgame-state.a
tests/ui/test-ui: src/action_management/libaction_management.a
tests/ui/test-ui: src/ui/libui.a
tests/ui/test-ui: /usr/lib/x86_64-linux-gnu/libncursesw.so
tests/ui/test-ui: /usr/lib/x86_64-linux-gnu/libformw.so
tests/ui/test-ui: src/quests/libquests.a
tests/ui/test-ui: src/wdl/libwdl.a
tests/ui/test-ui: src/libobj/liblibobj.a
tests/ui/test-ui: src/npc/libnpc.a
tests/ui/test-ui: src/battle/libbattle.a
tests/ui/test-ui: src/playerclass/libplayerclass.a
tests/ui/test-ui: src/skilltrees/libskilltrees.a
tests/ui/test-ui: /usr/lib/x86_64-linux-gnu/libzip.so
tests/ui/test-ui: /usr/lib/x86_64-linux-gnu/libjson-c.so
tests/ui/test-ui: /usr/lib/x86_64-linux-gnu/liblua5.3.so
tests/ui/test-ui: /usr/lib/x86_64-linux-gnu/libm.so
tests/ui/test-ui: tests/ui/CMakeFiles/test-ui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable test-ui"
	cd /home/maggiex/cs220/chiventure/tests/ui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-ui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/ui/CMakeFiles/test-ui.dir/build: tests/ui/test-ui

.PHONY : tests/ui/CMakeFiles/test-ui.dir/build

tests/ui/CMakeFiles/test-ui.dir/clean:
	cd /home/maggiex/cs220/chiventure/tests/ui && $(CMAKE_COMMAND) -P CMakeFiles/test-ui.dir/cmake_clean.cmake
.PHONY : tests/ui/CMakeFiles/test-ui.dir/clean

tests/ui/CMakeFiles/test-ui.dir/depend:
	cd /home/maggiex/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/tests/ui /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/tests/ui /home/maggiex/cs220/chiventure/tests/ui/CMakeFiles/test-ui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/ui/CMakeFiles/test-ui.dir/depend

