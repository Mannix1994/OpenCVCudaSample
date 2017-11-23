#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <vector>
#include <iostream>
#include <cstring>
#include <cassert>

#include <cuda.h>
#include <cuda_runtime.h>

#include "toolfunctions.h"

using namespace std;



class DeviceInfoes
{
    public:
        DeviceInfoes();
        virtual ~DeviceInfoes();

        void refreshDeviceInfo();

        string getDeviceName(int index = 0);        //获取设备名
        size_t getTotalGlobalMemory(int index = 0); //获取全局内存
        size_t getSharedMemoryPerBlock(int index = 0);
        int getRegsPerBlock(int index = 0);
        int getWarpSize(int index = 0);
        size_t getMemoryPitch(int index = 0);
        int getMaxThreadsPerBlock(int index = 0);
        void getMaxThreadsDim(int dim[3],int index = 0);
        void getMaxGridSize(int gridSize[3],int index = 0);
        size_t getTotalConstMemory(int index = 0);
        int getComputeCapabilityMajor(int index = 0);
        int getComputeCapabilityMinor(int index = 0);
        string getComputeCapabilityString(int index = 0);
        int getClockRate(int index = 0);
        size_t getTextureAlignment(int index = 0);
        int getDeviceOverlap(int index = 0);
        int getMultiProcessorCount(int index = 0);
        int getKernelExecTimeoutEnabled(int index = 0);
        int getIntegrated(int index = 0);
        int canMapHostMemeory(int index = 0);
        int getComputeMode(int index = 0);
        int getMaxTexture1D(int index = 0);
        void getMaxTexture2D(int maxTexture[2],int index = 0);
        void getMaxTexture3D(int maxTexture[3],int index = 0);
        void getMaxTexture2DArray(int maxTextureArray[3],int index = 0);
        int getConcurrentKernels(int index = 0);

    protected:

    private:
        int deviceCount;
        vector<cudaDeviceProp> deviceList;
};

#endif // DEVICEINFO_H
