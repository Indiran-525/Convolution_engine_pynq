// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XCONVBAS_H
#define XCONVBAS_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xconvbas_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Ctrl_BaseAddress;
} XConvbas_Config;
#endif

typedef struct {
    u64 Ctrl_BaseAddress;
    u32 IsReady;
} XConvbas;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XConvbas_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XConvbas_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XConvbas_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XConvbas_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XConvbas_Initialize(XConvbas *InstancePtr, UINTPTR BaseAddress);
XConvbas_Config* XConvbas_LookupConfig(UINTPTR BaseAddress);
#else
int XConvbas_Initialize(XConvbas *InstancePtr, u16 DeviceId);
XConvbas_Config* XConvbas_LookupConfig(u16 DeviceId);
#endif
int XConvbas_CfgInitialize(XConvbas *InstancePtr, XConvbas_Config *ConfigPtr);
#else
int XConvbas_Initialize(XConvbas *InstancePtr, const char* InstanceName);
int XConvbas_Release(XConvbas *InstancePtr);
#endif

void XConvbas_Start(XConvbas *InstancePtr);
u32 XConvbas_IsDone(XConvbas *InstancePtr);
u32 XConvbas_IsIdle(XConvbas *InstancePtr);
u32 XConvbas_IsReady(XConvbas *InstancePtr);
void XConvbas_EnableAutoRestart(XConvbas *InstancePtr);
void XConvbas_DisableAutoRestart(XConvbas *InstancePtr);

void XConvbas_Set_in_r(XConvbas *InstancePtr, u64 Data);
u64 XConvbas_Get_in_r(XConvbas *InstancePtr);
void XConvbas_Set_out_r(XConvbas *InstancePtr, u64 Data);
u64 XConvbas_Get_out_r(XConvbas *InstancePtr);
void XConvbas_Set_H(XConvbas *InstancePtr, u32 Data);
u32 XConvbas_Get_H(XConvbas *InstancePtr);
void XConvbas_Set_W(XConvbas *InstancePtr, u32 Data);
u32 XConvbas_Get_W(XConvbas *InstancePtr);
void XConvbas_Set_w_kernel(XConvbas *InstancePtr, u64 Data);
u64 XConvbas_Get_w_kernel(XConvbas *InstancePtr);

void XConvbas_InterruptGlobalEnable(XConvbas *InstancePtr);
void XConvbas_InterruptGlobalDisable(XConvbas *InstancePtr);
void XConvbas_InterruptEnable(XConvbas *InstancePtr, u32 Mask);
void XConvbas_InterruptDisable(XConvbas *InstancePtr, u32 Mask);
void XConvbas_InterruptClear(XConvbas *InstancePtr, u32 Mask);
u32 XConvbas_InterruptGetEnabled(XConvbas *InstancePtr);
u32 XConvbas_InterruptGetStatus(XConvbas *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
