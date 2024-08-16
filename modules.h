#include "systemc.h"  // Include SystemC library
#include "digit.h"    // Include digit manipulation definitions

#ifndef _MODULES_H_
#define _MODULES_H_ 1

// Module for hardware register
SC_MODULE(hw_register) {
    // Input clock signal
    sc_in_clk clk;
    // Input data signal
    sc_in<NN_DIGIT> in_data;
    // Input control signal to load data
    sc_in<bool> load_data;
    // Output data signal
    sc_out<NN_DIGIT> out_data;

    // Process function for the hardware register
    void run_hw_register();

    // Constructor to initialize and register the process
    SC_CTOR(hw_register) {
        // Register process with positive edge of the clock
        SC_CTHREAD(run_hw_register, clk.pos());
        // Initialize output data
        out_data.initialize(0);
    }
};

// Module for high hardware register (using half digits)
SC_MODULE(hw_register_h) {
    sc_in_clk clk;  // Input clock signal
    sc_in<NN_HALF_DIGIT> in_data;  // Input half-digit data signal
    sc_in<bool> load_data;  // Input control signal to load data
    sc_out<NN_HALF_DIGIT> out_data;  // Output half-digit data signal

    // Process function for the high hardware register
    void run_hw_register_h();

    // Constructor to initialize and register the process
    SC_CTOR(hw_register_h) {
        // Register process with positive edge of the clock
        SC_CTHREAD(run_hw_register_h, clk.pos());
        // Initialize output data
        out_data.initialize(0);
    }
};

// Module for splitting a digit into high and low parts
SC_MODULE(hw_splitter) {
    sc_in<NN_DIGIT> in_data;  // Input digit data signal
    sc_out<NN_DIGIT> out_data_high;  // Output high part of the digit
    sc_out<NN_DIGIT> out_data_low;  // Output low part of the digit

    // Process function to split the digit
    void run_hw_splitter();

    // Constructor to initialize and register the process
    SC_CTOR(hw_splitter) {
        // Register method process sensitive to input data changes
        SC_METHOD(run_hw_splitter);
        sensitive << in_data;
    }
};

// Module for multiplying two digits
SC_MODULE(hw_multiplier) {
    sc_in<NN_HALF_DIGIT> in_data_1;  // Input first half-digit data signal
    sc_in<NN_DIGIT> in_data_2;  // Input second digit data signal
    sc_out<NN_DIGIT> out_data;  // Output result data signal

    // Process function for the hardware multiplier
    void run_hw_multiplier();

    // Constructor to initialize and register the process
    SC_CTOR(hw_multiplier) {
        // Register method process sensitive to input data changes
        SC_METHOD(run_hw_multiplier);
        sensitive << in_data_1 << in_data_2;
    }
};

// Module for adding two digits
SC_MODULE(hw_adder) {
    sc_in<NN_DIGIT> in_data_1;  // Input first digit data signal
    sc_in<NN_DIGIT> in_data_2;  // Input second digit data signal
    sc_out<NN_DIGIT> out_data;  // Output result data signal

    // Process function for the hardware adder
    void run_hw_adder();

    // Constructor to initialize and register the process
    SC_CTOR(hw_adder) {
        // Register method process sensitive to input data changes
        SC_METHOD(run_hw_adder);
        sensitive << in_data_1 << in_data_2;
    }
};

// Module for subtracting two digits
SC_MODULE(hw_subber) {
    sc_in<NN_DIGIT> in_data_1;  // Input first digit data signal
    sc_in<NN_DIGIT> in_data_2;  // Input second digit data signal
    sc_out<NN_DIGIT> out_data;  // Output result data signal

    // Process function for the hardware subtractor
    void run_hw_subber();

    // Constructor to initialize and register the process
    SC_CTOR(hw_subber) {
        // Register method process sensitive to input data changes
        SC_METHOD(run_hw_subber);
        sensitive << in_data_1 << in_data_2;
    }
};

// Module for multiplexing two input digits based on a control signal
SC_MODULE(hw_multiplexor) {
    sc_in<NN_DIGIT> in_data_1;  // Input first digit data signal
    sc_in<NN_DIGIT> in_data_2;  // Input second digit data signal
    sc_in<bool> control;  // Input control signal
    sc_out<NN_DIGIT> out_data;  // Output selected data signal

    // Process function for the hardware multiplexor
    void run_hw_multiplexor();

    // Constructor to initialize and register the process
    SC_CTOR(hw_multiplexor) {
        // Register method process sensitive to input data changes and control signal
        SC_METHOD(run_hw_multiplexor);
        sensitive << in_data_1 << in_data_2 << control;
    }
};

// Module for shifting input digit to the high half
SC_MODULE(hw_to_hh) {
    sc_in<NN_DIGIT> in_data;  // Input digit data signal
    sc_out<NN_DIGIT> out_data;  // Output shifted data signal

    // Process function for shifting input to high half
    void run_hw_to_hh();

    // Constructor to initialize and register the process
    SC_CTOR(hw_to_hh) {
        // Register method process sensitive to input data changes
        SC_METHOD(run_hw_to_hh);
        sensitive << in_data;
    }
};

// Module for extracting the high half of a digit
SC_MODULE(hw_hh_extract) {
    sc_in<NN_DIGIT> in_data;  // Input digit data signal
    sc_out<NN_DIGIT> out_data;  // Output high half data signal

    // Process function for extracting the high half
    void run_hw_hh_extract();

    // Constructor to initialize and register the process
    SC_CTOR(hw_hh_extract) {
        // Register method process sensitive to input data changes
        SC_METHOD(run_hw_hh_extract);
        sensitive << in_data;
    }
};

// Module for comparing two digits
SC_MODULE(hw_comparator) {
    sc_in<NN_DIGIT> in_data_reference;  // Input reference digit data signal
    sc_in<NN_DIGIT> in_data_comparison;  // Input comparison digit data signal
    sc_out<bool> greater_than_signal;  // Output signal indicating comparison result

    // Process function for the hardware comparator
    void run_hw_comparator();

    // Constructor to initialize and register the process
    SC_CTOR(hw_comparator) {
        // Register method process sensitive to input data changes
        SC_METHOD(run_hw_comparator);
        sensitive << in_data_reference << in_data_comparison;
    }
};

#endif /* end _MODULES_H_ */
