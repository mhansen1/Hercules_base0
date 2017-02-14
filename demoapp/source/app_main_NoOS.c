#include "HL_reg_system.h"
#include "HL_reg_pinmux.h"
#include "HL_reg_het.h"
#include "HL_reg_gio.h"
#include "HL_reg_mibspi.h"


// Entry point for the program is the function _c_int00(void) in file HL_sys_startup.c

void main()
{
    // Testing out changing the I/O ball output mux
    // If the KICKER registers have their unlock values, then ball H3 (offset 19 for the pin mux register)
    // will be dedicated to N2HET2[04]
    // Otherwise it is at the default and dedicated to GIOA[6].
    // NOTE: TO CHANGE WHAT SIGNAL A MUX OUTPUT USES, THESE EXACT VALUES MUST BE PUT INTO BOTH KICKER
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

    // Enable the GIO pins for use
    gioREG->GCR0 |= (1 << 0);
    // Setup the test pins for GIOA and GIOB
    gioPORTB->DIR |= (3 << 6);
    gioPORTB->DSET |= (3 << 6);
    gioPORTA->DIR |= (1 << 6);
    gioPORTA->DOUT |= (1 << 6);

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
        gioPORTA->DOUT ^= (1 << 6);
        hetREG1->DOUT ^= (1 << 4);
        hetREG2->DOUT ^= ((1 << 20) | (1 << 19) | (1 << 4));
        hetREG2->DOUT ^= (1 << 8);
        hetREG1->DOUT ^= ((1 << 1) | (1 << 4) | (1 << 7) | (1 << 9)| (1 << 5));
        mibspiREG5->PC3 ^= ((1 << 27) | (1 << 19));
    }
}



