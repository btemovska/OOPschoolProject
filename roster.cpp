#include "roster.h"
#include <iostream>

void Roster::parse(string studentData) {

	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string strDegree = studentData.substr(lhs, rhs - lhs);

	DegreeProgram degree = DegreeProgram::SECURITY;
	if (strDegree == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	else if (strDegree == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int parr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, parr, degreeProgram);
}

//before revision
//void Roster::printAll() {
//	for (int i = 0; i <= Roster::lastIndex; i++) {
//		cout << classRosterArray[i]->getStudentID() << "\t";
//		cout << "First Name: " << classRosterArray[i]->getFirstName() << "\t";
//		cout << "Last Name: " << classRosterArray[i]->getLastName() << "\t";
//		cout << "Age: " <<classRosterArray[i]->getAge() << "\t";
//		cout << "daysInCourse: {" << classRosterArray[i]->getDaysInCourse()[0] << ", ";
//		cout << classRosterArray[i]->getDaysInCourse()[1] << ", ";
//		cout << classRosterArray[i]->getDaysInCourse()[2] << "}\t";
//		cout << "Degree Program: " << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()];
//		cout << endl;
//	}
//}

//after revision
void Roster::printAll() {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string emailAdd = (classRosterArray[i]->getEmailAddress());
		if (emailAdd.find('@') == string::npos) {
			cout << classRosterArray[i]->getEmailAddress() << " - missing an @ symbol." << endl;
		}
		else if (emailAdd.find('.') == string::npos) {
			cout << classRosterArray[i]->getEmailAddress() << " - missing a period." << endl;
		}
		else if (emailAdd.find(' ') != string::npos) {
			cout << classRosterArray[i]->getEmailAddress() << " - no spaces allowed." << endl;
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		int averageDays = (classRosterArray[i]->getDaysInCourse()[0] + 
							classRosterArray[i]->getDaysInCourse()[1] + 
							classRosterArray[i]->getDaysInCourse()[2]) / 3;
		cout << "Student ID: " << classRosterArray[i]->getStudentID() << ",";
		cout << " averages " << averageDays << " days in a course." << endl;
	}
}
//after revision - for single student
void Roster::printAverageDaysInCourse2(string studentID) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int averageDays = (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2]) / 3;
			cout << "Student ID: " << classRosterArray[i]->getStudentID() << ",";
			cout << " averages " << averageDays << " days in a course." << endl;
		}
	}
}

void Roster::printDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}


void Roster::remove(string studentID) {
	bool x = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			x = true;
			if (i < 4) {
				Student* tempArray = classRosterArray[i];
				classRosterArray[i] = classRosterArray[4];
				classRosterArray[4] = tempArray;
			}
			Roster::lastIndex--;
		}
	}
	if (x) {
		this->printAll();
	}
	else {
		cout << "The student with ID: "<< studentID << " was not found" << endl;
	}
}

Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
	}
}
