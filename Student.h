#ifndef STUDENT_H
#define STUDENT_H

#include "Participant.h"

using namespace std;

class Student : public Participant 
{
private:
	int studentNum;

public:
	Student(string newFName, string newLName, int newStudentNum);

	void setStudentNum(int newStudentNum);
	int getStudentNum();
	void printStudent();
	string getStudentInformation();

};


#endif // TEACHER_H