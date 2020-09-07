#include "Student.h"
#include <fstream>
using namespace std;

void main()
{
	ifstream inputFile;
	inputFile.open("StudentsData.txt");
	if (!inputFile.fail())
	{
		// Read the data of students from a file into an array of class Student.
		Student arr[3];
		int i = 0;
		string tempName;
		int tempID;
		while (!inputFile.eof() && (i < 3))
		{
			inputFile >> tempName;
			inputFile >> tempID;
			arr[i].setName(tempName);
			arr[i].setID(tempID);
			i++;
		}
		inputFile.close();

		// Print the data of the students.
		for (int i = 0; i < 3; i++)
		{
			arr[i].print();
		}
	}
}