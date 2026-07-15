#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

void administrator();
void tablemanager();
void roommanager();
void parkingmanager();

void write();
void read();

struct manage {
	string state[50], status[35];
	int table[35];
};
manage rest;

ofstream myfile;
ifstream readfile;
int main(){
	char dec;
	string username, password;
	bool j = false, k = false;
	while (j == false){
		cout << "\n\t=============== WELCOME TO RESTAURANT MANAGEMENT SYSTEM ==================\n\n";
		cout << "1.Start Program\n";
		cout << "2.End Program\n";
		cin >> dec;
		if (dec == '1'){
			while (k == false){
				cin.ignore();
				cout << "Enter Username   (type \"quit\" to end program) : ";
				getline(cin, username);
				cout << "Enter Password : ";
				cin >> password;

				if (username == "admin" && password == "admin123"){
					administrator();
				}
				else if (username == "table manager" && password == "tablemanager123"){
					tablemanager();
				}
				else if (username == "room manager" && password == "roommanager123"){
					roommanager();
				}
				else if (username == "parking manager" && password == "parkingmanager123"){
					parkingmanager();
				}
				else if (username == "quit"){
					k = true;
					j = true;
				}
				else {
					cout << "wrong username or password\n";
					cout << "try again\n";
				}
			}
		}
		else if (dec == '2'){
			j = true;0
		}
		else {
			cout << "invalid input\n";
			cout << "try again\n";
		}
	}
	write();
	read();
	system("pause");
}

void write(){
	myfile.open("data.txt");
	if (myfile.is_open()){
		for (int i = 0; i < 50; i++){
			myfile << rest.state[i] << endl;
		}
		for (int i = 0; i < 35; i++){
			myfile << rest.status[i] << endl;
		}
	}
	myfile.close();
}

void read(){
	string line;
	readfile.open("data.txt");
	while (getline(readfile, line)){
		cout << line << endl;
	}
	readfile.close();
}

void administrator(){
	char dec;
	bool j = false;
	while (j == false){
		cout << "\n   ***==============================================***\n\n";
		cout << "\tYou have successfully opened the Administrator branch\n";
		cout << "\t1.Start table management system \n";
		cout << "\t2.start rooms management system\n";
		cout << "\t3.start parking management system\n";
		cout << "\t4.Log Out\n";
		cout << "\n   ***==============================================***\n\n";
		cin >> dec;
		if (dec == '1'){
			tablemanager();
		}
		else if (dec == '2'){
			roommanager();
		}
		else if (dec == '3'){
			parkingmanager();
		}
		else if (dec == '4'){
			j = true;
		}
		else {
			cout << "invalid input\n";
			cout << "try again\n";
		}
	}
}

