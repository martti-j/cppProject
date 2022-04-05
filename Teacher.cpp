#include <iostream>
#include <sstream>
#include "Participant.h"
#include "Teacher.h"

using namespace std;

Teacher::Teacher(string newFName, string newLName, string newUsername, string newPassword):
	Participant(newFName, newLName)
{
	username = newUsername;
	password = newPassword;
}

void Teacher::setUsername(string newUsername) {
	username = newUsername;
}

void Teacher::setPassword(string newPassword) {
	password = newPassword;
}

string Teacher::getUsername() {
	return username;
}

string Teacher::getPassword() {
	return password;
}

void Teacher::printTeacher() {
	cout << "Teacher information: " << endl;
	Participant::printInformation();
	cout << "Username: " << username << "\n\n";
}

string Teacher::getTeacherInformation() {
	stringstream information;
	information << fName << "," << lName << "," << username;
	return information.str();

}



