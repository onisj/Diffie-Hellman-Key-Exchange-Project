#include "systemc.h"
#include "digit.h"
#include "dh_sw.h"
#include "dh_hw.h"

int sc_main(int argc, char *argv[]) {
    // Cast argc and argv to void to indicate they are intentionally unused
    (void)argc;
    (void)argv;

    // Define a clock signal for the simulation with a period of 10 ns
    sc_clock TestClk("Testclock", 10, SC_NS, 0.5, 1, SC_NS);

    // Define signals to connect the software and hardware modules
    sc_signal<NN_DIGIT> ch0, ch1, ch2;       // Signals for NN_DIGIT type
    sc_signal<NN_HALF_DIGIT> ch3, ch4;       // Signals for NN_HALF_DIGIT type

    // Define control signals
    sc_signal<bool> enable, done;
    enable.write(false);    // Initialize enable signal to false
    done.write(false);      // Initialize done signal to false

    // Instantiate the software module
    dh_sw DH_SW("DH_Software_Module");
    // Connect software module ports to signals
    DH_SW.to_hw0(ch0);                 // Output 0 from software to hardware
    DH_SW.to_hw1(ch1);                 // Output 1 from software to hardware
    DH_SW.to_hw2(ch2);                 // Output 2 from software to hardware
    DH_SW.to_hw3(ch3);                 // Output 3 from software to hardware
    DH_SW.from_hw(ch4);                // Input from hardware to software
    DH_SW.hw_enable(enable);           // Connect hardware-enable output to software
    DH_SW.hw_done(done);               // Connect hardware-done input to software

    // Instantiate the hardware module
    dh_hw DH_HW("DH_Hardware_Module");
    // Connect clock signal to hardware module
    DH_HW.clk(TestClk);
    // Connect hardware module ports to signals
    DH_HW.from_sw0(ch0);               // Input 0 from software to hardware
    DH_HW.from_sw1(ch1);               // Input 1 from software to hardware
    DH_HW.from_sw2(ch2);               // Input 2 from software to hardware
    DH_HW.from_sw3(ch3);               // Input 3 from software to hardware
    DH_HW.to_sw(ch4);                  // Output from hardware to software
    DH_HW.hw_enable(enable);           // Connect hardware-enable input to hardware
    DH_HW.hw_done(done);               // Connect hardware-done output to hardware

    // Start the SystemC simulation
    sc_start();

    return 0;   // Return 0 to indicate successful execution
}
