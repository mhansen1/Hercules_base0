/*
 *
 * This header file contains the base and offset addresses for the registers
 *
 */
 
 #ifndef _REGDEFS_H_
 #define _REGDEFS_H_
 
/*
 * INCLUDES
 */
#include <stdio.h>
#include <stdint.h>
#include <reg_defs.h>

/*
 *
 * GENERAL INFO:
 * 1. GCLK = CPU clock
 * 2. HCLK = System clock
 * 3. VCLK & VCLK2 = Peripheral clock
 * 4. LPO = Low Power Oscillator
 * 5. GIO = Generial Input/Output
 */
 
/**
 *
 * Primary system module registers.
 * More info found on page 139 of the technical reference manual
 *
 */ 
typedef volatile struct sysRegDefs1 {
	uint32_t SYSPC1;			// SYS Pin Control Register 1
	uint32_t SYSPC2;			// SYS Pin Control Register 2 
	uint32_t SYSPC3;			// SYS Pin Control Register 3
	uint32_t SYSPC4;			// SYS Pin Control Register 4
	uint32_t SYSPC5;			// SYS Pin Control Register 5
	uint32_t SYSPC6;			// SYS Pin Control Register 6
	uint32_t SYSPC7;			// SYS Pin Control Register 7
	uint32_t SYSPC8;			// SYS Pin Control Register 8
	uint32_t SYSPC9;			// SYS Pin Control Register 9
	uint32_t rsvd1;				// Reserved hardware space 
	uint32_t rsvd2;				// Reserved hardware space 
	uint32_t rsvd3;				// Reserved hardware space 
	uint32_t CSDIS;			// Clock source disable register
	uint32_t CSDISSET; 		// Clock source disable set register 
	uint32_t CSDISCLR;		// Clock source disable clear register 
	uint32_t CDDIS;			// CLock domain disable register 
	uint32_t CDDISSET;		// Clock domain disable set register 
	uint32_t CDDISCLR;		// Clock domain disable clear register 
	uint32_t GHVSRC;			// GCLK, HCLK, VCLK, and VCLK2 source register
	uint32_t VCLKASRC;		// Peripheral asynchronous clock source register 
	uint32_t RCLKSRC;		// RTI clock source register 
	uint32_t CSVSTAT;		// Clock source valid status register  
	uint32_t MSTGCR;			//  Memory self-test global control register 
	uint32_t MINITGCR;		// Memory hardware initialization global control register  
	uint32_t MSINEA;			// Memory self-test/initialization enable register 
	uint32_t rsvd12;			// Reserved hardware space 
	uint32_t MSTCGSTAT;	// MSTC global status register 
	uint32_t MINISTAT;		// Memory Hardware initialization status register 
	uint32_t PLLCTL1;			// PLL control register 1 
	uint32_t PLLCTL2;			// PLL control register 2 
	uint32_t SYSPC10;			// SYS Pin Control Register 10 
	uint32_t DIEIDL;			// Die identification register, lower word 
	uint32_t DIEIDH;			// Die identification register, upper word 
	uint32_t rsvd4;				// Reserved hardware space 
	uint32_t LPOMONCTL;		// LPO/clock monitor control register  
	uint32_t CLKTEST;			// Clock test register 
	uint32_t DFTCTRLREG;	// DFT control register 
	uint32_t DFTCTRLREG2;	// DFT control register 2 
	uint32_t rsvd5;				// Reserved hardware space
	uint32_t rsvd6;				// Reserved hardware space
	uint32_t GPREG1;			// General purpose register
	uint32_t rsvd7;				// Reserved hardware space
	uint32_t rsvd8;				// Reserved hardware space
	uint32_t rsvd9;				// Reserved hardware space
	uint32_t SSIR1;				// System software interrupt request 1 register
	uint32_t SSIR2;				// System software interrupt request 2 register
	uint32_t SSIR3;				// System software interrupt request 3 register
	uint32_t SSIR4;				// System software interrupt request 4 register
	uint32_t RAMGCR;			// RAM control register 
	uint32_t BMMCR1;			// Bus matrix module control register 1
	uint32_t rsvd10;			// Reserved hardware space
	uint32_t CPURSTCR;		// CPU reset control register 
	uint32_t CLKCNTL;			// Clock control register 
	uint32_t ECPCNTL;			// ECP control register 
	uint32_t rsvd11;			// Reserved hardware space
	uint32_t DEVCR1;			// DEV parity control register 1
	uint32_t SYSECR;			// System exception control register 
	uint32_t SYSESR;			// System exception status register 
	uint32_t SYSTASR;			// System test abort status register 
	uint32_t GBLSTAT;			// Global status register
	uint32_t DEVID;				// Device identification register
	uint32_t SSIVEC;			// Software interrupt vector register 
	uint32_t SSIF;				// System software interrupt flag register
} sysRegDefs1_t;
// Set the base address for the primary system registers 
#define SYSREG1 ((sysRegDefs1_t *)0xFFFFFF00U)
 
