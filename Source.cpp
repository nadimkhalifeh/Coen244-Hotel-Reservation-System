#include<iostream>
#include"Reservation_Manager.h"
using namespace std;

int main() {
	Reservation_Manager ResManager;
	char c;
	do {
		cout << "1. Print all reservation" << endl;
		cout << "2. Add new reservation" << endl;
		cout << "3. Remove a reservation" << endl;
		cout << "4. Print reservation detail" << endl;
		cout << "5. Press 'e' to exit" << endl;
		cin >> c;
		switch (c) {
			case '1': {
				for (int i = 0; i < 7; i++) {
					for (int j = 0; j < 20; j++)
						cout<< ResManager.GetResArr()[i][j] << " ";
					cout << endl;
				}
				break;
			}
			case '2': {
				Guests g;
				Date d;
				int a;
				d.SetMonth(3);
				d.SetYear(2022);
				cout << "enter check in Date:" << endl;
				cout << "enter day ";
				cin >> a;
				d.SetDay(a);
				g.SetCheckIn(d);
				cout << "enter check out Date:" << endl;
				cout << "enter day ";
				cin >> a;
				d.SetDay(a);
				g.SetCheckOut(d);

				cout << "enter how many person will be in the room" << endl;
				cin >> a;
				int nbP = a;
				information infarr[4];
				for (int i = 0; i < 4; i++) {
					if (i < nbP) {
						char name[100];
						cout << "enter first name :" << endl;
						cin >> name;
						infarr[i].SetFirstName(name);
						cout << "enter last name :" << endl;
						cin >> name;
						infarr[i].SetLastName(name);
						Date DOB;
						cout << "enter date of birth:" << endl;
						cout << "enter day:";
						cin >> a;
						DOB.SetDay(a);
						cout << "enter month:";
						cin >> a;
						DOB.SetMonth(a);
						cout << "enter year:";
						cin >> a;
						DOB.SetYear(a);
						infarr[i].SetDateOfBirth(DOB);
					}
					else {
						char name[100] = { '\0' };
						infarr[i].SetFirstName(name);
					}
				}
				g.SetInf(infarr);
				cout << "enter room nb" << endl;
				cin >> a;
				g.SetRoomNb(a);
				cout << "enter nb of night" << endl;
				cin >> a;
				Guests_Res_Request* r = new Guests_Res_Request(g, a);
				ResManager.Gusts_Res_Request(r);
				break;
			}
			case '3': {
				int ID;
				cout << "enter reservation ID" << endl;
				cin >> ID;
				ResManager.CancelRes(ID);
				break;
			}
			case '4': {
				int ID;
				cout << "enter reservation ID" << endl;
				cin >> ID;
				ResManager.PrintDetails(ID);
			}
		}
	} while (c != 'e');
}