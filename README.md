# Convolution_engine_pynq

##  Overview
This project implements a hardware-accelerated 3×3 convolution engine on the PYNQ-Z2 (Zynq-7000) platform. The goal is to offload convolution operations from the ARM processor (PS) to FPGA programmable logic (PL) and demonstrate improved performance for CNN workloads.

The design uses a streaming architecture with BRAM-based line buffers and sliding window reuse to reduce DDR memory accesses and improve efficiency.

---

## Key Features
- Hardware acceleration of 3×3 convolution
- Streaming datapath with line buffer and sliding window
- Reduced DDR bandwidth using BRAM reuse
- AXI-based PS–PL communication
- Python control using PYNQ
- Output verified against CPU reference

---

## System Architecture

### Processing System (PS)
- Image preprocessing
- DDR buffer allocation
- AXI-Lite control of accelerator
- Output validation

### Programmable Logic (PL)
- 3×3 convolution engine
- Line buffers stored in BRAM
- Sliding window MAC computation
- AXI master interface for DDR access

### Data Flow
DDR → BRAM (Line Buffer) → Sliding Window → MAC → DDR

---

## Implementation Details

### Convolution Engine
- Kernel size: 3×3
- Data type: int16
- Operation: Valid convolution (H-2 × W-2)
- Input: Single channel (RGB processed separately)
- Weights loaded once per execution

---

### HLS Optimizations
- Loop pipelining (target II ≈ 1)
- BRAM-based line buffers
- Sliding window reuse

---

##  Interfaces

### AXI-Lite (Control)
- Input address
- Output address
- Weight address
- Height (H), Width (W)
- Start / Done control

### AXI Master (Memory)
- gmem0 → Input
- gmem1 → Output
- gmem2 → Weights

---

##  Software Flow (PYNQ)

1. Load FPGA bitstream  
2. Allocate DDR buffers  
3. Copy input image  
4. Load kernel weights  
5. Configure registers  
6. Start accelerator  
7. Poll for completion  
8. Read output and verify  

---


