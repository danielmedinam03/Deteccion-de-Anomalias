#include <DHT.h>
#include <DHT_U.h>


// Incluimos librería
#include <DHT.h>
 
int SensorTempHum=8;
int temp, humedad;
const byte SensorCO=0;  //pin analogico A0
float CO;

DHT dht(SensorTempHum, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Lectura del sensor de humedad y temperatura
  humedad = dht.readHumidity();
  temp= dht.readTemperature();
  
  //Valor del UV
  int UV = analogRead(A5);
  
  //Valor del CO2
  CO= analogRead(SensorCO);
  
  //Temperatura
  Serial.print( temp);

  Serial.print(",");
  
  //Humedad
  Serial.print( humedad);

  Serial.print(",");

  //CO2
  Serial.print( CO / 1024.0);

  Serial.print(",");

  //UV
  Serial.println(UV / 1024.0);
  
  delay(2000);
  
}
