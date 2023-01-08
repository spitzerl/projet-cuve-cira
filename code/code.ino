//#include <Wire.h>
//#include "rgb_lcd.h"            //Pour écran LCD
//#include <SoftwareSerial.h>     //Pour module Bluetooth
//SoftwareSerial bluetooth(2,3); 
 
//rgb_lcd lcd;

int vegaek21 = 0;               // Variable pour la valeur de la sonde
int hauteurEau = 0;
int volumeEau = 0;

float hauteurCuve = 64;
float longueurCuve = 34;
float largeurCuve = 34;

void setup() {

    //lcd.begin(16, 2);           // Définit la résolution de l'écran LCD en 16x2
    Serial.begin(9600);           //
    //bluetooth.begin(9600);      //

}

void loop() {

    long hauteur;
    float tension;
    float volume;
    vegaek21 = analogRead(A0);    // Lit la valeur de la sonde sur le pin A0
    
    // Calcul la hauteur de l'eau dans la cuve
    hauteurEau = (vegaek21 * hauteurCuve) / 1024;
    Serial.print("Hauteur eau: ");
    Serial.print(hauteurEau);
    Serial.println(" cm");

    // Calcul le volume d'eau dans la cuve
    volumeEau = hauteurEau * largeurCuve * longueurCuve;
    Serial.println(hauteurEau);
    Serial.println(longueurCuve);
    Serial.println(largeurCuve);
    Serial.print("Volume eau: ");
    Serial.print(volumeEau);
    Serial.println(" cm3");
    
    delay(2000);

}
