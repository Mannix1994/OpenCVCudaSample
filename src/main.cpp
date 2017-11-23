#include <iostream>
#include "kernel.h"
#include "timer.h"
#include "toolfunctions.h"
#include "deviceinfoes.h"

int main()
{
    DeviceInfoes info;
    cout<<info.getDeviceName()<<endl;
    Timer t;
    Mat image = imread("lena.jpeg");
    imshow("src",image);
    GpuMat gpuMat,output;

    gpuMat.upload(image);
    callKernel(gpuMat,output);
    output.download(image);
    HANDLECUDAERROR(cudaGetLastError());
    imshow("gpu",image);
    t.printSeconds();

    waitKey(0);
    return 0;
}
