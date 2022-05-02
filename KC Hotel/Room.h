#include <string>

using namespace std;

class Room {
public:
	Room();
	void SetRoomAndCost(string, float);

	string GetType();
	float GetCost();
private:
	string type;
	float cost;

};
