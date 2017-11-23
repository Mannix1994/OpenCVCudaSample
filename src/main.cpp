#include <iostream>
#include "kernel.h"
#include "timer.h"
#include "toolfunctions.h"
#include "deviceinfoes.h"

int main()
{
    ASSERT(1);
    DeviceInfoes info;
    cout<<"Name"<<info.getDeviceName()<<endl;
    cout<<"Global Memory"<<info.getTotalGlobalMemory()/1024.0/1024.0<<"GB"<<endl;
    cout<<"SharedMemoryPerBlock"<<info.getSharedMemoryPerBlock()/1024.0<<"MB"<<endl;
    cout<<"RegsPerBlock:"<<info.getRegsPerBlock(0)<<endl;
    cout<<"WarpSize:"<<info.getWarpSize()<<endl;
    cout<<"MemPitch:"<<info.getMemoryPitch()<<endl;
    cout<<"maxThreadsdPerBlock:"<<info.getMaxThreadsPerBlock()<<endl;
    int dim[3];
    info.getMaxThreadsDim(dim);
    cout<<"ThreadsDim: "<<dim[0]<<" "<<dim[1]<<" "<<dim[2]<<endl;
    int grid[3];
    info.getMaxGridSize(grid);
    cout<<"GridSize: "<<grid[0]<<" "<<grid[1]<<" "<<grid[2]<<endl;
    cout<<"ConstMemory:"<<info.getTotalConstMemory()/1024.0<<"MB"<<endl;
    cout<<"Compute Capability Major:"<<info.getComputeCapabilityMajor()<<endl;
    cout<<"Compute Capability Minor:"<<info.getComputeCapabilityMinor()<<endl;
    cout<<"Compute Capability:"<<info.getComputeCapabilityString()<<endl;
    cout<<"Texture Alignment:"<<info.getTextureAlignment()<<endl;
    cout<<"Device Overlap:"<<info.getDeviceOverlap()<<endl;
    cout<<"MultiProcessorCount:"<<info.getMultiProcessorCount()<<endl;
    cout<<"KernelExecTimeEnabled:"<<info.getKernelExecTimeoutEnabled()<<endl;
    cout<<"Integrated:"<<info.getIntegrated()<<endl;
    cout<<"CanMapHostMemory:"<<info.canMapHostMemeory()<<endl;
    cout<<"Compute Mode:"<<info.getComputeMode()<<endl;
    cout<<"MaxTexture1D:"<<info.getMaxTexture1D()<<endl;
    int buffer[3];
    info.getMaxTexture2D(buffer);
    cout<<"getMaxTexture2D: "<<buffer[0]<<" "<<buffer[1]<<endl;
    info.getMaxTexture3D(buffer);
    cout<<"getMaxTexture2D: "<<buffer[0]<<" "<<buffer[1]<<" "<<buffer[2]<<endl;
    cout<<"ConcurrentKernels:"<<info.getConcurrentKernels()<<endl;

//    Mat image = imread("lena.jpeg");
//    imshow("src",image);
//    GpuMat gpuMat,output;
//    gpuMat.upload(image);
//    callKernel(gpuMat,output);
//    output.download(image);
//    HANDLECUDAERROR(cudaGetLastError());
//    imwrite("purple.jpeg",image);
//    imshow("gpu",image);
//    waitKey(0);
    return 0;
}
