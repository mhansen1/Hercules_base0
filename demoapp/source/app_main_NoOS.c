#include "HL_reg_system.h"
#include "HL_reg_pinmux.h"
#include "HL_reg_het.h"
#include "HL_reg_gio.h"
#include "HL_reg_mibspi.h"
#include "HL_reg_vim.h"
#include "VIM.h"
#include "ROLM.h"


// Entry point for the program is the function _c_int00(void) in file HL_sys_startup.c
// See the ARM compiler guide for more info on the subject

// Functions used by the GIO button interrupts
void button1(void) {
    gioPORTB->DOUT ^= (1 << 6);
}
void button2(void) {
    //gioPORTB-> ^= (1 << 6);
    gioPORTB->DOUT ^= (1 << 7);
}

// GIO high priority ISR entry point
void buttonISR(void)
{
    uint32 offset = gioREG->OFF1;
    // Make sure that there was not an error in calling the interrupt to this channel
    if (offset != 0U)
    {
        // Channels are offset by one
        offset = offset - 1U;
        // Check to see if interrupt was called on GIO4
        if (offset == 12)
        {
            button1();
        }
        // Check to see if interrupt was called on GIO5
        else if (offset == 13)
        {
            button2();
        }
    }
    // Re-enable the interrupts
    // May be a better way to do this but right now it works.
    // If function not called (specifically sets the CPSR's "I" bit) then interrupt will not be called again.
    _enable_IRQ();
}


void main()
{
    /**
     * Initialize the interrupts
     */
    // Enable the IRQ in the CPU
    _enable_IRQ();
    // Initialize VIM table to empty functions.
    uint32 i;
    for(i = 0; i < 128; i++)
        vimRAM->ISR[i] = s_vim_init[i];
    // Set the GIO high priority interrupt channel to the desired ISR.
    // Offset by one since ISR[0] is reserved
    vimRAM->ISR[10] = &buttonISR;
    // Enable INT9 channel (GIO high priority interrupt)
    // See data sheet for locations of interrupts in the particular device.
    vimREG->REQMASKSET0 |= (1 << 9);
    // Ignore setting the VIM priorities for now and leave at the default.
    // Ignore mapping the interrupt channels and leave at default

    /**
     * SET UP GIO
     */
    // Enable the GIO pins for use
    gioREG->GCR0 |= (1 << 0);
    // Setup the test pins for GIOA and GIOB
    gioPORTB->DIR |= (1 << 6);
    gioPORTB->DOUT &= ~(1 << 6);
    gioPORTB->DIR |= (1 << 7);
    gioPORTB->DOUT &= ~(1 << 7);
    // Set GIOB4 and GIOB5 for input (buttons on LaunchPad)
    gioPORTB->DIR &= ~((1 << 4) | (1 << 5));
    // Ensure that GIOB4 and GIOB5 is triggered on only one edge
    gioREG->INTDET &= ~(3 << 11);
    // Set GIOB4 to rising edge and GIOB5 to falling edge.
    gioREG->POL |= (1 << 12);
    gioREG->POL &= ~(1 << 13);
    // Set interrupt to high priority
    gioREG->LVLSET |= ((1 << 12) | (1 << 13));
    // Make sure that the GIO interrupt flag register is clear
    gioREG->FLG = 0xFF;
    // Enable GIOB interrupts
    gioREG->ENASET |= ((1 << 12) | (1 << 13));


    /**
     * SET UP PINS AS GIOS
     */
    // Testing out changing the I/O ball output mux
    // If the KICKER registers have their unlock values, then ball H3 (offset 19 for the pin mux register)
    // will be dedicated to N2HET2[04]
    // Otherwise it is at the default and dedicated to GIOA[6].
    // NOTE: TO CHANGE WHAT SIGNAL A MUX OUTPUT USES, THESE EXACT VALUES MUST BE PUT INTO BOTH KICK
    //       REGISTERS!
    pinMuxReg->KICKER0 = 0x83E70B13U; // Enable changing of mux outputs
    pinMuxReg->KICKER1 = 0x95A4F1E0U;
    pinMuxReg->PINMUX[19] &= ~(7 << 24); // Change the output on ball H3
    pinMuxReg->PINMUX[19] |= (1 << 26);
    pinMuxReg->KICKER0 = (uint32)0;
    pinMuxReg->KICKER1 = (uint32)0;

    // Enable N2HET1 for use
    hetREG1->GCR |= (1 << 24);

    // Set the direction and initial state of N2HET1 pins
    // NOTE: Originally though that the PINDIS register needed to be set,
    // but on N2HET1 if it is set then the GIO output does not work. N2HET2 still
    // works with PINDIS set for some reason, though...
    hetREG1->DIR |= (1U << 1);
    hetREG1->DSET |= (1U << 1);

    hetREG1->DIR |= (1 << 4);
    hetREG1->DOUT &= ~(1 << 4);

    hetREG1->DIR |= (1 << 7);
    hetREG1->DOUT |= (1 << 7);

    hetREG1->DIR |= (1 << 9);
    hetREG1->DOUT |= (1 << 9);

    hetREG1->DIR |= (1 << 5);
    hetREG1->DOUT |= (1 << 5);

    // Enable N2HET2 for use
    hetREG2->GCR |= (1 << 24);
    // Set the direction and initial state of N2HET1 pins
    hetREG2->DIR |= (1 << 20);
    hetREG2->DOUT |= (1 << 20);

    hetREG2->DIR |= (1 << 19);
    hetREG2->DOUT &= ~(1 << 19);

    hetREG2->DIR |= (1 << 8);
    hetREG2->DSET |= (1 << 8);

    hetREG2->DIR |= (1 << 4);
    hetREG2->DOUT &= ~(1 << 4);

    // Test out using the MibSPI data buses for GIO use
    // Using SOMI
    mibspiREG5->GCR0 |= (1 << 0); // Pull the SPI out of reset state.
    mibspiREG5->PC1 |= (1 << 27); // Set to output
    mibspiREG5->PC3 |= (1 << 27); // Set output to high

    // Using SIMO
    mibspiREG5->PC1 |= (1 << 19);
    mibspiREG5->PC2 |= (1 << 19);

    while (1) {
        // Toggle the various outputs to confirm that they are actually being used as GIO pins
        //gioPORTA->DOUT ^= (1 << 6);
        //hetREG1->DOUT ^= (1 << 4);
        hetREG2->DOUT ^= ((1 << 20) | (1 << 19) | (1 << 4));
        //_enable_IRQ();
        //gioPORTB->DOUT &= ~((1 << 6) | (1 << 7));
        //hetREG2->DOUT ^= (1 << 8);
        //hetREG1->DOUT ^= ((1 << 1) | (1 << 4) | (1 << 7) | (1 << 9)| (1 << 5));
        //mibspiREG5->PC3 ^= ((1 << 27) | (1 << 19));
    }
}



