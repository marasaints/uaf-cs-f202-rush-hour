// FileIO.cpp : Defines the entry point for the console application.

#include "fileIO.h"

//Function Prototypes
string getFileName(void);
void openFileOutput(string&);
void getNumOfVehicles(fstream&);
vehicle* getCoordinates(fstream&, int, int);
void printCoordinates(vehicle*, int, int);
void closeFile(string&);

fstream file;

int main()
{
	openFileOutput(getFileName());
	getNumOfVehicles(file);
	printCoordinates(getCoordinates(file,3,4),3,4);
	//getCoordinates(file,3,4);
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
}

vehicle* getCoordinates(fstream& file, int numOfCars, int numOfTrucks)
{
	file.seekg(0L, ios::beg);
	
	bool carsDone = false;
	int coordinateNum = 0;
	int numOfCarLines = numOfCars * 5;
	int numOfTruckLines = numOfTrucks * 7;
	int numOfLines = numOfCarLines + numOfTruckLines;
	int currentLine = 0;
	int totalNumOfVehicles = numOfCars + numOfTrucks;
	string garbage;

	vehicle *Vehicles;
	Vehicles = new vehicle[totalNumOfVehicles];

	//skipping the number of vehicles at top of file
	for(int index = 0; index < 4; ++index)
	{
		file >> garbage;
	}

	for(int vehicleNumIndex = 0; vehicleNumIndex < totalNumOfVehicles; ++vehicleNumIndex)
	{	
		Vehicles[vehicleNumIndex].vehicleNum = vehicleNumIndex + 1;

		for(int row = 0; row < ROW; ++row)
		{
			for(int column = 0; column < COLUMN; ++column)
			{		
				//case if reading in car data
				if(Vehicles[vehicleNumIndex].vehicleNum < numOfCars) 
				{
					//checking to see if going to read a garbage line
					if(currentLine % 5 == 0) 
					{
						file >> garbage;
						++currentLine;
						--column;
					}
					//storing in the coordinate value
					else 
					{	
						if(row < 2)
						{
							file >> Vehicles[vehicleNumIndex].coordinates[row][column];
							++currentLine;
							++coordinateNum;
						}
						else
						{
							break;
						}
					}
				}
				else if(Vehicles[vehicleNumIndex].vehicleNum >= numOfCars  && carsDone == false)
				{
					carsDone = true;
					--column;
					currentLine = 0;
				}

				//seeing if reading in truck data
	
				else if(Vehicles[vehicleNumIndex].vehicleNum <= numOfTrucks) 
				{
					 //checking to see if its a garbage line
					if(currentLine % 7 == 0)
					{
						file >> garbage;
						++currentLine;
						--column;
					}
					//reading in coordinate data
					else 
					{
						file >> Vehicles[vehicleNumIndex].coordinates[row][column];
						++currentLine;
					}
				}
			}
		}
	}
	return Vehicles;
}

void printCoordinates(vehicle* Vehicles, int numOfCars, int numOfTrucks)
{
	int totalNumOfVehicles = numOfCars + numOfTrucks;

	for(int vehicleNumIndex = 0; vehicleNumIndex < totalNumOfVehicles; ++vehicleNumIndex)
	{
		cout << "NUM OF VEHICLE " << Vehicles[vehicleNumIndex].vehicleNum << endl;
		if(Vehicles[vehicleNumIndex].vehicleNum <= numOfCars)
		{
			for(int row = 0; row < ROW; ++row)
			{
				for(int column = 0; column < COLUMN; ++column)
				{
					cout << Vehicles[vehicleNumIndex].coordinates[row][column] << "," 
						 << Vehicles[vehicleNumIndex].coordinates[row+1][column] << endl;
				}
			}
		}
		else if(Vehicles[vehicleNumIndex].vehicleNum <= numOfTrucks)
		{
			for(int row = 0; row < ROW; ++row)
			{
				for(int column = 0; column < COLUMN; ++column)
				{
					cout << Vehicles[vehicleNumIndex].coordinates[row][column] << "," 
						 << Vehicles[vehicleNumIndex].coordinates[row+1][column] << endl;
				}
			}			
		}
	}
}
