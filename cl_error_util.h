/*******************************************************************************
 * Copyright (c) 2015 StreamComputing BV - All Rights Reserved
 * www.streamcomputing.eu
 ******************************************************************************/
#ifndef __CL_ERROR_UTIL_H
#define __CL_ERROR_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

void print_cl_error(const char* functionName, int errorNumber);

#ifdef __cplusplus
}
#endif

#endif /* __CL_ERROR_UTIL_H */