/**
 *
 * Secondary system module registers.
 * More info found on page 191 of the technical reference manual
 *
 */ 
typedef volatile struct sysRegDefs2 {
	uint32_t PLLCTL3;			// PLL control register 3
	uint32_t rsvd1;				// Reserved hardware space 
	uint32_t STCCLKDIV;		// CPU logic BIST clock divider
	uint32_t rsvd2;				// Reserved hardware space
	uint32_t ECPCNTL;			// ECP control register. The ECPCNTL register has the mirrored location at this address 
	uint32_t ECPCNTL1;		// ECP control register 1
	uint32_t rsvd3;				// Reserved hardware space
	uint32_t CLK2CNTRL;		// Clock 2 control register 
	uint32_t VCLKACON1;	// Peripheral asynchronous clock configuration 1 register 
	uint32_t rsvd4;				// Reserved hardware space
	uint32_t HCLKCNTL;		// HCLK control register
	uint32_t rsvd5;				// Reserved hardware space
	uint32_t CLKCLIP;			// Clock slip control register 
	uint32_t rsvd6;				// Reserved hardware space
	uint32_t IP1ECCERREN;	// IP ECC error enable register 
	uint32_t rsvd7;				// Reserved hardware space
	uint32_t EFC_CTLREG;	// EFUSE controller control register
	uint32_t DIEDL_REG0;	// Die identification register, lower word
	uint32_t DIEDH_REG1;	// Die identification register, upper word
	uint32_t DIEDL_REG2;	// Die identification register, lower word
	uint32_t DIEDH_REG3;	// Die identification register, upper word	
} sysRegDefs2_t;
// Set the base address for the secondary system registers 
#define SYSREG2 ((sysRegDefs2_t *)0xFFFFE100U)
 
 
/**
 *
 * Setup the GIO configuration control registers 
 *
 */
 typedef volatile struct gioCntlRegDefs {
	uint32_t GCR0;		// GIO global control register
	uint32_t rsvd1;				// Reserved hardware space
	uint32_t INTDET;		// GIO interrupt detect register
	uint32_t POL;			// GIO interrupt polarity register
	uint32_t ENASET;		// GIO interrupt enable set register
	uint32_t ENACLR;		// GIO interrupt enable clear register
	uint32_t LVLSET;		// GIO interrupt priority set register
	uint32_t LVLCLR;		// GIO interrupt priority clear register
	uint32_t FLG;			// GIO interrupt flag register
	uint32_t OFF1;			// GIO offset 1 register
	uint32_t OFF2;			// GIO offset 2 register
	uint32_t EMU1;			// GIO emulation 1 register
	uint32_t EMU2;			// GIO emulation 2 register
} gioCntlRegDefs_t;
// Set base address for the GIO control registers 
#define GIOCNTL ((gioCntlRegDefs_t *)0xFFF7BC00U)
 
/*
 *
 * Setup the GIO port control registers
 *
 */
 typedef volatile struct gioPortRegDefs {
	uint32_t DIR;					// GIO data direction register 
	uint32_t DIN;					// GIO data input register 
	uint32_t DOUT;				// GIO data output register 
	uint32_t DSET;				// GIO data set register 
	uint32_t DCLEAR;			// GIO data clear registers 
	uint32_t PDR;				// GIO open drain register 
	uint32_t PULDIS;			// GIO pull disable register 
	uint32_t PSL;					// GIO pull select register 
} gioPortRegDefs_t;
// Set base address for GIO port A
#define GIOA ((gioPortRegDefs_t *)0xFFF7BC34U)
// Set base address for GIO port A
#define GIOB ((gioPortRegDefs_t *)0xFFF7BC54U)
 
/**
 *
 * Peripheral Central Recource (PCR) Control Registers
 * More info on these can be found on page 203 of the technical manual
 *
 */
 
