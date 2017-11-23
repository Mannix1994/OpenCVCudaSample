#include "deviceinfoes.h"

DeviceInfoes::DeviceInfoes()
{
    refreshDeviceInfo();
}

DeviceInfoes::~DeviceInfoes()
{
    //dtor
}

/**
* 刷新设备信息
*/
void DeviceInfoes::refreshDeviceInfo()
{
    HANDLECUDAERROR(cudaGetDeviceCount(&deviceCount));
    cudaDeviceProp prop;
    for(int i = 0; i < deviceCount; i++){
        if(cudaGetDeviceProperties(&prop,i) == cudaSuccess){
            deviceList.push_back(prop);
        }else{
            HANDLECUDAERROR(cudaGetLastError());
        }
    }
}

/**
* 获取设备名字
*/
string DeviceInfoes::getDeviceName(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    string s = deviceList.at(index).name;
    return s;
}

/**
* 设备上全局内存容量,单位为字节
*/
size_t DeviceInfoes::getTotalGlobalMemory(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).totalGlobalMem;
}

/**
* 每个Block中可用的最大共享内存数量,单位为字节
*/
size_t DeviceInfoes::getSharedMemoryPerBlock(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).sharedMemPerBlock;
}

/**
* 每个Block中可用的32位寄存器数量
*/
int DeviceInfoes::getRegsPerBlock(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).regsPerBlock;
}

/**
* 一个线程束(Warp)包含的线程数量
*/
int DeviceInfoes::getWarpSize(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).warpSize;
}

/**
*
*/
size_t DeviceInfoes::getMemoryPitch(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).memPitch;
}

/**
* 一个Block中可包含的最大线程数量
*/
int DeviceInfoes::getMaxThreadsPerBlock(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).maxThreadsPerBlock;
}

/**
*
*/
void DeviceInfoes::getMaxThreadsDim(int dim[3],int index)
{
    ASSERT(index > -1 && index < deviceCount);
    memcpy(dim,deviceList.at(index).maxThreadsDim,3*sizeof(int));
}

/**
*
*/
void DeviceInfoes::getMaxGridSize(int gridSize[3],int index)
{
    ASSERT(index > -1 && index < deviceCount);
    memcpy(gridSize,deviceList.at(index).maxGridSize,3*sizeof(int));
}

/**
*
*/
size_t DeviceInfoes::getTotalConstMemory(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).totalConstMem;
}

/**
*
*/
int DeviceInfoes::getComputeCapabilityMajor(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).major;
}

/**
*
*/
int DeviceInfoes::getComputeCapabilityMinor(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).minor;
}

/**
*
*/
string DeviceInfoes::getComputeCapabilityString(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    char buffer[100];
    sprintf(buffer,"%d.%d",deviceList.at(index).major,deviceList.at(index).minor);
    string s = buffer;
    return s;
}

/**
*
*/
size_t DeviceInfoes::getTextureAlignment(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).textureAlignment;
}

/**
*
*/
int DeviceInfoes::getDeviceOverlap(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).deviceOverlap;
}

/**
*
*/
int DeviceInfoes::getMultiProcessorCount(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).multiProcessorCount;
}

/**
*
*/
int DeviceInfoes::getKernelExecTimeoutEnabled(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).kernelExecTimeoutEnabled;
}

/**
*
*/
int DeviceInfoes::getIntegrated(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).integrated;
}

/**
*
*/
int DeviceInfoes::canMapHostMemeory(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).canMapHostMemory;
}

/**
*
*/
int DeviceInfoes::getComputeMode(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).computeMode;
}

/**
*
*/
int DeviceInfoes::getMaxTexture1D(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).maxTexture1D;
}

/**
*
*/
void DeviceInfoes::getMaxTexture2D(int maxTexture[2],int index)
{
    ASSERT(index > -1 && index < deviceCount);
    memcpy(maxTexture,deviceList.at(index).maxTexture2D,2*sizeof(int));
}

/**
*
*/
void DeviceInfoes::getMaxTexture3D(int maxTexture[3],int index)
{
    ASSERT(index > -1 && index < deviceCount);
    memcpy(maxTexture,deviceList.at(index).maxTexture3D,3*sizeof(int));
}

/**
*
*/
int DeviceInfoes::getConcurrentKernels(int index)
{
    ASSERT(index > -1 && index < deviceCount);
    return deviceList.at(index).concurrentKernels;
}
