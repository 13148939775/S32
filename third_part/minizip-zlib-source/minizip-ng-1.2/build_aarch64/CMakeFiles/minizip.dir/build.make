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
CMAKE_SOURCE_DIR = /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64

# Include any dependencies generated for this target.
include CMakeFiles/minizip.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minizip.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minizip.dir/flags.make

CMakeFiles/minizip.dir/crypt.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/crypt.c.o: ../crypt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minizip.dir/crypt.c.o"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/crypt.c.o   -c /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/crypt.c

CMakeFiles/minizip.dir/crypt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/crypt.c.i"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/crypt.c > CMakeFiles/minizip.dir/crypt.c.i

CMakeFiles/minizip.dir/crypt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/crypt.c.s"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/crypt.c -o CMakeFiles/minizip.dir/crypt.c.s

CMakeFiles/minizip.dir/ioapi.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/ioapi.c.o: ../ioapi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/minizip.dir/ioapi.c.o"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/ioapi.c.o   -c /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/ioapi.c

CMakeFiles/minizip.dir/ioapi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/ioapi.c.i"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/ioapi.c > CMakeFiles/minizip.dir/ioapi.c.i

CMakeFiles/minizip.dir/ioapi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/ioapi.c.s"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/ioapi.c -o CMakeFiles/minizip.dir/ioapi.c.s

CMakeFiles/minizip.dir/ioapi_buf.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/ioapi_buf.c.o: ../ioapi_buf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/minizip.dir/ioapi_buf.c.o"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/ioapi_buf.c.o   -c /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/ioapi_buf.c

CMakeFiles/minizip.dir/ioapi_buf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/ioapi_buf.c.i"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/ioapi_buf.c > CMakeFiles/minizip.dir/ioapi_buf.c.i

CMakeFiles/minizip.dir/ioapi_buf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/ioapi_buf.c.s"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/ioapi_buf.c -o CMakeFiles/minizip.dir/ioapi_buf.c.s

CMakeFiles/minizip.dir/ioapi_mem.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/ioapi_mem.c.o: ../ioapi_mem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/minizip.dir/ioapi_mem.c.o"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/ioapi_mem.c.o   -c /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/ioapi_mem.c

CMakeFiles/minizip.dir/ioapi_mem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/ioapi_mem.c.i"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/ioapi_mem.c > CMakeFiles/minizip.dir/ioapi_mem.c.i

CMakeFiles/minizip.dir/ioapi_mem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/ioapi_mem.c.s"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/ioapi_mem.c -o CMakeFiles/minizip.dir/ioapi_mem.c.s

CMakeFiles/minizip.dir/unzip.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/unzip.c.o: ../unzip.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/minizip.dir/unzip.c.o"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/unzip.c.o   -c /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/unzip.c

CMakeFiles/minizip.dir/unzip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/unzip.c.i"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/unzip.c > CMakeFiles/minizip.dir/unzip.c.i

CMakeFiles/minizip.dir/unzip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/unzip.c.s"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/unzip.c -o CMakeFiles/minizip.dir/unzip.c.s

CMakeFiles/minizip.dir/zip.c.o: CMakeFiles/minizip.dir/flags.make
CMakeFiles/minizip.dir/zip.c.o: ../zip.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/minizip.dir/zip.c.o"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/zip.c.o   -c /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/zip.c

CMakeFiles/minizip.dir/zip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/zip.c.i"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/zip.c > CMakeFiles/minizip.dir/zip.c.i

CMakeFiles/minizip.dir/zip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/zip.c.s"
	/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/zip.c -o CMakeFiles/minizip.dir/zip.c.s

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

libminizip.so: CMakeFiles/minizip.dir/crypt.c.o
libminizip.so: CMakeFiles/minizip.dir/ioapi.c.o
libminizip.so: CMakeFiles/minizip.dir/ioapi_buf.c.o
libminizip.so: CMakeFiles/minizip.dir/ioapi_mem.c.o
libminizip.so: CMakeFiles/minizip.dir/unzip.c.o
libminizip.so: CMakeFiles/minizip.dir/zip.c.o
libminizip.so: CMakeFiles/minizip.dir/build.make
libminizip.so: /home/miaow/work/S32G-UP/s32-Apps/third_part/zlib-1.2.13/lib_arm/libz.so.1.2.13
libminizip.so: CMakeFiles/minizip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C shared library libminizip.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minizip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minizip.dir/build: libminizip.so

.PHONY : CMakeFiles/minizip.dir/build

CMakeFiles/minizip.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minizip.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minizip.dir/clean

CMakeFiles/minizip.dir/depend:
	cd /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2 /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2 /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64 /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64 /home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/minizip-ng-1.2/build_aarch64/CMakeFiles/minizip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minizip.dir/depend

