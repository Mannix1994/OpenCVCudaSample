#include "kernel.h"
#include "timer.h"

/**
* 自定义核函数，在这个函数里面实现对每个像素的访问
*/
__global__ void kernel(const PtrStepSz<uchar3> src,PtrStep<uchar3> dst)
{
    int x = threadIdx.x + blockIdx.x * blockDim.x;
    int y = threadIdx.y + blockIdx.y * blockDim.y;

    if(x < src.cols && y < src.rows)
    {
        uchar3 v = src(y,x);
        dst(y,x) = make_uchar3(v.y,v.x,v.z);    //紫红色
        //dst(y,x) = make_uchar3(v.x,v.z,v.y);    //浅绿色
        //dst(y,x) = make_uchar3(v.y,v.z,v.x);
    }
}

/**
* 完成核函数的调用
*/
void kernelCaller(const PtrStepSz<uchar3>& src,PtrStep<uchar3> dst,cudaStream_t stream)
{
    dim3 block(32,32);
    dim3 grid((src.cols + block.x - 1)/block.x,(src.rows + block.y - 1)/block.y);

    kernel<<<grid,block,0,stream>>>(src,dst);
//    kernel<<<1024,1>>>(src,dst);
    if(stream == 0)
        cudaDeviceSynchronize();
}

/**
* 外部函数调用这个函数(留给外部的唯一接口)，把GpuMat传进来
*/
void callKernel(const GpuMat& src,GpuMat& dst,Stream& stream)
{
    CV_Assert(src.type() == CV_8UC3);
    dst.create(src.size(),src.type());
    cudaStream_t s = StreamAccessor::getStream(stream);
    kernelCaller(src,dst,s);
}