void tablemanager(){
	char start, rec, dish;
	unsigned int remove, entry = 0, space = 0, count = 0;
	unsigned int dish1 = 290, dish2 = 240, dish3 = 150, dish4 = 190, dish5 = 80;
	for (int i = 0; i < 35; i++){
		rest.status[i] = "vacant";
		rest.table[i] = 0;
	}
	bool j = false;
	while (j == false){
		bool k = false, m = false;
		cout << "\n   ***==============================================***\n\n";
		cout << "\tyou have successfully opened the table manager branch\n";
		cout << "\t1.Start table management system \n";
		cout << "\t2.Access records\n";
		cout << "\t3.Log out \n";
		cout << "\t4.More info\n";
		cout << "\t5.Pictorial Representation\n";
		cout << "\n   ***==============================================***\n\n";
		cin >> start;
		if (start == '1'){
			while (k == false){
				bool l = false;
				cout << "\nTo add an order enter the number of table (> 5 && < 35) : \n\n";
				cout << "2.Remove an order  \n\n";
				cout << "3.Return to main menu \n\n";
				cin >> entry;
				if (entry >= 5 && entry <= 35){
					rest.status[entry] = "occupied";
					count++;
					while (l == false){
						cout << "\nWhich dishes do you prefer (enter one at a time) :\n";
						cout << "1.Complete Breakfast  2.Zinger Burger  3.Chicken Biryani  4.Broast  5.Soft Drink\n";
						cout << "6.Return\n\n";
						cin >> dish;
						switch (dish){
						case '1':
							rest.table[entry] += dish1;
							break;
						case '2':
							rest.table[entry] += dish2;
							break;
						case '3':
							rest.table[entry] += dish3;
							break;
						case '4':
							rest.table[entry] += dish4;
							break;
						case '5':
							rest.table[entry] += dish5;
							break;
						case '6':
							l = true;
							break;
						default:
							cout << "invalid input\n";
						}
					}
					cout << "your total bill adds up to : " << rest.table[entry] << endl;
				}
				else if (entry == 3){
					k = true;
				}
				else if (entry == 2){
					count--;
					cout << "\nwhich table order you want to remove : \n\n";
					cin >> remove;
					rest.table[remove] = 0;
					rest.status[remove] = "vacant";
					cout << "Your order has successfully been removed \n";
				}
				else {
					cout << "invalid input\n";
				}
			}
		}
		else if (start == '2'){
			while (m == false){
				cout << "\n1.View records\n\n";
				cout << "2.Delete records\n\n";
				cout << "3.Return to main menu\n\n";
				cout << "4.More info\n\n";
				cin >> rec;
				switch (rec){
				case '1':
					space = 30 - count;
					cout << "\n\n\ttables record\n";
					cout << "the total tables vacant are : " << space << endl;
					cout << "the total tables occupied are : " << count << endl;
					break;
				case '2':
					for (int z = 0; z < 35; z++){
						rest.table[z] = 0;
						rest.status[z] = "vacant";
					}
					count = 0;
					cout << "the table records have been cleared \n";
					break;
				case '3':
					m = true;
					break;
				case '4':
					cout << "\nthe total tables available in the restaurant are 30\n";
					cout << "the total dishes avilable in the restaurant are 5\n";
					cout << "the tables have been numbered from 5 to 35\n";
					break;
				default:
					cout << "invalid input\n";
				}
			}
		}
		else if (start == '3'){
			j = true;
			return;
		}
		else if (start == '4'){
			cout << "the total tables available in the restaurant are 30\n";
			cout << "the total dishes avilable in the restaurant are 5\n";
			cout << "the tables have been numbered from 5 to 35\n";
		}
		else if (start == '5'){
			int s = 16;
			cout << setw(17) << "TABLE NO." << setw(18) << " STATUS " << setw(20) << "TOTAL BILL" << endl;
			for (int i = 0; i < 31; i++){
				if (i == 5){
					s = 15;
				}
				cout << setw(17) << "Table : " << i + 5 << setw(s) << rest.status[i + 4] << setw(16) << rest.table[i + 4] << endl;
			}
		}
		else {
			cout << "invalid input\n";
		}
	}
}

