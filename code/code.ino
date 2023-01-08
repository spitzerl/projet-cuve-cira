#include <Wire.h>
#include "rgb_lcd.h"            //Pour écran LCD
#include <SoftwareSerial.h>     //Pour module Bluetooth
SoftwareSerial bluetooth(2,3); 
 
rgb_lcd lcd;

int vegaek21 = 0;   // Variable pour la valeur de la sonde
long hauteur;
float tension;
float volume;

void setup()

{
    lcd.begin(16, 2);          // Définit la résolution de l'écran LCD en 16x2
    Serial.begin(9600);
    bluetooth.begin(9600);
}

void loop()

{
    long hauteur;
    float tension;
    float volume;
    valeur = analogRead(A0);     // Lit la valeur de la sonde sur le pin A0

}
