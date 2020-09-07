#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int ID;
public:
	Student();
	void setName(string n);
	void setID(int i);
	string getName();
	int getID();
	void print();
};