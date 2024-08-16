#include "systemc.h"
#include "digit.h"
#include "dh_hw.h"
#include "modules.h"

// Define the states for the finite state machine (FSM)
#define WAIT_STATE 0
#define INPUT_STATE 1
#define EXECUTE_STATE 2
#define OUTPUT_STATE 3
#define FINISH_STATE 4

/**
 * @brief Hardware process for Diffie-Hellman key exchange
 * 
 * This function implements the finite state machine (FSM) to handle the
 * hardware operations involved in the Diffie-Hellman key exchange algorithm.
 */
void dh_hw::process_hw() {
    // Initialize the state and hardware done signal
    UINT2 current_state = WAIT_STATE;
    hw_done.write(false);
    
    while (true) {
        // FSM to control hardware behavior
        switch (current_state) {
            case WAIT_STATE:
                // Wait for software to enable the hardware process
                if (hw_enable.read() == true) {
                    current_state = INPUT_STATE;
                }
                break;

            case INPUT_STATE:
                // Load the input values into the hardware registers
                ld_c.write(1);
                ld_t0.write(1);
                ld_t1.write(1);
                ld_aLow.write(1);
                t1_mux_1_ctrl.write(0);
                t1_mux_2_ctrl.write(0);
                
                // Wait for one clock cycle to ensure values are loaded
                wait();
                ld_c.write(0);
                ld_t0.write(0);
                ld_t1.write(0);
                ld_aLow.write(0);
                
                // Move to the EXECUTE_STATE
                current_state = EXECUTE_STATE;
                break;  

            case EXECUTE_STATE:
                // Execute the computation based on the input values
                // Update mux control signals based on the greater-than results
                t1_mux_1_ctrl.write(gt_1.read());
                t1_mux_2_ctrl.write(gt_2.read());
                
                // Move to the OUTPUT_STATE
                current_state = OUTPUT_STATE;
                break;

            case OUTPUT_STATE:
                // Output the result to the software
                to_sw.write(aLow.read());
                hw_done.write(true);
                
                // Move to the FINISH_STATE
                current_state = FINISH_STATE;
                break;

            case FINISH_STATE:
                // Wait for software to disable the hardware process
                if (hw_enable.read() == false) {
                    hw_done.write(false);
                    current_state = WAIT_STATE;
                }
                break;
        }
        
        // Wait for the next clock cycle
        wait();
    }
}
