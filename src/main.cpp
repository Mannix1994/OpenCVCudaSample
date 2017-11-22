#include <iostream>
#include "kernel.h"
#include "timer.h"

#define HANDLECUDAERROR(x)  (handleCudaError(__FILE__,__FUNCTION__,__LINE__,x))
void handleCudaError(const char *filename, const char *funcname,int linenumber,cudaError_t error)
{
    if (error != cudaSuccess)
    {
        cout<<filename<<" Function:"<<
        funcname<<" Line:"<<linenumber<<" Error:"<<cudaGetErrorString(error)<<endl;
    }

}

int main()
{
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
