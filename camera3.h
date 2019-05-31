#include <iostream>
#include <string>
#include "E101.h"
#include <unistd.h>
#include <time.h>

class camera3
{
	void activateQuad4();
	int takePicture(int phase);
};

//x : 320
//y : 240

void camera3::activateQuad4()
{
	//REMINDER TO SELF: Fix this when you get to the lab
	set_motors(4, 55);
	sleep(5);
	set_motors(4, 48);
}

int camera3::takePicture(int phase) //0 = red, 1 = green, 2 = blue, (exit color???)
{
	int pixelData[320][240];
	//first we gotta get ALL them pixels.
	for (int i = 0; i < 320; i++)
	{
		for (int j = 0; j < 240; j++)
		{
			pixelData[320][240] = (int)get_pixel(i, j, phase);
		}
	}
	
	double cameraSum = 0;
	for (int i = 0; i < 320; i++)
	{
		for (int j = 0; j < 240; j++)
		{
			cameraSum += pixel[i][j];
		}
	}
	double pixelDataRatio = cameraSum / 76800; //that is the amount of pixels
	
	//AND NOW, is the big moment...
	if(pixelDataRatio < 50)
	{
		//no pillar
		return 0;
	}
	
	if(pixelDataRatio > 50)
	{
		//OOO I see the pillar!!!!!
		return 1;
	}
	
	if(pixelDataRatio > 120)
	{
		//its RIGHT in my face...
		return 2;
	}
	
}
