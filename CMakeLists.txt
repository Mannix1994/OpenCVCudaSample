# required cmake version
cmake_minimum_required(VERSION 2.8)
# CMakeLists.txt for G4CU project
project(cudatest)

# packages
find_package(CUDA REQUIRED)
find_package(Ceres REQUIRED)
set(OpenCV_DIR "/usr/local/opencv342/share/OpenCV") 	#修改了这一句，指定opencv头文件的路径
find_package(OpenCV  3 REQUIRED)

set(CUDA_USE_STATIC_CUDA_RUNTIME ON) 		#这一句解决 cannot find -lopencv_dep_cudart
set(CMAKE_BUILD_TYPE "RELEASE")
# nvcc flags
#set(CUDA_NVCC_FLAGS -gencode arch=compute_20,code=sm_20;-G;-g)
set(CUDA_NVCC_FLAGS -gencode arch=compute_52,code=sm_52;-G;-g)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../run)

include_directories( ${OpenCV_INCLUDE_DIRS})
include_directories( ${CERES_INCLUDE_DIRS})
include_directories(include)

file(GLOB_RECURSE CURRENT_HEADERS  include/*.h include/*.hpp include/*.cuh)
file(GLOB CURRENT_SOURCES  src/*.c src/*.cpp src/*.cu)
source_group("Include" FILES ${CURRENT_HEADERS}) 
source_group("Source" FILES ${CURRENT_SOURCES}) 

CUDA_ADD_EXECUTABLE(cudatest ${CURRENT_HEADERS} ${CURRENT_SOURCES})

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} ${CERES_LIBRARIES})
