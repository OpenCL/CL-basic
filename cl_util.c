#include "cl_util.h"

///////////////////////////////////////////////////////////////////////////////
// Prints out the name of the input platform.
void PrintPlatformName(cl_platform_id platform)
{
    cl_uint clError = 0;
    size_t nameSize = 0;
    char* platformName = NULL;
    
    clError = clGetPlatformInfo(platform, CL_PLATFORM_NAME, 0, NULL, &nameSize);
    CHECK_OCL_ERR("clGetPlatformInfo", clError);

    platformName = (char*)malloc(nameSize * sizeof(char));
    CHECK_NULL(platformName);

    clError = clGetPlatformInfo(platform, CL_PLATFORM_NAME, nameSize, platformName, NULL);
    CHECK_OCL_ERR("clGetPlatformInfo", clError);

    printf("%s", platformName);

    free(platformName);
}

///////////////////////////////////////////////////////////////////////////////
// Prints out the name of the input device.
void PrintDeviceName(cl_device_id device)
{
    cl_uint clError = 0;
    size_t nameSize = 0;
    char* deviceName = NULL;

    clError = clGetDeviceInfo(device, CL_DEVICE_NAME, 0, NULL, &nameSize);
    CHECK_OCL_ERR("clGetDeviceInfo", clError);

    deviceName = (char*)malloc(nameSize * sizeof(char));
    CHECK_NULL(deviceName);

    clError = clGetDeviceInfo(device, CL_DEVICE_NAME, nameSize, deviceName, NULL);
    CHECK_OCL_ERR("clGetDeviceInfo", clError);

    printf("%s", deviceName);

    free(deviceName);
}

///////////////////////////////////////////////////////////////////////////////
// Prints out detailed information about OpenCL.
int PrintOpenCLInfo()
{    
    cl_uint numPlatforms = 0;
    cl_platform_id *platforms = 0;
    cl_int clError = 0;

    clError = clGetPlatformIDs(0, NULL, &numPlatforms);
    CHECK_OCL_ERR("clGetPlatformIDs", clError);

    if (0 >= numPlatforms)
        return 0;

    printf("\nOpenCL platforms detected: %d", numPlatforms);

    platforms = (cl_platform_id*)malloc(numPlatforms * sizeof(cl_platform_id));
    CHECK_NULL(platforms);

    clError = clGetPlatformIDs(numPlatforms, platforms, NULL);
    CHECK_OCL_ERR("clGetPlatformIDs", clError);

    for (cl_uint i = 0; i < numPlatforms; i++)
    {       
        cl_uint numDevices = 0;
        cl_device_id *devices = NULL;               

        printf("\n%d. Platform: ", i + 1);
        PrintPlatformName(platforms[i]);
        
        clError = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);
        CHECK_OCL_ERR("clGetDeviceIDs", clError);
        
        printf("\n\tNumber of devices: %d", numDevices);

        devices = (cl_device_id*)malloc(numDevices * sizeof(cl_device_id));
        CHECK_NULL(devices);

        clError = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, numDevices, devices, NULL);
        CHECK_OCL_ERR("clGetDeviceIDs", clError);

        for (cl_uint j = 0; j < numDevices; j++)
        {           
            printf("\n\t%d. Device: ", j + 1);
            PrintDeviceName(devices[j]);

            cl_device_type deviceType;
            clError = clGetDeviceInfo(devices[j], CL_DEVICE_TYPE, sizeof(deviceType), &deviceType, NULL);
            CHECK_OCL_ERR("clGetDeviceInfo", clError);

            switch (deviceType)
            {
            case CL_DEVICE_TYPE_CPU:                
                printf("\n\t\tType: CPU");
                break;
            case CL_DEVICE_TYPE_GPU:                
                printf("\n\t\tType: GPU");
                break;
            case CL_DEVICE_TYPE_ACCELERATOR:
                printf("\n\t\tType: ACCELERATOR");                
                break;
            default:            
                printf("\n\t\tType: Unknown");                
                break;
            }

            cl_uint cuCnt = 0;
            clError = clGetDeviceInfo(devices[j], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cuCnt), &cuCnt, NULL);
            CHECK_OCL_ERR("clGetDeviceInfo", clError);
            printf("\n\t\tNumber of CUs: %d", cuCnt);
        }

        if (devices)
            free(devices);
    }

    if (platforms)
        free(platforms);

    return numPlatforms;
}

