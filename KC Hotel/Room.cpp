#include <iostream>
#include <string>
#include "Room.h"

Room::Room() {
	type = "null";
	cost = 0.00;
}
void Room::SetRoomAndCost(string roomType, float price) {
	cost = price;
	type = roomType;
}
float Room::GetCost() {
	return cost;
}
string Room::GetType(){
	return type;
}

