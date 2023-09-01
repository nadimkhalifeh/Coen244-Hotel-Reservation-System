#pragma once
#include "Date.h"
#include"information.h"

class Guests {
private:
	Date checkIn; //Check in date as data member from type data
	Date checkOut; // //Check out date as data member from type data
	information inf[4];
	int roomNb;
public:
	Guests(const Date& chI,const Date& chO,information info[],int r); // passes Check in Date and Check out Date reference , information of the guest and room number
	Guests();
	~Guests(); // destructor
	void SetCheckIn(const Date& chI);
	void SetCheckOut(const Date& chI);
	void SetInf(information info[]);
	void SetRoomNb(int r);
	const Date& GetCheckIn() const;
	const Date& GetCheckOut() const;
	const information* GetInf() const;
	int GetRoomNb() const;
};
//used in header because linker will generate a error with the inline 
inline const Date& Guests::GetCheckIn() const {
	return checkIn;
}
inline const Date& Guests::GetCheckOut() const {
	return checkOut;
}
inline const information* Guests::GetInf() const {
	return inf;
}
inline int Guests::GetRoomNb() const {
	return roomNb;
}