///////////////////////////////////////////////////////////////////////////////
// Returns a platform and device id as selected by the user.
void SelectOpenCLPlatformAndDevice(cl_platform_id* pPlatform, cl_device_id* pDevice)
{
    cl_uint numPlatforms = 0;
    cl_uint numDevices = 0;
    cl_uint clError = 0;
    int platformIndex = 0;
    int deviceIndex = 0;
    cl_platform_id *platforms = 0;
    cl_device_id* devices = 0;

    CHECK_NULL(pPlatform);
    CHECK_NULL(pDevice);

    platforms = NULL;
    devices = NULL;

    clError = clGetPlatformIDs(0, NULL, &numPlatforms);
    CHECK_OCL_ERR("clGetPlatformIDs", clError);

    platforms = (cl_platform_id*)malloc(numPlatforms * sizeof(cl_platform_id));
    CHECK_NULL(platforms);

    clError = clGetPlatformIDs(numPlatforms, platforms, NULL);
    CHECK_OCL_ERR("clGetPlatformIDs", clError);

    printf("\n\nSelect platform to use [%d-%d]:", 1, numPlatforms);
    scanf("%d", &platformIndex);
    platformIndex--;

    *pPlatform = platforms[platformIndex];

    clError = clGetDeviceIDs(platforms[platformIndex], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);
    CHECK_OCL_ERR("clGetDeviceIDs", clError);

    devices = (cl_device_id*)malloc(numDevices * sizeof(cl_device_id));
    CHECK_NULL(devices);

    clError = clGetDeviceIDs(platforms[platformIndex], CL_DEVICE_TYPE_ALL, numDevices, devices, NULL);
    CHECK_OCL_ERR("clGetDeviceIDs", clError);

    printf("Select device to use [%d-%d]:", 1, numDevices);
    scanf("%d", &deviceIndex);
    deviceIndex--;

    *pDevice = devices[deviceIndex];

    if (platforms)
        free(platforms);
    if (devices)
        free(devices);
}

///////////////////////////////////////////////////////////////////////////////
// Creates an OpenCL context for the given device and platform.
cl_context CreateOpenCLContext(cl_platform_id platform, cl_device_id device)
{
    cl_int clError;
    cl_context context;

    cl_context_properties contextProperties[] =
    {
        CL_CONTEXT_PLATFORM,
        (cl_context_properties)platform,
        0
    };

    context = clCreateContext(contextProperties, 1, &device, NULL, NULL, &clError);
    CHECK_OCL_ERR("clCreateContext", clError);

    return context;
}

