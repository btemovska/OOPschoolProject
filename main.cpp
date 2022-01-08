#include "roster.h"
#include <iostream>
using namespace std;


int main() {

	Roster classRoster;

	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 002871584" << endl;
	cout << "Name: Biljana Temovska" << endl; cout << endl;

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Biljana,Temovska,btemov@wgu.edu,31,53,30,25,SOFTWARE"
	};

	int studentDataSize = sizeof(studentData)/sizeof(studentData[0]);

	cout << "Displaying all students:" << endl;
	for (int i = 0; i < studentDataSize; i++) {
		classRoster.parse(studentData[i]);
	}
	classRoster.printAll();

	cout << "\nDisplaying invalid emails:\n" << endl;
	classRoster.printInvalidEmails();

	cout << "\nDisplaying average days in course:" << endl;
	int i = 0;
	classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());

	//after revision (for single student)
	cout << "\nDisplaying average days for single student:" << endl;
	classRoster.printAverageDaysInCourse2("A4");


	for (int i = 0; i < 3; i++) {
		if (degreeProgramStrings[i] == "SOFTWARE") {
			cout << "\nShowing students in degree program: " << degreeProgramStrings[i] << endl;
			classRoster.printDegreeProgram((DegreeProgram)i);
		}
	}

	cout << "\nRemoving A3:" << endl;
	classRoster.remove("A3");

	cout << "\nRemoving A3 again" << endl;
	classRoster.remove("A3");


	return 0;
}