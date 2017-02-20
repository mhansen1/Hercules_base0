#include "HL_sys_common.h"
#include "HL_reg_system.h"
#include "HL_reg_pinmux.h"
#include "HL_reg_het.h"
#include "HL_reg_gio.h"
#include "HL_reg_mibspi.h"
#include "HL_reg_vim.h"
#include "HL_rti.h"
#include "reg_defs.h"
#include "VIM.h"
#include "ROLM.h"


// Entry point for the program is the function _c_int00(void) in file HL_sys_startup.c
// See the ARM compiler guide for more info on the subject

// Clock sources can be found on page 75 of the processor datasheet

/**
 * SETUP ISR ROUTINES
 */
// Need to declare the ISR as an interrupt. If this is not done then if it called during
// another function call, then the will be stuck in that called function. This is because
// in the ARM Cortex-R4/R5 processors, there is only one SPSR and LR for storing the PC
// during branch-and-links. When the ISR is performed there is no automatic functionality
// for storing the old LR value. Found one solution to create custom push/pop routine
// for when an ISR is called. Still trying to figure out how to get it to work (not calling
// the push/pop assembly file when interrupt is fired). However, the #pragma INTERRUPT is
// used then the code is automatically implemented in CCS.
// http://www.ti.com/lit/an/spna219/spna219.pdf (Nested Interrupts on Hercules ARM Cortex-R4/R5 Based Microcontrollers)
// http://www.ti.com/lit/an/spna218/spna218.pdf (Interrupt and Exception Handling on Hercules ARM Cortex-R4/R5 Based Microcontrollers)
#pragma CODE_STATE(buttonISR,32)
#pragma INTERRUPT(buttonISR,IRQ)
// GIO high priority ISR entry point
void buttonISR(void)
{
    // Reading OFF1 or OFF0 clears the register
    uint32 offset = gioREG->OFF1;
    // Make sure that there was not an error in calling the interrupt to this channel
    if (offset != 0U)
    {
        // Channels are offset by one
        offset = offset - 1U;
        // Check to see if interrupt was called on GIO4
        if (offset == 12)
        {
            GIOB->DOUT ^= (1 << 6);
        }
        // Check to see if interrupt was called on GIO5
        else if (offset == 13)
        {
            GIOB->DOUT ^= (1 << 7);
        }
    }
    return;
}

#if 0
// Setup the RTI ISRs
#pragma CODE_STATE(timer1ISR,32)
#pragma INTERRUPT(timer1ISR,IRQ)
void timer1ISR(void) {
    rtiREG1->INTFLAG &= ~1U;
    GIOA->DOUT ^= (1 << 6);
    return;
}

#pragma CODE_STATE(timer2ISR,32)
#pragma INTERRUPT(timer2ISR,IRQ)
void timer2ISR(void) {
    GIOA->DOUT ^= (1 << 1);
    rtiREG1->INTFLAG &= ~2U;
    return;
}
#endif

void rtiNotification(rtiBASE_t *rtiREG,uint32 notification) {
    if(notification == rtiNOTIFICATION_COMPARE0) {
        rtiREG1->INTFLAG &= ~1U;
        gioPORTA->DOUT ^= (1 << 6);
    }
    else if(notification == rtiNOTIFICATION_COMPARE1) {
        rtiREG1->INTFLAG &= ~2U;
        gioPORTA->DOUT ^= (1 << 1);
    }
    return;
}

void main()
{
    /**
     * Initialize the interrupts
     */
    // Set the GIO high priority interrupt channel to the desired ISR.
    // Offset by one since ISR[0] is reserved
    vimRAM->ISR[10] = &buttonISR;
    //vimRAM->ISR[3] = &timer1ISR;
    //vimRAM->ISR[4] = &timer2ISR;
    // See data sheet for locations of interrupts in the particular device.
    vimREG->REQMASKSET0 |= (1 << 9); // GIO high priority interrupt
    vimREG->REQMASKSET0 |= (1 << 2); // RTI0 interrupt
    vimREG->REQMASKSET0 |= (1 << 3); // RTI1 interrupt
    // Ignore setting the VIM priorities for now and leave at the default.
    // Ignore mapping the interrupt channels and leave at default
    // Enable the IRQ in the CPU

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
    gioREG->INTDET &= ~(3 << 12);
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
    //pinMuxReg->KICKER0 = 0x83E70B13U; // Enable changing of mux outputs
    //pinMuxReg->KICKER1 = 0x95A4F1E0U;
    //pinMuxReg->PINMUX[19] &= ~(7 << 24); // Change the output on ball H3
    //pinMuxReg->PINMUX[19] |= (1 << 26);
    //pinMuxReg->KICKER0 = (uint32)0;
    //pinMuxReg->KICKER1 = (uint32)0;
#if 0
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
#endif
    ROLMinit();

    /**
     * SETUP RTI MODULE
     */
    // Set up GIOs to be toggled during the ISRs
    gioPORTA->DIR |= ((1 << 6) | (1 << 1));
    gioPORTA->DCLR |= ((1 << 6) | (1 << 1));

    rtiInit();
    rtiEnableNotification(rtiREG1,rtiNOTIFICATION_COMPARE0);
    rtiEnableNotification(rtiREG1,rtiNOTIFICATION_COMPARE1);
    rtiStartCounter(rtiREG1,rtiCOUNTER_BLOCK0);

    _enable_IRQ();

    while (1) {
        // Toggle the ROLM bus data out pins
        ROLMSDO((uint16_t)0xFFFF);
        ROLMEDO();
        ROLMDDO();
        ROLMSDO((uint16_t)0x0000);
        ROLMEDO();
        ROLMDDO();
        //GIOA->DOUT ^= (1 << 6);
    }
}



