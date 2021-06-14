//#include <FirebaseArduino.h>

#include  <ESP8266WiFi.h>
#include <DHT.h>




//#define FIREBASE_HOST "robogyani.firebaseio.com"
//#define FIREBASE_AUTH "vA32AUgbEG5C35ujfY7T9MhHceyWmrcRPeMecP4y"
#define WIFI_SSID "ROBOGYAN"
#define WIFI_PASSWORD "Rg@2k19+-*/"

#define DHTPIN 15   
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE); 

int rain = A0, rain_val, x =800;
float t,h;
 
void setup() {
   WiFi.mode(WIFI_STA);
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   Serial.begin(115200);
   for(int i=0;i<10;i++)
  {
    Serial.println("CONNECTING....................");
    delay(1000);
    if(WiFi.status()==WL_CONNECTED)
    break;
  }
   Serial.println ("");
   Serial.println ("WiFi Connected!");
   Serial.println(WiFi.localIP());
   //Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
   pinMode(rain,INPUT);
   dht.begin();
  
}


void loop() {

 rain_val = analogRead(rain);
 //rain_val = map(rain_val,150,144,1023,0);
 t = dht.readTemperature();
 h = dht.readHumidity();

  if (rain_val<= x)
{
     Serial.print("Rain is detected");
     Serial.print(" rain_val = ");
     Serial.println(rain_val);
     Serial.print("Temperature = ");
     Serial.print(t);
     Serial.print(" Humidity = ");
     Serial.print(h);
     Serial.println("");
     Serial.println("");
  }
  
  else
{
    Serial.print("Rain is not detected");
    Serial.print(" rain_val = ");
    Serial.println(rain_val);
    Serial.print("Temperature = ");
    Serial.print(t);
    Serial.print(" Humidity = ");
    Serial.print(h);
    Serial.println("");
    Serial.println("");
  }
 
 delay(2000);
}
