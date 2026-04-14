#include <stdint.h>

extern "C" {
void convbas(
    const int16_t *in,
    int16_t *out,
    int H,
    int W,
    const int16_t *w_kernel
) {
#pragma HLS INTERFACE m_axi port=in  offset=slave bundle=gmem0
#pragma HLS INTERFACE m_axi port=out offset=slave bundle=gmem1
#pragma HLS INTERFACE m_axi port=w_kernel offset=slave bundle=gmem2
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL
#pragma HLS INTERFACE s_axilite port=H bundle=CTRL
#pragma HLS INTERFACE s_axilite port=W bundle=CTRL
#pragma HLS INTERFACE s_axilite port=in bundle=CTRL
#pragma HLS INTERFACE s_axilite port=out bundle=CTRL
#pragma HLS INTERFACE s_axilite port=w_kernel bundle=CTRL

    // 1. Load weights into local registers for access
    int16_t local_kernel[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            local_kernel[i][j] = w_kernel[i*3 + j];
        }
    }

    // 2. Simple Nested Loops (No Pipeline)
    // We iterate from 1 to H-1 and 1 to W-1 to handle 3x3 boundaries simply
    for (int r = 1; r < H - 1; r++) {
        for (int c = 1; c < W - 1; c++) {
            int32_t acc = 0;
            
            // Window calculation
            for (int kr = 0; kr < 3; kr++) {
                for (int kc = 0; kc < 3; kc++) {
                    // Calculate absolute memory address for the current window pixel
                    int in_idx = (r + kr - 1) * W + (c + kc - 1);
                    acc += in[in_idx] * local_kernel[kr][kc];
                }
            }
            
            // Map output index (shifted to start at 0,0)
            int out_idx = (r - 1) * (W - 2) + (c - 1);
            out[out_idx] = (int16_t)acc;
        }
    }
}
}