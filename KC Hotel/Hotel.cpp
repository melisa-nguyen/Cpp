#include <iostream>
#include <string>

using namespace std;

#include "Hotel.h"

Hotel::Hotel() {
	number = 000;
	type = "null";
  booked = true;
}
void Hotel::SetRoomAndType(int roomNumber, string roomType) {
	number = roomNumber;
	type = roomType;
}
int Hotel::GetRoomNumber() {return number;}
string Hotel::GetType(){return type;}

void Hotel::SetBooked(){
  booked = false;
}
bool Hotel::GetBooked(){return booked;}
