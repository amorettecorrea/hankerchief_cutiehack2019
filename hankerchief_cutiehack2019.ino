/* Project for Cutie Hack 2019 at UC Riverside
 * By Amorette Correa
 * Project: Hankerchief
 * Description: LCD Display and an IR remote meant to 
 * be an interactive game similar to Netflix's Bandersnatch
 */

#include <LiquidCrystal.h>
#include "IRremote.h"

int receiver = 6; // Signal Pin of IR receiver to Arduino Digital Pin 11
/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

LiquidCrystal lcd(7,8,9,10,11,12);

/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  switch(results.value)

  {

  case 0xFF22DD: Serial.println("LEFT");
    lcd.print("YAY!");    
    break;

  case 0xFFC23D: Serial.println("RIGHT");
     lcd.print("oh well u going");
     break;

  default: 
    Serial.print("nothing happens");
    break;

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR


void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn();
  
  lcd.begin(16, 2);
  lcd.print("Wanna hack?"); 
  
  delay(1000);
  lcd.clear();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  if(irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  } 
}
