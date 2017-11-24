#include <iostream>
#include "kernel.h"
#include "timer.h"
#include "toolfunctions.h"
#include "devicesinfo.h"

int main()
{
    Mat image = imread("lena.jpeg");
    imshow("src",image);
    GpuMat gpuMat,output;
    gpuMat.upload(image);
    callKernel(gpuMat,output);
    HANDLECUDAERROR(cudaGetLastError());
    output.download(image);
    HANDLECUDAERROR(cudaGetLastError());
    imwrite("purple.jpeg",image);
    imshow("gpu",image);
    waitKey(0);
    return 0;
}