///////////////////////////////////////////////////////////////////////////////
// Releases the input OpenCL context.
void ReleaseOpenCLContext(cl_context *pContext)
{
    cl_int clError;

    CHECK_NULL(pContext);

    if (*pContext)
    {
        clError = clReleaseContext(*pContext);
        CHECK_OCL_ERR("clReleaseContext", clError);

        *pContext = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Creates an OpenCL queue for the given device and context.
cl_command_queue CreateOpenCLQueue(cl_device_id device, cl_context context)
{
    cl_int clError;
    cl_command_queue queue;

    queue = clCreateCommandQueue(context, device, 0, &clError);
    CHECK_OCL_ERR("clCreateCommandQueue", clError);

    return queue;
}

///////////////////////////////////////////////////////////////////////////////
// Releases the input OpenCL queue.
void ReleaseOpenCLQueue(cl_command_queue *pQueue)
{
    cl_int clError;

    CHECK_NULL(pQueue);

    if (*pQueue)
    {
        clError = clReleaseCommandQueue(*pQueue);
        CHECK_OCL_ERR("clReleaseCommandQueue", clError);

        *pQueue = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Creates an OpenCL buffer in the given context.
cl_mem CreateDeviceBuffer(cl_context context, size_t sizeInBytes)
{
    cl_int clError;

    cl_mem buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeInBytes, NULL, &clError);
    CHECK_OCL_ERR("clCreateBuffer", clError);

    return buffer;
}

///////////////////////////////////////////////////////////////////////////////
// Releases the input OpenCL memory buffer.
void ReleaseDeviceBuffer(cl_mem *pDeviceBuffer)
{
    cl_int clError;

    CHECK_NULL(pDeviceBuffer);

    if (*pDeviceBuffer)
    {
        clError = clReleaseMemObject(*pDeviceBuffer);
        CHECK_OCL_ERR("clReleaseMemObject", clError);

        *pDeviceBuffer = 0;
    }      
}

///////////////////////////////////////////////////////////////////////////////
// Copies data from a host buffer to an OpenCL device buffer.
void CopyHostToDevice(void* hostBuffer, cl_mem deviceBuffer, size_t sizeInBytes, cl_command_queue queue, cl_bool blocking)
{
    cl_int clError;

    clError = clEnqueueWriteBuffer(queue, deviceBuffer, blocking, 0, sizeInBytes, hostBuffer, 0, NULL, NULL);

    CHECK_OCL_ERR("clEnqueueWriteBuffer", clError);
}

///////////////////////////////////////////////////////////////////////////////
// Copies data from a device buffer back to host.
void CopyDeviceToHost(cl_mem deviceBuffer, void* hostBuffer, size_t sizeInBytes, cl_command_queue queue, cl_bool blocking)
{
    cl_int clError;

    clError = clEnqueueReadBuffer(queue, deviceBuffer, blocking, 0, sizeInBytes, hostBuffer, 0, NULL, NULL);

    CHECK_OCL_ERR("clEnqueueReadBuffer", clError);
}

///////////////////////////////////////////////////////////////////////////////
// Loads the OpenCL code from the input file.
char* LoadOpenCLSourceFromFile(char* filePath, size_t *pSourceLength)
{
    FILE* fileHandle;
    char* sourceCode;

    fileHandle = fopen(filePath, "rb");
    CHECK_NULL(fileHandle);
    fseek(fileHandle, 0, SEEK_END);

    *pSourceLength = ftell(fileHandle);
    sourceCode = (char*)malloc((*pSourceLength) + 1);
    CHECK_NULL(sourceCode);

    fseek(fileHandle, 0, SEEK_SET);
    fread(sourceCode, *pSourceLength, 1, fileHandle);
    sourceCode[(*pSourceLength)] = 0;
    *pSourceLength = (*pSourceLength) + 1;

    fclose(fileHandle);

    return sourceCode;
}

///////////////////////////////////////////////////////////////////////////////
// Creates and builds an OpenCL program with the input source code for
// the given context and source code string.
cl_program CreateAndBuildProgram(cl_context context, char* sourceCode, size_t sourceCodeLength)
{
    cl_program program;
    cl_int clError;
    char *buildLog;
    size_t buildLogSize;
    cl_device_id device;

    program = clCreateProgramWithSource(context, 1, (const char**)(&sourceCode), &sourceCodeLength, &clError);
    CHECK_OCL_ERR("clCreateProgramWithSource", clError);

    clGetContextInfo(context, CL_CONTEXT_DEVICES, sizeof(cl_device_id), &device, NULL);
    CHECK_OCL_ERR("clGetContextInfo", clError);

    clError = clBuildProgram(program, 1, &device, NULL, NULL, NULL);

    if (CL_SUCCESS != clError)
    {
        printf("\nOpenCL error %d at line %d in file %s\n", clError, __LINE__, __FILE__);
		print_cl_error("clBuildProgram", clError);

        buildLog = NULL;
        buildLogSize = 0;

        clError = clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &buildLogSize);
        CHECK_OCL_ERR("clGetProgramBuildInfo", clError);

        if (buildLogSize)
        {
            // Allocate memory to fit the build log - it can be very large in case of errors
            buildLog = (char*)malloc(buildLogSize);
            if (buildLog)
            {
                clError = clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, buildLogSize, buildLog, NULL);
                CHECK_OCL_ERR("clGetProgramBuildInfo", clError);

                printf("\nOpenCL program build info: \n%s\n", buildLog);

                // Free buildLog buffer
                free(buildLog);
            }
        }

        exit(EXIT_FAILURE);
    }

    return program;
}

///////////////////////////////////////////////////////////////////////////////
// Releases an OpenCL program object.
void ReleaseProgram(cl_program *pProgram)
{
    cl_int clError;

    CHECK_NULL(pProgram);

    if (*pProgram)
    {
        clError = clReleaseProgram(*pProgram);
        CHECK_OCL_ERR("clReleaseProgram", clError);

        *pProgram = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Creates an OpenCL kernel object for the kernel with the given name.
cl_kernel CreateKernel(cl_program program, char* kernelName)
{
    cl_int clError;
    cl_kernel kernel;

    kernel = clCreateKernel(program, kernelName, &clError);
    CHECK_OCL_ERR("clCreateKernel", clError);

    return kernel;
}

///////////////////////////////////////////////////////////////////////////////
// Releases an OpenCL kernel object.
void ReleaseKernel(cl_kernel *pKernel)
{
    cl_int clError;

    CHECK_NULL(pKernel);

    if (*pKernel)
    {
        clError = clReleaseKernel(*pKernel);
        CHECK_OCL_ERR("clReleaseKernel", clError);

        *pKernel = 0;
    }
}