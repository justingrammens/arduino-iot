int photoRPin = 0; 
int minLight;
int maxLight;
int lightLevel;
int adjustedLightLevel;
const int led = 9;

void setup() {
 Serial.begin(9600);
  pinMode(led, OUTPUT); 
   
 //Setup the starting light level limits
 lightLevel=analogRead(photoRPin);
 //minLight=lightLevel-20;
 maxLight=lightLevel;
}

void loop(){
 //auto-adjust the minimum and maximum limits in real time
 lightLevel=analogRead(photoRPin);
 if(minLight>lightLevel){
 minLight=lightLevel;
 }
 if(maxLight<lightLevel){
 maxLight=lightLevel;
 }
 
 //Adjust the light level to produce a result between 0 and 100.
 adjustedLightLevel = map(lightLevel, minLight, maxLight, 0, 100); 
 
 //Send the adjusted Light level result to Serial port (processing)
 Serial.println(adjustedLightLevel);
 
 if(adjustedLightLevel < 50) { // the light turning on causes the values to fluxuate.
   digitalWrite(led, HIGH);
 } else {
   digitalWrite(led, LOW);
 }
 
 //slow down the transmission for effective Serial communication.
 delay(100);
}
