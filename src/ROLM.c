/**
 *
 * INCLUDES
 *
 */
#include "ROLM.h"

/**
 *
 * Initialize all of the ROLM data pins as GIOs
 *
 */
 void ROLMinit(void) {
	 // Make sure that HET2 is enabled
	 if(HET2REG->GCR & (1 << 24))
		HET2REG->GCR |= (1 << 24);
	// Set the DOUT pins  direction
	HET2REG->DIR |= 0xFFFF;
	// Initialize the DOUT of the outputs to zero (known state)
	HET2REG->DOUT &= ~(0xFFFF);
	
	// Make sure that HET1 is enabled
	if(HET1REG->GCR & (1 << 24))
		HET1REG->GCR |= (1 << 24);
	// Set the DIN pins to inputs  (Pins 0 through 15)
	HET1REG->DIR &= ~(0x17FFF);
	
	return;
}

/**
 *
 * Set data to the output bus
 *
 */
void setDATOUT(uint16_t dat) {
	ROLMBUS->DOUT = dat;
	return;
}

/**
 *
 * Set the bus pins to the set valies
 *
 */
void ENADOUT(void) {
	HET2REG->DOUT |= HET2REG->DOUT;
	return;
}

/**
 *
 * Read in data from the input bus
 *
 */
uint16_t getDATIN(void) {
	uint16_t dat = (HET1REG->DIN & 0x07FFF);
	dat |= (HET1REG->DIN & 0x10000);
	return dat;
}














