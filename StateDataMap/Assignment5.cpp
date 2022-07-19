#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <iomanip>
#include <utility>
#include <set>


using namespace std;

//print key values of a map
template <typename O>
void printMap(map<O, O> const& map) {
	for (auto it = map.cbegin(); it != map.cend(); ++it) {
		cout << (*it).first << ": " << (*it).second << "\n";
	}
}
void getCapital(string state, map<string,string> const&map) {
	bool found = false;
	for (auto it = map.cbegin(); it != map.cend(); ++it) {
		if (state == (*it).first) {
			cout << (*it).second << "\n" << endl;
			found = true;
		}
	} 
	if (found != true){
		cout << "Entry not found\n" << endl;
	}
}

int main()
{
	map<string, string> stateDataMap;

	//add the following pairs to stateDataMap: 
	stateDataMap["Nebraska"] = "Lincoln";
	stateDataMap["New York"] = "Albany";
	stateDataMap["Ohio"] = "Columbus";
	stateDataMap["California"] = "Sacramento";
	stateDataMap["Massachusetts"] = "Boston";
	stateDataMap["Texas"] = "Austin";

	//outputs the data stored in stateDataMap:
	cout << "State Name; Capital Name" << endl;
	cout << "--------------------------" << endl;
	printMap(stateDataMap);
	cout << "\n" << endl;

	//statement that changes the capital of California to Los Angeles
	stateDataMap["California"] = "Los Angeles";
	cout << "State Name; Capital Name" << endl;
	cout << "--------------------------" << endl;
	printMap(stateDataMap);
	cout << "\n" << endl;

	string entry = "0";
	while (entry != "q" && entry != "Q") {
		cout << "Enter state name to find the capital in our database or Q to quit:" << endl;
		getline(cin, entry);
		getCapital(entry, stateDataMap);
	}
	cout << "Thank you for using mn map search" << endl;


}