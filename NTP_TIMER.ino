// ESP_01 NTP RELAYED FAN TIMER FOR OVERHEATING INDOOR SOLAR MICRO-INVERTER VIA PARALLEL POWERED MODULE  
// Coded by Sroto& Gargees 15/10/2021   
// MAC:F4-CF-A2-E4-21-A4

#include <ESP8266WiFi.h>

#define RELAY 0 

const char* ssid     = "AP";     
const char* password = "AP_PW";    

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 28800;      // Timezone * 60 min * 60 sec 
const int   daylightOffset_sec = 0;

char Time[40];
WiFiClient client;

void setup(void)

{
  pinMode(RELAY,OUTPUT);
  digitalWrite(RELAY, LOW);
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(">");
  }
  
  delay(1000);
  
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
 
  unsigned timeout = 5000;
  unsigned start = millis();
  while (!time(nullptr))
  {
    delay(1000);
  }
  delay(1000);
}

void printLocalTime()

{
  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  strftime (Time,40,"%H%M",timeinfo); 
  String T = Time;
  Serial.println(T);
  
  if ( T == "0900" || T == "0940" || T == "1015"){digitalWrite(RELAY,HIGH);}
  if ( T == "0915" || T == "0945" || T == "1025"){digitalWrite(RELAY,LOW );}
  if ( T == "0920" || T == "0950" || T == "1030"){digitalWrite(RELAY,HIGH);}
  if ( T == "0925" || T == "0955" || T == "1040"){digitalWrite(RELAY,LOW );}
  if ( T == "0930" || T == "1000" || T == "1050"){digitalWrite(RELAY,HIGH);}
  if ( T == "0935" || T == "1010" || T == "1100"){digitalWrite(RELAY,LOW );}
  
  if ( T == "1105" || T == "1143" || T == "1213"){digitalWrite(RELAY,HIGH);}
  if ( T == "1115" || T == "1150" || T == "1220"){digitalWrite(RELAY,LOW );}
  if ( T == "1120" || T == "1153" || T == "1225"){digitalWrite(RELAY,HIGH);}
  if ( T == "1130" || T == "1200" || T == "1245"){digitalWrite(RELAY,LOW );}
  if ( T == "1135" || T == "1203" || T == "1247"){digitalWrite(RELAY,HIGH);}
  if ( T == "1140" || T == "1210" || T == "1300"){digitalWrite(RELAY,LOW );}
  
  if ( T == "1302" || T == "1342" || T == "1433"){digitalWrite(RELAY,HIGH );}
  if ( T == "1320" || T == "1400" || T == "1440"){digitalWrite(RELAY,LOW  );}
  if ( T == "1322" || T == "1403" || T == "1443"){digitalWrite(RELAY,HIGH );}
  if ( T == "1330" || T == "1415" || T == "1450"){digitalWrite(RELAY,LOW  );}
  if ( T == "1332" || T == "1417" || T == "1453"){digitalWrite(RELAY,HIGH );}
  if ( T == "1340" || T == "1430" || T == "1500"){digitalWrite(RELAY,LOW  );}

  if ( T == "1502" || T == "1542" || T == "1633"){digitalWrite(RELAY,HIGH );}
  if ( T == "1520" || T == "1600" || T == "1640"){digitalWrite(RELAY,LOW  );}
  if ( T == "1522" || T == "1610" || T == "1643"){digitalWrite(RELAY,HIGH );}
  if ( T == "1530" || T == "1615" || T == "1650"){digitalWrite(RELAY,LOW  );}
  if ( T == "1532" || T == "1620" || T == "1700"){digitalWrite(RELAY,HIGH );}
  if ( T == "1540" || T == "1625" || T == "1705"){digitalWrite(RELAY,LOW  );}

  if ( T == "1720" || T == "1740" || T == "1800"){digitalWrite(RELAY,HIGH );}
  if ( T == "1725" || T == "1742" || T == "1805"){digitalWrite(RELAY,LOW  );}
  
}

void loop(void)
{
  printLocalTime();
  delay(1000);
}
