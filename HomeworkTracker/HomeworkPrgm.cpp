#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iterator>
#include "Homework.h"


//ERROR HANDLING: Assignment names may only be entered without spaces
using namespace std;


int main() {
	cout << "Welcome to Assignment Tracker\n\n" << endl;

	vector<Homework> AssignmentList; //Create vector of Homework objects
	bool access = true;

	while (access == true) {
		
		int user = printMenu();
		if (user == 5) { //Exit the program
			cout << "Thank you for using Assignment Tracker" << endl;
			access = false;
		}
		else {
			switch (user) { //Executes user choice
			case 1: 
				addAssignment(AssignmentList); //MAY ONLY ACCEPT ONE WORK NAMES
				break;
			case 2:
				removeAssignment(AssignmentList);
				break;
			case 3:
				printAssignments(AssignmentList);
				cout << endl;
				break;
			case 4:
				if (AssignmentList.size() == 0) //Error when there are no assignments in the list
					cout << "No assignments found" << endl;
				else {
					cout << endl;
					cout << findFirstDue(AssignmentList);
					cout << endl;
				}
				break;
			}

		}
	}
}

