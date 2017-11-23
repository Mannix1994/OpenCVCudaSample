#include "deviceinfoes.h"

DeviceInfoes::DeviceInfoes()
{
    //ctor
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

string DeviceInfoes::getDeviceName(int index)
{
    assert(index > -1 && index < deviceCount);
    string s = deviceList.at(index).name;
    return s;
}

size_t DeviceInfoes::getTotalGlobalMemory(int index)
{
    assert(index > -1 && index < deviceCount);
    return deviceList.at(index).totalGlobalMem;
}

size_t DeviceInfoes::getSharedMemoryPerBlock(int index)
{
    assert(index > -1 && index < deviceCount);
    return deviceList.at(index).sharedMemPerBlock;
}
