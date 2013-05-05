#include <stdio.h>
#include <stdlib.h>
#include <p33Fxxxx.h>


void __attribute__((__interrupt__,no_auto_psv)) _U1RInterrupt(void)
{
    //Obtain data from buffer

    //Clear flag
     IFS0bits.U1RXIF = 0; //Set recieve interrupt flag to 0
}


void initUART(void)
{
    //Include all UART initializations here:
    U1MODEbits.UARTEN = 0; //Disables the UART
    //For now I will not implement: U1MODEbits.USIDL = 0/1 -Discontinues when in sleep/idle
    //U1MODEbits.IREN = 0/1 - encoding/decoding
    U1MODEbits.RTSMD = 0; //Flow control mode or 1 - Simplex mode Simplex = 1 directional
    U1MODEbits.UEN = 0b01; //UXTX,UXRX,UXCTS are used and enabled.
    U1MODEbits.WAKE = 0; //Wake up disabled
    U1MODEbits.LPBACK = 0; //Loopback mode is disabled
    U1MODEbits.ABAUD = 0; //Auto Baud rate measurement disabled
    U1MODEbits.URXINV = 0; //No inversion of transmition line
    U1MODEbits.BRGH = 1; //High speed mode - 16bit clock
    U1MODEbits.PDSEL = 0b00; //NO PARITY - we don't need to know if the bit arrived or not. LOOK UP DOCUMENTATION
    U1MODEbits.STSEL = 0; // 1 stop bit


    //Status Register
    U1STAbits.URXISEL = 0b10; //Interrupt is set when the buffer is 3/4 full

    //Enable Interrupts

    //UART RECIEVE
    IEC0bits.U1RXIE = 1; //Enable recieve interrupt for UART1
    IPC2bits.U1RXIP = 0b100; //This is the default priority
    IFS0bits.U1RXIF = 0; //Set recieve interrupt flag to 0

    //UART ERROR
    //IEC4bits.U1EIE = 1; //Enable error interrupt for UART1
    //IPC16bits.U1EIP = 0b100; //This is te default interrupt priority
    //IFS4bits.U1EIF = 0; //Set error interrupt flag to 0



    U1MODEbits.UARTEN = 1; //Enables the UART
}
