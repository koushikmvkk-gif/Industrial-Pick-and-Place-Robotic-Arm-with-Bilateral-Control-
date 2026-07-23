/*
=========================================================
 Industrial Pick & Place Bilateral Robot Arm
 Master Arm Controller

 Board  : Arduino UNO
 Language : Embedded C (Arduino)

 Features
 --------
 ✔ Reads 6 potentiometers
 ✔ Drives 6 master servos
 ✔ Sends joint angles through Serial
 ✔ Two finger gripper support
 ✔ Motion smoothing
=========================================================
*/

#include <Servo.h>

#define NUM_SERVOS 6

// ---------------- Servo Pins ----------------

const byte servoPins[NUM_SERVOS] =
{
  3,
  5,
  6,
  9,
  10,
  11
};

// ---------------- Pot Pins ----------------

const byte potPins[NUM_SERVOS] =
{
  A0,
  A1,
  A2,
  A3,
  A4,
  A5
};

Servo servo[NUM_SERVOS];

int angle[NUM_SERVOS];
int filtered[NUM_SERVOS];

// smoothing

const byte alpha = 4;

//=========================================================

void setup()
{
  Serial.begin(115200);

  for(int i=0;i<NUM_SERVOS;i++)
  {
      servo[i].attach(servoPins[i]);

      filtered[i]=analogRead(potPins[i]);
  }
}

//=========================================================

void loop()
{

  for(int i=0;i<NUM_SERVOS;i++)
  {

      int value=analogRead(potPins[i]);

      filtered[i]=filtered[i]+((value-filtered[i])/alpha);

      angle[i]=map(filtered[i],0,1023,0,180);

      angle[i]=constrain(angle[i],0,180);

      servo[i].write(angle[i]);
  }

  sendPacket();

  delay(15);

}

//=========================================================

void sendPacket()
{

    Serial.print('<');

    for(int i=0;i<NUM_SERVOS;i++)
    {

        Serial.print(angle[i]);

        if(i<NUM_SERVOS-1)
            Serial.print(',');

    }

    Serial.println('>');

}

/*
Example Packet

<90,120,45,80,100,35>

Slave receives these values and
moves the servos.
*/
