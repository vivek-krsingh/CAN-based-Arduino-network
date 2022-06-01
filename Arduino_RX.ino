#include <SPI.h>
#include <mcp2515.h>

#define beepPin 8 //Define the arduino pin connected to the positive terminal of Peizoelectric beeper
MCP2515 mcp2515(10); //Define the arduino pin connected to the CS pin of the MCP2515 CAN module

struct can_frame canMsg; 

float thresh_dist = 5; //Set threshold distance to start beeper alert.
int idx=0;
float sum = 0.0;
float avg_dist = 0.0;
int rate = 100; //Beeper cycle delay, also used to calculate velocity
int freq = 500; //Beeper Frequency

int idx2 = 0; 
float vel = 0.0;
static float prev_dist = 0.0; 
static float prev_vel = 0.0;

void setup() {
  pinMode(beepPin, OUTPUT);
  Serial.begin(115200);
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();
  
  Serial.println("Reading data from sensor");
}

void loop()
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) 
  { 
    sum = 0;
    
    for(idx=0; idx<8; idx++)  // Loop to calculate the sum of distances in the recieved message.
        sum+=canMsg.data[idx];    
    
    avg_dist = sum/8;  // Calculate the average distance, averaging reduces the noise in the recieved sensor data.
    
    Serial.println();

    if(avg_dist<thresh_dist)
    {     
    Serial.print("Distance Close ");
    Serial.print(avg_dist);
    Serial.print(" cm ");
     
    tone(beepPin, freq);
    delay(rate);
    noTone(beepPin);

    Serial.print(" Velocity "); 
    Serial.print(velocity(avg_dist));
    Serial.print(" m/s ");
    }
    else
    {
     Serial.print("Distance Clear "); 
     Serial.print(avg_dist);
     Serial.print(" cm ");
     
     Serial.print(" Velocity "); 
     Serial.print(velocity(avg_dist));
     Serial.print(" m/s ");
     
     noTone(beepPin); 
     }
    
  }
}

float velocity( float cur_dist)   //Function to calculate velocity
{
  float temp = ((prev_dist - cur_dist)/rate)*10;
  prev_dist = cur_dist;  
  return abs(temp);
}
