#pragma once
#include<iostream>
#include<list>
#include<iterator>
#include <string>
using namespace std;

class Homework {
private:
	string Name;
	string dueDate;
public:
	Homework();
	Homework(string name, string due) {
		Name = name;
		dueDate = due;
	}
	string getName() { return Name; }
	string getDueDate() { return dueDate; }
	friend bool operator==(Homework A, Homework B) { //Override == to compare both name and due dates of input homework and homework in list
		if (A.Name == B.Name && A.dueDate == B.dueDate)
			return true;
		else {
			return false;
		}

	}
	friend ostream& operator<<(ostream& out, const Homework hw) { //Override cout operator to print homework as "Name, MM/DD/YY"
		out << hw.Name << ", " << hw.dueDate;
		return out;
	}

};

int printMenu() {
	while (true) {
		cout << "MENU" << endl;
		cout << "1 - Add an assignment" << endl;
		cout << "2 - Remove an assignment" << endl;
		cout << "3 - Print assignent list" << endl;
		cout << "4 - Find assignment with earliest due date" << endl;
		cout << "5 - Exit\n" << endl;
		int choice;
		cout << "User selection: ";
		cin >> choice;
		if (choice <= 5 && choice > 0)
			return choice;
		else {
			cout << "\nInvalid choice\n" << endl;
		}
	}
}

void addAssignment(vector<Homework>& List) {
	string name;
	string due;
	cout << "\nAssignment name: ";
	cin >> name;
	
	cout << "Due date(DD/MM/YY): ";
	cin >> due;
	cout << endl;
	Homework tempAssignment(name, due);

	List.push_back(tempAssignment);
}

void removeAssignment(vector<Homework>& List) {

	string name;
	string due;
	cout << "To remove an assignment please provide the following:\n" << endl;
	cout << "Name: ";
	cin >> name;
	cout << "Due date (DD/MM/YY): ";
	cin >> due;
	Homework temp(name, due);

	for (int i = 0; i < List.size(); i++) { //Search for matching assignment to remove
		Homework temp2 = List.at(i);
		if (temp == temp2) {
			List.erase(List.begin() + i);
			cout << "\nAssignment was successfully removed\n" << endl;
			return;
		}
	}
	cout << "Assignment not found\n" << endl;
	return;
}
void printAssignments(vector<Homework> List) { //Iterate through list of homework and prints 
	cout << "\n\nAssignment List:\n";
	for (vector<Homework>::iterator p = List.begin(); p != List.end(); p++) {
		cout << *p << endl;
	}
	cout << endl;

}

struct dueDate { //Function provided by instructor
	int month, day, year;
	dueDate(int m, int d, int y) {
		month = m;
		day = d;
		year = y;
	}
	// override the == operator
	friend bool operator==(dueDate a, dueDate b) {
		if (a.month = b.month && a.day == b.day && a.year == b.year) {
			return true;
		}
		else {
			return false;
		}
	}
};
Homework findFirstDue(vector<Homework> list) {
	Homework tempHW = list.at(0); //Assume first item has the earliest due date
	string due = list.at(0).getDueDate(); //Convert string due date to an int and seperate by category
	double tempM = stoi(due.substr(0, 2));
	int tempD = stoi(due.substr(3, 4));
	// assume all years are the same
	// find the month with the smalles value
	for (int i = 0; i < list.size(); i++) {
		string due = list.at(i).getDueDate();
		double month = stoi(due.substr(0, 2));
		double day = stoi(due.substr(3, 4));

		if (month < tempM) { //Auto populates earliest due date if month is smaller than temp month
			tempHW = list.at(i);
			tempM = month;
			tempD = day;
		}
		if (month == tempM && day < tempD) { //If iterated item has a smaller or equal month and a smaller day, we upate the temp values and temp Homework
				tempHW = list.at(i);
				tempM = month;
				tempD = day;
			}

	}
	return tempHW;


}
