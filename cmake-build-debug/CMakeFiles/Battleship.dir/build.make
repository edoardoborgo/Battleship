# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/219/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/219/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jnks/Battleship/Battleship

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jnks/Battleship/Battleship/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Battleship.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Battleship.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Battleship.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Battleship.dir/flags.make

CMakeFiles/Battleship.dir/lib/nave.cpp.o: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/lib/nave.cpp.o: /home/jnks/Battleship/Battleship/lib/nave.cpp
CMakeFiles/Battleship.dir/lib/nave.cpp.o: CMakeFiles/Battleship.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jnks/Battleship/Battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Battleship.dir/lib/nave.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Battleship.dir/lib/nave.cpp.o -MF CMakeFiles/Battleship.dir/lib/nave.cpp.o.d -o CMakeFiles/Battleship.dir/lib/nave.cpp.o -c /home/jnks/Battleship/Battleship/lib/nave.cpp

CMakeFiles/Battleship.dir/lib/nave.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Battleship.dir/lib/nave.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jnks/Battleship/Battleship/lib/nave.cpp > CMakeFiles/Battleship.dir/lib/nave.cpp.i

CMakeFiles/Battleship.dir/lib/nave.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Battleship.dir/lib/nave.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jnks/Battleship/Battleship/lib/nave.cpp -o CMakeFiles/Battleship.dir/lib/nave.cpp.s

CMakeFiles/Battleship.dir/lib/corazzata.cpp.o: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/lib/corazzata.cpp.o: /home/jnks/Battleship/Battleship/lib/corazzata.cpp
CMakeFiles/Battleship.dir/lib/corazzata.cpp.o: CMakeFiles/Battleship.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jnks/Battleship/Battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Battleship.dir/lib/corazzata.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Battleship.dir/lib/corazzata.cpp.o -MF CMakeFiles/Battleship.dir/lib/corazzata.cpp.o.d -o CMakeFiles/Battleship.dir/lib/corazzata.cpp.o -c /home/jnks/Battleship/Battleship/lib/corazzata.cpp

CMakeFiles/Battleship.dir/lib/corazzata.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Battleship.dir/lib/corazzata.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jnks/Battleship/Battleship/lib/corazzata.cpp > CMakeFiles/Battleship.dir/lib/corazzata.cpp.i

CMakeFiles/Battleship.dir/lib/corazzata.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Battleship.dir/lib/corazzata.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jnks/Battleship/Battleship/lib/corazzata.cpp -o CMakeFiles/Battleship.dir/lib/corazzata.cpp.s

CMakeFiles/Battleship.dir/lib/supporto.cpp.o: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/lib/supporto.cpp.o: /home/jnks/Battleship/Battleship/lib/supporto.cpp
CMakeFiles/Battleship.dir/lib/supporto.cpp.o: CMakeFiles/Battleship.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jnks/Battleship/Battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Battleship.dir/lib/supporto.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Battleship.dir/lib/supporto.cpp.o -MF CMakeFiles/Battleship.dir/lib/supporto.cpp.o.d -o CMakeFiles/Battleship.dir/lib/supporto.cpp.o -c /home/jnks/Battleship/Battleship/lib/supporto.cpp

CMakeFiles/Battleship.dir/lib/supporto.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Battleship.dir/lib/supporto.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jnks/Battleship/Battleship/lib/supporto.cpp > CMakeFiles/Battleship.dir/lib/supporto.cpp.i

CMakeFiles/Battleship.dir/lib/supporto.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Battleship.dir/lib/supporto.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jnks/Battleship/Battleship/lib/supporto.cpp -o CMakeFiles/Battleship.dir/lib/supporto.cpp.s

CMakeFiles/Battleship.dir/lib/sottomarino.cpp.o: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/lib/sottomarino.cpp.o: /home/jnks/Battleship/Battleship/lib/sottomarino.cpp
CMakeFiles/Battleship.dir/lib/sottomarino.cpp.o: CMakeFiles/Battleship.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jnks/Battleship/Battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Battleship.dir/lib/sottomarino.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Battleship.dir/lib/sottomarino.cpp.o -MF CMakeFiles/Battleship.dir/lib/sottomarino.cpp.o.d -o CMakeFiles/Battleship.dir/lib/sottomarino.cpp.o -c /home/jnks/Battleship/Battleship/lib/sottomarino.cpp

CMakeFiles/Battleship.dir/lib/sottomarino.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Battleship.dir/lib/sottomarino.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jnks/Battleship/Battleship/lib/sottomarino.cpp > CMakeFiles/Battleship.dir/lib/sottomarino.cpp.i

CMakeFiles/Battleship.dir/lib/sottomarino.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Battleship.dir/lib/sottomarino.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jnks/Battleship/Battleship/lib/sottomarino.cpp -o CMakeFiles/Battleship.dir/lib/sottomarino.cpp.s

CMakeFiles/Battleship.dir/utilities/coordinata.cpp.o: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/utilities/coordinata.cpp.o: /home/jnks/Battleship/Battleship/utilities/coordinata.cpp
CMakeFiles/Battleship.dir/utilities/coordinata.cpp.o: CMakeFiles/Battleship.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jnks/Battleship/Battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Battleship.dir/utilities/coordinata.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Battleship.dir/utilities/coordinata.cpp.o -MF CMakeFiles/Battleship.dir/utilities/coordinata.cpp.o.d -o CMakeFiles/Battleship.dir/utilities/coordinata.cpp.o -c /home/jnks/Battleship/Battleship/utilities/coordinata.cpp

