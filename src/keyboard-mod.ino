#include <PS2Keyboard.h>

const int DataPin = 8;
const int IRQpin =  5;

PS2Keyboard keyboard;

void setup() {
delay(1000);
keyboard.begin(DataPin, IRQpin);
Serial.begin(9600);
Serial.println("Key Test: ");
Serial.println(PS2_F1);
}

void loop() {
  if (keyboard.available()) {
    char c = keyboard.read();
    Serial.print("C: ");
    Serial.print(c);
    Serial.println();
  }
}

void press(byte lkeycode, byte lmodkeys)
{
  Keyboard.set_modifier(lmodkeys);
  Keyboard.set_key1(lkeycode);
  Keyboard.send_now();
}

void release()
{
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void SendOnceToKeyboard(byte lkeycode, byte lmodkeys)
{
  Keyboard.set_modifier(lmodkeys);
  Keyboard.set_key1(lkeycode);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
}


/* ASCII to HID code converter
 */
byte ASCIItoHID(byte ASCIIbyte)
{
  //Upper Letters
  if( ASCIIbyte >= 65 && ASCIIbyte <= 90 ) {
    return(ASCIIbyte-61);
  }
  //Lower Letters
  if( ASCIIbyte >= 97 && ASCIIbyte <= 122 ) {
    return(ASCIIbyte-93);
  }
  //Numbers
  if( ASCIIbyte >= 49 && ASCIIbyte <= 57 ) {
    return(ASCIIbyte-19);
  }
  //get not continuous ones
  switch(ASCIIbyte) {
  case 48:
    return( 39 ); //0
  case '~' :
    return((unsigned char)KEY_TILDE);
  case '`' :
    return((unsigned char)KEY_TILDE);
  case '!' :
    return((unsigned char)KEY_1);
  case '@' :
    return((unsigned char)KEY_2);
  case '#' :
    return((unsigned char)KEY_3);
  case '$' :
    return((unsigned char)KEY_4);
  case '%' :
    return((unsigned char)KEY_5);
  case '^' :
    return((unsigned char)KEY_6);
  case '&' :
    return((unsigned char)KEY_7);
  case '*' :
    return((unsigned char)KEY_8);
  case '(' :
    return((unsigned char)KEY_9);
  case ')' :
    return((unsigned char)KEY_0);
  case '_' :
    return((unsigned char)KEY_MINUS);
  case '-' :
    return((unsigned char)KEY_MINUS);
  case '+' :
    return((unsigned char)KEY_EQUAL);
  case '=' :
    return((unsigned char)KEY_EQUAL);
  case '{' :
    return((unsigned char)KEY_LEFT_BRACE);
  case '[' :
    return((unsigned char)KEY_LEFT_BRACE);
  case '}' :
    return((unsigned char)KEY_RIGHT_BRACE);
  case ']' :
    return((unsigned char)KEY_RIGHT_BRACE);
  case '|' :
    return((unsigned char)KEY_BACKSLASH);
  case '\\' :
    return((unsigned char)KEY_BACKSLASH);
  case ':' :
    return((unsigned char)KEY_SEMICOLON);
  case ';' :
    return((unsigned char)KEY_SEMICOLON);
  case '"' :
    return((unsigned char)KEY_QUOTE);
  case '\'' :
    return((unsigned char)KEY_QUOTE);
  case '<' :
    return((unsigned char)KEY_COMMA);
  case ',' :
    return((unsigned char)KEY_COMMA);
  case '>' :
    return((unsigned char)KEY_PERIOD);
  case '.' :
    return((unsigned char)KEY_PERIOD);
  case '?' :
    return((unsigned char)KEY_SLASH);
  case '/' :
    return((unsigned char)KEY_SLASH);
  case ' ' :
    return((unsigned char)KEY_SPACE);
  }
  return(0);
}
