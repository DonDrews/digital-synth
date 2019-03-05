
// PIC24F32KA302 Configuration Bit Settings

// 'C' source line config statements

// FBS
#pragma config BWRP = OFF               // Boot Segment Write Protect (Disabled)
#pragma config BSS = OFF                // Boot segment Protect (No boot program flash segment)

// FGS
#pragma config GWRP = OFF               // General Segment Write Protect (General segment may be written)
#pragma config GSS0 = OFF               // General Segment Code Protect (No Protection)

// FOSCSEL
#pragma config FNOSC = FRCPLL           // Oscillator Select (Fast RC Oscillator with Postscaler and PLL Module (FRCDIV+PLL))
#pragma config SOSCSRC = ANA            // SOSC Source Type (Analog Mode for use with crystal)
#pragma config LPRCSEL = HP             // LPRC Oscillator Power and Accuracy (High Power, High Accuracy Mode)
#pragma config IESO = OFF               // Internal External Switch Over bit (Internal External Switchover mode disabled (Two-speed Start-up disabled))

// FOSC
#pragma config POSCMOD = NONE           // Primary Oscillator Configuration bits (Primary oscillator disabled)
#pragma config OSCIOFNC = OFF           // CLKO Enable Configuration bit (CLKO output disabled)
#pragma config POSCFREQ = HS            // Primary Oscillator Frequency Range Configuration bits (Primary oscillator/external clock input frequency greater than 8MHz)
#pragma config SOSCSEL = SOSCHP         // SOSC Power Selection Configuration bits (Secondary Oscillator configured for high-power operation)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Both Clock Switching and Fail-safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPS = PS32768          // Watchdog Timer Postscale Select bits (1:32768)
#pragma config FWPSA = PR128            // WDT Prescaler bit (WDT prescaler ratio of 1:128)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable bits (WDT disabled in hardware; SWDTEN bit disabled)
#pragma config WINDIS = OFF             // Windowed Watchdog Timer Disable bit (Standard WDT selected(windowed WDT disabled))

// FPOR
#pragma config BOREN = BOR3             // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware, SBOREN bit disabled)
#pragma config LVRCFG = OFF             // Low Voltage Regulator Configuration bit (Low Voltage regulator is not available)
#pragma config PWRTEN = ON              // Power-up Timer Enable bit (PWRT enabled)
#pragma config I2C1SEL = PRI            // Alternate I2C1 Pin Mapping bit (Use Default SCL1/SDA1 Pins For I2C1)
#pragma config BORV = V18               // Brown-out Reset Voltage bits (Brown-out Reset set to lowest voltage (1.8V))
#pragma config MCLRE = ON               // MCLR Pin Enable bit (RA5 input pin disabled,MCLR pin enabled)

// FICD
#pragma config ICS = PGx1               // ICD Pin Placement Select bits (EMUC/EMUD share PGC1/PGD1)

// FDS
#pragma config DSWDTPS = DSWDTPSF       // Deep Sleep Watchdog Timer Postscale Select bits (1:2,147,483,648 (25.7 Days))
#pragma config DSWDTOSC = LPRC          // DSWDT Reference Clock Select bit (DSWDT uses Low Power RC Oscillator (LPRC))
#pragma config DSBOREN = ON             // Deep Sleep Zero-Power BOR Enable bit (Deep Sleep BOR enabled in Deep Sleep)
#pragma config DSWDTEN = ON             // Deep Sleep Watchdog Timer Enable bit (DSWDT enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define FCY 16000000
#include <libpic30.h>

//this allows 500 instructions to pass between each sample sent
//should make samples at 32kHz
#define TIMER_RESET_VAL 500

