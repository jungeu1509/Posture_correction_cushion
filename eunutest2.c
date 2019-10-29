#include <stdio.h>
#include <wiringPi.h>

#define RAL 2 // BCM_GPIO 27
#define RAR 3 // BCM_GPIO 22
#define LEDL 4 // BCM_GPIO 23
#define LEDR 5 // BCM_GPIO 24
#define LEDP 6 // BCM_GPIO 25
#define PW_SW 1 // BCM_GPIO 18

volatile int POWER_state = 0;
volatile int POWER_change = 0;

void powerPressed(void)
{
	if(POWER_state==0)
	POWER_state = 1;
	else
	POWER_state = 0;//POWER_state가 0이면 1을 넣고 1이면 0을 넣는다.
	POWER_change = 1; //POWER_change를1로 변경한다.
}

int main (void)
{
	int heavy;
  int diff;
  if(wiringPiSetup () ==-1)
      return 1;

  pinMode (LEDL, OUTPUT);
  pinMode (LEDR, OUTPUT);
  pinMode (RAL, INPUT);
  pinMode (RAR, INPUT)
	pinMode (LEDP, OUTPUT);
	pinMode (PW_SW, INPUT);

	wiringPiISR(PW_SW,INT_EDGE_RISING,powerPressed);

  while(1)
  {
		POWER_change=0;
		digitalWrite(LEDP, POWER_state);
		while(POWER_state==1)
		{
			digitalWrite(LEDP,1);
			while(digitalRead(RAL)==0 && digitalRead(RAR)==0)
	    {
	      digitalWrite(LEDL,1);
	      digitalWrite(LEDR,1);
				delay(1000);
				digitalWrite(LEDL,0);
	      digitalWrite(LEDR,0);
				delay(1000);
	    }
			while(digitalRead(RAL)==0 && digitalRead(RAR)==0)
	    {
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
		}
		while(POWER_state==0)
		{
			digitalWrite(LEDL, 0);
			digitalWrite(LEDR, 0);
		}
  }
  return 0;
}
