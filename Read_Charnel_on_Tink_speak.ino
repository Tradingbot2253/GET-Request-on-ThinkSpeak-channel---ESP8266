#include<DNSServer.h>

#include<ESP8266WiFi.h>
#include<WiFiManager.h>
# include<ESP8266HTTPClient.h>
#include<WiFiClient.h>

WiFiClient client;
HTTPClient http;
WiFiManager wifi;
String response,begin_string,end_string,result;
int httpcode;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);



pinMode(2,OUTPUT);
wifi.autoConnect("NODEMCU1.0(E-12)");
Serial.println("Connected to the Network");
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2,HIGH);
delay(300);

digitalWrite(2,LOW);
delay(1000);
begin_string = indexOf("\"entry_id");
end_string=indexOf("\"}]}");
result=response.substring(begin_string=+26,end_string-1);
http.begin(client,"http://api.thingspeak.com/channels/2615982/fields/1.json?results=1");
Serial.println("Waiting for response");
httpcode=http.GET();
if(httpcode>0){
  Serial.println("GET Request Sent");
 response= http.getString();
 Serial.println(result);

}
 else{
  Serial.println("failled to Get Request");
 }
 http.end();
delay(16000);
}
