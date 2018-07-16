#include <iostream>
#include "kernel.h"
#include "timer.h"
#include "toolfunctions.h"
#include "devicesinfo.h"

typedef Point3_<unsigned char> Point3u;

int main()
{
    Mat image = imread("lena.jpeg");
    imshow("src",image);
    Vec3b a = image.at<Vec3b>(0,0);
    printf("(%u,%u,%u)\n",a[0],a[1],a[2]);
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
