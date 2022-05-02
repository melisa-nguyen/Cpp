#pragma once
#include <iostream>
#include <vector>

#include "Room.h"
#include "Booking.h"
#include "Hotel.h"
#include "Error.h"



int readFile(vector<Booking>& bookingList,vector<Room>& roomCosts, vector<Hotel>& hotelRooms, vector<Error>& errorList);
//pre  : vector is empty
//post : open file and load valid values into appropriate vector

void printReport(vector<Booking> bookingList, vector<Error> errorList);
//pre  : vector is NOT empty
//post : print vector to screen 

void assignRooms(vector<Booking>& bookingList, vector<Hotel>& hotelRooms, vector<Room> roomCosts, vector<Error>& errorList);
//pre : loaded vectors
//post : update booking list vector with rooms and cost
