#include <iostream>
#include <string>
#include "E101.h"
#include <unistd.h>
#include <time.h>

class camera1
{
	int takePicture(int dist);
	
	bool senseRedness();
};

//x : 320
//y : 240

//come talk to me, this is gonna require some explanation

//REMINDER TO SELF: if this doesnt work, use 10 sectors instead of 5.

int camera1::takePicture(int dist) //0 = far, 1 = further, 2 = mid, 3 = closer, 4 = close
{
	select_IO(0,0);
	//open_screen_stream();
	take_picture();
	update_screen();
	
	int yPos = ((dist + 1) * 48);
	
	//so this is the actual pixel count.
	int rowPixelCount = 320;
	
	int pixelData[rowPixelCount];
	
	for(int i = 0; i < rowPixelCount; i++)
	{
		pixelData[i] = (int)get_pixel(yPos, i, 3);
	}
	
	//now we divide all the results into five sectors (was originally gonna be seven but it doesnt divide cleanly)
	//320 / 5 = 64
	
	int sector1[64];
	int sector2[64];
	int sector3[64];
	int sector4[64];
	int sector5[64];
	
	for(int alpha = 0; alpha < 64; alpha++)
	{
		sector1[alpha] = pixelData[alpha];
		
		int bravo = 64 + alpha;
		sector2[alpha] = pixelData[bravo];
		
		int charlie = 64 + bravo;
		sector3[alpha] = pixelData[charlie];
		
		int delta = 64 + charlie;
		sector4[alpha] = pixelData[delta];
		
		int echo = 64 + delta;
		sector5[alpha] = pixelData[echo];
	}
	
	//now we gotta find the average
	
	int sector1Sum = 0;
	for(int i = 0; i < 64; i++)
	{
		sector1Sum += sector1[i];
	}
	double sector1Avg = sector1Sum / 64;
	
	
	int sector2Sum = 0;
	for(int i = 0; i < 64; i++)
	{
		sector2Sum += sector2[i];
	}
	double sector2Avg = sector2Sum / 64;
	
	int sector3Sum = 0;
	for(int i = 0; i < 64; i++)
	{
		sector3Sum += sector3[i];
	}
	double sector3Avg = sector3Sum / 64;
	
	int sector4Sum = 0;
	for(int i = 0; i < 64; i++)
	{
		sector4Sum += sector4[i];
	}
	double sector4Avg = sector4Sum / 64;
	
	int sector5Sum = 0;
	for(int i = 0; i < 64; i++)
	{
		sector5Sum += sector5[i];
	}
	double sector5Avg = sector5Sum / 64;
	
	//FINALLY, we can see which one has the black line by finding the sector with the lowest number
	double theONE = 1;
	double theLowest = sector1Avg;
	
	if(theLowest > sector2Avg)
	{
		theONE = 2;
		theLowest = sector2Avg;
	}
	
	if(theLowest > sector3Avg)
	{
		theONE = 3;
		theLowest = sector3Avg;
	}
	
	if(theLowest > sector4Avg)
	{
		theONE = 4;
		theLowest = sector4Avg;
	}
	
	if(theLowest > sector5Avg)
	{
		theONE = 5;
		theLowest = sector5Avg;
	}
	//check to see if it qualifies
	
	if(theLowest > 60)
	{
		theONE = 0;
	}
	return theONE;
}

bool camera1::senseRedness() //there's red tape signaling the end of quad 2
{
	select_IO(0,0);
	//open_screen_stream();
	take_picture();
	update_screen();
	
	int rowPixelCount = 320;
	int colPixelCount = 240;
	
	int totalPixelRedness;
	
	for(int i = 0; i < rowPixelCount; i++)
	{
		for(int j = 0; j < colPixelCount; j++)
		{
			totalPixelRedness = (int)get_pixel(j, i, 0); //hopefully 0 = red...
		}
	}
	
	int average = totalPixelRedness / (320*240);
	
	if(average > 125)
	{
		return true;
	}
	else
	{
		return false;
	}
}
