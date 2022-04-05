#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <filesystem>
#include <map>
#include "Participant.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;
using filesystem::current_path;
using filesystem::exists;

void addObjToFile(string obj, string fileName) {
    fstream fileOut;
    fileOut.open(fileName, ios_base::app);
    fileOut << obj << endl;
    fileOut.close();
}

map<int, string> getCourses(string fileName) {
    fstream fileIn;
    map<int, string> courses;
    int num = 1;
    fileIn.open(fileName, ios_base::in);
    string line;
    while (getline(fileIn, line)) {
        cout << line << " " << num << endl;
        courses.insert({ num, line });
        ++num;
    }
    fileIn.close();
    return courses;
}

vector<Teacher> getTechers(string fileName) {
    fstream fileIn;
    vector<string> information;
    vector<Teacher> teachers;
    fileIn.open(fileName, ios_base::in);
    string line;
    while (getline(fileIn, line)) {
        string w = "";
        for (auto x : line) {
            if (x == ',') {
                information.push_back(w);
                w = "";
            }
            else {
                w = w + x;
            }
        }
        information.push_back(w);
        Teacher teacher = Teacher(information[0], information[1], information[2], information[3]);
        teachers.push_back(teacher);
        information.clear();
    }
    fileIn.close();
    return teachers;

}

Teacher login() {
    vector<Teacher>teachers = getTechers("teachers.txt");
    while (true) {
        string username, password;
        cout << "Give your username: ";
        cin >> username;
        cout << "Give your password: ";
        cin >> password;
        cout << "Log in..." << endl;

        for (auto i : teachers) {
            if (i.getUsername() == username && i.getPassword() == password) {
                return i;
            }
            else {
                continue;
            }
        }
        cout << "The username or the password was wrong. Plese try again." << endl;
    }
}

string spaceToUnderscore(string text) {
    for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
        if (*it == ' ') {
            *it = '_';
        }
    }
    return text;
}

int checkInput() {
    // Checking if the given input is a number.
    int answer;
    while (!(cin >> answer)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again: ";
    }
    return answer;
}

void createCourse(Teacher& teacher) {
    string courseName;
    stringstream fileName;
    cout << "Give course's name: ";
    getline(cin.ignore(), courseName);
    fileName << current_path().string() << "\\courses\\" << spaceToUnderscore(courseName) << ".txt";
    if (exists(fileName.str())) {
        cout << "Corse exists already." << endl;
    }
    else {
        cout << fileName.str() << endl;
        addObjToFile(courseName, "courses.txt");
        addObjToFile(teacher.getTeacherInformation(), fileName.str());
    }
}

void deleteCorse() {
    map<int, string> courses = getCourses("Courses.txt");
    stringstream fileName;
    ifstream fin;
    fin.open("courses.txt");
    ofstream temp;
    temp.open("temp.txt");
    string line;
    int deleteLine = checkInput();
    auto it = courses.find(deleteLine);
    if (it != courses.end()) {
        while (getline(fin, line)) {
            if (line != it->second) {
                temp << line << endl;
            }
        }
        fileName << current_path().string() << "\\courses\\" << spaceToUnderscore(it->second) << ".txt";
        fin.close();
        temp.close();
        filesystem::remove(fileName.str());
        remove("courses.txt");
        if (rename("temp.txt", "courses.txt") != 0) {
            cout << "Something went wrong." << endl;
        }
    }
    else {
        cout << "not found\n";
    }
}

int teacherView(Teacher teacher) {
    cout << "Hello " << teacher.getFName() << " " << teacher.getLName() << endl;
    int answer;
    while (true) {
        cout << "Create new course: 1" << endl;
        cout << "Show all courses: 2" << endl;
        cout << "Delete corse: 3" << endl;
        cout << "Back to main menu: 4" << endl;

        answer = checkInput();
        
        switch (answer) {

        case 1:
            createCourse(teacher);
            cout << "The course has been created." << endl;
            break;

        case 2:
            cout << "Here are all the available courses." << endl;
            getCourses("Courses.txt");
            break;

        case 3:
            deleteCorse();
            break;

        case 4:
            return 0;

        default:
            cout << "It isn't an option. Try again. " << endl;
        }
    }
}

bool checkStudent(string corse, Student student) {
    fstream students;
    vector<string> information;
    students.open(corse, ios_base::in);
    string line;
    while (getline(students, line)) {
        string w = "";
        for (auto x : line) {
            if (x == ',') {
                information.push_back(w);
                w = "";
            }
            else {
                w = w + x;
            }
        }
        information.push_back(w);
        try {
            int num = stoi(information[2]);
            if (num == student.getStudentNum()) {
                return true;
            }
            else {
                information.clear();
                continue;
            }
        }
        catch (exception& err) {
            information.clear();
            continue;
        }
    }
    return false;
        
}

void corseSignUp(string corseName, Student student) {
    stringstream  corse;
    corse << current_path().string() << "\\courses\\" << spaceToUnderscore(corseName) << ".txt";
    cout << "You are sing up for " << corseName << "." << endl;
    if (checkStudent(corse.str(), student)) {
        cout << "You are already sign up." << endl;
    }
    else {
        addObjToFile(student.getStudentInformation(), corse.str());
    }
}

void studentView() {
    string fname, lname;
    int studentNum;
    cout << "Please give your information." << endl;
    cout << "First name: "; cin >> fname;
    cout << "Last name: "; cin >> lname;
    cout << "Student number: "; studentNum = checkInput();
    Student student = Student(fname, lname, studentNum);
    cout << "Here are all the available courses." << endl;
    map<int, string> courses = getCourses("courses.txt");
    cout << "What course do you want to sign up for?" << endl;
    cout << "Give the coursea number: ";
    int answer = checkInput();
    map<int, string>::iterator itr;
    for (itr = courses.begin(); itr != courses.end(); ++itr) {
        if (answer == itr->first) {
            corseSignUp(itr->second, student);
        }
    }
}


int main() {
    int answer;
    cout << "Current working directory: " << current_path() << endl;
    while (true) {
        cout << "Course registration program" << endl;
        cout << "Teacher: 1" << endl;
        cout << "Student: 2" << endl;
        cout << "Exit: 3" << endl;

        answer = checkInput();

        switch (answer) {
        case 1: {
            Teacher teacher = login();
            teacherView(teacher);
            break;
        }

        case 2:
            studentView();
            break;

        case 3:
            return 0;

        default:
            cout << "It isn't an option. Try again. " << endl;
        }
    }
}