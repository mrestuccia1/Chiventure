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
include tests/libobj/CMakeFiles/test-obj.dir/depend.make

# Include the progress variables for this target.
include tests/libobj/CMakeFiles/test-obj.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libobj/CMakeFiles/test-obj.dir/flags.make

tests/libobj/CMakeFiles/test-obj.dir/test_obj.c.o: tests/libobj/CMakeFiles/test-obj.dir/flags.make
tests/libobj/CMakeFiles/test-obj.dir/test_obj.c.o: tests/libobj/test_obj.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libobj/CMakeFiles/test-obj.dir/test_obj.c.o"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-obj.dir/test_obj.c.o   -c /home/maggiex/cs220/chiventure/tests/libobj/test_obj.c

tests/libobj/CMakeFiles/test-obj.dir/test_obj.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-obj.dir/test_obj.c.i"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/libobj/test_obj.c > CMakeFiles/test-obj.dir/test_obj.c.i

tests/libobj/CMakeFiles/test-obj.dir/test_obj.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-obj.dir/test_obj.c.s"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/libobj/test_obj.c -o CMakeFiles/test-obj.dir/test_obj.c.s

tests/libobj/CMakeFiles/test-obj.dir/test_load_json.c.o: tests/libobj/CMakeFiles/test-obj.dir/flags.make
tests/libobj/CMakeFiles/test-obj.dir/test_load_json.c.o: tests/libobj/test_load_json.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/libobj/CMakeFiles/test-obj.dir/test_load_json.c.o"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-obj.dir/test_load_json.c.o   -c /home/maggiex/cs220/chiventure/tests/libobj/test_load_json.c

tests/libobj/CMakeFiles/test-obj.dir/test_load_json.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-obj.dir/test_load_json.c.i"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/libobj/test_load_json.c > CMakeFiles/test-obj.dir/test_load_json.c.i

tests/libobj/CMakeFiles/test-obj.dir/test_load_json.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-obj.dir/test_load_json.c.s"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/libobj/test_load_json.c -o CMakeFiles/test-obj.dir/test_load_json.c.s

tests/libobj/CMakeFiles/test-obj.dir/test_load_wdz.c.o: tests/libobj/CMakeFiles/test-obj.dir/flags.make
tests/libobj/CMakeFiles/test-obj.dir/test_load_wdz.c.o: tests/libobj/test_load_wdz.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/libobj/CMakeFiles/test-obj.dir/test_load_wdz.c.o"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-obj.dir/test_load_wdz.c.o   -c /home/maggiex/cs220/chiventure/tests/libobj/test_load_wdz.c

tests/libobj/CMakeFiles/test-obj.dir/test_load_wdz.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-obj.dir/test_load_wdz.c.i"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/libobj/test_load_wdz.c > CMakeFiles/test-obj.dir/test_load_wdz.c.i

tests/libobj/CMakeFiles/test-obj.dir/test_load_wdz.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-obj.dir/test_load_wdz.c.s"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/libobj/test_load_wdz.c -o CMakeFiles/test-obj.dir/test_load_wdz.c.s

tests/libobj/CMakeFiles/test-obj.dir/main.c.o: tests/libobj/CMakeFiles/test-obj.dir/flags.make
tests/libobj/CMakeFiles/test-obj.dir/main.c.o: tests/libobj/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/libobj/CMakeFiles/test-obj.dir/main.c.o"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-obj.dir/main.c.o   -c /home/maggiex/cs220/chiventure/tests/libobj/main.c

tests/libobj/CMakeFiles/test-obj.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-obj.dir/main.c.i"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/tests/libobj/main.c > CMakeFiles/test-obj.dir/main.c.i

tests/libobj/CMakeFiles/test-obj.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-obj.dir/main.c.s"
	cd /home/maggiex/cs220/chiventure/tests/libobj && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/tests/libobj/main.c -o CMakeFiles/test-obj.dir/main.c.s

# Object files for target test-obj
test__obj_OBJECTS = \
"CMakeFiles/test-obj.dir/test_obj.c.o" \
"CMakeFiles/test-obj.dir/test_load_json.c.o" \
"CMakeFiles/test-obj.dir/test_load_wdz.c.o" \
"CMakeFiles/test-obj.dir/main.c.o"

