/*******************************************************************************
 * Copyright (c) 2015 StreamComputing BV - All Rights Reserved
 * www.streamcomputing.eu
 ******************************************************************************/

__kernel void SimpleFunction(__global float* input1, __global float* input2, __global float* output, int count)
{
	int i = get_global_id(0);
	
	if (i >= count)
		return;

	output[i] = input1[i] + input2[i];
}