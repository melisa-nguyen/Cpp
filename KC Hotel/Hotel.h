#pragma once

#include <string>


using namespace std;

class Hotel {
public:
	Hotel();
	void SetRoomAndType(int, string);
	int GetRoomNumber();
	string GetType();
  void SetBooked();
  bool GetBooked();

private:
	int number;
	string type;
  bool booked;

};

