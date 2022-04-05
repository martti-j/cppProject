#ifndef PARTICIPANT_H
#define PARTICIPANT_H

using namespace std;

class Participant
{
protected:
    string fName, lName;

public:
    Participant(string newFName, string newLName);

    void setFName(string f);
    void setLName(string l);
    string getFName();
    string getLName();
    void printInformation();

};

#endif // PARTICIPANT_H