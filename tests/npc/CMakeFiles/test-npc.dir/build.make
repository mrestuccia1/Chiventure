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
include tests/npc/CMakeFiles/test-npc.dir/depend.make

# Include the progress variables for this target.
include tests/npc/CMakeFiles/test-npc.dir/progress.make

# Include the compile flags for this target's objects.
include tests/npc/CMakeFiles/test-npc.dir/flags.make

tests/npc/CMakeFiles/test-npc.dir/test_dialogue.c.o: tests/npc/CMakeFiles/test-npc.dir/flags.make
tests/npc/CMakeFiles/test-npc.dir/test_dialogue.c.o: tests/npc/test_dialogue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/npc/CMakeFiles/test-npc.dir/test_dialogue.c.o"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-npc.dir/test_dialogue.c.o   -c /home/maggiex/cs220/chiventure/tests/npc/test_dialogue.c

tests/npc/CMakeFiles/test-npc.dir/test_dialogue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-npc.dir/test_dialogue.c.i"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/npc/test_dialogue.c > CMakeFiles/test-npc.dir/test_dialogue.c.i

tests/npc/CMakeFiles/test-npc.dir/test_dialogue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-npc.dir/test_dialogue.c.s"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/npc/test_dialogue.c -o CMakeFiles/test-npc.dir/test_dialogue.c.s

tests/npc/CMakeFiles/test-npc.dir/test_npc.c.o: tests/npc/CMakeFiles/test-npc.dir/flags.make
tests/npc/CMakeFiles/test-npc.dir/test_npc.c.o: tests/npc/test_npc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/npc/CMakeFiles/test-npc.dir/test_npc.c.o"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-npc.dir/test_npc.c.o   -c /home/maggiex/cs220/chiventure/tests/npc/test_npc.c

tests/npc/CMakeFiles/test-npc.dir/test_npc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-npc.dir/test_npc.c.i"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/npc/test_npc.c > CMakeFiles/test-npc.dir/test_npc.c.i

tests/npc/CMakeFiles/test-npc.dir/test_npc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-npc.dir/test_npc.c.s"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/npc/test_npc.c -o CMakeFiles/test-npc.dir/test_npc.c.s

tests/npc/CMakeFiles/test-npc.dir/test_rooms_npc.c.o: tests/npc/CMakeFiles/test-npc.dir/flags.make
tests/npc/CMakeFiles/test-npc.dir/test_rooms_npc.c.o: tests/npc/test_rooms_npc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/npc/CMakeFiles/test-npc.dir/test_rooms_npc.c.o"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-npc.dir/test_rooms_npc.c.o   -c /home/maggiex/cs220/chiventure/tests/npc/test_rooms_npc.c

tests/npc/CMakeFiles/test-npc.dir/test_rooms_npc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-npc.dir/test_rooms_npc.c.i"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/npc/test_rooms_npc.c > CMakeFiles/test-npc.dir/test_rooms_npc.c.i

tests/npc/CMakeFiles/test-npc.dir/test_rooms_npc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-npc.dir/test_rooms_npc.c.s"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/npc/test_rooms_npc.c -o CMakeFiles/test-npc.dir/test_rooms_npc.c.s

tests/npc/CMakeFiles/test-npc.dir/test_npc_battle.c.o: tests/npc/CMakeFiles/test-npc.dir/flags.make
tests/npc/CMakeFiles/test-npc.dir/test_npc_battle.c.o: tests/npc/test_npc_battle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/npc/CMakeFiles/test-npc.dir/test_npc_battle.c.o"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-npc.dir/test_npc_battle.c.o   -c /home/maggiex/cs220/chiventure/tests/npc/test_npc_battle.c

tests/npc/CMakeFiles/test-npc.dir/test_npc_battle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-npc.dir/test_npc_battle.c.i"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/npc/test_npc_battle.c > CMakeFiles/test-npc.dir/test_npc_battle.c.i

tests/npc/CMakeFiles/test-npc.dir/test_npc_battle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-npc.dir/test_npc_battle.c.s"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/npc/test_npc_battle.c -o CMakeFiles/test-npc.dir/test_npc_battle.c.s

tests/npc/CMakeFiles/test-npc.dir/test_npc_move.c.o: tests/npc/CMakeFiles/test-npc.dir/flags.make
tests/npc/CMakeFiles/test-npc.dir/test_npc_move.c.o: tests/npc/test_npc_move.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object tests/npc/CMakeFiles/test-npc.dir/test_npc_move.c.o"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-npc.dir/test_npc_move.c.o   -c /home/maggiex/cs220/chiventure/tests/npc/test_npc_move.c

tests/npc/CMakeFiles/test-npc.dir/test_npc_move.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-npc.dir/test_npc_move.c.i"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/npc/test_npc_move.c > CMakeFiles/test-npc.dir/test_npc_move.c.i

tests/npc/CMakeFiles/test-npc.dir/test_npc_move.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-npc.dir/test_npc_move.c.s"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/npc/test_npc_move.c -o CMakeFiles/test-npc.dir/test_npc_move.c.s

tests/npc/CMakeFiles/test-npc.dir/main.c.o: tests/npc/CMakeFiles/test-npc.dir/flags.make
tests/npc/CMakeFiles/test-npc.dir/main.c.o: tests/npc/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object tests/npc/CMakeFiles/test-npc.dir/main.c.o"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-npc.dir/main.c.o   -c /home/maggiex/cs220/chiventure/tests/npc/main.c

