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
CMAKE_SOURCE_DIR = /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build

# Include any dependencies generated for this target.
include CMakeFiles/minizip.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minizip.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minizip.dir/flags.make

CMakeFiles/minizip.dir/crypt.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/crypt.c.o: ../crypt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minizip.dir/crypt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/crypt.c.o   -c /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/crypt.c

CMakeFiles/minizip.dir/crypt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/crypt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/crypt.c > CMakeFiles/minizip.dir/crypt.c.i

CMakeFiles/minizip.dir/crypt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/crypt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/crypt.c -o CMakeFiles/minizip.dir/crypt.c.s

CMakeFiles/minizip.dir/ioapi.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/ioapi.c.o: ../ioapi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/minizip.dir/ioapi.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/ioapi.c.o   -c /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/ioapi.c

CMakeFiles/minizip.dir/ioapi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/ioapi.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/ioapi.c > CMakeFiles/minizip.dir/ioapi.c.i

CMakeFiles/minizip.dir/ioapi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/ioapi.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/ioapi.c -o CMakeFiles/minizip.dir/ioapi.c.s

CMakeFiles/minizip.dir/ioapi_buf.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/ioapi_buf.c.o: ../ioapi_buf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/minizip.dir/ioapi_buf.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/ioapi_buf.c.o   -c /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/ioapi_buf.c

CMakeFiles/minizip.dir/ioapi_buf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/ioapi_buf.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/ioapi_buf.c > CMakeFiles/minizip.dir/ioapi_buf.c.i

CMakeFiles/minizip.dir/ioapi_buf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/ioapi_buf.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/ioapi_buf.c -o CMakeFiles/minizip.dir/ioapi_buf.c.s

CMakeFiles/minizip.dir/ioapi_mem.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/ioapi_mem.c.o: ../ioapi_mem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/minizip.dir/ioapi_mem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/ioapi_mem.c.o   -c /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/ioapi_mem.c

CMakeFiles/minizip.dir/ioapi_mem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/ioapi_mem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/ioapi_mem.c > CMakeFiles/minizip.dir/ioapi_mem.c.i

CMakeFiles/minizip.dir/ioapi_mem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/ioapi_mem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/ioapi_mem.c -o CMakeFiles/minizip.dir/ioapi_mem.c.s

CMakeFiles/minizip.dir/unzip.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/unzip.c.o: ../unzip.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/minizip.dir/unzip.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/unzip.c.o   -c /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/unzip.c

CMakeFiles/minizip.dir/unzip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/unzip.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/unzip.c > CMakeFiles/minizip.dir/unzip.c.i

CMakeFiles/minizip.dir/unzip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/unzip.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/unzip.c -o CMakeFiles/minizip.dir/unzip.c.s

CMakeFiles/minizip.dir/zip.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/zip.c.o: ../zip.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/minizip.dir/zip.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/zip.c.o   -c /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/zip.c

CMakeFiles/minizip.dir/zip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/zip.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/zip.c > CMakeFiles/minizip.dir/zip.c.i

CMakeFiles/minizip.dir/zip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/zip.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/zip.c -o CMakeFiles/minizip.dir/zip.c.s

# Object files for target minizip
minizip_OBJECTS = \
"CMakeFiles/minizip.dir/crypt.c.o" \
"CMakeFiles/minizip.dir/ioapi.c.o" \
"CMakeFiles/minizip.dir/ioapi_buf.c.o" \
"CMakeFiles/minizip.dir/ioapi_mem.c.o" \
"CMakeFiles/minizip.dir/unzip.c.o" \
"CMakeFiles/minizip.dir/zip.c.o"

# External object files for target minizip
minizip_EXTERNAL_OBJECTS =

libminizip.a: CMakeFiles/minizip.dir/crypt.c.o
libminizip.a: CMakeFiles/minizip.dir/ioapi.c.o
libminizip.a: CMakeFiles/minizip.dir/ioapi_buf.c.o
libminizip.a: CMakeFiles/minizip.dir/ioapi_mem.c.o
libminizip.a: CMakeFiles/minizip.dir/unzip.c.o
libminizip.a: CMakeFiles/minizip.dir/zip.c.o
libminizip.a: CMakeFiles/minizip.dir/build.make
libminizip.a: CMakeFiles/minizip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libminizip.a"
	$(CMAKE_COMMAND) -P CMakeFiles/minizip.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minizip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minizip.dir/build: libminizip.a

.PHONY : CMakeFiles/minizip.dir/build

CMakeFiles/minizip.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minizip.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minizip.dir/clean

CMakeFiles/minizip.dir/depend:
	cd /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2 /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2 /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build /work/xjl_work/minizip-ng-1.2/minizip-ng-1.2/build/CMakeFiles/minizip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minizip.dir/depend