void roommanager(){
	char start, room, rec;
	unsigned int space = 0, vstate = 0, fstate = 10, nstate = 25;
	unsigned int count = 0, vip = 0, first = 0, normal = 0;
	bool j = false;
	for (int i = 0; i < 50; i++){
		rest.state[i] = "vacant";
	}
	while (j == false){
		bool k = false, l = false;
		cout << "\n   ***==============================================***\n\n";
		cout << "\tyou have successfully opened the room manager branch\n";
		cout << "\t1.Start room management system \n";
		cout << "\t2.Access records\n";
		cout << "\t3.Log out \n";
		cout << "\t4.More info\n";
		cout << "\t5.Pictorial Representation \n";
		cout << "\n   ***==============================================***\n\n";
		cin >> start;
		if (start == '1'){
			while (k == false){
				cout << "\n1.Book a VIP lounge :\n\n";
				cout << "2.Book a first class lounge room :\n\n";
				cout << "3.Book a normal room :\n\n";
				cout << "4.More options :\n\n";
				cin >> room;
				if (room == '1'){
					if (vip < 10){
						cout << "you have successfully booked VIP room " << vip + 1 << endl;
						rest.state[vstate] = "occupied";
						vip++;
						count++;
						vstate++;
					}
					else {
						cout << "maximum capacity reached\n";
						cout << "no more VIP rooms available\n";
					}
				}
				else if (room == '2'){
					if (first < 15){
						cout << "you have successfully booked first class room " << first + 1 << endl;
						rest.state[fstate] = "occupied";
						first++;
						count++;
						fstate++;
					}
					else {
						cout << "maximum capacity reached\n";
						cout << "no more first class rooms available\n";
					}
				}
				else if (room == '3'){
					if (normal < 25){
						cout << "you have successfully booked normal room " << normal + 1 << endl;
						rest.state[nstate] = "occupied";
						normal++;
						count++;
						nstate++;
					}
					else {
						cout << "maximum capacity reached\n";
						cout << "no more normal rooms available\n";
					}
				}
				else if (room == '4'){
					cout << "5.Cancel booking of VIP lounge :\n\n";
					cout << "6.Cancel booking of first class lounge :\n\n";
					cout << "7.Cancel booking of normal room :\n\n";
					cout << "8.View records :\n\n";
					cout << "9.Return To Main Menu :\n";
				}
				else if (room == '5'){
					cout << "you have successfully cancelled booking of a VIP room \n";
					vip--;
					count--;
					vstate--;
					rest.state[vstate] = "vacant";
				}
				else if (room == '6'){
					cout << "you have successfully cancelled booking of a first class room \n";
					first--;
					count--;
					fstate--;
					rest.state[fstate] = "vacant";
				}
				else if (room == '7'){
					cout << "you have successfully cancelled booking of a normal room \n";
					normal--;
					count--;
					nstate--;
					rest.state[nstate] = "vacant";
				}
				else if (room == '8'){
					space = 50 - count;
					cout << "\n\n\trooms record\n";
					cout << "the total rooms booked are : " << count << endl;
					cout << "the total rooms available for booking are : " << space << endl;
					cout << "total VIP rooms booked are : " << vip << endl;
					cout << "total first class rooms booked are : " << first << endl;
					cout << "total normal rooms booked are : " << normal << endl;
				}
				else if (room == '9'){
					k = true;
				}
				else {
					cout << "invalid input\n";
				}
			}
		}
		else if (start == '2'){
			while (l == false){
				cout << "\n1.View records\n\n";
				cout << "2.Delete records\n\n";
				cout << "3.Return to main menu\n\n";
				cout << "4.More info\n\n";
				cin >> rec;
				if (rec == '1'){
					cout << "\n\n\trooms record\n";
					cout << "the total rooms booked are : " << count << endl;
					cout << "total VIP rooms booked are : " << vip << endl;
					cout << "total first class rooms booked are : " << first << endl;
					cout << "total normal rooms booked are : " << normal << endl;
				}
				else if (rec == '2'){
					cout << "\nall records have been cleared\n";
					count = 0;
					vip = 0;
					first = 0;
					normal = 0;
					for (int i = 0; i < 50; i++){
						rest.state[i] = "vacant";
					}
				}
				else if (rec == '3'){
					l = true;
				}
				else if (rec == '4'){
					cout << "there are a total of 50 rooms in the restaurant\n";
					cout << "among them there are 10 VIP rooms\n";
					cout << "there are 15 first class rooms\n";
					cout << "there are 25 normal rooms\n";
				}
				else {
					cout << "invalid input\n";
				}
			}
		}
		else if (start == '3'){
			j = true;
		}
		else if (start == '4'){
			cout << "there are a total of 50 rooms in the restaurant\n";
			cout << "among them there are 10 VIP rooms\n";
			cout << "there are 15 first class rooms\n";
			cout << "there are 25 normal rooms\n";
		}
		else if (start == '5'){
			int x = 16;
			cout << setw(17) << "VIP ROOMS" << setw(16) << " STATUS ";
			cout << setw(20) << "FIRST CLASS ROOMS" << setw(17) << " STATUS ";
			cout << setw(20) << "NORMAL ROOMS" << setw(17) << " STATUS " << endl;
			for (int i = 0; i < 25; i++){
				{
					if (i == 9){
						x = 15;
					}
				}
				if (i < 10){
					cout << setw(15) << "Room : " << i + 1 << setw(x) << rest.state[i];
					cout << setw(15) << "Room : " << i + 11 << setw(20) << rest.state[(i + 10)];
					cout << setw(17) << "Room : " << i + 26 << setw(18) << rest.state[(i + 25)] << endl;
				}
				else if (i < 15){
					cout << setw(47) << "Room : " << i + 11 << setw(20) << rest.state[(i + 10)];
					cout << setw(17) << "Room : " << i + 26 << setw(18) << rest.state[(i + 25)] << endl;
				}
				else {
					cout << setw(86) << "Room : " << i + 26 << setw(18) << rest.state[(i + 25)] << endl;
				}
			}
		}
		else {
			cout << "invalid input\n";
		}

	}

}


