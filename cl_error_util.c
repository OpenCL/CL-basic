/*******************************************************************************
 * Copyright (c) 2015 StreamComputing BV - All Rights Reserved
 * www.streamcomputing.eu
 ******************************************************************************/

#include <string.h>
#include <stdio.h>
#include "cl_error_vals.h"
#include "cl_error_util.h"

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

typedef struct functionMessages_
{
    const int *errVals;
    const char **errMessages;
    unsigned int numMessages;
} functionMessages;

functionMessages mess[105];

int get_function_id(const char* fName)
{
    int i;
    const char *functionNames[] = {"clBuildProgram", "clCompileProgram", "clCreateBuffer", "clCreateCommandQueue", "clCreateContextFromType", "clCreateContext", "clCreateEventFromGLsyncKHR", "clCreateFromD3D10BufferKHR", "clCreateFromD3D10Texture2DKHR", "clCreateFromD3D10Texture3DKHR", "clCreateFromD3D11BufferKHR", "clCreateFromD3D11Texture2DKHR", "clCreateFromD3D11Texture3DKHR", "clCreateFromDX9MediaSurfaceKHR", "clCreateFromGLBuffer", "clCreateFromGLRenderbuffer", "clCreateFromGLTexture", "clCreateImage", "clCreateKernel", "clCreateKernelsInProgram", "clCreateProgramWithBinary", "clCreateProgramWithBuiltInKernels", "clCreateProgramWithSource", "clCreateSampler", "clCreateSubBuffer", "clCreateSubDevices", "clCreateUserEvent", "clEnqueueAcquireD3D10ObjectsKHR", "clEnqueueAcquireD3D11ObjectsKHR", "clEnqueueAcquireDX9MediaSurfacesKHR", "clEnqueueAcquireGLObjects", "clEnqueueBarrierWithWaitList", "clEnqueueCopyBuffer", "clEnqueueCopyBufferRect", "clEnqueueCopyBufferToImage", "clEnqueueCopyImage", "clEnqueueCopyImageToBuffer", "clEnqueueFillBuffer", "clEnqueueFillImage", "clEnqueueMapBuffer", "clEnqueueMapImage", "clEnqueueMarkerWithWaitList", "clEnqueueMigrateMemObjects", "clEnqueueNativeKernel", "clEnqueueNDRangeKernel", "clEnqueueReadBuffer", "clEnqueueReadBufferRect", "clEnqueueReadImage", "clEnqueueReleaseD3D10ObjectsKHR", "clEnqueueReleaseD3D11ObjectsKHR", "clEnqueueReleaseDX9MediaSurfacesKHR", "clEnqueueReleaseGLObjects", "clEnqueueTask", "clEnqueueUnmapMemObject", "clEnqueueWriteBuffer", "clEnqueueWriteBufferRect", "clEnqueueWriteImage", "clFinish", "clFlush", "clGetCommandQueueInfo", "clGetContextInfo", "clGetDeviceIDsFromD3D10KHR", "clGetDeviceIDsFromD3D11KHR", "clGetDeviceIDsFromDX9MediaAdapterKHR", "clGetDeviceIDs", "clGetDeviceInfo", "clGetEventInfo", "clGetEventProfilingInfo", "clGetGLContextInfoKHR", "clGetGLObjectInfo", "clGetGLTextureInfo", "clGetImageInfo", "clGetKernelArgInfo", "clGetKernelInfo", "clGetKernelWorkGroupInfo", "clGetMemObjectInfo", "clGetPlatformInfo", "clGetProgramBuildInfo", "clGetProgramInfo", "clGetSamplerInfo", "clGetSupportedImageFormats", "clIcdGetPlatformIDsKHR", "clLinkProgram", "clReleaseCommandQueue", "clReleaseContext", "clReleaseDevice", "clReleaseEvent", "clReleaseKernel", "clReleaseMemObject", "clReleaseProgram", "clReleaseSampler", "clRetainCommandQueue", "clRetainContext", "clRetainDevice", "clRetainEvent", "clRetainKernel", "clRetainMemObject", "clRetainProgram", "clRetainSampler", "clSetEventCallback", "clSetKernelArg", "clSetMemObjectDestructorCallback", "clSetUserEventStatus", "clUnloadPlatformCompiler", "clWaitForEvents"};
    for (i = 0; i < 105; ++i)
    {
        if (!strcmp(functionNames[i], fName))
        {
            return i;
        }
    }

    return -1;
}

