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
CMAKE_SOURCE_DIR = /home/maggiex/cs220/chiventure/src/custom-scripts

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maggiex/cs220/chiventure/src/custom-scripts/examples

# Include any dependencies generated for this target.
include CMakeFiles/custom-scripts.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/custom-scripts.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/custom-scripts.dir/flags.make

CMakeFiles/custom-scripts.dir/src/custom_type.o: CMakeFiles/custom-scripts.dir/flags.make
CMakeFiles/custom-scripts.dir/src/custom_type.o: ../src/custom_type.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maggiex/cs220/chiventure/src/custom-scripts/examples/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/custom-scripts.dir/src/custom_type.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom-scripts.dir/src/custom_type.o   -c /home/maggiex/cs220/chiventure/src/custom-scripts/src/custom_type.c

CMakeFiles/custom-scripts.dir/src/custom_type.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom-scripts.dir/src/custom_type.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maggiex/cs220/chiventure/src/custom-scripts/src/custom_type.c > CMakeFiles/custom-scripts.dir/src/custom_type.i

CMakeFiles/custom-scripts.dir/src/custom_type.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom-scripts.dir/src/custom_type.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maggiex/cs220/chiventure/src/custom-scripts/src/custom_type.c -o CMakeFiles/custom-scripts.dir/src/custom_type.s

# Object files for target custom-scripts
custom__scripts_OBJECTS = \
"CMakeFiles/custom-scripts.dir/src/custom_type.o"

# External object files for target custom-scripts
custom__scripts_EXTERNAL_OBJECTS =

libcustom-scripts.a: CMakeFiles/custom-scripts.dir/src/custom_type.o
libcustom-scripts.a: CMakeFiles/custom-scripts.dir/build.make
libcustom-scripts.a: CMakeFiles/custom-scripts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maggiex/cs220/chiventure/src/custom-scripts/examples/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libcustom-scripts.a"
	$(CMAKE_COMMAND) -P CMakeFiles/custom-scripts.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/custom-scripts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/custom-scripts.dir/build: libcustom-scripts.a

.PHONY : CMakeFiles/custom-scripts.dir/build

CMakeFiles/custom-scripts.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/custom-scripts.dir/cmake_clean.cmake
.PHONY : CMakeFiles/custom-scripts.dir/clean

CMakeFiles/custom-scripts.dir/depend:
	cd /home/maggiex/cs220/chiventure/src/custom-scripts/examples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maggiex/cs220/chiventure/src/custom-scripts /home/maggiex/cs220/chiventure/src/custom-scripts /home/maggiex/cs220/chiventure/src/custom-scripts/examples /home/maggiex/cs220/chiventure/src/custom-scripts/examples /home/maggiex/cs220/chiventure/src/custom-scripts/examples/CMakeFiles/custom-scripts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/custom-scripts.dir/depend
