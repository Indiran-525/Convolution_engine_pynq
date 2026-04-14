set SynModuleInfo {
  {SRCNAME convbas_Pipeline_VITIS_LOOP_23_1_VITIS_LOOP_24_2 MODELNAME convbas_Pipeline_VITIS_LOOP_23_1_VITIS_LOOP_24_2 RTLNAME convbas_convbas_Pipeline_VITIS_LOOP_23_1_VITIS_LOOP_24_2
    SUBMODULES {
      {MODELNAME convbas_flow_control_loop_pipe_sequential_init RTLNAME convbas_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME convbas_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME convbas_Pipeline_VITIS_LOOP_31_3_VITIS_LOOP_32_4 MODELNAME convbas_Pipeline_VITIS_LOOP_31_3_VITIS_LOOP_32_4 RTLNAME convbas_convbas_Pipeline_VITIS_LOOP_31_3_VITIS_LOOP_32_4
    SUBMODULES {
      {MODELNAME convbas_mul_31ns_32s_63_2_1 RTLNAME convbas_mul_31ns_32s_63_2_1 BINDTYPE op TYPE mul IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME convbas_mul_16s_16s_16_1_1 RTLNAME convbas_mul_16s_16s_16_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME convbas_mac_muladd_16s_16s_16ns_16_4_1 RTLNAME convbas_mac_muladd_16s_16s_16ns_16_4_1 BINDTYPE op TYPE all IMPL dsp_slice LATENCY 3}
    }
  }
  {SRCNAME convbas MODELNAME convbas RTLNAME convbas IS_TOP 1
    SUBMODULES {
      {MODELNAME convbas_mul_32ns_32ns_64_2_1 RTLNAME convbas_mul_32ns_32ns_64_2_1 BINDTYPE op TYPE mul IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME convbas_local_kernel_RAM_AUTO_1R1W RTLNAME convbas_local_kernel_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME convbas_gmem0_m_axi RTLNAME convbas_gmem0_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME convbas_gmem1_m_axi RTLNAME convbas_gmem1_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME convbas_gmem2_m_axi RTLNAME convbas_gmem2_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME convbas_CTRL_s_axi RTLNAME convbas_CTRL_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
