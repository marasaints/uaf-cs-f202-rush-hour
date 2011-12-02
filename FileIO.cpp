// FileIO.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
const int COLUMN = 3;
const int ROW = 2;

struct vehicle
{	
	int vehicleNum;
	int coordinates[COLUMN][ROW];
};

//Function Prototypes
string getFileName(void);
void openFileOutput(string&);
void getNumOfVehicles(fstream&);
vehicle* getCoordinates(fstream&, int, int);
void closeFile(string&);

fstream file;

int main()
{

	openFileOutput(getFileName());
	getNumOfVehicles(file);
	getCoordinates(file,3,4);
	return 0;
}
string getFileName(void)
{	
	string filePath;
	string pathNamePrompt("What is the full path to the senario?");
	cout << pathNamePrompt << endl;
	cin >> filePath;

	return filePath;
}
void openFileOutput(string& filePath)
{
	bool fileError = true;
	
	do{
		file.open(filePath);
		if(file.fail())
			{filePath = getFileName();}
		else
			{fileError = false;}
	}while(fileError);
}
void closeFile(string& filePath)
{
	file.close();
}

void getNumOfVehicles(fstream& file)
{
	int numOfCars = 0;
	int numOfTrucks = 0;

	string garbage;
	file >> garbage;
	file >> numOfCars;
	file >> garbage;
	file >> numOfTrucks;

	cout << numOfCars << endl;
	cout << numOfTrucks << endl;
}

vehicle* getCoordinates(fstream& file, int numOfCars, int numOfTrucks)
{
	file.seekg(0L, ios::beg);
	string garbage;
	
	int numOfCarLines = numOfCars * 5;
	int numOfTruckLines = numOfTrucks * 7;
	int numOfLines = numOfCarLines + numOfTruckLines;

	int totalNumOfVehicles = numOfCars + numOfTrucks;
	int currentLine = 0;
	//skipping the number of vehicles at top of file
	for(int index = 0; index < 4; ++index)
	{
		file >> garbage;
	}

	vehicle *Vehicles;
	Vehicles = new vehicle[totalNumOfVehicles];

	for(int vehicleNumIndex = 0; vehicleNumIndex < totalNumOfVehicles; ++vehicleNumIndex)
	{	
		Vehicles[vehicleNumIndex].vehicleNum = vehicleNumIndex + 1;		
	
		for(int column = 0; column < COLUMN; ++column)
		{
			for(int row = 0; row < ROW; ++row)
			{
				
				if((currentLine > numOfCarLines) && (currentLine <= numOfTruckLines))
				{
					if(currentLine % 7 == 0){file >> garbage; ++currentLine;}
					else{file >> Vehicles[vehicleNumIndex].coordinates[column][row]; ++currentLine;}
				}
				else if(currentLine <= numOfCarLines)
				{
					if(currentLine % 5 == 0){file >> garbage; ++currentLine;}
					else{file >> Vehicles[vehicleNumIndex].coordinates[column][row]; ++currentLine;}
				}
			}
		}
	}
	return Vehicles;
}