CMakeFiles/Battleship.dir/utilities/coordinata.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Battleship.dir/utilities/coordinata.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jnks/Battleship/Battleship/utilities/coordinata.cpp > CMakeFiles/Battleship.dir/utilities/coordinata.cpp.i

CMakeFiles/Battleship.dir/utilities/coordinata.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Battleship.dir/utilities/coordinata.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jnks/Battleship/Battleship/utilities/coordinata.cpp -o CMakeFiles/Battleship.dir/utilities/coordinata.cpp.s

CMakeFiles/Battleship.dir/utilities/griglia.cpp.o: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/utilities/griglia.cpp.o: /home/jnks/Battleship/Battleship/utilities/griglia.cpp
CMakeFiles/Battleship.dir/utilities/griglia.cpp.o: CMakeFiles/Battleship.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jnks/Battleship/Battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Battleship.dir/utilities/griglia.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Battleship.dir/utilities/griglia.cpp.o -MF CMakeFiles/Battleship.dir/utilities/griglia.cpp.o.d -o CMakeFiles/Battleship.dir/utilities/griglia.cpp.o -c /home/jnks/Battleship/Battleship/utilities/griglia.cpp

CMakeFiles/Battleship.dir/utilities/griglia.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Battleship.dir/utilities/griglia.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jnks/Battleship/Battleship/utilities/griglia.cpp > CMakeFiles/Battleship.dir/utilities/griglia.cpp.i

CMakeFiles/Battleship.dir/utilities/griglia.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Battleship.dir/utilities/griglia.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jnks/Battleship/Battleship/utilities/griglia.cpp -o CMakeFiles/Battleship.dir/utilities/griglia.cpp.s

CMakeFiles/Battleship.dir/lib/griglia.cpp.o: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/lib/griglia.cpp.o: /home/jnks/Battleship/Battleship/lib/griglia.cpp
CMakeFiles/Battleship.dir/lib/griglia.cpp.o: CMakeFiles/Battleship.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jnks/Battleship/Battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Battleship.dir/lib/griglia.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Battleship.dir/lib/griglia.cpp.o -MF CMakeFiles/Battleship.dir/lib/griglia.cpp.o.d -o CMakeFiles/Battleship.dir/lib/griglia.cpp.o -c /home/jnks/Battleship/Battleship/lib/griglia.cpp

CMakeFiles/Battleship.dir/lib/griglia.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Battleship.dir/lib/griglia.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jnks/Battleship/Battleship/lib/griglia.cpp > CMakeFiles/Battleship.dir/lib/griglia.cpp.i

CMakeFiles/Battleship.dir/lib/griglia.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Battleship.dir/lib/griglia.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jnks/Battleship/Battleship/lib/griglia.cpp -o CMakeFiles/Battleship.dir/lib/griglia.cpp.s

# Object files for target Battleship
Battleship_OBJECTS = \
"CMakeFiles/Battleship.dir/lib/nave.cpp.o" \
"CMakeFiles/Battleship.dir/lib/corazzata.cpp.o" \
"CMakeFiles/Battleship.dir/lib/supporto.cpp.o" \
"CMakeFiles/Battleship.dir/lib/sottomarino.cpp.o" \
"CMakeFiles/Battleship.dir/utilities/coordinata.cpp.o" \
"CMakeFiles/Battleship.dir/utilities/griglia.cpp.o" \
"CMakeFiles/Battleship.dir/lib/griglia.cpp.o"

# External object files for target Battleship
Battleship_EXTERNAL_OBJECTS =

Battleship: CMakeFiles/Battleship.dir/lib/nave.cpp.o
Battleship: CMakeFiles/Battleship.dir/lib/corazzata.cpp.o
Battleship: CMakeFiles/Battleship.dir/lib/supporto.cpp.o
Battleship: CMakeFiles/Battleship.dir/lib/sottomarino.cpp.o
Battleship: CMakeFiles/Battleship.dir/utilities/coordinata.cpp.o
Battleship: CMakeFiles/Battleship.dir/utilities/griglia.cpp.o
Battleship: CMakeFiles/Battleship.dir/lib/griglia.cpp.o
Battleship: CMakeFiles/Battleship.dir/build.make
Battleship: CMakeFiles/Battleship.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jnks/Battleship/Battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Battleship"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Battleship.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Battleship.dir/build: Battleship
.PHONY : CMakeFiles/Battleship.dir/build

CMakeFiles/Battleship.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Battleship.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Battleship.dir/clean

CMakeFiles/Battleship.dir/depend:
	cd /home/jnks/Battleship/Battleship/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jnks/Battleship/Battleship /home/jnks/Battleship/Battleship /home/jnks/Battleship/Battleship/cmake-build-debug /home/jnks/Battleship/Battleship/cmake-build-debug /home/jnks/Battleship/Battleship/cmake-build-debug/CMakeFiles/Battleship.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Battleship.dir/depend

