#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define LEDP D7
#define LED1 D1
#define LED2 D2
#define LED3 D5
#define LED4 D6

// WiFi
const char *ssid = "infinergy"; // Enter your WiFi name
const char *password = "okeokeoke";  // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "lestari";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LEDP, OUTPUT);
  Serial.begin(115200);
  // connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  //connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
      String client_id = "esp8266-client-";
      client_id += String(WiFi.macAddress());
      Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
      if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
          Serial.println("Public emqx mqtt broker connected");
      } else {
          Serial.print("failed with state ");
          Serial.print(client.state());
          delay(2000);
      }
  }
  // publish and subscribe
  client.publish(topic, "ready");
  client.subscribe(topic);
}

void callback(char *topic, byte *payload, unsigned int length) {
  digitalWrite(LEDP,HIGH);
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
      if(i == 0 && (char)payload[i] == '1'){
        digitalWrite(LED1, HIGH);
        Serial.print("1");
      }
      if(i == 0 && (char)payload[i] == '0'){
        digitalWrite(LED1, LOW);
        Serial.print("0");
      }
      if(i == 1 && (char)payload[i] == '1'){
        digitalWrite(LED2, HIGH);
        Serial.print("1");
      }
      if(i == 1 && (char)payload[i] == '0'){
        digitalWrite(LED2, LOW);
        Serial.print("0");
      }
      if(i == 2 && (char)payload[i] == '1'){
        digitalWrite(LED3, HIGH);
        Serial.print("1");
      }
      if(i == 2 && (char)payload[i] == '0'){
        digitalWrite(LED3, LOW);
        Serial.print("0");
      }
      if(i == 3 && (char)payload[i] == '1'){
        digitalWrite(LED4, HIGH);
        Serial.print("1");
      }
      if(i == 3 && (char)payload[i] == '0'){
        digitalWrite(LED4, LOW);
        Serial.print("0");
      }
    }
  Serial.println();
  Serial.println("-----------------------");
  delay(100);
  digitalWrite(LEDP, LOW);
}

void loop() {
  client.loop();
  client.publish("lestariconfirmation","ready");
}