void parkingmanager(){
	char start, vehicle, rec;
	unsigned int count = 0, space = 0;
	unsigned int carlane = 0, carlane1 = 0;
	unsigned int bikelane = 0, bikelane1 = 0;
	unsigned int buslane = 0, buslane1 = 0;
	bool k = false;
	while (k == false){
		bool j = false, l = false;
		cout << "\n   ***==============================================***\n\n";
		cout << "\tyou have successfully opened the parking manager branch\n";
		cout << "\t1.Start parking management system \n";
		cout << "\t2.Access parking records\n";
		cout << "\t3.Log out \n";
		cout << "\t4.More info\n";
		cout << "\n   ***==============================================***\n\n";
		cin >> start;
		if (start == '1'){
			while (j == false){
				cout << "\n1.Add car in inventory : \n\n";
				cout << "2.Add bus in inventory : \n\n";
				cout << "3.Add bike in inventory : \n\n";
				cout << "9.More options : \n\n";
				cin >> vehicle;
				if (vehicle == '1'){
					if (carlane < 51){
						cout << "a car has parked in carlane C" << carlane1 + 1 << endl;
						count++;
						carlane++;
						if (carlane == 10 || carlane == 20 || carlane == 30 || carlane == 40){
							carlane1 = carlane1 + 1;
						}
					}
					else {
						cout << "you have run out of maximum space\n";
						cout << "no more cars can be parked in the carlane\n";
					}
				}
				else if (vehicle == '2'){
					if (buslane < 21){
						cout << "a bus has parked in buslane B" << buslane1 + 1 << endl;
						count++;
						buslane++;
						if (buslane == 10){
							buslane1 = buslane1 + 1;
						}
					}
					else {
						cout << "you have run out of maximum space\n";
						cout << "no more buses can be parked in the buslane\n";
					}
				}
				else if (vehicle == '3'){
					if (bikelane < 31){
						cout << "a motor bike has parked in bikelane M" << bikelane1 + 1 << endl;
						count++;
						bikelane++;
						if (bikelane == 10 || bikelane == 20){
							bikelane1 = bikelane1 + 1;
						}
					}
					else {
						cout << "you have run out of maximum space\n";
						cout << "no more motor bikes can be parked in the bikelane\n";
					}
				}
				else if (vehicle == '4'){
					cout << "a car has successfully left from the parking area \n";
					count--;
					carlane--;
				}
				else if (vehicle == '5'){
					cout << "a bus has successfully left from the parking area \n";
					count--;
					buslane--;
				}
				else if (vehicle == '6'){
					cout << "a motor bike has successfully left from the parking area \n";
					count--;
					bikelane--;
				}
				else if (vehicle == '7'){
					space = 100 - count;
					cout << "\n\n\tvehicle record\n";
					cout << "the total vehicles parked are : " << count << endl;
					cout << "the total space available in parking area is : " << space << endl;
					cout << "the total cars parked are : " << carlane << endl;
					cout << "the total buses parked are : " << buslane << endl;
					cout << "the total motor bikes parked are : " << bikelane << endl;
				}
				else if (vehicle == '8'){
					j = true;
				}
				else if (vehicle == '9'){
					cout << "4.Remove a car from inventory : \n\n";
					cout << "5.Remove a bus from inventory : \n\n";
					cout << "6.Remove a bike from inventory : \n\n";
					cout << "7.View records in inventory : \n\n";
					cout << "8.Log out of parking management system : \n";
				}
				else {
					cout << "invalid input\n";
				}
			}
		}
		else if (start == '2'){
			while (l == false){
				cout << "1.View records\n";
				cout << "2.Delete records\n";
				cout << "3.Return to main menu\n";
				cout << "4.More info\n";
				cin >> rec;
				if (rec == '1'){
					cout << "\n\n\tvehicle record\n";
					cout << "\nthe total vehicles parked are : " << count << endl;
					cout << "\nthe total cars parked are : " << carlane << endl;
					cout << "\nthe total buses parked are : " << buslane << endl;
					cout << "\nthe total motor bikes parked are : " << bikelane << endl << endl;
				}
				else if (rec == '2'){
					cout << "\nall records have been cleared\n";
					count = 0;
					carlane = 0;
					carlane1 = 0;
					bikelane = 0;
					bikelane1 = 0;
					buslane = 0;
					buslane1 = 0;
				}
				else if (rec == '3'){
					l = true;
				}
				else if (rec == '4'){
					cout << "\nthe total space available in parking area is 100 vehicles\n";
					cout << "the total space available for cars is 50 cars with 10 cars per lane\n";
					cout << "the total space available for motor bikes is 30 bikes with 10 bikes per lane\n";
					cout << "the total space available for buses is 20 buses with 10 buses per lane\n";
				}
				else {
					cout << "invalid input\n";
				}
			}
		}
		else if (start == '3'){
			k = true;
		}
		else if (start == '4'){
			cout << "\nthe total space available in parking area is 100 vehicles\n";
			cout << "the total space available for cars is 50 cars with 10 cars per lane\n";
			cout << "the total space available for motor bikes is 30 bikes with 10 bikes per lane\n";
			cout << "the total space available for buses is 20 buses with 10 buses per lane\n";
		}
		else {
			cout << "invalid input\n";
		}
	}

}
