/**
 * SETUP INTERRUPT CAPABILITY
 */
 
// Define the type used for the interrupt ISR function.
typedef void (*callback)(void);
// Define the struct for the VIM ISR functions in RAM.
typedef volatile struct vimRam {
	callback ISR[128U];
} vimRAM_t;
// Set up the starting address of the VIM RAM
#define vimRAM ((vimRAM_t *)0xFFF82000U)

