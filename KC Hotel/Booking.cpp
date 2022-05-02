#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Booking.h"

using namespace std;


Booking::Booking(){
	reservation = 000;
  firstName = "null";
	lastName = "null";
	roomNumber= 0;
	type = "null";
	nights = 000;
  cost = 0.00;
}
void Booking::setBooking(int reservationNum, string fName, string lName, string roomType, int nightsNum){
  reservation = reservationNum;
	lastName = lName;
	firstName = fName;
	type = roomType;
	nights = nightsNum;
}
int Booking::GetReservation() { return reservation; }
string Booking::GetfName() { return firstName; }
string Booking::GetlName() { return lastName; }
string Booking::GetType() { return type;}
int Booking::GetRoomNumber() { return roomNumber; }
int Booking::GetNights() { return nights; }
float Booking::GetCost() { return cost;}


void Booking::SetCost(float roomCost) {
	cost = roomCost;
}
void Booking::SetRoomNumber(int roomNum){
  this->roomNumber = roomNum;
}

void Booking::Print(){
  cout << setw(5) << left << GetReservation() << setw(10) << left <<GetfName() << setw(20) << GetlName() << setw(10) << right << GetType() << setw(10) << GetRoomNumber() << setw(10) << GetCost() <<endl;

}

