#ifndef KERNEL_H_INCLUDED
#define KERNEL_H_INCLUDED

#include <stdio.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <opencv2/opencv.hpp>
//#include <opencv2/gpu/gpu.hpp>

using namespace cv;
using namespace cv::cuda;

void callKernel(const GpuMat& src,GpuMat& dst);

#endif // KERNEL_H_INCLUDED
