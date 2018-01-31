
#include<iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
#ifndef __LOGIN_H_INCLUDED__  
#define __LOGIN_H_INCLUDED__

string login()
{
	system("cls");
	system("Color 4E");
	string Username, Password, temp, fail = "$";
	char ch;
	cout << " \n\n\t<<<<<<<<<<<<<<<< ---- University of Bridgeport Human Resource Management System ---- >>>>>>>>>>>>>>>>>";
	cout << "\n\n\t\t\t\t\t============ >> Admin Login << =============\n\n\n\n\n\n\n\n\n\n\t\t\t\t Administrator login: ";
	cin >> Username;
	cout << "\n\t\t\t\t Please enter your password: ";
	temp = "";
	ch = _getch();
	while (ch != 13) {
		temp.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	Password = temp;
	string userAndPass = Username + " " + Password; // Search pattern
	string line;
	ifstream ilogin("admin.txt");
	if (ilogin.is_open())
	{
		getline(ilogin, line);
		if (line.compare(userAndPass) == 0) { //match strings exactly!
			return Username;
		}
		else {
			cout << "\nUsername and/or Password incorrect!\n\n\n\n";
			_getch();
			login(); //ok we didn't find them, lets redo this!
		}
	}

	else {
		cout << "\n User account doesnot exist" << endl;
		_getch();
		return fail;
	}
	ilogin.close();
}
#endif
