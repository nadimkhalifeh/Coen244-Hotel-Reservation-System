
#include<iostream>
#include"Reservation_Manager.h"

using namespace std;

Reservation_Manager::Reservation_Manager() {
	for (int i = 0; i < max_no_of_nights * no_of_rooms; i++)
		arr[i] = NULL;

	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 20; j++)
			ResArr[i][j] = 0;
}  // initialized to 0

Reservation_Manager::Reservation_Manager(Guests_Res_Request* arr_Req[], int res_Arr[max_no][no_of_r]) {
	
	for (int i = 0; i < max_no_of_nights * no_of_rooms; i++)
		arr[i] = arr_Req[i];
	
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 20; j++)
			ResArr[i][j] = res_Arr[i][j];
} // passes the values into the aarrays
Reservation_Manager::~Reservation_Manager() {
	cout << "Reservation manager destructor" << endl;
	for (int i = 0; i < max_no_of_nights * no_of_rooms; i++)
		delete arr[i];
} // manager destructor
const int Reservation_Manager::GetMaxNoNight() const{
	return max_no_of_nights;
}

const int Reservation_Manager::GetNoRoom() const{
	return no_of_rooms;
}
Guests_Res_Request** Reservation_Manager::GetArr(){
	return arr;
}

int (*Reservation_Manager::GetResArr())[20]{
	return ResArr;
}

void Reservation_Manager::SetArr(Guests_Res_Request* arr_Req[]) {
	for (int i = 0; i < max_no_of_nights * no_of_rooms; i++)
		arr[i] = arr_Req[i];
}

void Reservation_Manager::SetResArr(int resArr[max_no][no_of_r]) {
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 20; j++)
			ResArr[i][j] = resArr[i][j];
}

int Reservation_Manager::Gusts_Res_Request(Guests_Res_Request* r) {
	arr[r->GetId() - 1] = r;
	bool b = true;
	for(int i=(r->GetGuests().GetCheckIn().GetDay() - 1); i < (r->GetGuests().GetCheckOut().GetDay());i++)
		if (ResArr[i][r->GetGuests().GetRoomNb() - 1] != 0)
			b = false;
	if (b == false) {
		delete arr[r->GetId() - 1];
		Guests_Res_Request::SetNextId(Guests_Res_Request::GetNextId() - 1);
		return -1;
	}
	else {
		for (int i = (r->GetGuests().GetCheckIn().GetDay() - 1); i < (r->GetGuests().GetCheckOut().GetDay()); i++)
			ResArr[i][r->GetGuests().GetRoomNb() - 1] = r->GetId();
		return r->GetId();
	}
} // if its reserving in an alread taken number it decreases by 1

void Reservation_Manager::PrintDetails(int ID) {
	Guests_Res_Request* r = NULL;
	for (int i = 0; i < max_no * no_of_r && arr[i] != NULL; i++)
		if (arr[i]->GetId() == ID) {
			r = arr[i];        // fill arr
			break;
		}
	if (r != NULL) {
		cout << "Room nb: " << r->GetGuests().GetRoomNb() << endl;
		cout << "Check in day: " << r->GetGuests().GetCheckIn().GetDay() << endl;
		cout << "Check out day: " << r->GetGuests().GetCheckOut().GetDay() << endl;
		for (int i = 0; i < 4 && r->GetGuests().GetInf()[i].GetFirstName()[0] != '\0'; i++) // max 4  in the room
			cout << i + 1 << "_th person Date of birth: " << r->GetGuests().GetInf()[i].GetDateOfBirth().GetDay() << "/" << r->GetGuests().GetInf()[i].GetDateOfBirth().GetMonth() << "/" << r->GetGuests().GetInf()[i].GetDateOfBirth().GetYear() << endl << "First name: " << r->GetGuests().GetInf()[i].GetFirstName() << endl << "Last name: " << r->GetGuests().GetInf()[i].GetLastName() << endl;
	}
	else {
		cout << "This Id does not exist" << endl;
	}
}

void Reservation_Manager::CancelRes(int ID) {
	Guests_Res_Request* r = NULL;
	for (int i = 0; i < max_no * no_of_r && arr[i] != NULL; i++)
		if (arr[i]->GetId() == ID) {
			r = arr[i];
			break;
		}
	if (r != NULL) {

		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 20; j++)
				if (ResArr[i][j] == ID)
					ResArr[i][j] = 0;
				else if (ResArr[i][j] > ID) // just decrement by 1 the IDS bigger than the ID you cancel
					ResArr[i][j]--;
		int k;
		for (k = 0; k < max_no_of_nights * no_of_rooms && arr[k] != NULL; k++)
			if (arr[k]->GetId() > ID) {
				arr[k]->SetId((arr[k]->GetId() - 1)); // sets id after decrementing and repplaces the values
				arr[k - 1] = arr[k];
			}
		Guests_Res_Request::SetNextId(Guests_Res_Request::GetNextId() - 1);
		delete r;
		arr[k - 1] = NULL;
	}
	else {
		cout << "This Id does not exist" << endl;
	}
}