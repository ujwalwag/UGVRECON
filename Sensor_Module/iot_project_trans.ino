#include <SPI.h>
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <DHT.h>
#include <TinyGPS++.h>

#define ONE_WIRE_BUS 5
#define RE 8
#define DE 7
#define DHTPIN 4
#define DHTTYPE DHT11
#define AIR_VALUE 645
#define WATER_VALUE 254
#define SECOND_AIR_VALUE 700
#define SECOND_WATER_VALUE 300

DHT dht(DHTPIN, DHTTYPE);
RF24 radio(9, 10);
const uint64_t address = 0xF0F0F0F0E1;

const byte code[] = {0x01, 0x03, 0x00, 0x1e, 0x00, 0x03, 0x65, 0xCD};
byte values[11];
SoftwareSerial mod(2, 3);
int nitrogen, phosphorous, potassium;

static const int GPS_RX_PIN = 6, GPS_TX_PIN = 5;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);

int soilMoistureValue1 = 0, soilMoistureValue2 = 0;
int soilmoisturepercent1 = 0, soilmoisturepercent2 = 0;
float temperature, humidity;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

struct MyVariable {
  byte soilmoisturepercent1;
  byte soilmoisturepercent2;
  float temperature;
  float humidity;
  byte nitrogen;
  byte phosphorous;
  byte potassium;
  double latitude;
  double longitude;
};
MyVariable variable;

void setup() {
  Serial.begin(9600);
  mod.begin(9600);
  gpsSerial.begin(GPSBaud);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  sensors.begin();
  dht.begin();
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
}

void loop() {
  byte val;
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);

  if (mod.write(code, sizeof(code)) == 8) {
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    for (byte i = 0; i < 11; i++) {
      values[i] = mod.read();
      Serial.print(values[i], HEX);
    }
    Serial.println();
  }
  nitrogen = values[4];
  phosphorous = values[6];
  potassium = values[8];

  soilMoistureValue1 = analogRead(A0);
  soilmoisturepercent1 = map(soilMoistureValue1, AIR_VALUE, WATER_VALUE, 0, 100);
  soilmoisturepercent1 = constrain(soilmoisturepercent1, 0, 100);

  soilMoistureValue2 = analogRead(A1);
  soilmoisturepercent2 = map(soilMoistureValue2, SECOND_AIR_VALUE, SECOND_WATER_VALUE, 0, 100);
  soilmoisturepercent2 = constrain(soilmoisturepercent2, 0, 100);

  humidity = dht.readHumidity();
  float dhtTemperature = dht.readTemperature();
  if (isnan(humidity) || isnan(dhtTemperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  sensors.requestTemperatures();
  temperature = sensors.getTempCByIndex(0);

  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
    if (gps.location.isUpdated()) {
      variable.latitude = gps.location.lat();
      variable.longitude = gps.location.lng();
    }
  }

  variable.soilmoisturepercent1 = soilmoisturepercent1;
  variable.soilmoisturepercent2 = soilmoisturepercent2;
  variable.temperature = dhtTemperature;
  variable.humidity = humidity;
  variable.nitrogen = nitrogen;
  variable.phosphorous = phosphorous;
  variable.potassium = potassium;

  radio.write(&variable, sizeof(variable));
  
  Serial.print("Primary Soil Moisture: ");
  Serial.print(variable.soilmoisturepercent1);
  Serial.println("%");
  Serial.print("Secondary Soil Moisture: ");
  Serial.print(variable.soilmoisturepercent2);
  Serial.println("%");
  Serial.print("Temperature: ");
  Serial.print(variable.temperature);
  Serial.println(" *C");
  Serial.print("Humidity: ");
  Serial.print(variable.humidity);
  Serial.println(" %");
  Serial.print("Nitrogen: ");
  Serial.print(variable.nitrogen);
  Serial.println(" mg/kg");
  Serial.print("Phosphorous: ");
  Serial.print(variable.phosphorous);
  Serial.println(" mg/kg");
  Serial.print("Potassium: ");
  Serial.print(variable.potassium);
  Serial.println(" mg/kg");
  Serial.print("GPS Latitude: ");
  Serial.println(variable.latitude, 6);
  Serial.print("GPS Longitude: ");
  Serial.println(variable.longitude, 6);
}
