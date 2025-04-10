#include <lpc214x.h>
#include <string.h>

#define GSM_UART_BAUD 9600
#define LED_DELAY 5000

void delay_ms(unsigned int ms);
void UART0_Init(void);
char UART0_ReadChar(void);
void UART0_WriteString(char *str);
void Init_GPIO(void);
void Display_Char_On_DotMatrix(char ch);

char sms_buffer[160];
unsigned int sms_index = 0;

int main(void) {
    UART0_Init();
    Init_GPIO();
    UART0_WriteString("AT\r");
    delay_ms(1000);
    UART0_WriteString("AT+CMGF=1\r");  // Set text mode
    delay_ms(1000);
    UART0_WriteString("AT+CNMI=1,2,0,0,0\r");  // Auto display SMS
    delay_ms(1000);

    while (1) {
        char ch = UART0_ReadChar();
        if (ch == '\n') {
            sms_buffer[sms_index] = '\0';
            sms_index = 0;

            // Display first 10 characters of SMS on Dot Matrix
            for (int i = 0; i < 10 && sms_buffer[i] != '\0'; i++) {
                Display_Char_On_DotMatrix(sms_buffer[i]);
                delay_ms(500);
            }
        } else {
            sms_buffer[sms_index++] = ch;
            if (sms_index >= sizeof(sms_buffer)) sms_index = 0;
        }
    }
}

void UART0_Init(void) {
    PINSEL0 = 0x00000005;   // Enable UART0 Rx/Tx
    U0LCR = 0x83;           // DLAB = 1, 8-bit data, 1 stop bit
    U0DLL = 97;             // For 9600 baud with 15MHz PCLK
    U0LCR = 0x03;           // DLAB = 0
}

char UART0_ReadChar(void) {
    while (!(U0LSR & 0x01)); // Wait until data is received
    return U0RBR;
}

void UART0_WriteString(char *str) {
    while (*str) {
        while (!(U0LSR & 0x20)); // Wait until THR is empty
        U0THR = *str++;
    }
}

void delay_ms(unsigned int ms) {
    for (unsigned int i = 0; i < ms * 3000; i++) {
        __asm("NOP");
    }
}

void Init_GPIO(void) {
    IO0DIR |= 0xFF << 16; // Assume P0.16 - P0.23 are connected to shift register
}

void Display_Char_On_DotMatrix(char ch) {
    // Dummy function: You need to write custom bit pattern
    // for each character from a font table
    IO0CLR = 0xFF << 16;
    IO0SET = (ch << 16); // Simplified (won't display real chars)
    delay_ms(LED_DELAY);
}

