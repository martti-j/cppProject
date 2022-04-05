#include <iostream>
#include "Participant.h"

using namespace std;

Participant::Participant(string newFName, string newLName) {
    fName = newFName;
    lName = newLName;
}

void Participant::setFName(string newFName) {
    this->fName = newFName;
}

void Participant::setLName(string newLName) {
    this->lName = newLName;
}

string Participant::getFName() {
    return fName;
}

string Participant::getLName() {
    return lName;
}

void Participant::printInformation() {
    cout << "Name: " << fName << " " << lName << endl;
}