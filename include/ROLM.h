/**
 *
 * ALIAS FILE FOR ROLM I/O PORTS
 *
 */
#ifndef _ROLM_H_
#define _ROLM_H_
 
#include "reg_defs.h"	// Contains the register definitions
#include <stdint.h>
 
// Use N2HET1 for input data.
//		DIN0 - J10[20] - N2HET1[0]
//		DIN1 - J10[21] - N2HET1[1]
//		DIN2 - J4[1] - N2HET1[2]
//		DIN3 - J10[22] - N2HET1[3]
//		DIN4 - J1[9] - N2HET1[4]
//		DIN5 - J10[25] - N2HET1[5]
//		DIN6 - J1[3] - N2HET1[6]
//		DIN7 - J10[28] - N2HET1[7]
//		DIN8 - J8[3] - N2HET1[8]
//		DIN9 - J1[10] - N2HET1[9]
//		DIN10 - J8[1] - N2HET1[10]
//		DIN11 - J8[6] - N2HET1[11]
//		DIN12 - J4[6] - N2HET1[12]
//		DIN13 - J1[4] - N2HET1[13]
//		DIN14 - J4[5] - N2HET1[14]
//		DIN15 - J4[3] - NHET1[16]

// Use N2HET2 for output data.
//		DOUT0 - J9[5] - N2HET2[0]
//		DOUT1 - J9[6] - N2HET2[1]
//		DOUT2 - J9[18] - N2HET2[2]
//		DOUT3 - J9[17] - N2HET2[3]
//		DOUT4 - J9[14] - N2HET2[4]
//		DOUT5 - J9[11] - N2HET2[5]
//		DOUT6 - J9[7] - N2HET2[6]
//		DOUT7 - J9[20] - N2HET2[7]
//		DOUT8 - J10[19] - N2HET2[8]
//		DOUT9 - J9[27] - N2HET2[9]
//		DOUT10 - J9[26] - N2HET2[10]
//		DOUT11 - J9[24] - N2HET2[11]
//		DOUT12 - J10[47] - N2HET2[12]
//		DOUT13 - J10[46] - N2HET2[13]
//		DOUT14 - J9[22] - N2HET2[14]
//		DOUT15 - J10[33] - N2HET2[15]

/*
 * Struct to create ROLM data bus.
 */
 
typedef volatile struct ROLMIO_t {
	uint16_t DIN;			/** 	INPUT DATA	*/
	uint16_t DOUT;			/** 	OUTPUT DATA	*/
	uint16_t DS;				/**	DEVICE SELECT	*/
	uint8_t   DATOA;		/**	DATA OUT A */
	uint8_t   DATOB;		/**	DATA OUT B	*/
	uint8_t   DATOC;		/**	DATA OUT C */
	uint8_t   DATIA;		/**	DATA IN A	*/
	uint8_t   DATIB;		/**	DATA IN B	*/
	uint8_t   DATIC;		/**	DATA IN C	*/
	uint8_t   STRT;			/**	START SIGNAL	*/
	uint8_t   CLR;			/**	CLEAR SIGNAL	*/
	uint8_t   IOPLS;		/**	I/O PULSE		*/
	uint8_t   SELB;			/**	SELECT BUSY (ACTIVE LOW)	*/
	uint8_t   SELD;			/**	SELECT DONE (ACTIVE LOW)	*/
	uint8_t   IORST;		/**	I/O RESET	*/
	uint8_t   INTR;			/**	INTERRUPT REQUEST (ACTIVE LOW)	*/
	uint8_t   INTA;			/**	INTERRUPT ACKNOWLEDGE	*/
	uint8_t   INTP;			/**	INTERRUPT PRIORITY (ACTIVE LOW)	*/
	uint8_t   MSKO;		/**	MASK OUT (ACTIVE LOW)	*/
	uint8_t   RQENB;		/**	REQUEST ENABLE (ACTIVE LOW)	*/
	uint8_t   DCHR;		/**	DATA CHANNEL REQUEST (ACTIVE LOW)	*/
	uint8_t   DCHA;		/**	DATA CHANNEL ACKNOWLEDGE (ACTIVE LOW)	*/
	uint8_t   DCHP;			/**	DATA CHANNEL PRIORITY (ACTIVE LOW)	*/
	uint8_t   DCHM0;		/**	DATA CHANNEL MODE 0 (ACTIVE LOW)	*/
	uint8_t   DCHM1;		/**	DATA CHANNEL MODE 1 (ACTIVE LOW)	*/
	uint8_t   DCHS;		/**	DATA CHANNEL HIGH SPEED	*/
	uint8_t   DCHO;		/**	DATA CHANNEL OUT	*/
	uint8_t   OVFLO;		/**	OVERFLOW	*/
} ROLMIO_t;

void ROLMinit(void);
void ROLMSDO(uint16_t dat);
void ROLMEDO(void);
void ROLMDDO(void);
uint16_t ROLMRDI(void);
void test_func(void);
void test_func2(void);

#endif