/** TODO: 
 *    This is still in the format of TI's given register file. May need to redo because of copywrite stuffs.
 *    Mainly need to look some more at the PCR section and figure out exaclt how things with a 'x' function
 *    (such as PSxMSTID[32]). To just write out all the registers would be a monsterous task.
 */
 typedef volatile struct pcrRegDefs
{
    uint32_t PMPROTSET0;    /* 0x0000 */
    uint32_t PMPROTSET1;    /* 0x0004 */
    uint32_t rsvd1[2U];     /* 0x0008 */
    uint32_t PMPROTCLR0;    /* 0x0010 */
    uint32_t PMPROTCLR1;    /* 0x0014 */
    uint32_t rsvd2[2U];     /* 0x0018 */
    uint32_t PPROTSET0;     /* 0x0020 */
    uint32_t PPROTSET1;     /* 0x0024 */
    uint32_t PPROTSET2;     /* 0x0028 */
    uint32_t PPROTSET3;     /* 0x002C */
    uint32_t rsvd3[4U];     /* 0x0030 */
    uint32_t PPROTCLR0;     /* 0x0040 */
    uint32_t PPROTCLR1;     /* 0x0044 */
    uint32_t PPROTCLR2;     /* 0x0048 */
    uint32_t PPROTCLR3;     /* 0x004C */
    uint32_t rsvd4[4U];     /* 0x0050 */
    uint32_t PCSPWRDWNSET0; /* 0x0060 */
    uint32_t PCSPWRDWNSET1; /* 0x0064 */
    uint32_t rsvd5[2U];     /* 0x0068 */
    uint32_t PCSPWRDWNCLR0; /* 0x0070 */
    uint32_t PCSPWRDWNCLR1; /* 0x0074 */
    uint32_t rsvd6[2U];     /* 0x0078 */
    uint32_t PSPWRDWNSET0;  /* 0x0080 */
    uint32_t PSPWRDWNSET1;  /* 0x0084 */
    uint32_t PSPWRDWNSET2;  /* 0x0088 */
    uint32_t PSPWRDWNSET3;  /* 0x008C */
    uint32_t rsvd7[4U];     /* 0x0090 */
    uint32_t PSPWRDWNCLR0;  /* 0x00A0 */
    uint32_t PSPWRDWNCLR1;  /* 0x00A4 */
    uint32_t PSPWRDWNCLR2;  /* 0x00A8 */
    uint32_t PSPWRDWNCLR3;  /* 0x00AC */
    uint32_t rsvd8[4U];     /* 0x00B0 */
    uint32_t PDPWRDWNSET;   /* 0x00C0 */
    uint32_t PDPWRDWNCLR;   /* 0x00C4 */
    uint32_t rsvd9[78U];    /* 0x00C8 */
    uint32_t MSTIDWRENA;    /* 0x0200 */
    uint32_t MSTIDENA;      /* 0x0204 */
    uint32_t MSTIDDIAGCTRL; /* 0x0208 */
    uint32_t rsvd10[61U];   /* 0x020C */
    struct
    {
        uint32_t PSxMSTID_L;
        uint32_t PSxMSTID_H;
    }PSxMSTID[32];            /* 0x0300 */
    struct
    {
        uint32_t PPSxMSTID_L;
        uint32_t PPSxMSTID_H;
    }PPSxMSTID[8];            /* 0x0400 */
    struct
    {
        uint32_t PPSExMSTID_L;
        uint32_t PPSExMSTID_H;
    }PPSExMSTID[32];            /* 0x0440 */
    uint32_t PCSxMSTID[32];    /* 0x0540 */
    uint32_t PPCSxMSTID[8];    /* 0x05C0 */
} pcrRegDefs_t;
// Set base address of PCR register 1
#define PCRREG1 ((pcrRegDefs_t *)0xFFFF1000U)
// Set base address of PCR register 2
#define PCRREG2 ((pcrRegDefs_t *)0xFCFF1000U)
// Set base address of PCR register 3
#define PCRREG3 ((pcrRegDefs_t *)0xFFF78000U)


/**
 *
 * Pin multiplexing register (I/O Multiplexing and Control Module (IOMM))
 * For more info see page 313 of the technical manual
 * For a table on the pin functions see tables 6-1 (page 289), 6-2 (page 294)
 * and 6-3 (page 297) of the technical manual
 * Register info found on page 313 of the technical manual
 * 
 */
