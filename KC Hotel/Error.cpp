#include <iostream>
#include <string>
using namespace std;

#include "Error.h"

void Error::SetError(string category, string value, string reason) {
	this->category = category;
	this->value = value;
	this->reason = reason;
}

void Error::PrintError() {
	cout << "Error on " << category << ": " << value << ". " << reason << endl;
}

Error::Error(){
  category = "null";
  value = "null";
  reason = "null";
}