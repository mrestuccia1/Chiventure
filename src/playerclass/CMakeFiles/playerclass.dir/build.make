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
include src/playerclass/CMakeFiles/playerclass.dir/depend.make

# Include the progress variables for this target.
include src/playerclass/CMakeFiles/playerclass.dir/progress.make

# Include the compile flags for this target's objects.
include src/playerclass/CMakeFiles/playerclass.dir/flags.make

src/playerclass/CMakeFiles/playerclass.dir/src/class.c.o: src/playerclass/CMakeFiles/playerclass.dir/flags.make
src/playerclass/CMakeFiles/playerclass.dir/src/class.c.o: src/playerclass/src/class.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/playerclass/CMakeFiles/playerclass.dir/src/class.c.o"
	cd /home/maggiex/cs220/chiventure/src/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playerclass.dir/src/class.c.o   -c /home/maggiex/cs220/chiventure/src/playerclass/src/class.c

src/playerclass/CMakeFiles/playerclass.dir/src/class.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playerclass.dir/src/class.c.i"
	cd /home/maggiex/cs220/chiventure/src/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/src/playerclass/src/class.c > CMakeFiles/playerclass.dir/src/class.c.i

src/playerclass/CMakeFiles/playerclass.dir/src/class.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playerclass.dir/src/class.c.s"
	cd /home/maggiex/cs220/chiventure/src/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/src/playerclass/src/class.c -o CMakeFiles/playerclass.dir/src/class.c.s

src/playerclass/CMakeFiles/playerclass.dir/src/class_item.c.o: src/playerclass/CMakeFiles/playerclass.dir/flags.make
src/playerclass/CMakeFiles/playerclass.dir/src/class_item.c.o: src/playerclass/src/class_item.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/playerclass/CMakeFiles/playerclass.dir/src/class_item.c.o"
	cd /home/maggiex/cs220/chiventure/src/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playerclass.dir/src/class_item.c.o   -c /home/maggiex/cs220/chiventure/src/playerclass/src/class_item.c

src/playerclass/CMakeFiles/playerclass.dir/src/class_item.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playerclass.dir/src/class_item.c.i"
	cd /home/maggiex/cs220/chiventure/src/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/src/playerclass/src/class_item.c > CMakeFiles/playerclass.dir/src/class_item.c.i

src/playerclass/CMakeFiles/playerclass.dir/src/class_item.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playerclass.dir/src/class_item.c.s"
	cd /home/maggiex/cs220/chiventure/src/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/src/playerclass/src/class_item.c -o CMakeFiles/playerclass.dir/src/class_item.c.s

src/playerclass/CMakeFiles/playerclass.dir/src/class_prefabs.c.o: src/playerclass/CMakeFiles/playerclass.dir/flags.make
src/playerclass/CMakeFiles/playerclass.dir/src/class_prefabs.c.o: src/playerclass/src/class_prefabs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/playerclass/CMakeFiles/playerclass.dir/src/class_prefabs.c.o"
	cd /home/maggiex/cs220/chiventure/src/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playerclass.dir/src/class_prefabs.c.o   -c /home/maggiex/cs220/chiventure/src/playerclass/src/class_prefabs.c

src/playerclass/CMakeFiles/playerclass.dir/src/class_prefabs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playerclass.dir/src/class_prefabs.c.i"
	cd /home/maggiex/cs220/chiventure/src/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/src/playerclass/src/class_prefabs.c > CMakeFiles/playerclass.dir/src/class_prefabs.c.i

src/playerclass/CMakeFiles/playerclass.dir/src/class_prefabs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playerclass.dir/src/class_prefabs.c.s"
	cd /home/maggiex/cs220/chiventure/src/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/src/playerclass/src/class_prefabs.c -o CMakeFiles/playerclass.dir/src/class_prefabs.c.s

# Object files for target playerclass
playerclass_OBJECTS = \
"CMakeFiles/playerclass.dir/src/class.c.o" \
"CMakeFiles/playerclass.dir/src/class_item.c.o" \
"CMakeFiles/playerclass.dir/src/class_prefabs.c.o"

# External object files for target playerclass
playerclass_EXTERNAL_OBJECTS =

src/playerclass/libplayerclass.a: src/playerclass/CMakeFiles/playerclass.dir/src/class.c.o
src/playerclass/libplayerclass.a: src/playerclass/CMakeFiles/playerclass.dir/src/class_item.c.o
src/playerclass/libplayerclass.a: src/playerclass/CMakeFiles/playerclass.dir/src/class_prefabs.c.o
src/playerclass/libplayerclass.a: src/playerclass/CMakeFiles/playerclass.dir/build.make
src/playerclass/libplayerclass.a: src/playerclass/CMakeFiles/playerclass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maggiex/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libplayerclass.a"
	cd /home/maggiex/cs220/chiventure/src/playerclass && $(CMAKE_COMMAND) -P CMakeFiles/playerclass.dir/cmake_clean_target.cmake
	cd /home/maggiex/cs220/chiventure/src/playerclass && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/playerclass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/playerclass/CMakeFiles/playerclass.dir/build: src/playerclass/libplayerclass.a

.PHONY : src/playerclass/CMakeFiles/playerclass.dir/build

src/playerclass/CMakeFiles/playerclass.dir/clean:
	cd /home/maggiex/cs220/chiventure/src/playerclass && $(CMAKE_COMMAND) -P CMakeFiles/playerclass.dir/cmake_clean.cmake
.PHONY : src/playerclass/CMakeFiles/playerclass.dir/clean

src/playerclass/CMakeFiles/playerclass.dir/depend:
	cd /home/maggiex/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/src/playerclass /home/maggiex/cs220/chiventure /home/maggiex/cs220/chiventure/src/playerclass /home/maggiex/cs220/chiventure/src/playerclass/CMakeFiles/playerclass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/playerclass/CMakeFiles/playerclass.dir/depend

