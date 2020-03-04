#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define DHTPIN D6     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11  // DHT11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);


#define FIREBASE_HOST "xxxxxxx.firebaseio.com/mayanktest"
#define FIREBASE_AUTH "NQjwlSMjtajbHdZBGpDqbvancI4OhE6Maqoxxxxx"
#define WIFI_SSID "PANDA"
#define WIFI_PASSWORD "pandacansleepanywhere"



void setup() {
  Serial.begin(19200);
  Serial.println("DHTxx test!");
  pinMode(D7, INPUT);
  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);



  

}

void loop() {
  // Wait a few seconds between measurements.
  
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
 
  Serial.print(F("Humidity: "));
  Serial.println(h);
  Serial.print(F("%  Temperature: "));
  Serial.println(t);
  for(int i=0; i<100; i++)
  {
    if(digitalRead(D7))
    {
    Serial.println("Sound detected ");
    
    Firebase.setInt("Sound", 10);
    delay(1000);
    }
    delay(100);
  }
  
  Firebase.setInt("Humidity", h);
  Firebase.setInt("Temparature", t);
    



  
 
}
