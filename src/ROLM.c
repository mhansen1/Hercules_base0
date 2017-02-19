/**
 *
 * INCLUDES
 *
 */
#include "ROLM.h"

/**
 * LOCAL VARIABLES
 */
struct ROLMIO_t ROLMBUS;

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
void ROLMSDO(uint16_t dat) {
	ROLMBUS.DOUT = dat;
	return;
}

/**
 *
 * Set the bus pins to the set valies
 *
 */
void ROLMEDO(void) {
	// Clear the current values
	HET2REG->DOUT &= ~(0xFFFF);
	// Set new values
	HET2REG->DOUT |= ROLMBUS.DOUT;

	return;
}

/**
 *
 * Disable the output
 *
 */
void ROLMDDO(void) {
	HET2REG->DOUT &= ~(0xFFFF);
	return;
}

/**
 *
 * Read in data from the input bus
 *
 */
uint16_t ROLMRDI(void) {
	// Get bits 0 through 14
	uint16_t dat = (HET1REG->DIN & 0x07FFF);
	// Get bit 15
	dat |= (HET1REG->DIN & 0x10000);
	// Store the input 
	ROLMBUS.DIN = dat;
	return dat;
}












