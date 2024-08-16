#include "digit.h"  // Include definitions for digit manipulation
#include "modules.h"  // Include module declarations
// #include "../dhdemo/dhdemo/digit.h"  // Optional alternative include path
// #include "../dhdemo/dhdemo/modules.h"  // Optional alternative include path

// Process function for hardware register module
void hw_register::run_hw_register() {
    while (true) {
        if (load_data.read() == 1) {  // Check if load signal is active
            out_data.write(in_data.read());  // Load input data into output
        }
        wait();  // Wait for the next event
    }
}

// Process function for high hardware register module
void hw_register_h::run_hw_register_h() {
    while (true) {
        if (load_data.read() == 1) {  // Check if load signal is active
            out_data.write(in_data.read());  // Load input data into output
        }
        wait();  // Wait for the next event
    }
}

// Process function for hardware splitter module
void hw_splitter::run_hw_splitter() {
    // Split input data into high and low halves and write to respective outputs
    out_data_high.write(HIGH_HALF(in_data.read()));
    out_data_low.write(LOW_HALF(in_data.read()));
}

// Process function for hardware multiplier module
void hw_multiplier::run_hw_multiplier() {
    // Multiply two input data values and write result to output
    out_data.write(in_data_1.read() * in_data_2.read());
}

// Process function for hardware adder module
void hw_adder::run_hw_adder() {
    // Add two input data values and write result to output
    out_data.write(in_data_1.read() + in_data_2.read());
}

// Process function for hardware subtractor module
void hw_subber::run_hw_subber() {
    // Subtract second input data from first input data and write result to output
    out_data.write(in_data_1.read() - in_data_2.read());
}

// Process function for hardware multiplexer module
void hw_multiplexor::run_hw_multiplexor() {
    // Select one of the two input data values based on control signal and write to output
    if (control.read() == 0) {
        out_data.write(in_data_1.read());
    } else {
        out_data.write(in_data_2.read());
    }
}

// Process function for converting input to high half format
void hw_to_hh::run_hw_to_hh() {
    // Shift input data to the high half and write to output
    out_data.write(TO_HIGH_HALF(in_data.read()));
}

// Process function for extracting high half of input data
void hw_hh_extract::run_hw_hh_extract() {
    // Extract high half of input data and write to output
    out_data.write(HIGH_HALF(in_data.read()));
}

// Process function for hardware comparator module
void hw_comparator::run_hw_comparator() {
    // Compare input data values and set greater_than_signal accordingly
    if (in_data_comparison.read() > in_data_reference.read()) {
        greater_than_signal.write(1);
    } else {
        greater_than_signal.write(0);
    }
}