typedef volatile struct muxRegDefs {
	uint32_t REGISION_REG;		// Revision register
	uint32_t rsvd1[7];			// Reserved hardware space
	uint32_t BOOT_REG;			// Boot mode register
	uint32_t rsvd2[5];			// Reserved hardware space
	uint32_t KICK_REG0;			// Kicker register 0. Write 0x83E70B13 to unlock CPU write acess to PINMMRnn registers
	uint32_t KICK_REG1; 		// Kicker register 1. Write 0x95A4F1E0 to unlock CPU write acess to PINMMRnn registers
	uint32_t rsvd3[40];			// Reserved hardware space
	uint32_t ERR_RAW_STATUS_REG;// Error raw status/set register
	uint32_t ERR_ENABLED_STATUS_REG;// Error enabled status/clear register
	uint32_t ERR_ENABLE_REG;	// Error signalling enable register
	uint32_t ERR_ENABLE_CLR_REG;// Error signalling enable clear register
	uint32_t rsvd4;				// Reseverd hardware space
	uint32_t FAULT_ADDRESS_REG;	// Fault address register
	uint32_t FAULT_STATUS_REG;	// Fault status register
	uint32_t FAULT_CLEAR_REG;	// Fault clear register
	uint32_t rsvd5[4];			// Reserved hardware space
	uint32_t PINMUXOUT[38];		// Output pin multiplexing control registers
	uint32_t rsvd6[42];			// Reserved hardware space 
	uint32_t PINMUXIN[20];		// Input pin multiplexing control registers
	uint32_t rsvd[60];			// Reserved hardware space
	uint32_t PINMUXSPCL[20];	// Special functionality control registers
} muxRegDefs_t;
// Set base address for the I/O pin multiplexer
#define IOMMREG ((muxRegDefs_t *)0xFFFF1C00)
 
 /**
 *
 * High End Timer (HET) register definitions
 * For more info see page 968 of the technical manual.
 * 
 */
typedef volatile struct hetRegDefs {
	uint32_t GCR;			/**	Global configuration register	*/
	uint32_t PFR;			/**	Prescale factor register		*/
	uint32_t ADDR;			/**	NHET current address register	*/
	uint32_t OFF1;			/**	Offset index priority level 1 register	*/
	uint32_t OFF2;			/**	Offset index priority level 2 register	*/
	uint32_t INTENAS;	/**	Interrupt enable set register	*/
	uint32_t INTENAC;	/**	Interrupt enable clear register	*/
	uint32_t EXC1;			/**	Exception control register 1	*/
	uint32_t EXC2;			/**	Exception control register 2	*/
	uint32_t PRY;			/**	Interrupt priority register	*/
	uint32_t FLG;			/**	Interrupt flag register	*/
	uint32_t AND;			/**	AND share control register	*/
	uint32_t rsvd1;			/**	Reseverd hardware space	*/
	uint32_t HRSH;			/**	HR share control regsiter	*/
	uint32_t XOR;			/**	HR XOR share control register	*/
	uint32_t REQENS;		/**	Request enable set register	*/
	uint32_t REQENC;		/**	Request enable clear register	*/
	uint32_t REQDS;		/**	Request destination select register	*/
	uint32_t rsvd2;			/**	Reserved hardware space	*/
	uint32_t DIR;			/**	NHET direction register	*/
	uint32_t DIN;			/**	NHET data input register	*/
	uint32_t DOUT;			/**	NHET data output register	*/
	uint32_t DSET;			/**	NHET set output register	*/
	uint32_t DCLR;			/**	NHET clear output register	*/
	uint32_t PDR;			/**	NHET open drain register	*/
	uint32_t PULDIS;		/**	NHET pull disable register	*/
	uint32_t PSL;			/**	NHET pull select register	*/
	uint32_t rsvd3;			/**	Reserved hardware space	*/
	uint32_t rsvd4;			/** Reserved hardware space	*/
	uint32_t PCR;			/**	Parity control register	*/
	uint32_t PAR;			/**	Parity address register	*/
	uint32_t PPR;			/**	Parity pin register	*/
	uint32_t SFPRLD;		/**	Suppression filter preload register	*/
	uint32_t SFENA;		/**	Suppression filter enable register	*/
	uint32_t rsvd5;			/**	Reserved hardware space	*/
	uint32_t LBPSEL;		/**	Loop back pair select register	*/
	uint32_t LBPDIR;		/**	Loop back pair direction register	*/
	uint32_t PINDIS;		/**	NHET pin disable registe	*/
} hetRegDefs_t;
// Set the base for the HET modules (HET1 and HET2)
#define HET1REG ((hetRegDefs_t *)0xFFF7B800U)
#define HET2REG ((hetRegDefs_t *)0xFFF7B900U)

#endif
 
 /**
  *
  * USEFUL STUFFS!
  *
  * Declaring register names and addresses: http://www.embedded.com/electronics-blogs/programming-pointers/4025002/Mapping-memory
  * Helps to make structs a bit more clear: http://stackoverflow.com/questions/1675351/typedef-struct-vs-struct-definitions
  * 
  */
