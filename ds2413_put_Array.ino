#include <OneWire.h>

#define DS2413_ONEWIRE_PIN  (8)

#define DS2413_FAMILY_ID    0x3A
#define DS2413_ACCESS_READ  0xF5
#define DS2413_ACCESS_WRITE 0x5A
#define DS2413_ACK_SUCCESS  0xAA
#define DS2413_ACK_ERROR    0xFF

#define BUTTON_NO 3 //your number of DS2413 devices / input Buttons

OneWire oneWire(DS2413_ONEWIRE_PIN);
uint8_t address[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

uint8_t Addresses[BUTTON_NO][8]; //array of arrays (2D) for address storage

void setup(void) 
{
  Serial.begin(9600);  
  delay(1000);
  Serial.println(("Looking for a DS2413 on the bus"));

  fillArray();
  //now print what was stored in the array by the fillArray() method.
Serial.println(" ");
for (int x=0; x<BUTTON_NO;x++){
      Serial.print("DS2413 address at array address "); Serial.print(x); Serial.print(" = ");
  for(int i=0;i<8;i++){
Serial.print(Addresses[x][i], HEX);}
Serial.println("");}
}
  
void loop(void) {
//once you have your numbers, go and do something with them in the loop...
}

void fillArray(){ //discovery order is determined by the search tree algorithm of maxim onewire
for(int x=0;x<BUTTON_NO;x++){
  byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];
  
  if ( !oneWire.search(address)) {
    Serial.println("");
    Serial.print("No more addresses.\n");
    oneWire.reset_search();
    delay(50); //was 250
    return;
  }
//fill the array, but print device reading at the same time
 Serial.println("");
  Serial.print("Device number ");Serial.print(x); Serial.print( " = ");
  for( i = 0; i < 8; i++) {
    Serial.print(address[i], HEX);
    Serial.print(" ");
  Addresses[x][i] = address[i];
    }
  }
}
