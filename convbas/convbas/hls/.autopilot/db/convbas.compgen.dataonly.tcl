# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_CTRL {
in_r { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 16
	offset_end 27
}
out_r { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 28
	offset_end 39
}
H { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 40
	offset_end 47
}
W { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 48
	offset_end 55
}
w_kernel { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 56
	offset_end 67
}
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
interrupt {
}
}
dict set axilite_register_dict CTRL $port_CTRL


