// led initialize
int greenForStraight = 10;
int redForRight = 11;
int blueForLeft = 12;

// motor initialize
int motorLeft = 5;
int motorRight = 3;

// phototransistor intialize
int mSensor = A4;
int rSensor = A2;
int lSensor = A6;

// wheel speeds
int slowWheel = 40;
int fastWheel = 150;
int RregSpeed = 180;
int LregSpeed = 178;

// threshold values for each sensor
int Mthresh = 0;
int Rthresh = 0;
int Lthresh = 0;

void setup()
{
	// Set the modes for the led pins
	pinMode(greenForStraight, OUTPUT);
	pinMode(redForRight, OUTPUT);
	pinMode(blueForLeft, OUTPUT);

	// Set the modes for the motor pins
	pinMode(motorRight, OUTPUT);
	pinMode(motorLeft, OUTPUT);

	//Set the modes for the sensor pins
	pinMode(lSensor, INPUT);
	pinMode(mSensor, INPUT);
	pinMode(rSensor, INPUT);

	Mthresh = 500;
	Lthresh = 940;
	Rthresh = 650;

	Serial.begin(9600);
}
// put your main code here, to run repeatedly:

void loop() {

	if ((analogRead(mSensor) >= Mthresh))
	{
		if ((analogRead(rSensor) > Rthresh) && (analogRead(lSensor) > Lthresh))
		{
			turnOffAllLeds();
			digitalWrite(redForRight, HIGH);
			digitalWrite(blueForLeft, HIGH);

			//now stop

			analogWrite(motorRight, 0);
			analogWrite(motorLeft, 0);
			delay(500);
		}
		else
		{
			turnOffAllLeds();
			digitalWrite(greenForStraight, HIGH);
			driveStraight();
		}
	}

	else if ((analogRead(rSensor) >= Rthresh) && (analogRead(lSensor) < Lthresh))
	{
		turnOffAllLeds();
		digitalWrite(redForRight, HIGH);
		driveRight();
	}

	else if ((analogRead(lSensor) >= Lthresh) && (analogRead(rSensor) < Rthresh))
	{
		turnOffAllLeds();
		digitalWrite(blueForLeft, HIGH);
		driveLeft();
	}
}


////////////////////
//HELPER FUNCTIONS//
////////////////////


void driveStraight()
{
	analogWrite(motorRight, RregSpeed);
	analogWrite(motorLeft, LregSpeed);
}

void driveLeft()
{
	analogWrite(motorRight, fastWheel);
	analogWrite(motorLeft, slowWheel);
}

void driveRight()
{
	analogWrite(motorRight, slowWheel);
	analogWrite(motorLeft, fastWheel);
}

void turnOffAllLeds()
{
	digitalWrite(greenForStraight, LOW);
	digitalWrite(redForRight, LOW);
	digitalWrite(blueForLeft, LOW);
}