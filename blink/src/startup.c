#include <stdint.h>

    extern int main(void);

    extern unsigned long _estack;
    extern unsigned long _sidata;
    extern unsigned long _sdata;
    extern unsigned long _edata;
    extern unsigned long _sbss;
    extern unsigned long _ebss;

    void Reset_Handler(void);
    void Default_Handler(void);

    void NMI_Handler(void)
        __attribute__((weak, alias("Default_Handler")));

    void HardFault_Handler(void)
        __attribute__((weak, alias("Default_Handler")));

    __attribute__((section(".isr_vector")))
    const void* vector_table[] =
    {
        &_estack,
        Reset_Handler,
        NMI_Handler,
        HardFault_Handler
    };

    void Reset_Handler(void)
    {
        unsigned long* src = &_sidata;
        unsigned long* dst = &_sdata;

        while (dst < &_edata)
    {
        *dst++ = *src++;
    }

        dst = &_sbss;

        while (dst < &_ebss)
    {
        *dst++ = 0;
    }

        main();

        while (1)
        {
        }
    }

    void Default_Handler(void)
    {
        while (1)
        {
        }
    }
