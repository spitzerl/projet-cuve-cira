/* Electronoobs Bluetooth data receive with
 * Android and Arduino. Small example.
 * Remember to disconnect the Rx and Tx pins of the HC-06 when
 * uploading the code
 */

//Inputs
int in = A1;

void setup() {
  Serial.begin(9600);   //Set the baud rate of the comunication
  pinMode(in,INPUT);    //Define the pin as input
}

void loop() {
  //Read the analog value
  float val2 = analogRead(in);
  
  //Use serial.print to send the data in a "text" format
  Serial.print(val2);
  delay(400);//Small delay between each data send 
}