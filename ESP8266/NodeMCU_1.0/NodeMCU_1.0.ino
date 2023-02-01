#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

#define WIFI_SSID "infinergy"
#define WIFI_PASSWORD ""
#define API_KEY "AIzaSyBZegxKYFkfvRwinaMAvjqxSzuyOMift58"
#define DATABASE_URL "grerover-default-rtdb.asia-southeast1.firebasedatabase.app" 
#define USER_EMAIL "maulanareyhan252@gmail.com"
#define USER_PASSWORD "Maulana252"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup()
{

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

   if (Firebase.RTDB.getInt(&fbdo, "/controls/maju")) {
        getMaju = fbdo.intData();
        Serial.println(getMaju);
    }
   if (Firebase.RTDB.getInt(&fbdo, "/controls/mundur")) {
        getMundur = fbdo.intData();
        Serial.println(getMundur);
    }
   if (Firebase.RTDB.getInt(&fbdo, "/controls/kanan")) {
        getKanan = fbdo.intData();
        Serial.println(getKanan);
    }
   if (Firebase.RTDB.getInt(&fbdo, "/controls/kiri")) {
        getKiri = fbdo.intData();
        Serial.println(getKiri);
    }
   if (Firebase.RTDB.getInt(&fbdo, "/controls/bor")) {
        getBor = fbdo.intData();
        Serial.println(getBor);
    }
   if (Firebase.RTDB.getInt(&fbdo, "/controls/rotate")) {
        getRotate = fbdo.intData();
        Serial.println(getRotate);
    }
   if (Firebase.RTDB.getInt(&fbdo, "/controls/masuk")) {
        getMasuk = fbdo.intData();
        Serial.println(getMasuk);
    }
   if (Firebase.RTDB.getInt(&fbdo, "/controls/timeDelay")) {
        timeDelay = fbdo.intData();
        Serial.println(timeDelay);
    }
   
  }
}
