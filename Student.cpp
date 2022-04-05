#include <iostream>
#include <sstream>
#include "Participant.h"
#include "Student.h"

using namespace std;

Student::Student(string newFName, string newLName, int newStudentNum) :
	Participant(newFName, newLName) 
{
	studentNum = newStudentNum;
}

void Student::setStudentNum(int newStudentNum) {
	studentNum = newStudentNum;
}

int Student::getStudentNum() {
	return studentNum;
}

void Student::printStudent() {
	cout << "Student information: " << endl;
	Participant::printInformation();
	cout << "Student number: " << studentNum << "\n\n";
}

string Student::getStudentInformation() {
	stringstream information;
	information << fName << "," << lName << "," << studentNum;
	return information.str();
}