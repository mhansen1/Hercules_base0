/**
 * SETUP INTERRUPT CAPABILITY
 */
 
// extern void buttonISR(void);
 
// Define the type used for the interrupt ISR function.
typedef void (*callback)(void);
// Define the struct for the VIM ISR functions in RAM.
typedef volatile struct vimRam {
	callback ISR[128U];
} vimRAM_t;
// Set up the starting address of the VIM RAM
#define vimRAM ((vimRAM_t *)0xFFF82000U)
// Ensure that the phantom interrupt is compiles in 32 bit and not 16 bit
#pragma CODE_STATE(phantomInterrupt, 32)
// Assign the phantomInterrupt to interrupts (specifically IRQs)
#pragma INTERRUPT(phantomInterrupt, IRQ)
// Set the phantomInterrupt function to "weak" (will not create linker errors if undefined).
#pragma WEAK(phantomInterrupt)
void phantomInterrupt(void) { }

static const callback s_vim_init[128U] =
{
    &phantomInterrupt,
    &phantomInterrupt,        /* Channel 0   */
    &phantomInterrupt,        /* Channel 1   */
    &phantomInterrupt,        /* Channel 2   */
    &phantomInterrupt,        /* Channel 3   */
    &phantomInterrupt,        /* Channel 4   */
    &phantomInterrupt,        /* Channel 5   */
    &phantomInterrupt,          /* Channel 6   */
    &phantomInterrupt,          /* Channel 7   */
    &phantomInterrupt,          /* Channel 8   */
    &phantomInterrupt,          /* Channel 9   */
    &phantomInterrupt,          /* Channel 10  */
    &phantomInterrupt,          /* Channel 11  */
    &phantomInterrupt,          /* Channel 12  */
    &phantomInterrupt,          /* Channel 13  */
    &phantomInterrupt,          /* Channel 14  */
    &phantomInterrupt,          /* Channel 15  */
    &phantomInterrupt,          /* Channel 16  */
    &phantomInterrupt,          /* Channel 17  */
    &phantomInterrupt,          /* Channel 18  */
    &phantomInterrupt,          /* Channel 19  */
    &phantomInterrupt,       /* Channel 20  */
    &phantomInterrupt,          /* Channel 21  */
    &phantomInterrupt,          /* Channel 22  */
    &phantomInterrupt,          /* Channel 23  */
    &phantomInterrupt,          /* Channel 24  */
    &phantomInterrupt,          /* Channel 25  */
    &phantomInterrupt,          /* Channel 26  */
    &phantomInterrupt,          /* Channel 27  */
    &phantomInterrupt,          /* Channel 28  */
    &phantomInterrupt,          /* Channel 29  */
    &phantomInterrupt,          /* Channel 30  */
    &phantomInterrupt,          /* Channel 31  */
    &phantomInterrupt,          /* Channel 32  */
    &phantomInterrupt,          /* Channel 33  */
    &phantomInterrupt,          /* Channel 34  */
    &phantomInterrupt,          /* Channel 35  */
    &phantomInterrupt,          /* Channel 36  */
    &phantomInterrupt,          /* Channel 37  */
    &phantomInterrupt,          /* Channel 38  */
    &phantomInterrupt,          /* Channel 39  */
    &phantomInterrupt,          /* Channel 40  */
    &phantomInterrupt,          /* Channel 41  */
    &phantomInterrupt,          /* Channel 42  */
    &phantomInterrupt,          /* Channel 43  */
    &phantomInterrupt,          /* Channel 44  */
    &phantomInterrupt,          /* Channel 45  */
    &phantomInterrupt,          /* Channel 46  */
    &phantomInterrupt,          /* Channel 47  */
    &phantomInterrupt,          /* Channel 48  */
    &phantomInterrupt,          /* Channel 49  */
    &phantomInterrupt,          /* Channel 50  */
    &phantomInterrupt,          /* Channel 51  */
    &phantomInterrupt,          /* Channel 52  */
    &phantomInterrupt,          /* Channel 53  */
    &phantomInterrupt,          /* Channel 54  */
    &phantomInterrupt,          /* Channel 55  */
    &phantomInterrupt,          /* Channel 56  */
    &phantomInterrupt,          /* Channel 57  */
    &phantomInterrupt,          /* Channel 58  */
    &phantomInterrupt,          /* Channel 59  */
    &phantomInterrupt,          /* Channel 60  */
    &phantomInterrupt,          /* Channel 61  */
    &phantomInterrupt,          /* Channel 62  */
    &phantomInterrupt,          /* Channel 63  */
    &phantomInterrupt,          /* Channel 64  */
    &phantomInterrupt,          /* Channel 65  */
    &phantomInterrupt,          /* Channel 66  */
    &phantomInterrupt,          /* Channel 67  */
    &phantomInterrupt,          /* Channel 68  */
    &phantomInterrupt,          /* Channel 69  */
    &phantomInterrupt,          /* Channel 70  */
    &phantomInterrupt,          /* Channel 71  */
    &phantomInterrupt,          /* Channel 72  */
    &phantomInterrupt,          /* Channel 73  */
    &phantomInterrupt,          /* Channel 74  */
    &phantomInterrupt,          /* Channel 75  */
    &phantomInterrupt,          /* Channel 76  */
    &phantomInterrupt,          /* Channel 77  */
    &phantomInterrupt,          /* Channel 78  */
    &phantomInterrupt,          /* Channel 79  */
    &phantomInterrupt,          /* Channel 80  */
    &phantomInterrupt,          /* Channel 81  */
    &phantomInterrupt,          /* Channel 82  */
    &phantomInterrupt,          /* Channel 83  */
    &phantomInterrupt,          /* Channel 84  */
    &phantomInterrupt,          /* Channel 85  */
    &phantomInterrupt,          /* Channel 86  */
    &phantomInterrupt,          /* Channel 87  */
    &phantomInterrupt,          /* Channel 88  */
    &phantomInterrupt,          /* Channel 89  */
    &phantomInterrupt,          /* Channel 90  */
    &phantomInterrupt,          /* Channel 91  */
    &phantomInterrupt,          /* Channel 92  */
    &phantomInterrupt,          /* Channel 93  */
    &phantomInterrupt,          /* Channel 94  */
    &phantomInterrupt,          /* Channel 95  */
    &phantomInterrupt,          /* Channel 96  */
    &phantomInterrupt,          /* Channel 97  */
    &phantomInterrupt,          /* Channel 98  */
    &phantomInterrupt,          /* Channel 99  */
    &phantomInterrupt,          /* Channel 100 */
    &phantomInterrupt,          /* Channel 101 */
    &phantomInterrupt,          /* Channel 102 */
    &phantomInterrupt,          /* Channel 103 */
    &phantomInterrupt,          /* Channel 104 */
    &phantomInterrupt,          /* Channel 105 */
    &phantomInterrupt,          /* Channel 106 */
    &phantomInterrupt,          /* Channel 107 */
    &phantomInterrupt,          /* Channel 108 */
    &phantomInterrupt,          /* Channel 109 */
    &phantomInterrupt,          /* Channel 110 */
    &phantomInterrupt,          /* Channel 111 */
    &phantomInterrupt,          /* Channel 112 */
    &phantomInterrupt,          /* Channel 113 */
    &phantomInterrupt,          /* Channel 114 */
    &phantomInterrupt,          /* Channel 115 */
    &phantomInterrupt,          /* Channel 116 */
    &phantomInterrupt,          /* Channel 117 */
    &phantomInterrupt,          /* Channel 118 */
    &phantomInterrupt,          /* Channel 119 */
    &phantomInterrupt,          /* Channel 120 */
    &phantomInterrupt,          /* Channel 121 */
    &phantomInterrupt,          /* Channel 122 */
    &phantomInterrupt,          /* Channel 123 */
    &phantomInterrupt,          /* Channel 124 */
    &phantomInterrupt,          /* Channel 125 */
    &phantomInterrupt,          /* Channel 126 */
};


