#pragma once
#include"Guests_Res_Request.h"
#define max_no 7 // max_no is 7
#define no_of_r 20 // no_of_r is 20
class Reservation_Manager {
private:
	const int max_no_of_nights = 7;
	const int no_of_rooms = 20;
	Guests_Res_Request* arr[max_no * no_of_r]; // array of pointers to Guest_res_req
	int ResArr[max_no][no_of_r]; //2D array
public:
	Reservation_Manager();
	Reservation_Manager(Guests_Res_Request* arr_Req[],int res_Arr[max_no][no_of_r]);// passes Guest_Res_request ptr adn res Arr 
	~Reservation_Manager();
	const int GetMaxNoNight() const;
	const int GetNoRoom() const;
	Guests_Res_Request** GetArr(); // gets Guests_Res_Request* arr[max_no * no_of_r];
	int (*GetResArr())[20]; //ResArr[max_no][no_of_r]
	void SetArr(Guests_Res_Request* arr_Req[]);
	void SetResArr(int resArr[max_no][no_of_r]);
	int Gusts_Res_Request(Guests_Res_Request* r);
	void PrintDetails(int ID);
	void CancelRes(int ID);
};