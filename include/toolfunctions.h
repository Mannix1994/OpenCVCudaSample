#ifndef TOOLFUNCTIONS_H
#define TOOLFUNCTIONS_H

#include <iostream>

#include <cuda.h>
#include <cuda_runtime.h>

using namespace std;

#define HANDLECUDAERROR(x)  (handleCudaError(__FILE__,__FUNCTION__,__LINE__,x))
void handleCudaError(const char *filename, const char *funcname,int linenumber,cudaError_t error);


#endif // TOOLFUNCTIONS_H
