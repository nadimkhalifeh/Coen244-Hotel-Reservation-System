#pragma once
#include"Guests.h"

class Guests_Res_Request {
private:
	//member
	Guests guests; // Guests object
	int ID;
	int nb_night;
	//static
	static int Next_Id; // int counter generatng reservations ID
public:
	static int GetNextId();
	static void SetNextId(int id);
	Guests_Res_Request(const Guests& g, int nb_night);
	~Guests_Res_Request();
	void SetGuests(const Guests& g);
	void SetId(int id);
	void SetNbNight(int nb);
	Guests& GetGuests();
	const int GetId() const;
	const int GetNbNight() const;
};