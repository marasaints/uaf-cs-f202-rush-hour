// FileIO.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

//Function Prototypes
string getFileName(void);
void openFileOutput(string&);
void getNumOfVehicles(fstream&);
vehicle getCoordinates(fstream&, int, int);
void closeFile(string&);

fstream file;

int const COLUMN = 3;
int const ROW = 2;

struct vehicle
{	
	string vehicleType;
	short vehicleNum;
	int coordinates[COLUMN][ROW];
};

int main()
{
	openFileOutput(getFileName());
	getNumOfVehicles(file);
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

vehicle getCoordinates(fstream& file, int numOfCars, int numOfTrucks)
{
	file.seekg(0L, ios::beg);
	string garbage;
	
	for(int index = 0; index < 4; ++index)
	{
		file >> garbage;
	}

	vehicle *cars;
	vehicle *trucks;

	cars = new vehicle[numOfCars];
	trucks = new vehicle[numOfTrucks];

	for(int carNumIndex = 0; carNumIndex < numOfCars; ++carNumIndex)
	{	
		int numOfLines = numOfCars * 5;
		for(int fileLineIndex = 0; fileLineIndex < numOfLines; ++fileLineIndex)		
		{
			if(numOfLines % 5 == 0){file >> garbage;}

			cars[carNumIndex].coordinates[][];
		}

	}
}