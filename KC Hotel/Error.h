#pragma once

#include <string>


using namespace std;

class Error {
public:
  Error();
	void SetError(string, string, string);
	void PrintError();

private:
	string category;
	string value;
	string reason;
};
