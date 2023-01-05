#include "Ultrasonic.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2,3); 
 
rgb_lcd lcd;

Ultrasonic ultrasonic(7); // Déclaration de la broche utilisée par le capteur

void setup()

{
    lcd.begin(16, 2);// set up the LCD's number of columns and rows:
    Serial.begin(9600);
    bluetooth.begin(9600);
}

void loop()

{
    long hauteur;
    float tension;
    float volume;

    tension = analogRead(A0);                          // Lecture de la valeur de notre capteur, la tension en fonction de la hauteur.
    hauteur = ((tension-0.4)*64)/1.6;                  // Conversion de la tension en hauteur.
    volume = 34*34*hauteur;                            // Calcul du volume de la cuve en cm3
    lcd.setCursor(0, 0);
    lcd.print(volume);                                 // Affichage en cm3
    lcd.print("cm3");
    if(Serial.available()) {                           // les données reçues par le moniteur série sont envoyées au port BT
    bluetooth.print(volume); }                       
    delay(2500);
    lcd.clear();
    
    volume = 34*34*hauteur;                         
    hauteur = 64-ultrasonic.MeasureInCentimeters();
    lcd.print(volume/1000);                            // affichage en L
    lcd.print("L");
    if(Serial.available()) {                           // les données reçues par le moniteur série sont envoyées au port BT
    bluetooth.print(volume); }
    delay(2500);
    lcd.clear();
    
    volume = 34*34*hauteur;
    hauteur = 64-ultrasonic.MeasureInCentimeters(); 
    lcd.print((volume/73984)*100);                      // affichage en %
    lcd.print("%");
    if(Serial.available()) {                           // les données reçues par le moniteur série sont envoyées au port BT
    bluetooth.print(volume); }
    delay(2500);
    lcd.clear();

}
