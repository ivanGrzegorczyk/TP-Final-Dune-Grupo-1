# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /home/osboxes/.local/lib/python3.9/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/osboxes/.local/lib/python3.9/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1"

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

ui_mainwindow.h: sources/mainwindow.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_mainwindow.h"
	/usr/lib/qt5/bin/uic -o "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/ui_mainwindow.h" "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/mainwindow.ui"

CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.o: Server_autogen/mocs_compilation.cpp
CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.o -MF CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.o -c "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/Server_autogen/mocs_compilation.cpp"

CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/Server_autogen/mocs_compilation.cpp" > CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.i

CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/Server_autogen/mocs_compilation.cpp" -o CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.s

CMakeFiles/Server.dir/sources/Navigator.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/sources/Navigator.cpp.o: sources/Navigator.cpp
CMakeFiles/Server.dir/sources/Navigator.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Server.dir/sources/Navigator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/sources/Navigator.cpp.o -MF CMakeFiles/Server.dir/sources/Navigator.cpp.o.d -o CMakeFiles/Server.dir/sources/Navigator.cpp.o -c "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/Navigator.cpp"

CMakeFiles/Server.dir/sources/Navigator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/sources/Navigator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/Navigator.cpp" > CMakeFiles/Server.dir/sources/Navigator.cpp.i

CMakeFiles/Server.dir/sources/Navigator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/sources/Navigator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/Navigator.cpp" -o CMakeFiles/Server.dir/sources/Navigator.cpp.s

CMakeFiles/Server.dir/sources/Node.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/sources/Node.cpp.o: sources/Node.cpp
CMakeFiles/Server.dir/sources/Node.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Server.dir/sources/Node.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/sources/Node.cpp.o -MF CMakeFiles/Server.dir/sources/Node.cpp.o.d -o CMakeFiles/Server.dir/sources/Node.cpp.o -c "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/Node.cpp"

CMakeFiles/Server.dir/sources/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/sources/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/Node.cpp" > CMakeFiles/Server.dir/sources/Node.cpp.i

CMakeFiles/Server.dir/sources/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/sources/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/Node.cpp" -o CMakeFiles/Server.dir/sources/Node.cpp.s

CMakeFiles/Server.dir/sources/ServerCell.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/sources/ServerCell.cpp.o: sources/ServerCell.cpp
CMakeFiles/Server.dir/sources/ServerCell.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Server.dir/sources/ServerCell.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/sources/ServerCell.cpp.o -MF CMakeFiles/Server.dir/sources/ServerCell.cpp.o.d -o CMakeFiles/Server.dir/sources/ServerCell.cpp.o -c "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/ServerCell.cpp"

CMakeFiles/Server.dir/sources/ServerCell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/sources/ServerCell.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/ServerCell.cpp" > CMakeFiles/Server.dir/sources/ServerCell.cpp.i

CMakeFiles/Server.dir/sources/ServerCell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/sources/ServerCell.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/ServerCell.cpp" -o CMakeFiles/Server.dir/sources/ServerCell.cpp.s

CMakeFiles/Server.dir/sources/ServerMap.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/sources/ServerMap.cpp.o: sources/ServerMap.cpp
CMakeFiles/Server.dir/sources/ServerMap.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Server.dir/sources/ServerMap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/sources/ServerMap.cpp.o -MF CMakeFiles/Server.dir/sources/ServerMap.cpp.o.d -o CMakeFiles/Server.dir/sources/ServerMap.cpp.o -c "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/ServerMap.cpp"

CMakeFiles/Server.dir/sources/ServerMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/sources/ServerMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/ServerMap.cpp" > CMakeFiles/Server.dir/sources/ServerMap.cpp.i

CMakeFiles/Server.dir/sources/ServerMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/sources/ServerMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/ServerMap.cpp" -o CMakeFiles/Server.dir/sources/ServerMap.cpp.s

CMakeFiles/Server.dir/sources/server_main.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/sources/server_main.cpp.o: sources/server_main.cpp
CMakeFiles/Server.dir/sources/server_main.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Server.dir/sources/server_main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/sources/server_main.cpp.o -MF CMakeFiles/Server.dir/sources/server_main.cpp.o.d -o CMakeFiles/Server.dir/sources/server_main.cpp.o -c "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/server_main.cpp"

CMakeFiles/Server.dir/sources/server_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/sources/server_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/server_main.cpp" > CMakeFiles/Server.dir/sources/server_main.cpp.i

CMakeFiles/Server.dir/sources/server_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/sources/server_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/sources/server_main.cpp" -o CMakeFiles/Server.dir/sources/server_main.cpp.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Server.dir/sources/Navigator.cpp.o" \
"CMakeFiles/Server.dir/sources/Node.cpp.o" \
"CMakeFiles/Server.dir/sources/ServerCell.cpp.o" \
"CMakeFiles/Server.dir/sources/ServerMap.cpp.o" \
"CMakeFiles/Server.dir/sources/server_main.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/Server_autogen/mocs_compilation.cpp.o
Server: CMakeFiles/Server.dir/sources/Navigator.cpp.o
Server: CMakeFiles/Server.dir/sources/Node.cpp.o
Server: CMakeFiles/Server.dir/sources/ServerCell.cpp.o
Server: CMakeFiles/Server.dir/sources/ServerMap.cpp.o
Server: CMakeFiles/Server.dir/sources/server_main.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server
.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend: ui_mainwindow.h
	cd "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1" "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1" "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1" "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1" "/home/osboxes/Documents/Cpp/grupal reclone/TP-Final-Dune-Grupo-1/CMakeFiles/Server.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend

