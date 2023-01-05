#include "Ultrasonic.h"
#include <Wire.h>
#include "rgb_lcd.h"
 
rgb_lcd lcd;

float volume;

Ultrasonic ultrasonic(7); // Déclaration de la broche utilisée par le capteur

void setup()

{
    lcd.begin(16, 2);// set up the LCD's number of columns and rows:
    Serial.begin(9600);
}

void loop()

{
    long hauteur;

    hauteur = 64-ultrasonic.MeasureInCentimeters();    // Lecture de la valeur de notre capteur, la hauteur.
    volume = 34*34*hauteur;                            // calcul du volume de la cuve en cm3
    lcd.setCursor(0, 0);
    lcd.print(volume);                                 // affichage en cm3
    lcd.print("cm3");
    delay(2500);
    lcd.clear();
    
    volume = 34*34*hauteur;                         
    hauteur = 64-ultrasonic.MeasureInCentimeters();
    lcd.print(volume/1000);                            // affichage en L
    lcd.print("L");
    delay(2500);
    lcd.clear();
    
    volume = 34*34*hauteur;
    hauteur = 64-ultrasonic.MeasureInCentimeters(); 
    lcd.print((volume/73984)*100);                      // affichage en %
    lcd.print("%");
    delay(2500);
    lcd.clear();

}
