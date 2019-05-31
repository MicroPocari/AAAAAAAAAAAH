#include <iostream>
#include <string>

using namespace std;
//set_motors(designation number, movement)

//60 is clockwise

//48 is stationary

//30 is anti clockwise

//left wheel's port should be M1
//right wheel's port should be M2

class driver
{
	public:
	//manually move the right wheel.
	void rightWheel(int num); //12 MAX
		
	//manually move the left wheel.
	void leftWheel(int num); //12 MAX
	
	//move both wheels
	void bothWheels(int num); //12 MAX
	
	void stopEverything(); //stop.... hammer time!

};
void driver::rightWheel(int num)
{
	int actualNumber = 48 + num; //-12 + 48 = 30 AND 12 + 48 = 60!!
	set_motors(1, actualNumber);
	hardware_exchange();
}

void driver::leftWheel(int num)
{
	int actualNumber = 48 - num;
	set_motors(5, actualNumber);
	hardware_exchange();
}

void driver::bothWheels(int num)
{
	int leftNumber = 48 - num; //dont have to do any fancy shmancy with negative and positive numbers!
	int rightNumber = 48 + num;
	set_motors(5, leftNumber);
	set_motors(1, rightNumber);
	hardware_exchange();
}

void driver::stopEverything() //stop both wheels.
{
	set_motors(1, 48);
	set_motors(5, 48);
	hardware_exchange();
}
