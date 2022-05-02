#include <string>
#include <vector>

using namespace std;

class Booking {
public:
  Booking();
	void setBooking(int, string, string, string, int);
  int GetReservation();
  string GetfName();
  string GetlName();
  string GetType();
  int GetRoomNumber();
  int GetNights();
  float GetCost();

  void SetCost(float);
  void SetRoomNumber(int);
  void Print();

private:
	int reservation;
	string lastName;
	string firstName;
	int roomNumber;
	string type;
	int nights;
  float cost;

};