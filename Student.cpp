#include "Student.h"

Student::Student()
{
	name = "";
	ID = 0;
}
void Student::setName(string n)
{
	name = n;
}
void Student::setID(int i)
{
	ID = i;
}
string Student::getName()
{
	return name;
}
int Student::getID()
{
	return ID;
}
void Student::print()
{
	cout << "Name: " << name << endl;
	cout << "ID: " << ID << endl;
}