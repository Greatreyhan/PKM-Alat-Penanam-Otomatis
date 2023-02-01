#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <Wire.h>
#include <I2C_Anything.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

#define SLAVE_ADDRESS 8
#define WIFI_SSID "infinergy"
#define WIFI_PASSWORD "okeokeoke"
#define API_KEY "AIzaSyBZegxKYFkfvRwinaMAvjqxSzuyOMift58"
#define DATABASE_URL "grerover-default-rtdb.asia-southeast1.firebasedatabase.app" 
#define USER_EMAIL "maulanareyhan252@gmail.com"
#define USER_PASSWORD "Maulana252"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup()
{
  Wire.begin(D1, D2);
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback; 
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  Firebase.setDoubleDigits(5);
}

uint8_t getMaju = 0;
uint8_t getMundur = 0;
uint8_t getKanan = 0;
uint8_t getKiri = 0;
uint8_t getBor = 0;
uint8_t getRotate = 0;
uint8_t getMasuk = 0;
uint32_t timeDelay = 0;

void loop()
{
  
  if (Firebase.ready())
  {
   kirimData();
  }
}

void kirimData(){
    Serial.println("Send");
    Wire.beginTransmission (SLAVE_ADDRESS);
       if (Firebase.RTDB.getInt(&fbdo, "/controls/maju")) {
            getMaju = (uint8_t) fbdo.intData();
            I2C_writeAnything (getMaju);
            Serial.println(getMaju);
        }
       if (Firebase.RTDB.getInt(&fbdo, "/controls/mundur")) {
            getMundur = (uint8_t) fbdo.intData();
            I2C_writeAnything (getMundur);
            Serial.println(getMundur);
        }
       if (Firebase.RTDB.getInt(&fbdo, "/controls/kanan")) {
            getKanan = (uint8_t) fbdo.intData();
            I2C_writeAnything (getKanan);
            Serial.println(getKanan);
        }
       if (Firebase.RTDB.getInt(&fbdo, "/controls/kiri")) {
            getKiri = (uint8_t) fbdo.intData();
            I2C_writeAnything (getKiri);
            Serial.println(getKiri);
        }
       if (Firebase.RTDB.getInt(&fbdo, "/controls/bor")) {
            getBor = (uint8_t) fbdo.intData();
            I2C_writeAnything (getBor);
            Serial.println(getBor);
        }
       if (Firebase.RTDB.getInt(&fbdo, "/controls/rotate")) {
            getRotate = (uint8_t) fbdo.intData();
            I2C_writeAnything (getRotate);
            Serial.println(getRotate);
        }
       if (Firebase.RTDB.getInt(&fbdo, "/controls/masuk")) {
            getMasuk = (uint8_t) fbdo.intData();
            I2C_writeAnything (getMasuk);
            Serial.println(getMasuk);
        }
       if (Firebase.RTDB.getInt(&fbdo, "/controls/timeDelay")) {
            timeDelay = (uint32_t) fbdo.intData();
            I2C_writeAnything (timeDelay);
            Serial.println(timeDelay);
        }
    Wire.endTransmission();
    Serial.println("End");
}
