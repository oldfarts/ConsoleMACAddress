#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif

byte mac[6];

void setup(){
  Serial.begin(9600);
  Serial.println();
  //Serial.print("ESP Board MAC Address:  ");
  //Serial.println(WiFi.macAddress());
}
 
void loop(){
  WiFi.macAddress(mac);
  Serial.print(mac[0],HEX);
  Serial.print(" ");
  Serial.print(mac[1],HEX);
  Serial.print(" ");
  Serial.print(mac[2],HEX);
  Serial.print(" ");
  Serial.print(mac[3],HEX);
  Serial.print(" ");
  Serial.print(mac[4],HEX);
  Serial.print(" ");
  Serial.println(mac[5],HEX);
  
 //Serial.println(WiFi.macAddress());
 // Serial.println(WiFi.softAPmacAddress());
  delay(3000);
}
