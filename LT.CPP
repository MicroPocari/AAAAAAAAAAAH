#include <iostream>
#include "everything.h"

using namespace std;

int main()
{
	int err;
	int init(err);
	cout<<" Hello"<<endl;
	
	bool quad1 = true;
	bool quad2 = false;
	bool quad3 = false;
	bool quad4 = false;
	
	cout<<"Quadrant one ACTIVAAATUUU" << endl;
	//=====QUADRANT ONE=====//
	gateControl apple;
	
	while(quad1)
	{
		apple.OPENTEHGATES();
		
		driver orange;
		for (int i = 0; i < 40; i++)
		{	
			orange.bothWheels(12); //ONWARD!!!!!
		}
		orange.bothWheels(0);
		
		quad1 = false;
		
		cout <<"Quadrant one complete"<< endl;
		
		quad2 = true;
		cout<< "Quadrant two ACTIVE" <<endl;
	}
	//=====QUADRANT TWO=====//
	//ACTIVATE TEEH CAMERAAAAS
	camera1 banana;
	
	while(quad2)
	{
		//-->Below is a shit load of driving functions and "if" statements<--
		
		//NOTE TO SELF: if the robot is confused as hell, switch to "else if" statements instead
		
		//0 = far, 1 = further, 2 = mid, 3 = closer, 4 = close
		int far = banana.takePicture(0);
		int further = banana.takePicture(1);
		int mid = banana.takePicture(2);
		int closer = banana.takePicture(3);
		int close = banana.takePicture(4);
		
		bool selection = true;
		
		if(banana.senseRedness()) //if there's redness
		{
			while(banana.senseRedness())
			{//move up until the AVC cant see the redness
				orange.bothWheels(10);
			}
			quad2 = false;
			cout << "quad 2 complete!" << endl;
			
			quad3 = true;
			cout << "quad 3 ACTIVE" << endl;
			break;
		}
		
		while(selection)
		{
			if(close != 3 || close != 2 || close != 4)
			{
				//if the black line isnt centered on close, something has gone terribly wrong, go back.
				while(further == 0)
				{ //move back until (further) has line
					orange.bothWheels(-6);
					further = banana.takePicture(1);
				}
				orange.stopEverything();
				selection = false;
				cout << "Cant see the line!" << endl;
			}
			
			if(close == 3 && closer == 3 && mid == 3 && further == 3 && far == 3)
			{
				//straight line
				orange.bothWheels(10);
				selection = false;
				cout << "Straight" << endl;
			}
			
			//-----bends-----//
			if(close == 3 && mid >=3 && mid <=4 && far <= 5 && far >= 4)
			{
				//..to the right
				while(mid != 0 || far != 0)
				{
					orange.leftWheel(10);
					orange.rightWheel(7);
				}
				orange.stopEverything();
				selection = false;
				cout << "Right bend" << endl;
			}
			
			if(close == 3 && mid <=3 && mid >=2 && far <= 2 && far >= 1)
			{
				//..to the left
				while(mid != 0 || far != 0)
				{
					orange.leftWheel(7);
					orange.rightWheel(10);
				}
				orange.stopEverything();
				selection = false;
				cout << "Left bend" << endl;
			}
			
			//-----turns-----//
			if(close == 3 && mid == 4 && further >= 4 && far == 0)
			{
				//...to the right
				while(mid != 0 || far != 0)
				{
					orange.leftWheel(11);
					orange.rightWheel(6);
				}
				orange.stopEverything();
				selection = false;
				cout << "Right turn" << endl;
			}
			
			if(close == 3 && mid == 2 && further >= 2 && far == 0)
			{
				//...to the left
				while(mid != 0 || far != 0)
				{
					orange.leftWheel(6);
					orange.rightWheel(11);
				}
				orange.stopEverything();
				selection = false;
				cout << "Left turn" << endl;
			}
			
			//-----corner-----//
			if(close == 3 && closer == 4 && mid == 5 && further == 0)
			{
				//...to the right
				while(mid != 0 || far != 0)
				{
					orange.leftWheel(12);
					orange.rightWheel(5);
				}
				orange.stopEverything();
				selection = false;
				cout << "Right corner!!!!" << endl;
			}
			
			if(close == 3 && closer == 2 && mid == 1 && further == 0)
			{
				//...to the left
				while(mid != 0 || far != 0)
				{
					orange.leftWheel(5);
					orange.rightWheel(12);		
				}
				orange.stopEverything();
				selection = false;
				
				cout << "Left corner!!!!" << endl;
			}
			
			//-----HAIRPIN DORRIFTOO (a really tight corner)-----//
			if(close == 3 && closer >= 4 && mid == 0)
			{
				//...to the right
				while(mid != 0 || far != 0)
				{
					orange.leftwheel(12);
					orange.rightWheel(2);
				}
				orange.stopEverything();
				selection = false;
				cout << "Right HAIRPIN DORRIFTOOOO!!!!" << endl;
			}
			
			if(close == 3 && closer <= 2 && mid == 0)
			{
				//...to the left
				while(mid != 0 || far != 0)
				{
					orange.leftwheel(2);
					orange.rightWheel(12);
				}
				orange.stopEverything();
				selection = false;
				cout << "Left HAIRPIN DORRIFTOOOO!!!!" << endl;
			}
		}
		
		//=====QUADRANT THREE=====//
		//activate camera2!!!!
		camera2 pineapple;
		
		while(quad3)
		{
			//NOTE TO SELF: if the robot is confused as hell, switch to "else if" statements instead
			orange.bothWheels(10);
			
			//0 = left, 1 = right
			
			//imma use brute force tactics because im lazy... sorry
			int leftCheck = pineapple.takePicture(0);
			int rightCheck = pineapple.takePicture(1);
			
			bool oneEighty = false; //after it does the "180" the exit should be straight ahead. this enables it to exit.
			
			int far = banana.takePicture(0);
			int further = banana.takePicture(1);
			int mid = banana.takePicture(2);
			int closer = banana.takePicture(3);
			int close = banana.takePicture(4);
			
			if(oneEighty)
			{
				
				while(close == 3 )
				{
					orange.bothWheels(12); //exits straight ahead! FULL SPEED!!!!
				}
				cout << "MAZE CLEAR!!!" << endl;
				quad3 = false;
				cout << "quadrant 3 COMPLETE!" << endl;
				quad4 = true;
				
			}
			
			if(leftCheck == 2 && quad3 == true)//if there's a left turn, take it.
			{
				while(mid != 3 && far != 3)
				{
					orange.leftWheel(5);
					orange.rightWheel(10);
				}
				orange.stopEverything();
				cout << "turning a sharp left" << endl;
			}
			else if(RightCheck == 2 && far == 0 && quad3 == true) //if there's a right turn but no left turn NOR anything ahead, take it.
			{
				while(mid != 3 && far !=3)
				{
					orange.leftWheel(10);
					orange.rightWheel(5);
				}
				orange.stopEverything();
				cout << "turning a sharp right" << endl;
			}
			else if(leftCheck == 0 && rightCheck == 0 && mid == 0 && quad3 == true) //if it's a dead end, turn around...
			{
				//...and keep turning until it's aligned again.
				while(mid != 3 && further != 3 && far != 3)
				{
					orange.leftWheel(5);
					orange.rightWheel(-5);
				}
				orange.stopEverything();
				cout << "spinning her 'round" << endl;
			}
			
		}
		
		//=====QUADRANT FOUR=====//
		//create a third camera.h file.
		camera3 coconut;
		
		orange.stopEverything();
		
		coconut.activateQuad4 //this moves the motor so that the camera is facing forwards
		bool phase1 = true; //red pillar
		bool phase1Found = false;
		
		bool phase2 = false; //green pillar
		bool phase2Found = false;
		
		bool phase3 = false; //blue pillar
		bool phase3Found = false;
		
		bool phase4 = false; //orange exit...?
		
		while(quad4)
		{
			while(phase1)
			{
				while(!phase1Found)
				{
					if(coconut.takePicture(0) == 0) //find the pillar
					{
						orange.leftWheel(10);
						orange.rightWheel(1);
					}
					
					if(coconut.takePicture(0) == 1)
					{
						phase1Found = true; //found the pillar, break this while loop
					}
				}
				while(coconut.takePicture(0) != 2)
				{ //approach until it's RIGHT in my face...
					orange.bothWheels(4);
				}
				orange.stopEverything();
				phase1 = false;
				phase2 = true;
				cout << "red phase complete!" << endl;
			}
			
			while(phase2)
			{
				orange.leftWheel(1);
				orange.rightWheel(8);
				sleep(2);
				orange.stopEverything();
				
				while(!phase1Found)
				{
					if(coconut.takePicture(1) == 0) //find the pillar
					{
						orange.leftWheel(9);
						orange.rightWheel(4);
					}
					
					if(coconut.takePicture(1) == 1)
					{
						phase1Found = true; //found the pillar, break this while loop
					}
				}
				while(coconut.takePicture(1) != 2)
				{ //approach until it's RIGHT in my face...
					orange.bothWheels(4);
				}
				orange.stopEverything();
				phase2 = false;
				phase3 = true;
				cout << "green phase complete!" << endl;
			}
			
			while(phase3)
			{
				orange.leftWheel(8);
				orange.rightWheel(1);
				sleep(2);
				orange.stopEverything();
				
				while(!phase1Found)
				{
					if(coconut.takePicture(2) == 0) //find the pillar
					{
						orange.leftWheel(4);
						orange.rightWheel(9);
					}
					
					if(coconut.takePicture(2) == 1)
					{
						sleep(1);
						phase1Found = true; //found the pillar, break this while loop
					}
				}
				while(coconut.takePicture(2) != 2)
				{ //approach until it's RIGHT in my face...
					orange.bothWheels(4);
				}
				orange.stopEverything();
				phase3 = false;
				phase4 = true;
				cout << "blue phase complete!" << endl;
			}
		}
		
	}
	
}
