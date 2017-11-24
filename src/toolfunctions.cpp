#include "toolfunctions.h"

/**
* 处理CUDA函数调用失败问题
*/
void handleCudaError(const char *filename, const char *funcname,int linenumber,cudaError_t error)
{
    if (error != cudaSuccess)
    {
        cout<<filename<<" Function:"<<
        funcname<<" Line:"<<linenumber<<" Error:"<<cudaGetErrorString(error)<<endl;
    }

}

void mAssert(const char *filename, const char *funcname,int linenumber,int expression)
{
    if(expression == 0){
        cerr<<filename<<" Function:"<<
        funcname<<" Line:"<<linenumber<<">>: Assert failed, illegal expression"<<endl;
        exit(-1);
    }
}
