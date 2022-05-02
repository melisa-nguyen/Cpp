#include <iostream>
#include <vector>

#include "Functions.h"



using namespace std;

int main() {
	vector<Booking> bookingList;
	vector<Hotel> hotelRooms;
	vector<Room> roomCosts;
	vector<Error> errorList;
  
	readFile(bookingList, roomCosts, hotelRooms, errorList);



  assignRooms(bookingList,hotelRooms,roomCosts,errorList);

  printReport(bookingList, errorList);

	}
