#include "kernel.h"
#include "timer.h"
#include <device_launch_parameters.h>

/**
* 自定义核函数，在这个函数里面实现对每个像素的访问
*/
__global__ void kernel(const PtrStepSz<uchar3> src,PtrStep<uchar3> dst)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x; //列坐标
    int j = threadIdx.y + blockIdx.y * blockDim.y; //行坐标

//    if(i>50){
//        return;
//    }
    if(i==25 && j==15){
        uchar3 vv = src(j,i);
        printf("(%u,%u,%u)",vv.x,vv.y,vv.z);
    }
    if(j < src.rows && i < src.cols)
    {
        uchar3 v = src(j,i);
        dst(j,i) = make_uchar3(v.y,v.x,v.z);    //紫红色
    }
}

/**
* 完成核函数的调用
*/
void kernelCaller(const PtrStepSz<uchar3>& src,PtrStep<uchar3> dst)
{
    dim3 block(32,//一个block有多少列
            32);//一个block多少行
    dim3 grid((src.cols + block.x - 1)/block.x,// 列的方向的block数目
            (src.rows + block.y - 1)/block.y);// 行的方向的block数目

    kernel<<<grid,block,0>>>(src,dst);
}

/**
* 外部函数调用这个函数(留给外部的唯一接口)，把GpuMat传进来
*/
void callKernel(const GpuMat& src,GpuMat& dst)
{
    CV_Assert(src.type() == CV_8UC3);
    dst.create(src.size(),src.type());
    kernelCaller(src,dst);
}
