# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/thz/Desktop/tomato_weight/PCLLearning/normal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thz/Desktop/tomato_weight/PCLLearning/normal/build

# Include any dependencies generated for this target.
include CMakeFiles/normal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/normal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/normal.dir/flags.make

CMakeFiles/normal.dir/normal.cpp.o: CMakeFiles/normal.dir/flags.make
CMakeFiles/normal.dir/normal.cpp.o: ../normal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thz/Desktop/tomato_weight/PCLLearning/normal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/normal.dir/normal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/normal.dir/normal.cpp.o -c /home/thz/Desktop/tomato_weight/PCLLearning/normal/normal.cpp

CMakeFiles/normal.dir/normal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/normal.dir/normal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thz/Desktop/tomato_weight/PCLLearning/normal/normal.cpp > CMakeFiles/normal.dir/normal.cpp.i

CMakeFiles/normal.dir/normal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/normal.dir/normal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thz/Desktop/tomato_weight/PCLLearning/normal/normal.cpp -o CMakeFiles/normal.dir/normal.cpp.s

CMakeFiles/normal.dir/normal.cpp.o.requires:

.PHONY : CMakeFiles/normal.dir/normal.cpp.o.requires

CMakeFiles/normal.dir/normal.cpp.o.provides: CMakeFiles/normal.dir/normal.cpp.o.requires
	$(MAKE) -f CMakeFiles/normal.dir/build.make CMakeFiles/normal.dir/normal.cpp.o.provides.build
.PHONY : CMakeFiles/normal.dir/normal.cpp.o.provides

CMakeFiles/normal.dir/normal.cpp.o.provides.build: CMakeFiles/normal.dir/normal.cpp.o


# Object files for target normal
normal_OBJECTS = \
"CMakeFiles/normal.dir/normal.cpp.o"

# External object files for target normal
normal_EXTERNAL_OBJECTS =

