#include<iostream>
#include "Guests.h"

using namespace std;

Guests::Guests() {

}

Guests::Guests(const Date& chI, const Date& chO, information info[], int r) {
	checkIn = chI;
	checkOut = chO;
	for (int i = 0; i < 4; i++) // passes the value of array info[i]
		inf[i] = info[i];
	roomNb = r;
}

Guests::~Guests() {
	cout << "Guests destructor" << endl;
}

void Guests::SetCheckIn(const Date& chI) {
	checkIn = chI;
}
void Guests::SetCheckOut(const Date& chO) {
	checkOut = chO;
}
void Guests::SetInf(information info[]) {
	for (int i = 0; i < 4; i++)
		inf[i] = info[i];
}
void Guests::SetRoomNb(int r) {
	roomNb = r;
}

