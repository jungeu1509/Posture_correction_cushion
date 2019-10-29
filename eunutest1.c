#include <stdio.h>
#include <wiringPi.h>

#define RAL 2 // BCM_GPIO 27
#define RAR 3 // BCM_GPIO 22
#define LEDL 4 // BCM_GPIO 23
#define LEDR 5 // BCM_GPIO 24

int main (void)
{
	int heavy;
  int diff;
  if(wiringPiSetup () ==-1)
      return 1;

  pinMode (LEDL, OUTPUT);
  pinMode (LEDR, OUTPUT);
  pinMode (RAL, INPUT);
  pinMode (RAR, INPUT);

  while(1)
  {
    while(digitalRead(RAL)==0 && digitalRead(RAR)==0)
    {
      digitalWrite(LEDL,1);
      digitalWrite(LEDR,1);
    }
    diff = digitalRead(RAL)-digitalRead(RAR)

    if(diff>0)
    {
      heavy=digitalRead(RAL)-digitalRead(RAR);
      digitalWrite(LEDL, heavy);
      digitalWrite(LEDR, 0);
    }
    else if(diff<0)
    {
      heavy=digitalRead(RAR)-digitalRead(RAL);
      digitalWrite(LEDR, heavy);
      digitalWrite(LEDL, 0);
    }
    else
    {
      digitalWrite(LEDL, 0);
      digitalWrite(LEDR, 0);
    }
  }
  return 0;
}
