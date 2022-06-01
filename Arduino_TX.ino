#include <SPI.h>
#include <mcp2515.h>

#define echoPin 4 //Define the arduino pin connected to the Echo Pin of HC-SR04 Ultrasonic sensor
#define trigPin 3 //Define the arduino pin connected to the Trigger Pin of HC-SR04 Ultrasonic sensor

static double sound_speed = 0.0;
float T = 20;   //Define temperature of environment, for calculation of sound wave speed

long duration; 
long distance; 
int idx=0;
struct can_frame canMsg;

MCP2515 mcp2515(10);

void setup() 
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  
  while (!Serial);
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();

  for(idx=0;idx<8;idx++)  //Initialize the CAN Message Data
    canMsg.data[idx]=0;
  
  Serial.println("Distance measured by the sensor");
  sound_speed = 0.034 * (sqrt(1 + T/273.15)); // Calculation of sound speed as per the environment temperature
}

void loop() 
{
  canMsg.can_id  = 0x0F6;
  canMsg.can_dlc = 8;
  idx++;
  if(idx<8)
  {
   canMsg.data[idx]=measure();
  }
  else 
  {
   idx=0;
   canMsg.data[idx]=measure();
  }
  mcp2515.sendMessage(&canMsg); //Send the CAN Message

  Serial.println("Message sent");
  delay(100);
}

long measure()  //Function to measure the distance
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * sound_speed / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  return distance;
}