const char* get_error_description(int functionID, int errorNumber)
{

    static const int t_errVals0[] = {CL_INVALID_PROGRAM, CL_INVALID_VALUE, CL_INVALID_DEVICE, CL_INVALID_BINARY, CL_INVALID_BUILD_OPTIONS, CL_INVALID_OPERATION, CL_COMPILER_NOT_AVAILABLE, CL_BUILD_PROGRAM_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages0[] = {"program is not a valid program object", "device_list is NULL and num_devices is greater than zero, or if device_list is not NULL and num_devices is zero OR pfn_notify is NULL but user_data is not NULL", "OpenCL devices listed in device_list are not in the list of devices associated with program", "program is created with clCreateProgramWithBinary and devices listed in device_list do not have a valid program binary loaded", "the build options specified by options are invalid", "the build of a program executable for any of the devices listed in device_list by a previous call to clBuildProgram for program has not completed OR there are kernel objects attached to program OR program was not created with clCreateProgramWithSource or clCreateProgramWithBinary", "program is created with clCreateProgramWithSource and a compiler is not available i.e. CL_DEVICE_COMPILER_AVAILABLE specified in the table of OpenCL Device Queries for clGetDeviceInfo is set to CL_FALSE", "there is a failure to build the program executable. This error will be returned if clBuildProgram does not return until the build has completed", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[0].errVals = t_errVals0;
    mess[0].errMessages = t_errMessages0;
    mess[0].numMessages = 10;

    static const int t_errVals1[] = {CL_INVALID_PROGRAM, CL_INVALID_VALUE, CL_INVALID_DEVICE, CL_INVALID_COMPILER_OPTIONS, CL_INVALID_OPERATION, CL_COMPILER_NOT_AVAILABLE, CL_COMPILE_PROGRAM_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages1[] = {"program is not a valid program object", "device_list is NULL and num_devices is greater than zero, or if device_list is not NULL and num_devices is zero OR num_input_headers is zero and header_include_names or input_headers are not NULL or if num_input_headers is not zero and header_include_names or input_headers are NULL OR pfn_notify is NULL but user_data is not NULL", "OpenCL devices listed in device_list are not in the list of devices associated with program", "the compiler options specified by options are invalid", "the compilation or build of a program executable for any of the devices listed in device_list by a previous call to clCompileProgram or clBuildProgram for program has not completed OR there are kernel objects attached to program OR program has no source i.e. it has not been created with clCreateProgramWithSource", "a compiler is not available i.e. CL_DEVICE_COMPILER_AVAILABLE specified in in the table of allowed values for param_name for clGetDeviceInfo is set to CL_FALSE", "there is a failure to compile the program source. This error will be returned if clCompileProgram does not return until the compile has completed", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[1].errVals = t_errVals1;
    mess[1].errMessages = t_errMessages1;
    mess[1].numMessages = 9;

    static const int t_errVals2[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_BUFFER_SIZE, CL_INVALID_HOST_PTR, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages2[] = {"context is not a valid context", "values specified in flags are not valid as defined in the table above", "size is 0.  Implementations may return CL_INVALID_BUFFER_SIZE if size is greater than the CL_DEVICE_MAX_MEM_ALLOC_SIZE value specified in the table of allowed values for param_name for clGetDeviceInfo for all devices in context", "host_ptr is NULL and CL_MEM_USE_HOST_PTR or CL_MEM_COPY_HOST_PTR are set in flags or if host_ptr is not NULL but CL_MEM_COPY_HOST_PTR or CL_MEM_USE_HOST_PTR are not set in flags", "there is a failure to allocate memory for buffer object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[2].errVals = t_errVals2;
    mess[2].errMessages = t_errMessages2;
    mess[2].numMessages = 7;

    static const int t_errVals3[] = {CL_INVALID_CONTEXT, CL_INVALID_DEVICE, CL_INVALID_VALUE, CL_INVALID_QUEUE_PROPERTIES, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages3[] = {"context is not a valid context", "device is not a valid device or is not associated with context", "values specified in properties are not valid", "values specified in properties are valid but are not supported by the device", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[3].errVals = t_errVals3;
    mess[3].errMessages = t_errMessages3;
    mess[3].numMessages = 6;

    static const int t_errVals4[] = {CL_INVALID_PLATFORM, CL_INVALID_PROPERTY, CL_INVALID_VALUE, CL_INVALID_DEVICE_TYPE, CL_DEVICE_NOT_AVAILABLE, CL_DEVICE_NOT_FOUND, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY, CL_INVALID_D3D10_DEVICE_KHR, CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR, CL_INVALID_DX9_MEDIA_ADAPTER_KHR, CL_INVALID_ADAPTER_KHR, CL_INVALID_OPERATION, CL_INVALID_D3D11_DEVICE_KHR};
    static const char *t_errMessages4[] = {"properties is NULL and no platform could be selected or if platform value specified in properties is not a valid platform. If the cl_khr_gl_sharing extension is supported, this error is replaced (or not) by CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR and possibly CL_INVALID_OPERATION (see below and section 9.6.4 of the spec for clarification)", "context property name in properties is not a supported property name, or if the value specified for a supported property name is not valid, or if the same property name is specified more than once", "pfn_notify is NULL but user_data is not NULL", "device_type is not a valid value", "no devices that match device_type and property values specified in properties are currently available", "no devices that match device_type and property values specified in properties were found", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host", "the Direct3D 10 device specified for interoperability is not compatible with the devices against which the context is to be created (if the cl_khr_d3d10_sharing extension is enabled)", "when an invalid OpenGL context or share group object handle is specified in properties if the cl_khr_gl_sharing extension is enabled OR no OpenGL or OpenGL ES context or share group is specified in the attribute list, then memory objects may not be shared, and calling any of the commands in section 9.7 will result in this error (if the cl_khr_gl_sharing extension is enabled) OR a share group was specified for a CGL-based OpenGL implementation by setting the attribute CL_CGL_SHAREGROUP_KHR, and the specified share group does not identify a valid CGL share group object (only if the cl_khr_gl_sharing extension is enabled)", "the media adapter specified for interoperability is not compatible with the devices against which the context is to be created (only if the cl_khr_dx9_media_sharing extension is supported)", "any of the values of the properties CL_CONTEXT_ADAPTER_D3D9_KHR, CL_CONTEXT_ADAPTER_D3D9EX_KHR or CL_CONTEXT_ADAPTER_DXVA_KHR is non-NULL and does not specify a valid media adapter with which the cl_device_ids against which this context is to be created may interoperate. (only if the cl_khr_dx9_media_sharing extension is supported)", "interoperability is specified by setting CL_CONTEXT_ADAPTER_D3D9_KHR, CL_CONTEXT_ADAPTER_D3D9EX_KHR or CL_CONTEXT_ADAPTER_DXVA_KHR to a non-NULL value, and interoperability with another graphics API is also specified. (only if the cl_khr_dx9_media_sharing extension is supported) OR Direct3D 11 interoperability is specified by setting CL_INVALID_D3D11_DEVICE_KHR to a non-NULL value, and interoperability with another graphics API is also specified. (only if the cl_khr_d3d11_sharing extension is supported)", "the Direct3D 11 device specified for interoperability is not compatible with the devices against which the context is to be created (only if the cl_khr_d3d11_sharing extension is supported) OR the value of the property CL_CONTEXT_D3D11_DEVICE_KHR is non-NULL and does not specify a valid Direct3D 11 device with which the cl_device_ids against which this context is to be created may interoperate. (only if the cl_khr_d3d11_sharing extension is supported)"};
    mess[4].errVals = t_errVals4;
    mess[4].errMessages = t_errMessages4;
    mess[4].numMessages = 14;

    static const int t_errVals5[] = {CL_INVALID_PLATFORM, CL_INVALID_PROPERTY, CL_INVALID_VALUE, CL_INVALID_DEVICE, CL_INVALID_OPERATION, CL_DEVICE_NOT_AVAILABLE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY, CL_INVALID_D3D10_DEVICE_KHR, CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR, CL_INVALID_DX9_MEDIA_ADAPTER_KHR, CL_INVALID_ADAPTER_KHR, CL_INVALID_D3D11_DEVICE_KHR};
    static const char *t_errMessages5[] = {"properties is NULL and no platform could be selected or if platform value specified in properties is not a valid platform. (If the extension cl_khr_gl_sharing is enabled, then this error is replaced with CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR; see below.", "context property name in properties is not a supported property name, if the value specified for a supported property name is not valid, or if the same property name is specified more than once. However if the extension cl_khr_gl_sharing is enabled, then CL_INVALID_PROPERTY is returned if an attribute name other than those listed in the table for properties above or if CL_CONTEXT_INTEROP_USER_SYNC is specified in properties OR an attribute name other than those specified in table 4.5 or if CL_CONTEXT_INTEROP_USER_SYNC is specified in properties", "devices is NULL; if num_devices is equal to zero; or if pfn_notify is NULL but user_data is not NULL", "devices contains an invalid device", "Direct3D 10 interoperability is specified by setting CL_INVALID_D3D10_DEVICE_KHR to a non-NULL value, and interoperability with another graphics API is also specified (if the cl_khr_d3d10_sharing extension is enabled) OR a context was specified as described above and any of the following conditions hold:  A context or share group object was specified for one of CGL, EGL, GLX, or WGL and the OpenGL implementation does not support that window-system binding API OR interoperability is specified by setting CL_CONTEXT_ADAPTER_D3D9_KHR, CL_CONTEXT_ADAPTER_D3D9EX_KHR or CL_CONTEXT_ADAPTER_DXVA_KHR to a non-NULL value, and interoperability with another graphics API is also specified (only if the cl_khr_dx9_media_sharing extension is supported) OR Direct3D 11 interoperability is specified by setting CL_INVALID_D3D11_DEVICE_KHR to a non-NULL value, and interoperability with another graphics API is also specified (only if the cl_khr_d3d11_sharing extension is supported)", "a device in devices is currently not available even though the device was returned by clGetDeviceIDs", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host", "the Direct3D 10 device specified for interoperability is not compatible with the devices against which the context is to be created (if the cl_khr_d3d10_sharing extension is enabled) OR the value of the property CL_CONTEXT_D3D10_DEVICE_KHR is non-NULL and does not specify a valid Direct3D 10 device with which the cl_device_ids against which this context is to be created may interoperate (if the cl_khr_d3d10_sharing extension is enabled)", "when an invalid OpenGL context or share group object handle is specified in properties (only if the cl_khr_gl_sharing extension is enabled) OR no OpenGL or OpenGL ES context or share group is specified in the attribute list given to clCreateContext and any of the commands in section 9.7 are called. (if the cl_khr_gl_sharing extension is enabled OR the cl_khr_gl_sharing extension is enabled and if a context was specified by any of the following means:  A context specified for an EGL-based OpenGL ES or OpenGL implementation by setting the attributes CL_GL_CONTEXT_KHR and CL_EGL_DISPLAY_KHR OR a share group was specified for a CGL-based OpenGL implementation by setting the attribute CL_CGL_SHAREGROUP_KHR, and the specified share group does not identify a valid CGL share group object (if the cl_khr_gl_sharing extension is enabled)", "the media adapter specified for interoperability is not compatible with the devices against which the context is to be created (only if the cl_khr_dx9_media_sharing extension is supported)", "any of the values of the properties CL_CONTEXT_ADAPTER_D3D9_KHR, CL_CONTEXT_ADAPTER_D3D9EX_KHR or CL_CONTEXT_ADAPTER_DXVA_KHR is non-NULL and does not specify a valid media adapter with which the cl_device_ids against which this context is to be created may interoperate (only if the cl_khr_dx9_media_sharing extension is supported)", "the value of the property CL_CONTEXT_D3D11_DEVICE_KHR is non-NULL and does not specify a valid Direct3D 11 device with which the cl_device_ids against which this context is to be created may interoperate (only if the cl_khr_d3d11_sharing extension is supported) OR the Direct3D 11 device specified for interoperability is not compatible with the devices against which the context is to be created (only if the cl_khr_d3d11_sharing extension is supported)"};
    mess[5].errVals = t_errVals5;
    mess[5].errMessages = t_errMessages5;
    mess[5].numMessages = 13;

    static const int t_errVals6[] = {CL_INVALID_CONTEXT, CL_INVALID_GL_OBJECT};
    static const char *t_errMessages6[] = {"context is not a valid context or was not created from a GL context", "sync is not the name of a sync object in the GL share group associated with context"};
    mess[6].errVals = t_errVals6;
    mess[6].errMessages = t_errMessages6;
    mess[6].numMessages = 2;

    static const int t_errVals7[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_D3D10_RESOURCE_KHR, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages7[] = {"context is not a valid context", "values specified in flags are not valid", "resource is not a Direct3D 10 buffer resource, if resource was created with the D3D10_USAGE flag D3D10_USAGE_IMMUTABLE, if a cl_mem from resource has already been created using clCreateFromD3D10BufferKHR, or if context was not created against the same Direct3D 10 device from which resource was created", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[7].errVals = t_errVals7;
    mess[7].errMessages = t_errMessages7;
    mess[7].numMessages = 4;

    static const int t_errVals8[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_D3D10_RESOURCE_KHR, CL_INVALID_IMAGE_FORMAT_DESCRIPTOR, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages8[] = {"context is not a valid context", "values specified in flags are not valid or if subresource is not a valid subresource index for resource", "resource is not a Direct3D 10 texture resource, if resource was created with the D3D10_USAGE flag D3D10_USAGE_IMMUTABLE, if a resource is a multisampled texture, if cl_mem from subresource subresource of resource has already been created using clCreateFromD3D10Texture2DKHR, or if context was not created against the same Direct3D 10 device from which resource was created", "the Direct3D 10 texture format of resource is not a value listed in the table of Direct3D 10 and corresponding OpenCL image formats for clCreateFromD3D10Texture3DKHR, or if the Direct3D 10 texture format of resource does not map to a supported OpenCL image format", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[8].errVals = t_errVals8;
    mess[8].errMessages = t_errMessages8;
    mess[8].numMessages = 5;

    static const int t_errVals9[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_D3D10_RESOURCE_KHR, CL_INVALID_IMAGE_FORMAT_DESCRIPTOR, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages9[] = {"context is not a valid context", "values specified in flags are not valid or if subresource is not a valid subresource index for resource", "resource is not a Direct3D 10 texture resource, if resource was created with the D3D10_USAGE flag D3D10_USAGE_IMMUTABLE, if a resource is a multisampled texture, if cl_mem from subresource subresource of resource has already been created using clCreateFromD3D10Texture3DKHR, or if context was not created against the same Direct3D 10 device from which resource was created", "the Direct3D 10 texture format of resource is not a value listed in the above table of Direct3D 10 and corresponding OpenCL image formats, or if the Direct3D 10 texture format of resource does not map to a supported OpenCL image format", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[9].errVals = t_errVals9;
    mess[9].errMessages = t_errMessages9;
    mess[9].numMessages = 5;

    static const int t_errVals10[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_D3D11_RESOURCE_KHR, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages10[] = {"context is not a valid context", "values specified in flags are not valid", "resource is not a Direct3D 11 buffer resource, if resource was created with the D3D11_USAGE flag D3D11_USAGE_IMMUTABLE, if a cl_mem from resource has already been created using clCreateFromD3D11BufferKHR, or if context was not created against the same Direct3D 11 device from which resource was created", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[10].errVals = t_errVals10;
    mess[10].errMessages = t_errMessages10;
    mess[10].numMessages = 4;

    static const int t_errVals11[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_D3D11_RESOURCE_KHR, CL_INVALID_IMAGE_FORMAT_DESCRIPTOR, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages11[] = {"context is not a valid context", "values specified in flags are not valid or if subresource is not a valid subresource index for resource", "resource is not a Direct3D 11 texture resource, if resource was created with the D3D11_USAGE flag D3D11_USAGE_IMMUTABLE, if a resource is a multisampled texture, if cl_mem from subresource subresource of resource has already been created using clCreateFromD3D11Texture2DKHR, or if context was not created against the same Direct3D 11 device from which resource was created OR resource is not a Direct3D 11 texture object", "the Direct3D 11 texture format of resource is not a value listed in the table of Direct3D 11 and corresponding OpenCL image formats for clCreateFromD3D11Texture3DKHR, or if the Direct3D 11 texture format of resource does not map to a supported OpenCL image format", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[11].errVals = t_errVals11;
    mess[11].errMessages = t_errMessages11;
    mess[11].numMessages = 5;

    static const int t_errVals12[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_D3D11_RESOURCE_KHR, CL_INVALID_IMAGE_FORMAT_DESCRIPTOR, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages12[] = {"context is not a valid context", "values specified in flags are not valid or if subresource is not a valid subresource index for resource", "resource is not a Direct3D 11 texture resource, if resource was created with the D3D11_USAGE flag D3D11_USAGE_IMMUTABLE, if a resource is a multisampled texture, if cl_mem from subresource subresource of resource has already been created using clCreateFromD3D11Texture3DKHR, or if context was not created against the same Direct3D 11 device from which resource was created OR resource is not a Direct3D 11 texture object", "the Direct3D 11 texture format of resource is not a value listed in the table above of Direct3D 11 and corresponding OpenCL image formats for clCreateFromD3D11Texture3DKHR, or if the Direct3D 11 texture format of resource does not map to a supported OpenCL image format", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[12].errVals = t_errVals12;
    mess[12].errMessages = t_errMessages12;
    mess[12].numMessages = 5;

    static const int t_errVals13[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_DX9_MEDIA_SURFACE_KHR, CL_INVALID_IMAGE_FORMAT_DESCRIPTOR, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages13[] = {"context is not a valid context", "values specified in flags are not valid or if plane is not a valid plane of resource specified in surface_info.", "resource specified in surface_info is not a valid resource or is not associated with adapter_type (e.g., adapter_type is set to CL_ADAPTER_D3D9_KHR and resource is not a Direct3D 9 surface created in D3DPOOL_DEFAULT) OR shared_handle specified in surface_info is not NULL or a valid handle value", "the texture format of resource is not listed in tables 9.10.3 and 9.10.4", "there are no devices in context that support adapter_type", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[13].errVals = t_errVals13;
    mess[13].errMessages = t_errMessages13;
    mess[13].numMessages = 7;

    static const int t_errVals14[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_GL_OBJECT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages14[] = {"context is not a valid context or was not created from a GL context", "values specified in flags are not valid", "bufobj is not a GL buffer object or is a GL buffer object but does not have an existing data store e or the size of the buffer is 0. ", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[14].errVals = t_errVals14;
    mess[14].errMessages = t_errMessages14;
    mess[14].numMessages = 5;

    static const int t_errVals15[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_GL_OBJECT, CL_INVALID_IMAGE_FORMAT_DESCRIPTOR, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages15[] = {"context is not a valid context or was not created from a GL context", "values specified in flags are not valid", "renderbuffer is not a GL renderbuffer object or if the width or height of renderbuffer is zero", "the OpenGL renderbuffer internal format does not map to a supported OpenCL image format", "renderbuffer is a multi-sample GL renderbuffer object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[15].errVals = t_errVals15;
    mess[15].errMessages = t_errMessages15;
    mess[15].numMessages = 7;

    static const int t_errVals16[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_MIP_LEVEL, CL_INVALID_GL_OBJECT, CL_INVALID_IMAGE_FORMAT_DESCRIPTOR, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages16[] = {"context is not a valid context or was not created from a GL context", "values specified in flags are not valid or if value specified in texture_target is not one of the values specified in the description of texture_target", "miplevel is less than the value of levelbase (for OpenGL implementations) or zero (for OpenGL ES implementations); or greater than the value of q (for both OpenGL and OpenGL ES). levelbase and q are defined for the texture in section 3.8.10 (Texture Completeness) of the OpenGL 2.1 specification and section 3.7.10 of the OpenGL ES 2.0 OR miplevel is greater than zero and the OpenGL implementation does not support creating from non-zero mipmap levels", "texture is not a GL texture object whose type matches texture_target, if the specified miplevel of texture is not defined, or if the width or height of the specified miplevel is zero", "the OpenGL texture internal format does not map to a supported OpenCL image format", "texture is a GL texture object created with a border width value greater than zero", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[16].errVals = t_errVals16;
    mess[16].errMessages = t_errMessages16;
    mess[16].numMessages = 8;

    static const int t_errVals17[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_IMAGE_FORMAT_DESCRIPTOR, CL_INVALID_IMAGE_DESCRIPTOR, CL_INVALID_IMAGE_SIZE, CL_INVALID_HOST_PTR, CL_IMAGE_FORMAT_NOT_SUPPORTED, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages17[] = {"context is not a valid context", "values specified in flags are not valid OR a 1D image buffer is being created and the buffer object was created with CL_MEM_WRITE_ONLY and flags specifies CL_MEM_READ_WRITE or CL_MEM_READ_ONLY, or if the buffer object was created with CL_MEM_READ_ONLY and flags specifies CL_MEM_READ_WRITE or CL_MEM_WRITE_ONLY, or if flags specifies CL_MEM_USE_HOST_PTR or CL_MEM_ALLOC_HOST_PTR or CL_MEM_COPY_HOST_PTR OR a 1D image buffer is being created and the buffer object was created with CL_MEM_HOST_WRITE_ONLY and flags specifies CL_MEM_HOST_READ_ONLY, or if the buffer object was created with CL_MEM_HOST_READ_ONLY and flags specifies CL_MEM_HOST_WRITE_ONLY, or if the buffer object was created with CL_MEM_HOST_NO_ACCESS and flags specifies CL_MEM_HOST_READ_ONLY or CL_MEM_HOST_WRITE_ONLY", "values specified in image_format are not valid or if image_format is NULL", "values specified in image_desc are not valid or if image_desc is NULL", "image dimensions specified in image_desc exceed the minimum maximum image dimensions described in the table of allowed values for param_name for clGetDeviceInfo for all devices in context", "host_ptr in image_desc is NULL and CL_MEM_USE_HOST_PTR or CL_MEM_COPY_HOST_PTR are set in flags or if host_ptr is not NULL but CL_MEM_COPY_HOST_PTR or CL_MEM_USE_HOST_PTR are not set in flags", "the image_format is not supported", "there is a failure to allocate memory for image object", "there are no devices in context that support images (i.e. CL_DEVICE_IMAGE_SUPPORT (specified in the table of OpenCL Device Queries for clGetDeviceInfo) is CL_FALSE)", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[17].errVals = t_errVals17;
    mess[17].errMessages = t_errMessages17;
    mess[17].numMessages = 11;

    static const int t_errVals18[] = {CL_INVALID_PROGRAM, CL_INVALID_PROGRAM_EXECUTABLE, CL_INVALID_KERNEL_NAME, CL_INVALID_KERNEL_DEFINITION, CL_INVALID_VALUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages18[] = {"program is not a valid program object", "there is no successfully built executable for program", "kernel_name is not found in program", "the function definition for __kernel function given by kernel_name such as the number of arguments, the argument types are not the same for all devices for which the program executable has been built", "kernel_name is NULL", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[18].errVals = t_errVals18;
    mess[18].errMessages = t_errMessages18;
    mess[18].numMessages = 7;

    static const int t_errVals19[] = {CL_INVALID_PROGRAM, CL_INVALID_PROGRAM_EXECUTABLE, CL_INVALID_VALUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages19[] = {"program is not a valid program object", "there is no successfully built executable for any device in program", "kernels is not NULL and num_kernels is less than the number of kernels in program", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[19].errVals = t_errVals19;
    mess[19].errMessages = t_errMessages19;
    mess[19].numMessages = 5;

    static const int t_errVals20[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_DEVICE, CL_INVALID_BINARY, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages20[] = {"context is not a valid context", "device_list is NULL or num_devices is zero OR or if lengths or binaries are NULL or if any entry in lengths[i] or binaries[i] is NULL", "OpenCL devices listed in device_list are not in the list of devices associated with context", "an invalid program binary was encountered for any device. binary_status will return specific status for each device", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[20].errVals = t_errVals20;
    mess[20].errMessages = t_errMessages20;
    mess[20].numMessages = 6;

    static const int t_errVals21[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_DEVICE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages21[] = {"context is not a valid context", "device_list is NULL or num_devices is zero OR kernel_names is NULL or kernel_names contains a kernel name that is not supported by any of the devices in device_list", "devices listed in device_list are not in the list of devices associated with context", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[21].errVals = t_errVals21;
    mess[21].errMessages = t_errMessages21;
    mess[21].numMessages = 5;

    static const int t_errVals22[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages22[] = {"context is not a valid context", "count is zero or if strings or any entry in strings is NULL", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[22].errVals = t_errVals22;
    mess[22].errMessages = t_errMessages22;
    mess[22].numMessages = 4;

    static const int t_errVals23[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages23[] = {"context is not a valid context", "addressing_mode, filter_mode, or normalized_coords or a combination of these argument values are not valid", "images are not supported by any device associated with context (i.e. CL_DEVICE_IMAGE_SUPPORT specified in the table of OpenCL Device Queries for clGetDeviceInfo is CL_FALSE)", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[23].errVals = t_errVals23;
    mess[23].errMessages = t_errMessages23;
    mess[23].numMessages = 5;

    static const int t_errVals24[] = {CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_BUFFER_SIZE, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages24[] = {"buffer is not a valid buffer object or is a sub-buffer object", "buffer was created with CL_MEM_WRITE_ONLY and flags specifies CL_MEM_READ_WRITE or CL_MEM_READ_ONLY, or if buffer was created with CL_MEM_READ_ONLY and flags specifies CL_MEM_READ_WRITE or CL_MEM_WRITE_ONLY, or if flags specifies CL_MEM_USE_HOST_PTR or CL_MEM_ALLOC_HOST_PTR or CL_MEM_COPY_HOST_PTR OR buffer was created with CL_MEM_HOST_WRITE_ONLY and flags specifies CL_MEM_HOST_READ_ONLY or if buffer was created with CL_MEM_HOST_READ_ONLY and flags specifies CL_MEM_HOST_WRITE_ONLY, or if buffer was created with CL_MEM_HOST_NO_ACCESS and flags specifies CL_MEM_HOST_READ_ONLY or CL_MEM_HOST_WRITE_ONLY OR value specified in buffer_create_type is not valid OR value(s) specified in buffer_create_info (for a given buffer_create_type) is not valid or if buffer_create_info is NULL", "size is 0", "there is a failure to allocate memory for sub-buffer object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[24].errVals = t_errVals24;
    mess[24].errMessages = t_errMessages24;
    mess[24].numMessages = 6;

    static const int t_errVals25[] = {CL_INVALID_DEVICE, CL_INVALID_VALUE, CL_DEVICE_PARTITION_FAILED, CL_INVALID_DEVICE_PARTITION_COUNT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages25[] = {"in_device is not valid", "values specified in properties are not valid or if values specified in properties are valid but not supported by the device OR out_devices is not NULL and num_devices is less than the number of sub-devices created by the partition scheme", "the partition name is supported by the implementation but in_device could not be further partitioned", "the partition name specified in properties is CL_DEVICE_PARTITION_BY_COUNTS and the number of sub-devices requested exceeds CL_DEVICE_PARTITION_MAX_SUB_DEVICES or the total number of compute units requested exceeds CL_DEVICE_PARTITION_MAX_COMPUTE_UNITS for in_device, or the number of compute units requested for one or more sub-devices is less than zero or the number of sub-devices requested exceeds CL_DEVICE_PARTITION_MAX_COMPUTE_UNITS for in_device", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[25].errVals = t_errVals25;
    mess[25].errMessages = t_errMessages25;
    mess[25].numMessages = 6;

    static const int t_errVals26[] = {CL_INVALID_CONTEXT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages26[] = {"context is not a valid context", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[26].errVals = t_errVals26;
    mess[26].errMessages = t_errMessages26;
    mess[26].numMessages = 3;

    static const int t_errVals27[] = {CL_INVALID_VALUE, CL_INVALID_MEM_OBJECT, CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_D3D10_RESOURCE_ALREADY_ACQUIRED_KHR, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages27[] = {"num_objects is zero and mem_objects is not a NULL value or if num_objects &gt; 0 and mem_objects is NULL", "memory objects in mem_objects are not valid OpenCL memory objects or if memory objects in mem_objects have not been created from Direct3D 10 resources", "command_queue is not a valid command-queue", "context associated with command_queue was not created from an Direct3D 10 context", "memory objects in mem_objects is not have previously been acquired using clEnqueueAcquireD3D10ObjectsKHR but have not been released using clEnqueueReleaseD3D10ObjectsKHR", "event_wait_list is NULL and num_event_in_wait_list &gt; 0, or event_wait_list is not NULL and num_event_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[27].errVals = t_errVals27;
    mess[27].errMessages = t_errMessages27;
    mess[27].numMessages = 7;

    static const int t_errVals28[] = {CL_INVALID_VALUE, CL_INVALID_MEM_OBJECT, CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_D3D11_RESOURCE_ALREADY_ACQUIRED_KHR, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages28[] = {"num_objects is zero and mem_objects is not a NULL value or if num_objects &gt; 0 and mem_objects is NULL", "memory objects in mem_objects are not valid OpenCL memory objects or if memory objects in mem_objects have not been created from Direct3D 11 resources", "command_queue is not a valid command-queue", "context associated with command_queue was not created from a Direct3D 11 context", "memory objects in mem_objects have previously been acquired using clEnqueueAcquireD3D11ObjectsKHR but have not been released using clEnqueueReleaseD3D11ObjectsKHR OR when any of mem_objectsare currently acquired by OpenCL", "event_wait_list is NULL and num_event_in_wait_list &gt; 0, or event_wait_list is not NULL and num_event_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[28].errVals = t_errVals28;
    mess[28].errMessages = t_errMessages28;
    mess[28].numMessages = 7;

    static const int t_errVals29[] = {CL_INVALID_VALUE, CL_INVALID_MEM_OBJECT, CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_DX9_MEDIA_SURFACE_ALREADY_ACQUIRED_KHR, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages29[] = {"num_objects is zero and mem_objects is not a NULL value or if num_objects &gt; 0 and mem_objects is NULL", "memory objects in mem_objects are not valid OpenCL memory objects or if memory objects in mem_objects have not been created from media surfaces", "command_queue is not a valid command-queue", "context associated with command_queue was not created from a device that can share the media surface referenced by mem_objects", "memory objects in mem_objects have previously been acquired using clEnqueueAcquireDX9MediaSurfacesKHR but have not been released using clEnqueueReleaseDX9MediaSurfacesKHR", "event_wait_list is NULL and num_event_in_wait_list &gt; 0, or event_wait_list is not NULL and num_event_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[29].errVals = t_errVals29;
    mess[29].errMessages = t_errMessages29;
    mess[29].numMessages = 7;

    static const int t_errVals30[] = {CL_INVALID_VALUE, CL_INVALID_MEM_OBJECT, CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_GL_OBJECT, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages30[] = {"num_objects is zero and mem_objects is not a NULL value or if num_objects &gt; 0 and mem_objects is NULL", "memory objects in mem_objects are not valid OpenCL memory objects", "command_queue is not a valid command-queue", "context associated with command_queue was not created from an OpenGL context", "memory objects in mem_objects have not been created from a GL object(s)", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[30].errVals = t_errVals30;
    mess[30].errMessages = t_errMessages30;
    mess[30].numMessages = 8;

    static const int t_errVals31[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages31[] = {"command_queue is not a valid command-queue", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[31].errVals = t_errVals31;
    mess[31].errMessages = t_errMessages31;
    mess[31].numMessages = 4;

    static const int t_errVals32[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MISALIGNED_SUB_BUFFER_OFFSET , CL_MEM_COPY_OVERLAP, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages32[] = {"command_queue is not a valid command-queue", "the context associated with command_queue, src_buffer, and dst_buffer are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "src_buffer and dst_buffer are not valid buffer objects", "src_offset, dst_offset, size, src_offset + size, or dst_offset + size require accessing elements outside the src_buffer and dst_buffer buffer objects respectively OR size is 0", "event_wait_list is NULL and num_events_in_wait_list is &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "src_buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue OR dst_buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "src_buffer and dst_buffer are the same buffer or subbuffer object and the source and destination regions overlap or if src_buffer and dst_buffer are different sub-buffers of the same associated buffer object and they overlap. The regions overlap if src_offset ≤ to dst_offset ≤ to src_offset + size - 1, or if dst_offset ≤ to src_offset ≤ to dst_offset + size - 1", "there is a failure to allocate memory for data store associated with src_buffer or dst_buffer", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[32].errVals = t_errVals32;
    mess[32].errMessages = t_errMessages32;
    mess[32].numMessages = 10;

    static const int t_errVals33[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MEM_COPY_OVERLAP, CL_MISALIGNED_SUB_BUFFER_OFFSET , CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages33[] = {"command_queue is not a valid command-queue", "the context associated with command_queue, src_buffer, and dst_buffer are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "src_buffer and dst_buffer are not valid buffer objects", "(src_offset, region) or (dst_offset, region) require accessing elements outside the src_buffer and dst_buffer objects respectively OR any region array element is 0 OR src_row_pitch is not 0 and is less than region[0] OR dst_row_pitch is not 0 and is less than region[0] OR src_slice_pitch is not 0 and is less than region[1] * src_row_pitch or if src_slice_pitch is not 0 and is not a multiple of src_row_pitch OR dst_slice_pitch is not 0 and is less than region[1] * dst_row_pitch or if dst_slice_pitch is not 0 and is not a multiple of dst_row_pitch OR src_buffer and dst_buffer are the same buffer object and src_slice_pitch is not equal to dst_slice_pitch and src_row_pitch is not equal to dst_row_pitch", "event_wait_list is NULL and num_events_in_wait_list is &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "src_buffer and dst_buffer are the same buffer object and the source and destination regions overlap or if src_buffer and dst_buffer are different sub-buffers of the same associated buffer object and they overlap. Refer to Appendix E in the OpenCL specification for details on how to determine if source and destination regions overlap", "src_buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue OR dst_buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "there is a failure to allocate memory for data store associated with src_buffer or dst_buffer", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[33].errVals = t_errVals33;
    mess[33].errMessages = t_errMessages33;
    mess[33].numMessages = 10;

    static const int t_errVals34[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MISALIGNED_SUB_BUFFER_OFFSET, CL_INVALID_IMAGE_SIZE, CL_INVALID_IMAGE_FORMAT, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages34[] = {"command_queue is not a valid command-queue", "the context associated with command_queue, src_buffer and dst_image are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "src_buffer is not a valid buffer object and dst_image is not a valid image object or if dst_image is a 1D image buffer object created from src_buffer", "the 1D, 2D, or 3D rectangular region specified by dst_origin and dst_origin + region refers to a region outside dst_origin, or if the region specified by src_offset and src_offset + src_cb refers to a region outside src_buffer OR values in dst_origin and region do not follow rules described in the argument description for dst_origin and region", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "src_buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "image dimensions (image width, height, specified or compute row and/or slice pitch) for dst_image are not supported by device associated with queue", "image format (image channel order and data type) for dst_image are not supported by device associated with queue", "there is a failure to allocate memory for data store associated with src_buffer or dst_image", "the device associated with command_queue does not support images (i.e. CL_DEVICE_IMAGE_SUPPORT specified in the table of OpenCL Device Queries for clGetDeviceInfo is CL_FALSE)", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[34].errVals = t_errVals34;
    mess[34].errMessages = t_errMessages34;
    mess[34].numMessages = 12;

    static const int t_errVals35[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_IMAGE_FORMAT_MISMATCH, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_INVALID_IMAGE_SIZE, CL_INVALID_IMAGE_FORMAT, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY, CL_INVALID_OPERATION, CL_MEM_COPY_OVERLAP};
    static const char *t_errMessages35[] = {"command_queue is not a valid command-queue", "the context associated with command_queue, src_image and dst_image are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "src_image and dst_image are not valid image objects", "src_image and dst_image do not use the same image format", "the 2D or 3D rectangular region specified by src_origin and src_origin + region refers to a region outside src_image, or if the 2D or 3D rectangular region specified by dst_origin and dst_origin + region refers to a region outside dst_image OR values in src_origin, dst_origin and region do not follow rules described in the argument description for src_origin, dst_origin and region", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "image dimensions (image width, height, specified or compute row and/or slice pitch) for src_image or dst_image are not supported by device associated with queue", "image format (image channel order and data type) for src_image or dst_image are not supported by device associated with queue", "there is a failure to allocate memory for data store associated with src_image or dst_image", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host", "the device associated with command_queue does not support images (i.e. CL_DEVICE_IMAGE_SUPPORT specified in the table of OpenCL Device Queries for clGetDeviceInfo is CL_FALSE)", "src_image and dst_image are the same image object and the source and destination regions overlap"};
    mess[35].errVals = t_errVals35;
    mess[35].errMessages = t_errMessages35;
    mess[35].numMessages = 13;

    static const int t_errVals36[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MISALIGNED_SUB_BUFFER_OFFSET, CL_INVALID_IMAGE_SIZE, CL_INVALID_IMAGE_FORMAT, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages36[] = {"command_queue is not a valid command-queue", "the context associated with command_queue, src_image and dst_buffer are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "src_image is not a valid image object or dst_buffer is not a valid buffer object or if src_image is a 1D image buffer object created from dst_buffer", "the 1D, 2D, or 3D rectangular region specified by src_origin and src_origin + region refers to a region outside src_image, or if the region specified by dst_offset and dst_offset + dst_cb refers to a region outside dst_buffer OR values in src_origin and region do not follow rules described in the argument description for src_origin and region", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "dst_buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "image dimensions (image width, height, specified or compute row and/or slice pitch) for src_image are not supported by device associated with queue", "image format (image channel order and data type) for src_image are not supported by device associated with queue", "there is a failure to allocate memory for data store associated with src_image or dst_buffer", "the device associated with command_queue does not support images (i.e. CL_DEVICE_IMAGE_SUPPORT specified in the table of OpenCL Device Queries for clGetDeviceInfo is CL_FALSE)", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[36].errVals = t_errVals36;
    mess[36].errMessages = t_errMessages36;
    mess[36].numMessages = 12;

    static const int t_errVals37[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MISALIGNED_SUB_BUFFER_OFFSET, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages37[] = {"command_queue is not a valid command-queue", "the context associated with command_queue and buffer are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "buffer is not a valid buffer object", "offset or offset + size require accessing elements outside the buffer buffer object respectively OR pattern is NULL or if pattern_size is 0 or if pattern_size is not one of {1, 2, 4, 8, 16, 32, 64, 128} OR offset and size are not a multiple of pattern_size", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "there is a failure to allocate memory for data store associated with buffer", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[37].errVals = t_errVals37;
    mess[37].errMessages = t_errMessages37;
    mess[37].numMessages = 9;

    static const int t_errVals38[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_INVALID_IMAGE_SIZE, CL_INVALID_IMAGE_FORMAT, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages38[] = {"command_queue is not a valid command-queue", "the context associated with command_queue and image are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "image is not a valid image object", "fill_color is NULL OR the region being written specified by origin and region is out of bounds or if ptr is a NULL value OR values in origin and region do not follow rules described in the argument description for origin and region", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "image dimensions (image width, height, specified or compute row and/or slice pitch) for image are not supported by device associated with queue", "image format (image channel order and data type) for image are not supported by device associated with queue", "there is a failure to allocate memory for data store associated with image", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[38].errVals = t_errVals38;
    mess[38].errMessages = t_errMessages38;
    mess[38].numMessages = 10;

    static const int t_errVals39[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MISALIGNED_SUB_BUFFER_OFFSET, CL_MAP_FAILURE, CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages39[] = {"command_queue is not a valid command-queue", "the context associated with command_queue and image are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "image is not a valid image object", "region being mapped given by (offset, size) is out of bounds or if size is 0 or values specified in map_flags are not valid", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "there is a failure to map the requested region into the host address space. This error cannot occur for image objects created with CL_MEM_USE_HOST_PTR or CL_MEM_ALLOC_HOST_PTR", "the map operation is blocking and the execution status of any of the events in event_wait_list is a negative integer value", "there is a failure to allocate memory for data store associated with buffer", "buffer has been created with CL_MEM_HOST_WRITE_ONLY or CL_MEM_HOST_NO_ACCESS and CL_MAP_READ is set in map_flags or if buffer has been created with CL_MEM_HOST_READ_ONL or CL_MEM_HOST_NO_ACCESS and CL_MAP_WRITE or CL_MAP_WRITE_INVALIDATE_REGION is set in map_flags", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[39].errVals = t_errVals39;
    mess[39].errMessages = t_errMessages39;
    mess[39].numMessages = 12;

    static const int t_errVals40[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_INVALID_IMAGE_SIZE, CL_INVALID_IMAGE_FORMAT, CL_MAP_FAILURE, CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages40[] = {"command_queue is not a valid command-queue", "the context associated with command_queue and image are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "image is not a valid image object", "region being mapped given by (origin, origin+region) is out of bounds or if values specified in map_flags are not valid OR values in origin and region do not follow rules described in the argument description for origin and region OR image_row_pitch is NULL OR image is a 3D image, 1D or 2D image array object and image_slice_pitch is NULL", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "image dimensions (image width, height, specified or compute row and/or slice pitch) for image are not supported by device associated with queue", "image format (image channel order and data type) for image are not supported by device associated with queue", "there is a failure to map the requested region into the host address space. This error cannot occur for image objects created with CL_MEM_USE_HOST_PTR or CL_MEM_ALLOC_HOST_PTR", "the map operation is blocking and the execution status of any of the events in event_wait_list is a negative integer value", "there is a failure to allocate memory for data store associated with buffer", "the device associated with command_queue does not support images (i.e. CL_DEVICE_IMAGE_SUPPORT specified in the table of OpenCL Device Queries for clGetDeviceInfo is CL_FALSE OR image has been created with CL_MEM_HOST_WRITE_ONLY or CL_MEM_HOST_NO_ACCESS and CL_MAP_READ is set in map_flags or if image has been created with CL_MEM_HOST_READ_ONLY or CL_MEM_HOST_NO_ACCESS and CL_MAP_WRITE or CL_MAP_WRITE_INVALIDATE_REGION is set in map_flags", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[40].errVals = t_errVals40;
    mess[40].errMessages = t_errMessages40;
    mess[40].numMessages = 13;

    static const int t_errVals41[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages41[] = {"command_queue is not a valid command-queue", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[41].errVals = t_errVals41;
    mess[41].errMessages = t_errMessages41;
    mess[41].numMessages = 4;

    static const int t_errVals42[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages42[] = {"command_queue is not a valid command_queue", "the context associated with command_queue and memory objects in memobj are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "any of the memory objects in mem_objs is not a valid memory object", "num_mem_objects is zero or if mem_objects is NULL OR flags is not 0 or is not any of the values described in the table above", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate memory for the specified set of memory objects in mem_objects", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[42].errVals = t_errVals42;
    mess[42].errMessages = t_errMessages42;
    mess[42].numMessages = 8;

    static const int t_errVals43[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_OPERATION, CL_INVALID_MEM_OBJECT, CL_OUT_OF_RESOURCES, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages43[] = {"command_queue is not a valid command-queue", "context associated with command_queue and events in event-wait_list are not the same", "user_func is NULL OR args is a NULL value and cb_args &gt; 0, or if args is a NULL value and num_mem_objects &gt; 0 OR args is not NULL and cb_args is 0 OR num_mem_objects &gt; 0 and mem_list or args_mem_loc are NULL OR num_mem_objects = 0 and mem_list or args_mem_loc are not NULL", "the device associated with command_queue cannot execute the native kernel", "one or more memory objects specified in mem_list are not valid or are not buffer objects", "there is a failure to queue the execution instance of kernel on the command-queue because of insufficient resources needed to execute the kernel OR there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate memory for data store associated with buffer objects specified as arguments to kernel", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[43].errVals = t_errVals43;
    mess[43].errMessages = t_errMessages43;
    mess[43].numMessages = 9;

    static const int t_errVals44[] = {CL_INVALID_PROGRAM_EXECUTABLE, CL_INVALID_COMMAND_QUEUE, CL_INVALID_KERNEL, CL_INVALID_CONTEXT, CL_INVALID_KERNEL_ARGS, CL_INVALID_WORK_DIMENSION, CL_INVALID_GLOBAL_WORK_SIZE, CL_INVALID_GLOBAL_OFFSET, CL_INVALID_WORK_GROUP_SIZE, CL_INVALID_WORK_ITEM_SIZE, CL_MISALIGNED_SUB_BUFFER_OFFSET, CL_INVALID_IMAGE_SIZE, CL_INVALID_IMAGE_FORMAT, CL_OUT_OF_RESOURCES, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages44[] = {"there is no successfully built program executable available for device associated with command_queue", "command_queue is not a valid command-queue", "kernel is not a valid kernel object", "context associated with command_queue and kernel is not the same or if the context associated with command_queue and events in event_wait_list are not the same", "the kernel argument values have not been specified", "work_dim is not a valid value (i.e. a value between 1 and 3)", "global_work_size is NULL, or if any of the values specified in global_work_size[0], ...global_work_size [work_dim - 1] are 0 or exceed the range given by the sizeof(size_t) for the device on which the kernel execution will be enqueued", "the value specified in global_work_size + the corresponding values in global_work_offset for any dimensions is greater than the sizeof(size_t) for the device on which the kernel execution will be enqueued", "local_work_size is specified and number of work-items specified by global_work_size is not evenly divisable by size of work-group given by local_work_size or does not match the work-group size specified for kernel using the  __attribute__ ((reqd_work_group_size(X, Y, Z))) qualifier in program source OR local_work_size is specified and the total number of work-items in the work-group computed as local_work_size[0] *... local_work_size[work_dim - 1] is greater than the value specified by CL_DEVICE_MAX_WORK_GROUP_SIZE in the table of OpenCL Device Queries for clGetDeviceInfo OR local_work_size is NULL and the __attribute__ ((reqd_work_group_size(X, Y, Z))) qualifier is used to declare the work-group size for kernel in the program source", "the number of work-items specified in any of local_work_size[0], ... local_work_size[work_dim - 1] is greater than the corresponding values specified by CL_DEVICE_MAX_WORK_ITEM_SIZES[0], .... CL_DEVICE_MAX_WORK_ITEM_SIZES[work_dim - 1]", "a sub-buffer object is specified as the value for an argument that is a buffer object and the offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "an image object is specified as an argument value and the image dimensions (image width, height, specified or compute row and/or slice pitch) are not supported by device associated with queue", "an image object is specified as an argument value and the image format (image channel order and data type) is not supported by device associated with queue", "there is a failure to queue the execution instance of kernel on the command-queue because of insufficient resources needed to execute the kernel. For example, the explicitly specified local_work_size causes a failure to execute the kernel because of insufficient resources such as registers or local memory. Another example would be the number of read-only image args used in kernel exceed the CL_DEVICE_MAX_READ_IMAGE_ARGS value for device or the number of write-only image args used in kernel exceed the CL_DEVICE_MAX_WRITE_IMAGE_ARGS value for device or the number of samplers used in kernel exceed CL_DEVICE_MAX_SAMPLERS for device OR there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate memory for data store associated with image or buffer objects specified as arguments to kernel", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[44].errVals = t_errVals44;
    mess[44].errMessages = t_errMessages44;
    mess[44].numMessages = 17;

    static const int t_errVals45[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MISALIGNED_SUB_BUFFER_OFFSET, CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages45[] = {"command_queue is not a valid command-queue", "the context associated with command_queue and buffer are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "buffer is not a valid buffer object", "the region being read specified by (offset, size) is out of bounds or if ptr is a NULL value or if size is 0", "event_wait_list is NULL and num_events_in_wait_list greater than 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "the read and write operations are blocking and the execution status of any of the events in event_wait_list is a negative integer value", "there is a failure to allocate memory for data store associated with buffer", "clEnqueueReadBuffer is called on buffer which has been created with CL_MEM_HOST_WRITE_ONLY or CL_MEM_HOST_NO_ACCESS", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[45].errVals = t_errVals45;
    mess[45].errMessages = t_errMessages45;
    mess[45].numMessages = 11;

    static const int t_errVals46[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MISALIGNED_SUB_BUFFER_OFFSET, CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages46[] = {"command_queue is not a valid command-queue", "the context associated with command_queue and buffer are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "buffer is not a valid buffer object", "the region being read specified by (buffer_origin, region, buffer_row_pitch, buffer_slice_pitch) is out of bounds OR ptr is a NULL value OR any region array element is 0 OR buffer_row_pitch is not 0 and is less than region[0] OR host_row_pitch is not 0 and is less than region[0] OR buffer_slice_pitch is not 0 and is less than region[1] * buffer_row_pitch and not a multiple of buffer_row_pitch OR host_slice_pitch is not 0 and is less than region[1] * host_row_pitch and not a multiple of host_row_pitch", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "the read and write operations are blocking and the execution status of any of the events in event_wait_list is a negative integer value", "there is a failure to allocate memory for data store associated with buffer", "clEnqueueReadBufferRect is called on buffer which has been created with CL_MEM_HOST_WRITE_ONLY or CL_MEM_HOST_NO_ACCESS", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[46].errVals = t_errVals46;
    mess[46].errMessages = t_errMessages46;
    mess[46].numMessages = 11;

    static const int t_errVals47[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_INVALID_IMAGE_SIZE, CL_INVALID_IMAGE_FORMAT, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages47[] = {"command_queue is not a valid command-queue", "the context associated with command_queue and image are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "image is not a valid image object", "the region being read specified by origin and region is out of bounds or if ptr is a NULL value OR values in origin and region do not follow rules described in the argument description for origin and region", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "image dimensions (image width, height, specified or compute row and/or slice pitch) for image are not supported by device associated with queue", "image format (image channel order and data type) for image are not supported by device associated with queue", "there is a failure to allocate memory for data store associated with image", "the device associated with command_queue does not support images (i.e. CL_DEVICE_IMAGE_SUPPORT specified in the table of allowed values for param_name for clGetDeviceInfo is CL_FALSE) OR clEnqueueReadImage is called on image which has been created with CL_MEM_HOST_WRITE_ONLY or CL_MEM_HOST_NO_ACCE", "the read and write operations are blocking and the execution status of any of the events in event_wait_list is a negative integer value", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[47].errVals = t_errVals47;
    mess[47].errMessages = t_errMessages47;
    mess[47].numMessages = 12;

    static const int t_errVals48[] = {CL_INVALID_VALUE, CL_INVALID_MEM_OBJECT, CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_D3D10_RESOURCE_NOT_ACQUIRED_KHR, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages48[] = {"num_objects is zero and mem_objects is not a NULL value or if num_objects &gt; 0 and mem_objects is NULL", "memory objects in mem_objects are not valid OpenCL memory objects or if memory objects in mem_objects have not been created from Direct3D 10 resources", "command_queue is not a valid command-queue", "context associated with command_queue was not created from an Direct3D 10 context", "memory objects in mem_objects have not previously been acquired using clEnqueueAcquireD3D10ObjectsKHR, or have been released using clEnqueueReleaseD3D10ObjectsKHR since the last time that they were acquired", "event_wait_list is NULL and num_event_in_wait_list &gt; 0, or event_wait_list is not NULL and num_event_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[48].errVals = t_errVals48;
    mess[48].errMessages = t_errMessages48;
    mess[48].numMessages = 7;

    static const int t_errVals49[] = {CL_INVALID_VALUE, CL_INVALID_MEM_OBJECT, CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_D3D11_RESOURCE_NOT_ACQUIRED_KHR, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages49[] = {"num_objects is zero and mem_objects is not a NULL value or if num_objects &gt; 0 and mem_objects is NULL", "memory objects in mem_objects are not valid OpenCL memory objects or if memory objects in mem_objects have not been created from Direct3D 11 resources", "command_queue is not a valid command-queue", "context associated with command_queue was not created from a Direct3D 11 context", "memory objects in mem_objects have not previously been acquired using clEnqueueAcquireD3D11ObjectsKHR, or have been released using clEnqueueReleaseD3D11ObjectsKHR since the last time that they were acquired", "event_wait_list is NULL and num_event_in_wait_list &gt; 0, or event_wait_list is not NULL and num_event_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[49].errVals = t_errVals49;
    mess[49].errMessages = t_errMessages49;
    mess[49].numMessages = 7;

    static const int t_errVals50[] = {CL_INVALID_VALUE, CL_INVALID_MEM_OBJECT, CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_DX9_MEDIA_SURFACE_NOT_ACQUIRED_KHR, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages50[] = {"num_objects is zero and mem_objects is not a NULL value or if num_objects &gt; 0 and mem_objects is NULL", "memory objects in mem_objects are not valid OpenCL memory objects or if memory objects in mem_objects have not been created from media surfaces", "command_queue is not a valid command-queue", "context associated with command_queue was not created from a media object", "memory objects in mem_objects have not been previously been acquired using clEnqueueAcquireDX9MediaSurfacesKHR or have been released using clEnqueueReleaseDX9MediaSurfacesKHR since the last time that they were acquired", "event_wait_list is NULL and num_event_in_wait_list &gt; 0, or event_wait_list is not NULL and num_event_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[50].errVals = t_errVals50;
    mess[50].errMessages = t_errMessages50;
    mess[50].numMessages = 7;

    static const int t_errVals51[] = {CL_INVALID_VALUE, CL_INVALID_MEM_OBJECT, CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_GL_OBJECT, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages51[] = {"num_objects is zero and mem_objects is not a NULL value or if num_objects &gt; 0 and mem_objects is NULL", "memory objects in mem_objects are not valid OpenCL memory objects", "command_queue is not a valid command-queue", "context associated with command_queue was not created from an OpenGL context", "memory objects in mem_objects have not been created from a GL object(s)", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[51].errVals = t_errVals51;
    mess[51].errMessages = t_errMessages51;
    mess[51].numMessages = 8;

    static const int t_errVals52[] = {CL_INVALID_PROGRAM_EXECUTABLE, CL_INVALID_COMMAND_QUEUE, CL_INVALID_KERNEL, CL_INVALID_CONTEXT, CL_INVALID_KERNEL_ARGS, CL_INVALID_WORK_GROUP_SIZE, CL_MISALIGNED_SUB_BUFFER_OFFSET, CL_INVALID_IMAGE_SIZE, CL_INVALID_IMAGE_FORMAT, CL_OUT_OF_RESOURCES, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages52[] = {"there is no successfully built program executable available for device associated with command_queue", "command_queue is not a valid command-queue", "kernel is not a valid kernel object", "context associated with command_queue and kernel is not the same or if the context associated with command_queue and events in event_wait_list are not the same", "the kernel argument values have not been specified", "a work-group size is specified for kernel using the __attribute__ ((reqd_work_group_size(X, Y, Z))) qualifier in program source and is not (1, 1, 1)", "a sub-buffer object is specified as the value for an argument that is a buffer object and the offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "an image object is specified as an argument value and the image dimensions (image width, height, specified or compute row and/or slice pitch) are not supported by device associated with queue", "an image object is specified as an argument value and the image format (image channel order and data type) is not supported by device associated with queue", "there is a failure to queue the execution instance of kernel on the command-queue because of insufficient resources needed to execute the kernel OR there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate memory for data store associated with image or buffer objects specified as arguments to kernel", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[52].errVals = t_errVals52;
    mess[52].errMessages = t_errMessages52;
    mess[52].numMessages = 13;

    static const int t_errVals53[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY, CL_INVALID_CONTEXT};
    static const char *t_errMessages53[] = {"command_queue is not a valid command-queue", "memobj is not a valid memory object", "mapped_ptr is not a valid pointer returned by clEnqueueMapBuffer or clEnqueueMapImage for memobj", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host", "the context associated with command_queue and memobj are not the same or if the context associated with command_queue and events in event_wait_list are not the same"};
    mess[53].errVals = t_errVals53;
    mess[53].errMessages = t_errMessages53;
    mess[53].numMessages = 7;

    static const int t_errVals54[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MISALIGNED_SUB_BUFFER_OFFSET, CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages54[] = {"command_queue is not a valid command-queue", "the context associated with command_queue and buffer are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "buffer is not a valid buffer object", "the region being written specified by (offset, size) is out of bounds or if ptr is a NULL value or if size is 0", "event_wait_list is NULL and num_events_in_wait_list greater than 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "the read and write operations are blocking and the execution status of any of the events in event_wait_list is a negative integer value", "there is a failure to allocate memory for data store associated with buffer", "clEnqueueWriteBuffer is called on buffer which has been created with CL_MEM_HOST_READ_ONLY or CL_MEM_HOST_NO_ACCESS", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[54].errVals = t_errVals54;
    mess[54].errMessages = t_errMessages54;
    mess[54].numMessages = 11;

    static const int t_errVals55[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_MISALIGNED_SUB_BUFFER_OFFSET, CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages55[] = {"command_queue is not a valid command-queue", "the context associated with command_queue and buffer are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "buffer is not a valid buffer object", "the region being read specified by (buffer_origin, region, buffer_row_pitch, buffer_slice_pitch) is out of bounds OR ptr is a NULL value OR any region array element is 0 OR buffer_row_pitch is not 0 and is less than region[0] OR host_row_pitch is not 0 and is less than region[0] OR buffer_slice_pitch is not 0 and is less than region[1] * buffer_row_pitch and not a multiple of buffer_row_pitch OR host_slice_pitch is not 0 and is less than region[1] * host_row_pitch and not a multiple of host_row_pitch", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "buffer is a sub-buffer object and offset specified when the sub-buffer object is created is not aligned to CL_DEVICE_MEM_BASE_ADDR_ALIGN value for device associated with queue", "the read and write operations are blocking and the execution status of any of the events in event_wait_list is a negative integer value", "there is a failure to allocate memory for data store associated with buffer", "clEnqueueWriteBufferRect is called on buffer which has been created with CL_MEM_HOST_READ_ONLY or CL_MEM_HOST_NO_ACCESS", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[55].errVals = t_errVals55;
    mess[55].errMessages = t_errMessages55;
    mess[55].numMessages = 11;

    static const int t_errVals56[] = {CL_INVALID_COMMAND_QUEUE, CL_INVALID_CONTEXT, CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_INVALID_EVENT_WAIT_LIST, CL_INVALID_IMAGE_SIZE, CL_INVALID_IMAGE_FORMAT, CL_MEM_OBJECT_ALLOCATION_FAILURE, CL_INVALID_OPERATION, CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages56[] = {"command_queue is not a valid command-queue", "the context associated with command_queue and image are not the same or if the context associated with command_queue and events in event_wait_list are not the same", "image is not a valid image object", "the region being written specified by origin and region is out of bounds or if ptr is a NULL value OR values in origin and region do not follow rules described in the argument description for origin and region", "event_wait_list is NULL and num_events_in_wait_list &gt; 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events", "image dimensions (image width, height, specified or compute row and/or slice pitch) for image are not supported by device associated with queue", "image format (image channel order and data type) for image are not supported by device associated with queue", "there is a failure to allocate memory for data store associated with image", "the device associated with command_queue does not support images (i.e. CL_DEVICE_IMAGE_SUPPORT specified the table of allowed values for param_name for clGetDeviceInfo is CL_FALSE) OR clEnqueueWriteImage is called on image which has been created with CL_MEM_HOST_WRITE_ONLY or CL_MEM_HOST_NO_ACCESS", "the write operations are blocking and the execution status of any of the events in event_wait_list is a negative integer value", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[56].errVals = t_errVals56;
    mess[56].errMessages = t_errMessages56;
    mess[56].numMessages = 12;

    static const int t_errVals57[] = {CL_INVALID_COMMAND_QUEUE, CL_OUT_OF_HOST_MEMORY, CL_OUT_OF_RESOURCES};
    static const char *t_errMessages57[] = {"command_queue is not a valid command-queue", "there is a failure to allocate resources required by the OpenCL implementation on the host", "there is a failure to allocate resources required by the OpenCL implementation on the device"};
    mess[57].errVals = t_errVals57;
    mess[57].errMessages = t_errMessages57;
    mess[57].numMessages = 3;

    static const int t_errVals58[] = {CL_INVALID_COMMAND_QUEUE, CL_OUT_OF_HOST_MEMORY, CL_OUT_OF_RESOURCES};
    static const char *t_errMessages58[] = {"command_queue is not a valid command-queue", "there is a failure to allocate resources required by the OpenCL implementation on the host", "there is a failure to allocate resources required by the OpenCL implementation on the device"};
    mess[58].errVals = t_errVals58;
    mess[58].errMessages = t_errMessages58;
    mess[58].numMessages = 3;

    static const int t_errVals59[] = {CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages59[] = {"there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[59].errVals = t_errVals59;
    mess[59].errMessages = t_errMessages59;
    mess[59].numMessages = 2;

    static const int t_errVals60[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages60[] = {"context is not a valid context", "param_name is not one of the supported values or if size in bytes specified by param_value_size is &lt; size of return type as specified in the table above and param_value is not a NULL value", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[60].errVals = t_errVals60;
    mess[60].errMessages = t_errMessages60;
    mess[60].numMessages = 4;

    static const int t_errVals61[] = {CL_INVALID_PLATFORM, CL_INVALID_VALUE, CL_DEVICE_NOT_FOUND};
    static const char *t_errMessages61[] = {"platform is not a valid platform", "d3d_device_source is not a valid value, d3d_device_set is not a valid value, num_entries is equal to zero and devices is not NULL, or if both num_devices and devices are NULL", "no OpenCL devices that correspond to d3d_object were found"};
    mess[61].errVals = t_errVals61;
    mess[61].errMessages = t_errMessages61;
    mess[61].numMessages = 3;

    static const int t_errVals62[] = {CL_INVALID_PLATFORM, CL_INVALID_VALUE, CL_DEVICE_NOT_FOUND};
    static const char *t_errMessages62[] = {"platform is not a valid platform", "d3d_device_source is not a valid value, d3d_device_set is not a valid value, num_entries is equal to zero and devices is not NULL, or if both num_devices and devices are NULL", "no OpenCL devices that correspond to d3d_object were found"};
    mess[62].errVals = t_errVals62;
    mess[62].errMessages = t_errMessages62;
    mess[62].numMessages = 3;

    static const int t_errVals63[] = {CL_INVALID_PLATFORM, CL_INVALID_VALUE, CL_DEVICE_NOT_FOUND, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages63[] = {"platform is not a valid platform", "num_media_adapters is zero or if media_adapters_type is NULL or if media_adapters is NULL OR any of the entries in media_adapters_type or media_adapters is not a valid value OR media_adapter_set is not a valid value OR num_entries is equal to zero and devices is not NULL or if both num_devices and devices are NULL", "no OpenCL devices that correspond to adapters specified in media_adapters and media_adapters_type were found", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[63].errVals = t_errVals63;
    mess[63].errMessages = t_errMessages63;
    mess[63].numMessages = 5;

    static const int t_errVals64[] = {CL_INVALID_PLATFORM, CL_INVALID_DEVICE_TYPE, CL_INVALID_VALUE, CL_DEVICE_NOT_FOUND, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages64[] = {"platform is not a valid platform", "device_type is not a valid value", "num_entries is equal to zero and devices is not NULL or if both num_devices and devices are NULL", "no OpenCL devices that matched device_type were found", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[64].errVals = t_errVals64;
    mess[64].errMessages = t_errMessages64;
    mess[64].numMessages = 6;

    static const int t_errVals65[] = {CL_INVALID_DEVICE, CL_INVALID_VALUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages65[] = {"device is not valid", "param_name is not one of the supported values or if size in bytes specified by param_value_size is less than size of return type as shown in the table above and param_value is not a NULL value or if param_name is a value that is available as an extension and the corresponding extension is not supported by the device", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[65].errVals = t_errVals65;
    mess[65].errMessages = t_errMessages65;
    mess[65].numMessages = 4;

    static const int t_errVals66[] = {CL_INVALID_VALUE, CL_INVALID_EVENT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages66[] = {"param_name is not valid, or if size in bytes specified by param_value_size is &lt; size of return type as described in the table above and param_value is not NULL OR information to query given in param_name cannot be queried for event", "event is not a valid event object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[66].errVals = t_errVals66;
    mess[66].errMessages = t_errMessages66;
    mess[66].numMessages = 4;

    static const int t_errVals67[] = {CL_PROFILING_INFO_NOT_AVAILABLE, CL_INVALID_VALUE, CL_INVALID_EVENT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages67[] = {"the CL_QUEUE_PROFILING_ENABLE flag is not set for the command-queue, if the execution status of the command identified by event is not CL_COMPLETE or if event is a user event object", "param_name is not valid, or if size in bytes specified by param_value_size is &lt; size of return type as described in the above table and param_value is not NULL", "event is a not a valid event object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[67].errVals = t_errVals67;
    mess[67].errMessages = t_errMessages67;
    mess[67].numMessages = 5;

    static const int t_errVals68[] = {CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR, CL_INVALID_VALUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages68[] = {"a context was specified by any of the following means:  A context was specified for an EGL-based OpenGL ES or OpenGL implementation by setting the attributes CL_GL_CONTEXT_KHR and CL_EGL_DISPLAY_K", "an attribute name other than those specified in the table of supported properties for clCreateContext is specified in properties OR param_name is not CL_CURRENT_DEVICE_FOR_GL_CONTEXT_KHR or CL_DEVICES_FOR_GL_CONTEXT_KHR; or if the size in bytes specified by param_value_size is less than the size of the return type shown above for CL_CURRENT_DEVICE_FOR_GL_CONTEXT_KHR or CL_DEVICES_FOR_GL_CONTEXT_KHR; and param_value is not a NULL value", "there is a failure to allocate resources required by the OpenCL implementation on the devic", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[68].errVals = t_errVals68;
    mess[68].errMessages = t_errMessages68;
    mess[68].numMessages = 4;

    static const int t_errVals69[] = {CL_INVALID_MEM_OBJECT, CL_INVALID_GL_OBJECT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages69[] = {"memobj is not a valid OpenCL memory object", "there is no GL object associated with memobj", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[69].errVals = t_errVals69;
    mess[69].errMessages = t_errMessages69;
    mess[69].numMessages = 4;

    static const int t_errVals70[] = {CL_INVALID_MEM_OBJECT, CL_INVALID_GL_OBJECT, CL_INVALID_VALUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages70[] = {"memobj is not a valid OpenCL memory objec", "there is no GL texture object associated with memobj", "param_name is not valid, or if size in bytes specified by param_value_size is &lt; size of return type as described in the table above and param_value is not NULL, or if param_value and param_value_size_ret are NULL", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[70].errVals = t_errVals70;
    mess[70].errMessages = t_errMessages70;
    mess[70].numMessages = 5;

    static const int t_errVals71[] = {CL_INVALID_VALUE, CL_INVALID_MEM_OBJECT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY, CL_INVALID_DX9_MEDIA_SURFACE_KHR, CL_INVALID_D3D10_RESOURCE_KHR, CL_INVALID_D3D11_RESOURCE_KHR};
    static const char *t_errMessages71[] = {"param_name is not valid, or if size in bytes specified by param_value_size is &lt; size of return type as described in the table above and param_value is not NULL", "image is a not a valid image object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host", "param_name is CL_IMAGE_DX9_MEDIA_PLANE_KHR and image was not created by the function clCreateFromDX9MediaSurfaceKHR. (If the cl_khr_dx9_media_sharing extension is supported", "param_name is CL_MEM_D3D10_SUBRESOURCE_KHR and image was not created by the function clCreateFromD3D10Texture2DKHR or clCreateFromD3D10Texture3DKHR. (If the cl_khr_d3d10_sharing extension is supported", "param_name is CL_MEM_D3D11_SUBRESOURCE_KHR and image was not created by the function clCreateFromD3D11Texture2DKHR or clCreateFromD3D11Texture3DKHR. (If the cl_khr_d3d11_sharing extension is supported"};
    mess[71].errVals = t_errVals71;
    mess[71].errMessages = t_errMessages71;
    mess[71].numMessages = 7;

    static const int t_errVals72[] = {CL_INVALID_ARG_INDEX, CL_INVALID_VALUE, CL_KERNEL_ARG_INFO_NOT_AVAILABLE, CL_INVALID_KERNEL};
    static const char *t_errMessages72[] = {"arg_indx is not a valid argument index", "param_name is not valid, or if size in bytes specified by param_value_size is &lt; size of return type as described in the table above and param_value is not NUL", "the argument information is not available for kernel", "kernel is not a valid kernel object"};
    mess[72].errVals = t_errVals72;
    mess[72].errMessages = t_errMessages72;
    mess[72].numMessages = 4;

    static const int t_errVals73[] = {CL_INVALID_VALUE, CL_INVALID_KERNEL, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages73[] = {"param_name is not valid, or if size in bytes specified by param_value_size is &lt; size of return type as described in the table above and param_value is not NULL", "kernel is not a valid kernel object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[73].errVals = t_errVals73;
    mess[73].errMessages = t_errMessages73;
    mess[73].numMessages = 4;

    static const int t_errVals74[] = {CL_INVALID_DEVICE, CL_INVALID_VALUE, CL_INVALID_KERNEL, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages74[] = {"device is not in the list of devices associated with kernel or if device is NULL but there is more than one device associated with kernel", "param_name is not valid, or if size in bytes specified by param_value_size is &lt; size of return type as described in the table above and param_value is not NULL OR param_name is CL_KERNEL_GLOBAL_WORK_SIZE and device is not a custom device or kernel is not a built-in kernel", "kernel is a not a valid kernel object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[74].errVals = t_errVals74;
    mess[74].errMessages = t_errMessages74;
    mess[74].numMessages = 5;

    static const int t_errVals75[] = {CL_INVALID_VALUE, CL_INVALID_MEM_OBJECT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY, CL_INVALID_D3D10_RESOURCE_KHR, CL_INVALID_DX9_MEDIA_SURFACE_KHR, CL_INVALID_D3D11_RESOURCE_KHR};
    static const char *t_errMessages75[] = {"param_name is not valid, or if size in bytes specified by param_value_size is &lt; the size of return type as described in the table above and param_value is not NULL", "memobj is a not a valid memory object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host", "the cl_khr_d3d10_sharing extension is enabled and if param_name is CL_MEM_D3D10_RESOURCE_KHR and memobj was not created by the function clCreateFromD3D10BufferKHR, clCreateFromD3D10Texture2DKHR, or clCreateFromD3D10Texture3DKHR", "param_name is CL_MEM_DX9_MEDIA_SURFACE_INFO_KHR and memobj was not created by the function clCreateFromDX9MediaSurfaceKHR from a Direct3D9 surface. (If the cl_khr_dx9_media_sharing extension is supported", "the cl_khr_d3d11_sharing extension is supported, if param_name is CL_MEM_D3D11_RESOURCE_KHR and memobj was not created by the function clCreateFromD3D11BufferKHR, clCreateFromD3D11Texture2DKHR, or clCreateFromD3D11Texture3DKHR."};
    mess[75].errVals = t_errVals75;
    mess[75].errMessages = t_errMessages75;
    mess[75].numMessages = 7;

    static const int t_errVals76[] = {CL_INVALID_PLATFORM, CL_INVALID_VALUE, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages76[] = {"platform is not a valid platform", "param_name is not one of the supported values or if size in bytes specified by param_value_size is less than size of return type and param_value is not a NULL value", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[76].errVals = t_errVals76;
    mess[76].errMessages = t_errMessages76;
    mess[76].numMessages = 3;

    static const int t_errVals77[] = {CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages77[] = {"there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[77].errVals = t_errVals77;
    mess[77].errMessages = t_errMessages77;
    mess[77].numMessages = 2;

    static const int t_errVals78[] = {CL_INVALID_VALUE, CL_INVALID_PROGRAM, CL_INVALID_PROGRAM_EXECUTABLE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages78[] = {"param_name is not valid, or if size in bytes specified by param_value_size is &lt; size of return type as described in the table above and param_value is not NULL", "program is not a valid program object", "param_name is CL_PROGRAM_NUM_KERNELS or CL_PROGRAM_KERNEL_NAMES and a successful program executable has not been built for at least one device in the list of devices associated with program", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[78].errVals = t_errVals78;
    mess[78].errMessages = t_errMessages78;
    mess[78].numMessages = 5;

    static const int t_errVals79[] = {CL_INVALID_VALUE, CL_INVALID_SAMPLER, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages79[] = {"param_name is not valid, or if size in bytes specified by param_value_size is &lt; size of return type as described in the table above and param_value is not NUL", "sampler is a not a valid sampler object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[79].errVals = t_errVals79;
    mess[79].errMessages = t_errMessages79;
    mess[79].numMessages = 4;

    static const int t_errVals80[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages80[] = {"context is not a valid context", "flags or image_type are not valid, or if num_entries is 0 and image_formats is not NULL", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[80].errVals = t_errVals80;
    mess[80].errMessages = t_errMessages80;
    mess[80].numMessages = 4;

    static const int t_errVals81[] = {CL_PLATFORM_NOT_FOUND_KHR, CL_INVALID_VALUE};
    static const char *t_errMessages81[] = {"zero platforms are available", "num_entries is equal to zero and platforms is not NULL or if both num_platforms and platforms are NULL"};
    mess[81].errVals = t_errVals81;
    mess[81].errMessages = t_errMessages81;
    mess[81].numMessages = 2;

    static const int t_errVals82[] = {CL_INVALID_CONTEXT, CL_INVALID_VALUE, CL_INVALID_PROGRAM, CL_INVALID_DEVICE, CL_INVALID_LINKER_OPTIONS, CL_INVALID_OPERATION, CL_LINKER_NOT_AVAILABLE, CL_LINK_PROGRAM_FAILURE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages82[] = {"context is not a valid context", "device_list is NULL and num_devices is greater than zero, or if device_list is not NULL and num_devices is zero OR num_input_programs is zero and input_programs is NULL or if num_input_programs is zero and input_programs is not NULL or if num_input_programs is not zero and input_programs is NULL OR pfn_notify is NULL but user_data is not NULL", "programs specified in input_programs are not valid program objects", "OpenCL devices listed in device_list are not in the list of devices associated with context", "the linker options specified by options are invali", "the compilation or build of a program executable for any of the devices listed in device_list by a previous call to clCompileProgram or clBuildProgram for program has not completed OR the rules for devices containing compiled binaries or libraries as described in input_programs argument above are not followed", "a linker is not available i.e. CL_DEVICE_LINKER_AVAILABLE specified in the table of allowed values for param_name for clGetDeviceInfo is set to CL_FALSE", "there is a failure to link the compiled binaries and/or libraries", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[82].errVals = t_errVals82;
    mess[82].errMessages = t_errMessages82;
    mess[82].numMessages = 10;

    static const int t_errVals83[] = {CL_INVALID_COMMAND_QUEUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages83[] = {"command_queue is not a valid command queue", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[83].errVals = t_errVals83;
    mess[83].errMessages = t_errMessages83;
    mess[83].numMessages = 3;

    static const int t_errVals84[] = {CL_INVALID_CONTEXT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages84[] = {"context is not a valid OpenCL context", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[84].errVals = t_errVals84;
    mess[84].errMessages = t_errMessages84;
    mess[84].numMessages = 3;

    static const int t_errVals85[] = {CL_INVALID_DEVICE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages85[] = {"device is not a valid sub-device created by a call to clCreateSubDevices", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[85].errVals = t_errVals85;
    mess[85].errMessages = t_errMessages85;
    mess[85].numMessages = 3;

    static const int t_errVals86[] = {CL_INVALID_EVENT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages86[] = {"event is not a valid event object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[86].errVals = t_errVals86;
    mess[86].errMessages = t_errMessages86;
    mess[86].numMessages = 3;

    static const int t_errVals87[] = {CL_INVALID_KERNEL, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages87[] = {"kernel is not a valid kernel object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[87].errVals = t_errVals87;
    mess[87].errMessages = t_errMessages87;
    mess[87].numMessages = 3;

    static const int t_errVals88[] = {CL_INVALID_MEM_OBJECT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages88[] = {"memobj is a not a valid memory object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[88].errVals = t_errVals88;
    mess[88].errMessages = t_errMessages88;
    mess[88].numMessages = 3;

    static const int t_errVals89[] = {CL_INVALID_PROGRAM, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages89[] = {"program is not a valid program object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[89].errVals = t_errVals89;
    mess[89].errMessages = t_errMessages89;
    mess[89].numMessages = 3;

    static const int t_errVals90[] = {CL_INVALID_SAMPLER, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages90[] = {"sampler is not a valid sampler object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[90].errVals = t_errVals90;
    mess[90].errMessages = t_errMessages90;
    mess[90].numMessages = 3;

    static const int t_errVals91[] = {CL_INVALID_COMMAND_QUEUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages91[] = {"command_queue is not a valid command-queue", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[91].errVals = t_errVals91;
    mess[91].errMessages = t_errMessages91;
    mess[91].numMessages = 3;

    static const int t_errVals92[] = {CL_INVALID_CONTEXT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages92[] = {"context is not a valid OpenCL context", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[92].errVals = t_errVals92;
    mess[92].errMessages = t_errMessages92;
    mess[92].numMessages = 3;

    static const int t_errVals93[] = {CL_INVALID_DEVICE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages93[] = {"device is not a valid sub-device created by a call to clCreateSubDevices", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[93].errVals = t_errVals93;
    mess[93].errMessages = t_errMessages93;
    mess[93].numMessages = 3;

    static const int t_errVals94[] = {CL_INVALID_EVENT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages94[] = {"event is not a valid event object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[94].errVals = t_errVals94;
    mess[94].errMessages = t_errMessages94;
    mess[94].numMessages = 3;

    static const int t_errVals95[] = {CL_INVALID_KERNEL, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages95[] = {"kernel is not a valid kernel object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[95].errVals = t_errVals95;
    mess[95].errMessages = t_errMessages95;
    mess[95].numMessages = 3;

    static const int t_errVals96[] = {CL_INVALID_MEM_OBJECT, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages96[] = {"memobj is a not a valid memory object (buffer or image object)", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[96].errVals = t_errVals96;
    mess[96].errMessages = t_errMessages96;
    mess[96].numMessages = 3;

    static const int t_errVals97[] = {CL_INVALID_PROGRAM, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages97[] = {"program is not a valid program object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[97].errVals = t_errVals97;
    mess[97].errMessages = t_errMessages97;
    mess[97].numMessages = 3;

    static const int t_errVals98[] = {CL_INVALID_SAMPLER, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages98[] = {"sampler is not a valid sampler object", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[98].errVals = t_errVals98;
    mess[98].errMessages = t_errMessages98;
    mess[98].numMessages = 3;

    static const int t_errVals99[] = {CL_INVALID_EVENT, CL_INVALID_VALUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages99[] = {"event is not a valid event object", "pfn_event_notify is NULL or if command_exec_callback_type is not CL_COMPLETE", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[99].errVals = t_errVals99;
    mess[99].errMessages = t_errMessages99;
    mess[99].numMessages = 4;

    static const int t_errVals100[] = {CL_INVALID_KERNEL, CL_INVALID_ARG_INDEX, CL_INVALID_ARG_VALUE, CL_INVALID_MEM_OBJECT, CL_INVALID_SAMPLER, CL_INVALID_ARG_SIZE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages100[] = {"kernel is not a valid kernel object", "arg_index is not a valid argument index", "arg_value specified is not a valid value OR the argument is an image declared with the read_only qualifier and arg_value refers to an image object created with cl_mem_flags of CL_MEM_WRITE or if the image argument is declared with the write_only qualifier and arg_value refers to an image object created with cl_mem_flags of CL_MEM_READ", "for an argument declared to be a memory object when the specified arg_value is not a valid memory object", "for an argument declared to be of type sampler_t when the specified arg_value is not a valid sampler object", "arg_size does not match the size of the data type for an argument that is not a memory object or if the argument is a memory object and arg_size != sizeof(cl_mem) or if arg_size is zero and the argument is declared with the __local qualifier or if the argument is a sampler and arg_size != sizeof(cl_sampler)", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[100].errVals = t_errVals100;
    mess[100].errMessages = t_errMessages100;
    mess[100].numMessages = 8;

    static const int t_errVals101[] = {CL_INVALID_MEM_OBJECT, CL_INVALID_VALUE, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages101[] = {"memobj is not a valid memory object", "pfn_notify is NULL", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[101].errVals = t_errVals101;
    mess[101].errMessages = t_errMessages101;
    mess[101].numMessages = 4;

    static const int t_errVals102[] = {CL_INVALID_EVENT, CL_INVALID_VALUE, CL_INVALID_OPERATION, CL_OUT_OF_RESOURCES, CL_OUT_OF_HOST_MEMORY};
    static const char *t_errMessages102[] = {"event is not a valid user event", "the execution_status is not CL_COMPLETE or a negative integer value", "the execution_status for event has already been changed by a previous call to clSetUserEventStatus", "there is a failure to allocate resources required by the OpenCL implementation on the device", "there is a failure to allocate resources required by the OpenCL implementation on the host"};
    mess[102].errVals = t_errVals102;
    mess[102].errMessages = t_errMessages102;
    mess[102].numMessages = 5;

    static const int t_errVals103[] = {CL_INVALID_PLATFORM};
    static const char *t_errMessages103[] = {"platform is not a valid platform"};
    mess[103].errVals = t_errVals103;
    mess[103].errMessages = t_errMessages103;
    mess[103].numMessages = 1;

    int error_id = -1;
    int i;
    for (i = 0; i < mess[functionID].numMessages; ++i)
    {
        if (errorNumber == mess[functionID].errVals[i])
        {
            error_id = i;
        }
    }
    if (error_id < 0)
    {
        printf("Error not found... functionID=%d", functionID);
        return "";
    }
    return mess[functionID].errMessages[error_id];
}

void print_cl_error(const char* functionName, int errorNumber)
{
    int f_id;
    char output[1500];

    if (errorNumber)
    {
        f_id = get_function_id(functionName);

        strcpy(output, "In function ");
        strcat(output, functionName);
        strcat(output, " ");
        strcat(output, get_error_description(f_id, errorNumber));

        printf("%s\n", output);
    }
}
