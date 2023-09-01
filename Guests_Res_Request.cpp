#include<iostream>
#include"Guests_Res_Request.h"

using namespace std;

int Guests_Res_Request::Next_Id = 0;

Guests_Res_Request::Guests_Res_Request(const Guests& g, int nb) {
	ID = ++Next_Id; // counts the IDS
	guests = g;
	nb_night = nb;
}

Guests_Res_Request::~Guests_Res_Request() {
	cout << "Guests_Res_Request desctructor" << endl;
}

Guests& Guests_Res_Request::GetGuests() {
	return guests;
}

const int Guests_Res_Request::GetId() const{
	return ID;
}

const int Guests_Res_Request::GetNbNight() const{
	return nb_night;
}

void Guests_Res_Request::SetGuests(const Guests& g) {
	guests = g;
}

void Guests_Res_Request::SetId(int id) {
	ID = id;
}

void Guests_Res_Request::SetNbNight(int nb) {
	nb_night = nb;
}

void Guests_Res_Request::SetNextId(int nextId) {
	Next_Id = nextId;
}

int Guests_Res_Request::GetNextId() {
	return Next_Id;
}