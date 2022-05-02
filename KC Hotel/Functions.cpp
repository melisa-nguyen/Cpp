#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iomanip>


#include "Functions.h"



using namespace std;

int readFile(vector<Booking>& bookingList,vector<Room>& roomCosts, vector<Hotel>& hotelRooms, vector<Error>& errorList) {
	
  ifstream inFile;              //Read csv file and check if file is good
	inFile.open("HotelData.csv", ios::in | ios::app);
	if (!inFile.is_open()) {
		cout << "File could not be opened" << endl;
		return 1;                        //Program stops and error message is displayed
	}
	cout << "Accessing file..." << endl;

	string inRec, tempStr;
	vector<string> row;

	while (getline(inFile, inRec)) { //Reads each line of csv file into string stream
    int i = 0;
		stringstream inSS(inRec);
		row.clear();                  //Clears temporary vector to prepare for next input
		while (getline(inSS, tempStr, ',')) {   //Breaks line into words by indicated symbol
		  row.push_back(tempStr);
    }
      if (row[0] == "R"){       //load vector of rooms with the type of bed and cost per night
        float tempCost;
        tempCost = stof(row.at(2));
        Room tempRoom;
        tempRoom.SetRoomAndCost(row.at(1), tempCost);
        roomCosts.push_back(tempRoom);
		}
      if(row[0] == "H") {    //load vector of hotel rooms with the room number and bed type
        int tempRoomNum;
        try{
          tempRoomNum = stoi(row[1]);
          Hotel tempRoom;
  			  tempRoom.SetRoomAndType(tempRoomNum, row[2]);
          hotelRooms.push_back(tempRoom);
                     //catch any input error and adds to error list
        }
        catch (...) {
				Error tempError;
				tempError.SetError("room number", row[1], "is not a valid room number.");
				errorList.push_back(tempError);
        }
      }
      if (row[0] == "B") {
        int tempNights, tempRes;
        
			try {
				tempNights = stoi(row[5]);
				tempRes = stoi(row[1]);
        Booking tempBook;
        tempBook.setBooking(tempRes, row[2], row[3], row[4],tempNights);
			  bookingList.push_back(tempBook);
			}
			catch (...) {              //catch any input error and adds to error list
				Error tempError;
				string tempName = row[2] + " " + row[3];
				tempError.SetError("customer", tempName, "Invalid data in input string");
				errorList.push_back(tempError);
			}
    }
  }
  inFile.close();
  return 0;
  }

void printReport(vector<Booking> bookingList, vector<Error> errorList) {    //Display booking records and error list
	cout << right <<setw(50) << "KANSAS CITY INTERNATIONAL HOTEL\n" << endl;
	for (int i = 0; i < bookingList.size(); i++) {
		bookingList.at(i).Print();
	}
cout << "\nError Records:\n" << endl;
	for (int i = 0; i < errorList.size(); i++) {
		errorList.at(i).PrintError();
	}
  }



void assignRooms(vector<Booking>& bookingList, vector<Hotel>& hotelRooms, vector<Room> roomCosts, vector<Error>& errorList){
  for (int i=0; i < bookingList.size(); i++){      //Search for room types that match reservation request and checking if available, if available, a room will be assigned
                                                  // and room will be marked as booked
    for (int j=0; j < hotelRooms.size(); j++){
      if (bookingList.at(i).GetType() == hotelRooms.at(j).GetType()){
        if (hotelRooms.at(j).GetBooked() == true) {
        int tempNum;
        tempNum = hotelRooms.at(j).GetRoomNumber();
        bookingList.at(i).SetRoomNumber(tempNum);
        hotelRooms.at(j).SetBooked();
        for(int k = 0 ; k < roomCosts.size(); k++){          //Calculating total cost of all nights by using vector or prices and room types
          if((bookingList.at(i).GetType()) == (roomCosts.at(k).GetType())){
            float priceTotal;
            priceTotal = roomCosts.at(k).GetCost() * bookingList.at(i).GetNights();
            bookingList.at(i).SetCost(priceTotal);
            break;
          }
        }
        break;
        }
        
          }
      
      }
      }
  for (int i=0; i < bookingList.size(); i++){    //If the room is still set to 0, we add the reservation to an error list and leave reservation as is
        if((bookingList.at(i).GetRoomNumber() == 0)) {
          int num = bookingList.at(i).GetReservation(); 
          string str; 
          stringstream ss;  
          ss << num;  
          ss >> str;  
          Error tempError;
          tempError.SetError("reservatoin", str,"There is no room available");
          errorList.push_back(tempError);
          continue;
          }
        }
  }

