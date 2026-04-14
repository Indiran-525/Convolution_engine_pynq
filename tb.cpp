#include <iostream>
#include <stdint.h>

// Prototype of your HLS function
extern "C" {
void convbas(
    const int16_t *in,
    int16_t *out,
    int H,
    int W,
    const int16_t *w_kernel
);
}

int main() {
    // 1. Define dimensions for a small test case (e.g., 5x5)
    const int H = 5;
    const int W = 5;
    const int OUT_H = H - 2;
    const int OUT_W = W - 2;

    // 2. Allocate and initialize input memory
    int16_t in_img[H * W];
    int16_t out_img[OUT_H * OUT_W];
    int16_t kernel[9] = {1, 1, 1, 1,1, 1, 1, 1, 1}; // Simple Box Filter

    // Fill input with a simple pattern (e.g., all 10s)
    for (int i = 0; i < H * W; i++) {
        in_img[i] = 10;
    }

    // Clear output buffer to 0s to ensure we catch actual writes
    for (int i = 0; i < OUT_H * OUT_W; i++) {
        out_img[i] = 0;
    }

    // 3. Call the HLS function
    std::cout << "Running HLS Convolution Simulation..." << std::endl;
    convbas(in_img, out_img, H, W, kernel);

    // 4. Verify Results
    int error_count = 0;
    bool all_zeros = true;

    std::cout << "Output Matrix (" << OUT_H << "x" << OUT_W << "):" << std::endl;
    for (int i = 0; i < OUT_H; i++) {
        for (int j = 0; j < OUT_W; j++) {
            int16_t val = out_img[i * OUT_W + j];
            std::cout << val << " ";
            if (val != 0) all_zeros = false;
            
            // For a 10-filled image and a kernel of all 1s, expect 90
            if (val != 90) error_count++;
        }
        std::cout << std::endl;
    }

    // 5. Final Report
    if (all_zeros) {
        std::cout << "TEST FAILED: Output is all zeros!" << std::endl;
        return 1;
    } else if (error_count > 0) {
        std::cout << "TEST FAILED: Logic error! Found " << error_count << " incorrect values." << std::endl;
        return 1;
    } else {
        std::cout << "TEST PASSED: Non-zero valid data produced!" << std::endl;
        return 0;
    }
}