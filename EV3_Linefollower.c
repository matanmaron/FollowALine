#pragma config(Sensor, S2,     colour,         sensorEV3_Color)
#pragma config(Motor,  motorB,          leftwheel,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightwheel,    tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void waitfunc (int n)
{
	for (int i=0; i<=n/10;i++) //finish move while searching
	{
		wait1Msec(10);
		if (SensorValue[colour] <= 20) break;
	}
}

int nMotorSpeedSetting = 25; //set universal speed
int n=1;



task main()
{
  	while(SensorValue[colour] > 20) //first search
	{playSoundFile("");
		displayCenteredBigTextLine(4,"search");
		motor[leftwheel] = nMotorSpeedSetting;
		motor[rightwheel] = nMotorSpeedSetting;
		wait1Msec(20);
	}
  while (true)
  {playSoundFile("");
  	if(SensorValue[colour] <= 20) //found black = go straight
		{
    	displayCenteredBigTextLine(4,"black");

    	playSound(soundShortBlip);

     	motor[leftwheel] = nMotorSpeedSetting;
			motor[rightwheel] = nMotorSpeedSetting;
			waitfunc(20);
		}
		else
  	{	wait1Msec(20);
  		displayCenteredBigTextLine(4,"lost");
  		n=1;
  	while(SensorValue[colour] > 20)
  		{

  			displayCenteredBigTextLine(4,"left");
  			wait1Msec(20);
				moveMotorTarget(rightwheel, n*45, nMotorSpeedSetting); // search left
				moveMotorTarget(leftwheel, n*45, -nMotorSpeedSetting );
				waitfunc(n*250);
				n++;
				if(SensorValue[colour] <= 20)
					break;

				displayCenteredBigTextLine(4,"right");
				moveMotorTarget(leftwheel, n*45, nMotorSpeedSetting); // search left
				moveMotorTarget(rightwheel, n*45, -nMotorSpeedSetting);
				n++;
			   waitfunc(n*250);
			 }
  	}
		 wait1Msec(10);
	}
}