normal: CMakeFiles/normal.dir/normal.cpp.o
normal: CMakeFiles/normal.dir/build.make
normal: /usr/local/lib/libpcl_surface.so
normal: /usr/local/lib/libpcl_keypoints.so
normal: /usr/local/lib/libpcl_tracking.so
normal: /usr/local/lib/libpcl_recognition.so
normal: /usr/local/lib/libpcl_stereo.so
normal: /usr/local/lib/libpcl_outofcore.so
normal: /usr/local/lib/libpcl_people.so
normal: /usr/lib/x86_64-linux-gnu/libboost_system.so
normal: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
normal: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
normal: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
normal: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
normal: /usr/lib/x86_64-linux-gnu/libboost_regex.so
normal: /usr/lib/x86_64-linux-gnu/libqhull.so
normal: /usr/lib/libOpenNI2.so
normal: /usr/local/lib/libvtkChartsCore-7.1.so.1
normal: /usr/local/lib/libvtkInfovisCore-7.1.so.1
normal: /usr/local/lib/libvtkIOGeometry-7.1.so.1
normal: /usr/local/lib/libvtkIOLegacy-7.1.so.1
normal: /usr/local/lib/libvtkIOPLY-7.1.so.1
normal: /usr/local/lib/libvtkRenderingLOD-7.1.so.1
normal: /usr/local/lib/libvtkViewsContext2D-7.1.so.1
normal: /usr/local/lib/libvtkViewsCore-7.1.so.1
normal: /usr/local/lib/libvtkRenderingContextOpenGL2-7.1.so.1
normal: /usr/local/lib/libvtkRenderingQt-7.1.so.1
normal: /usr/local/lib/libvtkFiltersTexture-7.1.so.1
normal: /usr/local/lib/libvtkGUISupportQt-7.1.so.1
normal: /usr/local/lib/libvtkRenderingLabel-7.1.so.1
normal: /usr/lib/x86_64-linux-gnu/libflann_cpp.so
normal: /usr/local/lib/libpcl_registration.so
normal: /usr/local/lib/libpcl_segmentation.so
normal: /usr/local/lib/libpcl_features.so
normal: /usr/local/lib/libpcl_filters.so
normal: /usr/local/lib/libpcl_sample_consensus.so
normal: /usr/local/lib/libpcl_ml.so
normal: /usr/local/lib/libpcl_visualization.so
normal: /usr/local/lib/libpcl_search.so
normal: /usr/local/lib/libpcl_kdtree.so
normal: /usr/local/lib/libpcl_io.so
normal: /usr/local/lib/libpcl_octree.so
normal: /usr/local/lib/libpcl_common.so
normal: /usr/local/lib/libvtkInteractionWidgets-7.1.so.1
normal: /usr/local/lib/libvtkFiltersModeling-7.1.so.1
normal: /usr/local/lib/libvtkFiltersHybrid-7.1.so.1
normal: /usr/local/lib/libvtkImagingGeneral-7.1.so.1
normal: /usr/local/lib/libvtkImagingSources-7.1.so.1
normal: /usr/local/lib/libvtkImagingHybrid-7.1.so.1
normal: /usr/local/lib/libvtkRenderingAnnotation-7.1.so.1
normal: /usr/local/lib/libvtkImagingColor-7.1.so.1
normal: /usr/local/lib/libvtkRenderingVolume-7.1.so.1
normal: /usr/local/lib/libvtkIOXML-7.1.so.1
normal: /usr/local/lib/libvtkIOXMLParser-7.1.so.1
normal: /usr/local/lib/libvtkIOCore-7.1.so.1
normal: /usr/local/lib/libvtkexpat-7.1.so.1
normal: /usr/local/lib/libvtkRenderingContext2D-7.1.so.1
normal: /usr/local/lib/libvtkInteractionStyle-7.1.so.1
normal: /usr/local/lib/libvtkFiltersExtraction-7.1.so.1
normal: /usr/local/lib/libvtkFiltersStatistics-7.1.so.1
normal: /usr/local/lib/libvtkImagingFourier-7.1.so.1
normal: /usr/local/lib/libvtkalglib-7.1.so.1
normal: /usr/local/lib/libvtkRenderingOpenGL2-7.1.so.1
normal: /usr/local/lib/libvtkImagingCore-7.1.so.1
normal: /usr/local/lib/libvtkIOImage-7.1.so.1
normal: /usr/local/lib/libvtkDICOMParser-7.1.so.1
normal: /usr/local/lib/libvtkmetaio-7.1.so.1
normal: /usr/local/lib/libvtkpng-7.1.so.1
normal: /usr/local/lib/libvtktiff-7.1.so.1
normal: /usr/local/lib/libvtkjpeg-7.1.so.1
normal: /usr/lib/x86_64-linux-gnu/libm.so
normal: /usr/local/lib/libvtkglew-7.1.so.1
normal: /usr/lib/x86_64-linux-gnu/libSM.so
normal: /usr/lib/x86_64-linux-gnu/libICE.so
normal: /usr/lib/x86_64-linux-gnu/libX11.so
normal: /usr/lib/x86_64-linux-gnu/libXext.so
normal: /usr/lib/x86_64-linux-gnu/libXt.so
normal: /usr/lib/x86_64-linux-gnu/libQtGui.so
normal: /usr/lib/x86_64-linux-gnu/libQtNetwork.so
normal: /usr/lib/x86_64-linux-gnu/libQtCore.so
normal: /usr/local/lib/libvtkRenderingFreeType-7.1.so.1
normal: /usr/local/lib/libvtkRenderingCore-7.1.so.1
normal: /usr/local/lib/libvtkCommonColor-7.1.so.1
normal: /usr/local/lib/libvtkFiltersGeometry-7.1.so.1
normal: /usr/local/lib/libvtkFiltersSources-7.1.so.1
normal: /usr/local/lib/libvtkFiltersGeneral-7.1.so.1
normal: /usr/local/lib/libvtkCommonComputationalGeometry-7.1.so.1
normal: /usr/local/lib/libvtkFiltersCore-7.1.so.1
normal: /usr/local/lib/libvtkCommonExecutionModel-7.1.so.1
normal: /usr/local/lib/libvtkCommonDataModel-7.1.so.1
normal: /usr/local/lib/libvtkCommonTransforms-7.1.so.1
normal: /usr/local/lib/libvtkCommonMisc-7.1.so.1
normal: /usr/local/lib/libvtkCommonMath-7.1.so.1
normal: /usr/local/lib/libvtkCommonSystem-7.1.so.1
normal: /usr/local/lib/libvtkCommonCore-7.1.so.1
normal: /usr/local/lib/libvtksys-7.1.so.1
normal: /usr/local/lib/libvtkfreetype-7.1.so.1
normal: /usr/local/lib/libvtkzlib-7.1.so.1
normal: CMakeFiles/normal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thz/Desktop/tomato_weight/PCLLearning/normal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable normal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/normal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/normal.dir/build: normal

.PHONY : CMakeFiles/normal.dir/build

CMakeFiles/normal.dir/requires: CMakeFiles/normal.dir/normal.cpp.o.requires

.PHONY : CMakeFiles/normal.dir/requires

CMakeFiles/normal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/normal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/normal.dir/clean

CMakeFiles/normal.dir/depend:
	cd /home/thz/Desktop/tomato_weight/PCLLearning/normal/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thz/Desktop/tomato_weight/PCLLearning/normal /home/thz/Desktop/tomato_weight/PCLLearning/normal /home/thz/Desktop/tomato_weight/PCLLearning/normal/build /home/thz/Desktop/tomato_weight/PCLLearning/normal/build /home/thz/Desktop/tomato_weight/PCLLearning/normal/build/CMakeFiles/normal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/normal.dir/depend

