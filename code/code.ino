#include "Ultrasonic.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2,3); 
 
rgb_lcd lcd;

void setup()

{
    lcd.begin(16, 2);// set up the LCD's number of columns and rows:
    Serial.begin(9600);
    bluetooth.begin(9600);
    pinMode(A1, INPUT);
}

void loop()

{
    long hauteur;
    float tension = 0;
    float volume;

    tension = analogRead(A1);                          // Lecture de la tension
    tension = (tension)*2/410;                         //Conversion binaire en tension
    hauteur = ((tension-0.4)*56)/1.6;                  // Conversion de la tension en hauteur.
    volume = 34*34*hauteur;                            // Calcul du volume de la cuve en cm3
    lcd.setCursor(0, 0);
    lcd.print(volume);                                 // Affichage en cm3 sur l'écran LCD
    lcd.print("cm3");
    Serial.print(volume);                              // Affichage en cm3 sur le terminal
    Serial.println("cm3");
    if(Serial.available()) {                           // les données reçues par le moniteur série sont envoyées au port BT
    bluetooth.print(volume); }                       
    delay(2500);
    lcd.clear();
    
    tension = analogRead(A1);      
    tension = (tension)*2/410;                        
    hauteur = ((tension-0.4)*56)/1.6;                  // Conversion de la tension en hauteur.
    volume = (34*34*hauteur)/1000;                     // Calcul du volume de la cuve en L
    lcd.print(volume);                                 // Affichage en L
    lcd.print("L");   
    Serial.print(volume);                              
    Serial.println("L");                                 
    if(Serial.available()) {                           // les données reçues par le moniteur série sont envoyées au port BT
    bluetooth.print(volume); }
    delay(2500);
    lcd.clear();
    
    tension = analogRead(A1);     
    tension = (tension)*2/410;                         
    hauteur = ((tension-0.4)*56)/1.6;                  // Conversion de la tension en hauteur.
    volume = (34*34*hauteur);                          // Calcul du volume de la cuve en cm3
    lcd.print((volume/64736)*100);                     // conversion et affichage du volume en %
    lcd.print("%");
    Serial.print((volume/64736)*100);                  
    Serial.println("%");            
    if(Serial.available()) {                           // les données reçues par le moniteur série sont envoyées au port BT
    bluetooth.print(volume); }
    delay(2500);
    lcd.clear();

}
