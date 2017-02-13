#include "HL_reg_system.h"
#include "HL_reg_pinmux.h"
#include "HL_reg_het.h"
#include "HL_reg_gio.h"
#include "HL_reg_mibspi.h"


// Entry point for the program is the function _c_int00(void) in file HL_sys_startup.c

void main()
{


    pinMuxReg->KICKER0 = 0x83E70B13U;
    pinMuxReg->KICKER1 = 0x95A4F1E0U;
    pinMuxReg->PINMUX[19] &= ~(7 << 24);
    pinMuxReg->PINMUX[19] |= (1 << 26);
    pinMuxReg->PINMUX[28] &= ~(7 << 8);
    pinMuxReg->PINMUX[28] |= (1 << 8);
    pinMuxReg->KICKER0 = (uint32)0;
    pinMuxReg->KICKER1 = (uint32)0;

    //hetREG1->GCR &= ~(1 << 0); // Turn off the N2HET1
    hetREG1->GCR |= (1 << 24);
    hetREG1->DIR |= (1U << 1);
    hetREG1->PINDIS |= (1U << 1);
    hetREG1->DSET |= (1U << 1);
    hetREG1->DIR |= (1 << 4);
    hetREG1->PINDIS |= (1 << 4);
    hetREG1->DOUT &= ~(1 << 4);
    hetREG1->DIR |= (1 << 7);
    hetREG1->PINDIS |= (1 << 7);
    hetREG1->DOUT |= (1 << 7);
    hetREG1->DIR |= (1 << 9);
    hetREG1->PINDIS |= (1 << 9);
    hetREG1->DOUT |= (1 << 9);

    hetREG2->GCR |= (1 << 24);
    hetREG2->DIR |= (1 << 20);
    hetREG2->PINDIS |= (1 << 20);
    hetREG2->DOUT |= (1 << 20);

    hetREG2->DIR |= (1 << 19);
    hetREG2->PINDIS |= (1 << 19);
    hetREG2->DOUT &= ~(1 << 19);

    hetREG2->DIR |= (1 << 8);
    hetREG2->PINDIS |= (1 << 8);
    hetREG2->DSET |= (1 << 8);

    hetREG2->DIR |= (1 << 4);
    hetREG2->PINDIS |= (1 << 4);
    hetREG2->DOUT &= ~(1 << 4);

    gioREG->GCR0 |= (1 << 0);
    gioPORTB->DIR |= (3 << 6);
    gioPORTB->DSET |= (3 << 6);
    gioPORTA->DIR |= (1 << 6);
    gioPORTA->DOUT |= (1 << 6);

    // Using SOMI
    mibspiREG5->GCR0 |= (1 << 0); // Pull the SPI out of reset state.
    mibspiREG5->PC1 |= (1 << 27); // Set to output
    mibspiREG5->PC3 |= (1 << 27); // Set output to high

    // Using SIMO
    mibspiREG5->PC1 |= (1 << 19);
    mibspiREG5->PC2 |= (1 << 19);

    while (1) {

        gioPORTA->DOUT ^= (1 << 6);
        hetREG1->DOUT ^= (1 << 4);
        hetREG2->DOUT ^= ((1 << 20) | (1 << 19) | (1 << 4));
        hetREG2->DOUT ^= (1 << 8);
        hetREG1->DOUT ^= ((1 << 1) | (1 << 4) | (1 << 7) | (1 << 9));
        mibspiREG5->PC3 ^= ((1 << 27) | (1 << 19));
    }
}



