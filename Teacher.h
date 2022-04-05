#ifndef TEACHER_H
#define TEACHER_H

#include "Participant.h"

using namespace std;

class Teacher : public Participant
{
private:
	string username, password;

public:

	Teacher(string newFName, string newLName, string newUsername, string newPassword);

	void setUsername(string newUsername);
	void setPassword(string newUsername);
	string getUsername();
	string getPassword();
	void printTeacher();
	string getTeacherInformation();

};

#endif // TEACHER_H
