#include <iostream>
#include <string>
#include "E101.h"
#include <unistd.h>
#include <time.h>

class camera2
{
	int takePicture(int dist);
};

//x : 320
//y : 240

int camera2::takePicture(int dist) //0 = left, 1 = right
{
	select_IO(0,0);
	//open_screen_stream();
	take_picture();
	update_screen();
	
	int xPos = ((dist * 160) + 80);
	
	//so this is the actual pixel count.
	int colPixelCount = 320;
	
	int pixelData[colPixelCount];
	
	for(int i = 0; i < colPixelCount; i++)
	{
		pixelData[i] = (int)get_pixel(i, xPos, 3);
	}
	
	//now we divide all the results into five sectors (was originally gonna be seven but it doesnt divide cleanly)
	//240 / 3 = 80
	
	int sector1[80]; //far
	int sector2[80]; //middle
	int sector3[80]; //close
	
	for(int alpha = 0; alpha < 80; alpha++)
	{
		sector1[alpha] = pixelData[alpha];
		
		int bravo = 64 + alpha;
		sector2[alpha] = pixelData[bravo];
		
		int charlie = 64 + bravo;
		sector3[alpha] = pixelData[charlie];
	}
	
	//now we gotta find the average
	
	int sector1Sum = 0;
	for(int i = 0; i < 80; i++)
	{
		sector1Sum += sector1[i];
	}
	double sector1Avg = sector1Sum / 80;
	
	
	int sector2Sum = 0;
	for(int i = 0; i < 80; i++)
	{
		sector2Sum += sector2[i];
	}
	double sector2Avg = sector2Sum / 80;
	
	int sector3Sum = 0;
	for(int i = 0; i < 80; i++)
	{
		sector3Sum += sector3[i];
	}
	double sector3Avg = sector3Sum / 80;
	
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
	
	//check to see if it qualifies
	
	if(theLowest > 60)
	{
		theONE = 0;
	}
	return theONE;
}
