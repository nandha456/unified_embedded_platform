ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 256K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

/* Top of RAM — used as the initial stack pointer */
_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
    /*
     * Interrupt Vector Table
     * Must be at the beginning of Flash.
     */
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH


    /*
     * Program code + read-only data
     */
    .text :
    {
        . = ALIGN(4);

        *(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)

        . = ALIGN(4);

        _etext = .;
    } > FLASH


    /*
     * Initialized variables.
     *
     * Runtime location: RAM
     * Initial values:    stored in Flash
     */
    .data :
    {
        . = ALIGN(4);

        _sdata = .;

        *(.data)
        *(.data*)

        . = ALIGN(4);

        _edata = .;
    } > RAM AT > FLASH


    /*
     * Address in FLASH containing
     * the initial values for .data.
     */
    _sidata = LOADADDR(.data);


    /*
     * Zero-initialized variables.
     *
     * startup.c clears this region before main().
     */
    .bss :
    {
        . = ALIGN(4);

        _sbss = .;

        *(.bss)
        *(.bss*)
        *(COMMON)

        . = ALIGN(4);

        _ebss = .;
    } > RAM


    /*
     * Discard things we don't need for
     * this minimal bare-metal firmware.
     */
    /DISCARD/ :
    {
        *(.comment)
        *(.note*)
    }
}