# External object files for target test-obj
test__obj_EXTERNAL_OBJECTS =

tests/libobj/test-obj: tests/libobj/CMakeFiles/test-obj.dir/test_obj.c.o
tests/libobj/test-obj: tests/libobj/CMakeFiles/test-obj.dir/test_load_json.c.o
tests/libobj/test-obj: tests/libobj/CMakeFiles/test-obj.dir/test_load_wdz.c.o
tests/libobj/test-obj: tests/libobj/CMakeFiles/test-obj.dir/main.c.o
tests/libobj/test-obj: tests/libobj/CMakeFiles/test-obj.dir/build.make
tests/libobj/test-obj: /usr/lib/libcriterion.so
tests/libobj/test-obj: src/action_management/libaction_management.a
tests/libobj/test-obj: src/battle/libbattle.a
tests/libobj/test-obj: src/cli/libcli.a
tests/libobj/test-obj: src/common/libcommon.a
tests/libobj/test-obj: src/custom-actions/libcustom-actions.a
tests/libobj/test-obj: src/game-state/libgame-state.a
tests/libobj/test-obj: src/libobj/liblibobj.a
tests/libobj/test-obj: src/quests/libquests.a
tests/libobj/test-obj: src/sound/libsound.a
tests/libobj/test-obj: src/npc/libnpc.a
tests/libobj/test-obj: src/openworld/libopenworld.a
tests/libobj/test-obj: src/playerclass/libplayerclass.a
tests/libobj/test-obj: src/skilltrees/libskilltrees.a
tests/libobj/test-obj: src/ui/libui.a
tests/libobj/test-obj: src/wdl/libwdl.a
tests/libobj/test-obj: src/custom-scripts/libcustom-scripts.a
tests/libobj/test-obj: src/cli/libcli.a
tests/libobj/test-obj: src/common/libcommon.a
tests/libobj/test-obj: src/game-state/libgame-state.a
tests/libobj/test-obj: src/cli/libcli.a
tests/libobj/test-obj: src/common/libcommon.a
tests/libobj/test-obj: src/game-state/libgame-state.a
tests/libobj/test-obj: src/action_management/libaction_management.a
tests/libobj/test-obj: src/ui/libui.a
tests/libobj/test-obj: /usr/lib/x86_64-linux-gnu/libncursesw.so
tests/libobj/test-obj: /usr/lib/x86_64-linux-gnu/libformw.so
tests/libobj/test-obj: src/quests/libquests.a
tests/libobj/test-obj: src/wdl/libwdl.a
tests/libobj/test-obj: src/libobj/liblibobj.a
tests/libobj/test-obj: src/npc/libnpc.a
tests/libobj/test-obj: src/battle/libbattle.a
tests/libobj/test-obj: src/playerclass/libplayerclass.a
tests/libobj/test-obj: src/skilltrees/libskilltrees.a
tests/libobj/test-obj: /usr/lib/x86_64-linux-gnu/libzip.so
tests/libobj/test-obj: /usr/lib/x86_64-linux-gnu/libjson-c.so
tests/libobj/test-obj: /usr/lib/x86_64-linux-gnu/liblua5.3.so
tests/libobj/test-obj: /usr/lib/x86_64-linux-gnu/libm.so
tests/libobj/test-obj: tests/libobj/CMakeFiles/test-obj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable test-obj"
	cd /home/maggiex/cs220/chiventure/tests/libobj && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-obj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libobj/CMakeFiles/test-obj.dir/build: tests/libobj/test-obj

.PHONY : tests/libobj/CMakeFiles/test-obj.dir/build

tests/libobj/CMakeFiles/test-obj.dir/clean:
	cd /home/maggiex/cs220/chiventure/tests/libobj && $(CMAKE_COMMAND) -P CMakeFiles/test-obj.dir/cmake_clean.cmake
.PHONY : tests/libobj/CMakeFiles/test-obj.dir/clean

tests/libobj/CMakeFiles/test-obj.dir/depend:
	cd /home/maggiex/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/tests/libobj /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/tests/libobj /home/maggiex/cs220/chiventure/tests/libobj/CMakeFiles/test-obj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libobj/CMakeFiles/test-obj.dir/depend