tests/npc/CMakeFiles/test-npc.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-npc.dir/main.c.i"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/npc/main.c > CMakeFiles/test-npc.dir/main.c.i

tests/npc/CMakeFiles/test-npc.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-npc.dir/main.c.s"
	cd /home/maggiex/cs220/chiventure/tests/npc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/npc/main.c -o CMakeFiles/test-npc.dir/main.c.s

# Object files for target test-npc
test__npc_OBJECTS = \
"CMakeFiles/test-npc.dir/test_dialogue.c.o" \
"CMakeFiles/test-npc.dir/test_npc.c.o" \
"CMakeFiles/test-npc.dir/test_rooms_npc.c.o" \
"CMakeFiles/test-npc.dir/test_npc_battle.c.o" \
"CMakeFiles/test-npc.dir/test_npc_move.c.o" \
"CMakeFiles/test-npc.dir/main.c.o"

# External object files for target test-npc
test__npc_EXTERNAL_OBJECTS =

tests/npc/test-npc: tests/npc/CMakeFiles/test-npc.dir/test_dialogue.c.o
tests/npc/test-npc: tests/npc/CMakeFiles/test-npc.dir/test_npc.c.o
tests/npc/test-npc: tests/npc/CMakeFiles/test-npc.dir/test_rooms_npc.c.o
tests/npc/test-npc: tests/npc/CMakeFiles/test-npc.dir/test_npc_battle.c.o
tests/npc/test-npc: tests/npc/CMakeFiles/test-npc.dir/test_npc_move.c.o
tests/npc/test-npc: tests/npc/CMakeFiles/test-npc.dir/main.c.o
tests/npc/test-npc: tests/npc/CMakeFiles/test-npc.dir/build.make
tests/npc/test-npc: /usr/lib/libcriterion.so
tests/npc/test-npc: src/action_management/libaction_management.a
tests/npc/test-npc: src/battle/libbattle.a
tests/npc/test-npc: src/cli/libcli.a
tests/npc/test-npc: src/common/libcommon.a
tests/npc/test-npc: src/custom-actions/libcustom-actions.a
tests/npc/test-npc: src/game-state/libgame-state.a
tests/npc/test-npc: src/libobj/liblibobj.a
tests/npc/test-npc: src/quests/libquests.a
tests/npc/test-npc: src/sound/libsound.a
tests/npc/test-npc: src/npc/libnpc.a
tests/npc/test-npc: src/openworld/libopenworld.a
tests/npc/test-npc: src/playerclass/libplayerclass.a
tests/npc/test-npc: src/skilltrees/libskilltrees.a
tests/npc/test-npc: src/ui/libui.a
tests/npc/test-npc: src/wdl/libwdl.a
tests/npc/test-npc: src/custom-scripts/libcustom-scripts.a
tests/npc/test-npc: src/cli/libcli.a
tests/npc/test-npc: src/common/libcommon.a
tests/npc/test-npc: src/game-state/libgame-state.a
tests/npc/test-npc: src/cli/libcli.a
tests/npc/test-npc: src/common/libcommon.a
tests/npc/test-npc: src/game-state/libgame-state.a
tests/npc/test-npc: src/action_management/libaction_management.a
tests/npc/test-npc: src/ui/libui.a
tests/npc/test-npc: /usr/lib/x86_64-linux-gnu/libncursesw.so
tests/npc/test-npc: /usr/lib/x86_64-linux-gnu/libformw.so
tests/npc/test-npc: src/quests/libquests.a
tests/npc/test-npc: src/wdl/libwdl.a
tests/npc/test-npc: src/libobj/liblibobj.a
tests/npc/test-npc: src/npc/libnpc.a
tests/npc/test-npc: src/battle/libbattle.a
tests/npc/test-npc: src/playerclass/libplayerclass.a
tests/npc/test-npc: src/skilltrees/libskilltrees.a
tests/npc/test-npc: /usr/lib/x86_64-linux-gnu/libzip.so
tests/npc/test-npc: /usr/lib/x86_64-linux-gnu/libjson-c.so
tests/npc/test-npc: /usr/lib/x86_64-linux-gnu/liblua5.3.so
tests/npc/test-npc: /usr/lib/x86_64-linux-gnu/libm.so
tests/npc/test-npc: tests/npc/CMakeFiles/test-npc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable test-npc"
	cd /home/maggiex/cs220/chiventure/tests/npc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-npc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/npc/CMakeFiles/test-npc.dir/build: tests/npc/test-npc

.PHONY : tests/npc/CMakeFiles/test-npc.dir/build

tests/npc/CMakeFiles/test-npc.dir/clean:
	cd /home/maggiex/cs220/chiventure/tests/npc && $(CMAKE_COMMAND) -P CMakeFiles/test-npc.dir/cmake_clean.cmake
.PHONY : tests/npc/CMakeFiles/test-npc.dir/clean

tests/npc/CMakeFiles/test-npc.dir/depend:
	cd /home/maggiex/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/tests/npc /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/tests/npc /home/maggiex/cs220/chiventure/tests/npc/CMakeFiles/test-npc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/npc/CMakeFiles/test-npc.dir/depend

