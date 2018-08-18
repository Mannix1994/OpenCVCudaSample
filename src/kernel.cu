#include "kernel.h"
#include "timer.h"
#include <device_launch_parameters.h>

/**
* 自定义核函数，在这个函数里面实现对每个像素的访问
*/
__global__ void kernel(const PtrStepSz<uchar3> src,PtrStep<uchar3> dst)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x; //行坐标
    int j = threadIdx.y + blockIdx.y * blockDim.y; //列坐标

//    if(i>50){
//        return;
//    }
    uchar3 vv = src(0,0);
    if(i==0 && j==0){
        printf("(%u,%u,%u)",vv.x,vv.y,vv.z);
    }
    if(i < src.cols && j < src.rows)
    {
        uchar3 v = src(i,j);
        dst(i,j) = make_uchar3(v.y,v.x,v.z);    //紫红色
        //dst(i,j) = make_uchar3(v.x,v.z,v.y);    //浅绿色
        //dst(i,j) = make_uchar3(v.y,v.z,v.x);
    }
}

/**
* 完成核函数的调用
*/
void kernelCaller(const PtrStepSz<uchar3>& src,PtrStep<uchar3> dst)
{
    dim3 block(32,32);
    dim3 grid((src.cols + block.x - 1)/block.x,(src.rows + block.y - 1)/block.y);

    kernel<<<grid,block,0>>>(src,dst);
//    kernel<<<1024,1>>>(src,dst);
}

/**
* 外部函数调用这个函数(留给外部的唯一接口)，把GpuMat传进来
*/
void callKernel(const GpuMat& src,GpuMat& dst,Stream& stream)
{
    CV_Assert(src.type() == CV_8UC3);
    dst.create(src.size(),src.type());
    kernelCaller(src,dst);
}
