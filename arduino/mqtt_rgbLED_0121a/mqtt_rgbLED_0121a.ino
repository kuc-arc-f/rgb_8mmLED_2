#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xE1 };

IPAddress ip(172, 168, 1, 41 );
//IPAddress local_server(192, 168, 10, 106 );
const char* mqtt_server = "test.mosquitto.org";

const char* mClient_id = "cliennt-arduino-0121A1";

char mTopic[]="item16-0121A1/device-1/rgb_led_1";
long mCount=0;
long lastMsg = 0;
  
void callback(char* topic, byte* payload, unsigned int length) {
  //Serial.print("Message arrived [");
  //Serial.print(topic);
  //Serial.print("] ");
  Serial.print("rgb=");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
Serial.println("");
}

EthernetClient ethClient;
PubSubClient client(ethClient);

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
//    if (client.connect("arduinoClient")) {
    if (client.connect( mClient_id )) {
      Serial.println("connected");
      //client.publish("outTopic","hello world");
      client.subscribe( mTopic );
      //
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

//
void setup()
{
  Serial.begin( 9600);
  Serial.println("# Start-mqtt_basic");
  
  client.setServer(mqtt_server, 1883);
  //client.setServer(local_server, 1883);
  client.setCallback(callback);

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip );
  }  
  // Allow the hardware to sort itself out
  delay(1500);
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
}




