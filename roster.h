#pragma once
#include "student.h"

class Roster {
public:
	int lastIndex = -1;
	Student* classRosterArray[5];

	void parse(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3 , DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printAverageDaysInCourse2(string studentID);
	void printInvalidEmails();
	void printDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};