uint16_t LOOKUP[256] = 
{
32768,
33572,
34375,
35178,
35979,
36779,
37576,
38370,
39160,
39947,
40729,
41507,
42280,
43046,
43807,
44561,
45307,
46046,
46778,
47500,
48214,
48919,
49614,
50298,
50972,
51636,
52287,
52927,
53555,
54171,
54773,
55362,
55938,
56500,
57047,
57580,
58098,
58600,
59087,
59558,
60013,
60452,
60874,
61279,
61666,
62037,
62389,
62724,
63041,
63340,
63620,
63882,
64125,
64349,
64553,
64739,
64906,
65053,
65181,
65289,
65378,
65447,
65496,
65526,
65535,
65526,
65496,
65447,
65378,
65289,
65181,
65053,
64906,
64739,
64553,
64349,
64125,
63882,
63620,
63340,
63041,
62724,
62389,
62037,
61666,
61279,
60874,
60452,
60013,
59558,
59087,
58600,
58098,
57580,
57047,
56500,
55938,
55362,
54773,
54171,
53555,
52927,
52287,
51636,
50972,
50298,
49614,
48919,
48214,
47500,
46778,
46046,
45307,
44561,
43807,
43046,
42280,
41507,
40729,
39947,
39160,
38370,
37576,
36779,
35979,
35178,
34375,
33572,
32768,
31963,
31160,
30357,
29556,
28756,
27959,
27165,
26375,
25588,
24806,
24028,
23255,
22489,
21728,
20974,
20228,
19489,
18757,
18035,
17321,
16616,
15921,
15237,
14563,
13899,
13248,
12608,
11980,
11364,
10762,
10173,
9597,
9035,
8488,
7955,
7437,
6935,
6448,
5977,
5522,
5083,
4661,
4256,
3869,
3498,
3146,
2811,
2494,
2195,
1915,
1653,
1410,
1186,
982,
796,
629,
482,
354,
246,
157,
88,
39,
9,
0,
9,
39,
88,
157,
246,
354,
482,
629,
796,
982,
1186,
1410,
1653,
1915,
2195,
2494,
2811,
3146,
3498,
3869,
4256,
4661,
5083,
5522,
5977,
6448,
6935,
7437,
7955,
8488,
9035,
9597,
10173,
10762,
11364,
11980,
12608,
13248,
13899,
14563,
15237,
15921,
16616,
17321,
18035,
18757,
19489,
20228,
20974,
21728,
22489,
23255,
24028,
24806,
25588,
26375,
27165,
27959,
28756,
29556,
30357,
31160,
31963
};

uint16_t currentSample = 0;
//set to 1 whenever controller is ready to produce another sample
volatile uint16_t nextSample = 1;

//To represent a certain frequency, increment through indices at a rate of
//2.048 * Hz per sample
uint16_t sine_approx(uint16_t index)
{
    long bigVal = LOOKUP[index >> 8];
    long bigVal2 = LOOKUP[(unsigned char)((index >> 8) + 1)];

    int smallVal = ((int)(index & 0x00FF) * (int)(bigVal2 - bigVal)) >> 8;

    return bigVal + smallVal;
}

void init_SPI()
{
    //disable SPI (req for configuration)
    SPI1STATbits.SPIEN = 0;
    
    IFS0bits.SPI1IF 		= 0;	// clear interrupt flag
    IEC0bits.SPI1IE 		= 0;	// disable interrupt

    //clear config registers
    SPI1CON1 = 0x0000;
    SPI1CON2 = 0x0000;
    
    //set word size on SPI bus to 16 (12 bit DAC)
    SPI1CON1bits.MODE16 = 1;
    //set us to SPI master
    SPI1CON1bits.MSTEN = 1;
    //configure oscillator scaling (1/2 of Fcy)
    SPI1CON1bits.PPRE = 0b11;
    SPI1CON1bits.SPRE = 0b110;
    
    //required by datasheet (still unsure why)
    SPI1STATbits.SPIROV = 0;
    //enable SPI
    SPI1STATbits.SPIEN = 1;
    
    //drive latch and CS pin active high
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    PORTBbits.RB8 = 1;
    PORTBbits.RB9 = 1;
}

void SPI_write(uint16_t data)
{
    //DAC is 12 bits, so shift value and add config bits
    data = data >> 4;
    data = data | 0b0111000000000000;
    
    //dummy read of SPI buffer to clear RX flag
    uint16_t dummy = SPI1BUF;
    
    //drive CS pin low
    PORTBbits.RB9 = 0;
    //begin transmission of data
    SPI1BUF = data;
    //wait for transmission to finish <50 clocks
    while(!SPI1STATbits.SPIRBF);
    //drive CS high again
    PORTBbits.RB9 = 1;
}

//setup timer to send samples to DAC at 32kHz
void setup_timer()
{
    //enable timer
    PR1 = TIMER_RESET_VAL;
    T1CONbits.TON = 1;
    //reset and enable timer interrupt
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
}

//open latch when audio sample should be produced by DAC
void update_latch()
{
    PORTBbits.RB8 = 0;
    //required delay
    __builtin_nop();
    __builtin_nop();
    __builtin_nop();
    PORTBbits.RB8 = 1;
}

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    //reset interrupt
    IFS0bits.T1IF = 0;
    //reset timer
    PR1 = TIMER_RESET_VAL;
    //let main function know we are ready to make another sample
    nextSample = 1;
}

int main()
{
    init_SPI();
    setup_timer();
    uint16_t val;
    
    while(1)
    {
        val += 2048;
        currentSample = val;//sine_approx(val);
        //wait for sample interrupt
        while(!nextSample)
        {
            __builtin_nop();
        }
        nextSample = 0;
        //send sample to DAC
        SPI_write(currentSample);
        update_latch();
    }
    return 0;
}
