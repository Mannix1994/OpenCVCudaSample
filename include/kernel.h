#ifndef KERNEL_H_INCLUDED
#define KERNEL_H_INCLUDED

#include <cuda.h>
#include <cuda_runtime.h>
#include <opencv2/opencv.hpp>
#include <opencv2/gpu/gpu.hpp>
#include <opencv2/gpu/gpu.hpp>
#include <opencv2/core/cuda_devptrs.hpp>
#include <opencv2/gpu/stream_accessor.hpp>
#include <stdio.h>

using namespace cv;
using namespace cv::gpu;

void callKernel(const GpuMat& src,GpuMat& dst,Stream& stream = Stream::Null());

#endif // KERNEL_H_INCLUDED
