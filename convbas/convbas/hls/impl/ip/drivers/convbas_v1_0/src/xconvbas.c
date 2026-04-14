// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xconvbas.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XConvbas_CfgInitialize(XConvbas *InstancePtr, XConvbas_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Ctrl_BaseAddress = ConfigPtr->Ctrl_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XConvbas_Start(XConvbas *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_AP_CTRL) & 0x80;
    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XConvbas_IsDone(XConvbas *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XConvbas_IsIdle(XConvbas *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XConvbas_IsReady(XConvbas *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XConvbas_EnableAutoRestart(XConvbas *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_AP_CTRL, 0x80);
}

void XConvbas_DisableAutoRestart(XConvbas *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_AP_CTRL, 0);
}

void XConvbas_Set_in_r(XConvbas *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_IN_R_DATA, (u32)(Data));
    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_IN_R_DATA + 4, (u32)(Data >> 32));
}

u64 XConvbas_Get_in_r(XConvbas *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_IN_R_DATA);
    Data += (u64)XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_IN_R_DATA + 4) << 32;
    return Data;
}

void XConvbas_Set_out_r(XConvbas *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_OUT_R_DATA, (u32)(Data));
    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_OUT_R_DATA + 4, (u32)(Data >> 32));
}

u64 XConvbas_Get_out_r(XConvbas *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_OUT_R_DATA);
    Data += (u64)XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_OUT_R_DATA + 4) << 32;
    return Data;
}

void XConvbas_Set_H(XConvbas *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_H_DATA, Data);
}

u32 XConvbas_Get_H(XConvbas *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_H_DATA);
    return Data;
}

void XConvbas_Set_W(XConvbas *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_W_DATA, Data);
}

u32 XConvbas_Get_W(XConvbas *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_W_DATA);
    return Data;
}

void XConvbas_Set_w_kernel(XConvbas *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_W_KERNEL_DATA, (u32)(Data));
    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_W_KERNEL_DATA + 4, (u32)(Data >> 32));
}

u64 XConvbas_Get_w_kernel(XConvbas *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_W_KERNEL_DATA);
    Data += (u64)XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_W_KERNEL_DATA + 4) << 32;
    return Data;
}

void XConvbas_InterruptGlobalEnable(XConvbas *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_GIE, 1);
}

void XConvbas_InterruptGlobalDisable(XConvbas *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_GIE, 0);
}

void XConvbas_InterruptEnable(XConvbas *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_IER);
    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_IER, Register | Mask);
}

void XConvbas_InterruptDisable(XConvbas *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_IER);
    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_IER, Register & (~Mask));
}

void XConvbas_InterruptClear(XConvbas *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvbas_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_ISR, Mask);
}

u32 XConvbas_InterruptGetEnabled(XConvbas *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_IER);
}

u32 XConvbas_InterruptGetStatus(XConvbas *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XConvbas_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONVBAS_CTRL_ADDR_ISR);
}

