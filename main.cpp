#include<iostream>
#include<conio.h>
#include"h1.h"
using namespace std;

void search() {
	string fname,lname;
	cout<<"Enter first name: ";
	cin>>fname;
	cout<<"Enter last name: ";
	cin>>lname;
	string line;
	ifstream inputFile("students.txt");
	while(getline(inputFile,line)) {
		if(line==fname+" "+lname) {
			cout<<line<<endl;
		}
	}
	inputFile.close();
}

void teamsList() {
	ifstream inputFile;
	inputFile.open("teams.txt",std::ios_base::app);
	string line;
	cout << "--------------------------" << endl;
	if (inputFile.is_open()) {
		int i = 1;
		while(inputFile >>line) {
			cout << "Team" << i << " : " <<line << "\n";
			i++;
		}

	} else
		cout << "Can not open the file!" << endl;
	inputFile.close();
}


int main () {
	string line;
	ifstream inputFile("studentsencode.txt");
	string fName,lName,callNumber;
	Morabi me(fName,lName,callNumber);
	Team myTeam;

	int option;
	do {
		cout<<endl<<"1.Read from file."<<endl;
		cout<<"2.Make coach."<<endl;
		cout<<"3.Make team and set players for team."<<endl;
		cout<<"4.Edit team."<<endl;
		cout<<"5.Team list."<<endl;
		cout<<"6.search for a player."<<endl;
		cout<<"0.exit."<<endl<<endl;
		cin>>option;

		switch (option) {
			case 0:
				exit(0);
			case 1:
				while(getline(inputFile,line)) {
					cout<<decoding(line)<<endl;
				}
				break;
			case 2:
				cout<<"Enter fName:\n";
				cin>>fName;
				cout<<"Enter lName:\n";
				cin>>lName;
				cout<<"Enter callnumber:\n";
				cin>>callNumber;
				break;
			case 3:
				myTeam=me.createTeam();
				me.setStudents(myTeam);
				break;
			case 4:
				me.editTeam(myTeam);
				break;
			case 5:
				teamsList();
				break;
			case 6:
				search();
				break;
			default:
				cout<<"Wrong option!!"<<endl;
				break;
		}
	} while(true);

	getch();
	return 0;
}