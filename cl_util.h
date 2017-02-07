#ifndef __CL_UTIL_H
#define __CL_UTIL_H

#include<stdlib.h>
#include<stdio.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#include "cl_error_util.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CHECK_NULL(p) \
    {\
        if (NULL == p)\
        {\
            printf("NULL pointer at line %d in file %s\n", __LINE__, __FILE__);\
            exit(EXIT_FAILURE);\
        }\
    }

#define CHECK_OCL_ERR(functionName, err) \
    {\
        if (CL_SUCCESS != err)\
        {\
            printf("OpenCL error %d at line %d in file %s\n", err, __LINE__, __FILE__);\
			print_cl_error(functionName, err);\
            exit(EXIT_FAILURE);\
        }\
    }
	
void PrintPlatformName(cl_platform_id platform);
void PrintDeviceName(cl_device_id device);
int PrintOpenCLInfo();
void SelectOpenCLPlatformAndDevice(cl_platform_id* pPlatform, cl_device_id* pDevice);
cl_context CreateOpenCLContext(cl_platform_id platform, cl_device_id device);
void ReleaseOpenCLContext(cl_context *pContext);
cl_command_queue CreateOpenCLQueue(cl_device_id device, cl_context context);
void ReleaseOpenCLQueue(cl_command_queue *pQueue);
cl_mem CreateDeviceBuffer(cl_context context, size_t sizeInBytes);
void ReleaseDeviceBuffer(cl_mem *pDeviceBuffer);
void CopyHostToDevice(void* hostBuffer, cl_mem deviceBuffer, size_t sizeInBytes, cl_command_queue queue, cl_bool blocking);
void CopyDeviceToHost(cl_mem deviceBuffer, void* hostBuffer, size_t sizeInBytes, cl_command_queue queue, cl_bool blocking);
char* LoadOpenCLSourceFromFile(char* filePath, size_t *pSourceLength);
cl_program CreateAndBuildProgram(cl_context context, char* sourceCode, size_t sourceCodeLength);
void ReleaseProgram(cl_program *pProgram);
cl_kernel CreateKernel(cl_program program, char* kernelName);
void ReleaseKernel(cl_kernel *pKernel);

#ifdef __cplusplus
}
#endif

#endif /* __CL_UTIL_H */
