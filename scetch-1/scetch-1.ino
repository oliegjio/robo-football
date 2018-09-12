#include <Servo.h>

#define IN1_PIN 11
#define IN2_PIN 6
#define IN3_PIN 5
#define IN4_PIN 3

#define CLAW_PIN 9

Servo claw;

String message;

void setup()
{
  Serial.begin(9600);
  
  claw.attach(CLAW_PIN);

  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);

  pinMode(CLAW_PIN, OUTPUT);
}

void claw_up()
{
  claw.write(60);
}

void claw_down()
{
  claw.write(160);
}

void forward()
{
  analogWrite(IN1_PIN, LOW);
  analogWrite(IN2_PIN, 156);

  analogWrite(IN3_PIN, 156);
  analogWrite(IN4_PIN, LOW);
}

void backward()
{
  analogWrite(IN1_PIN, 156);
  analogWrite(IN2_PIN, LOW);

  analogWrite(IN3_PIN, LOW);
  analogWrite(IN4_PIN, 156);
}

void left()
{
  analogWrite(IN1_PIN, 156);
  analogWrite(IN2_PIN, LOW);

  analogWrite(IN3_PIN, 156);
  analogWrite(IN4_PIN, LOW);
}

void right()
{
  analogWrite(IN1_PIN, LOW);
  analogWrite(IN2_PIN, 156);

  analogWrite(IN3_PIN, LOW);
  analogWrite(IN4_PIN, 156);
}

void stop()
{
  analogWrite(IN1_PIN, LOW);
  analogWrite(IN2_PIN, LOW);

  analogWrite(IN3_PIN, LOW);
  analogWrite(IN4_PIN, LOW);
}

#define DEL 1000

void loop()
{
//  forward();
//  delay(DEL);
//  stop();
//  delay(1000);
//  
//  backward();
//  delay(DEL);
//  stop();
//  delay(1000);
//  
//  left();
//  delay(DEL);
//  stop();
//  delay(1000);
//  
//  right();
//  delay(DEL);
//  stop();
//  delay(1000);
//  
//  stop();
//  delay(5000);
//  
//  claw_up();
//  delay(DEL);
//  
//  claw_dawn();
//  delay(DEL);

  if (Serial.available())
  {
    char message = Serial.read();

    if (message == 'F')
    {
      forward();
    }
    else if (message == 'B')
    {
      backward();
    }
    else if (message == 'L')
    {
      left();
    }
    else if (message == 'R')
    {
      right();
    }
    else if (message == 'U')
    {
      claw_up();
    }
    else if (message == 'W')
    {
      claw_down();
    }
    else
    {
      stop();
    }
  }
}

