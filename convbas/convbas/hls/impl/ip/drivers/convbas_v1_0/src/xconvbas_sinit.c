// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xconvbas.h"

extern XConvbas_Config XConvbas_ConfigTable[];

#ifdef SDT
XConvbas_Config *XConvbas_LookupConfig(UINTPTR BaseAddress) {
	XConvbas_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XConvbas_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XConvbas_ConfigTable[Index].Ctrl_BaseAddress == BaseAddress) {
			ConfigPtr = &XConvbas_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XConvbas_Initialize(XConvbas *InstancePtr, UINTPTR BaseAddress) {
	XConvbas_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XConvbas_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XConvbas_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XConvbas_Config *XConvbas_LookupConfig(u16 DeviceId) {
	XConvbas_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XCONVBAS_NUM_INSTANCES; Index++) {
		if (XConvbas_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XConvbas_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XConvbas_Initialize(XConvbas *InstancePtr, u16 DeviceId) {
	XConvbas_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XConvbas_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XConvbas_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

