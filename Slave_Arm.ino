/*
=========================================================
 Industrial Pick & Place Bilateral Robot Arm
 Slave Arm Controller

 Board      : Arduino UNO
 Language   : Embedded C (Arduino)

 Features
 --------------------------------------------------------
 ✔ Receives joint angles from Master
 ✔ Controls 6 Servo Motors
 ✔ Smooth Servo Motion
 ✔ Packet Validation
 ✔ Ready for Bluetooth / ESP32 / RF Modules
=========================================================
*/

#include <Servo.h>

#define NUM_SERVOS 6

// ------------------------------------------------------
// Servo Pins
// ------------------------------------------------------

const byte servoPins[NUM_SERVOS] =
{
  3,
  5,
  6,
  9,
  10,
  11
};

Servo servo[NUM_SERVOS];

// Current Servo Position
int currentAngle[NUM_SERVOS] =
{
  90,90,90,90,90,90
};

// Target Position
int targetAngle[NUM_SERVOS] =
{
  90,90,90,90,90,90
};

// Incoming Serial Packet
char receivedChars[50];

boolean newData = false;

// ------------------------------------------------------

void setup()
{
    Serial.begin(115200);

    for(int i=0;i<NUM_SERVOS;i++)
    {
        servo[i].attach(servoPins[i]);
        servo[i].write(currentAngle[i]);
    }
}

// ------------------------------------------------------

void loop()
{
    recvPacket();

    if(newData)
    {
        parsePacket();

        newData=false;
    }

    moveSmoothly();
}

// ------------------------------------------------------
// Receive Packet
// Packet Format:
// <90,45,120,80,70,30>
// ------------------------------------------------------

void recvPacket()
{
    static boolean recvInProgress = false;

    static byte index = 0;

    char startMarker='<';
    char endMarker='>';

    char rc;

    while(Serial.available()>0 && newData==false)
    {
        rc=Serial.read();

        if(recvInProgress)
        {
            if(rc!=endMarker)
            {
                receivedChars[index]=rc;
                index++;

                if(index>=sizeof(receivedChars))
                    index=sizeof(receivedChars)-1;
            }
            else
            {
                receivedChars[index]='\0';

                recvInProgress=false;

                index=0;

                newData=true;
            }
        }

        else if(rc==startMarker)
        {
            recvInProgress=true;
        }
    }
}

// ------------------------------------------------------

void parsePacket()
{
    char *token;

    token=strtok(receivedChars,",");

    int i=0;

    while(token!=NULL && i<NUM_SERVOS)
    {
        targetAngle[i]=atoi(token);

        targetAngle[i]=constrain(targetAngle[i],0,180);

        token=strtok(NULL,",");

        i++;
    }
}

// ------------------------------------------------------
// Smooth Servo Motion
// ------------------------------------------------------

void moveSmoothly()
{
    for(int i=0;i<NUM_SERVOS;i++)
    {

        if(currentAngle[i]<targetAngle[i])
        {
            currentAngle[i]++;
        }

        else if(currentAngle[i]>targetAngle[i])
        {
            currentAngle[i]--;
        }

        servo[i].write(currentAngle[i]);

    }

    delay(8);
}
