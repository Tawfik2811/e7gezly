#include<iostream>
#include<string>
#include <fstream>
#include<cmath>
using namespace std;
string doctorusername[100];
string doctorpassword[100];
int counter = 0;
int counter_time = 0;
int counter_size = 0;
string patientusername[100];
string patientpassword[100];
int counter2 = 0;
void RegistrationasDoctor()
{

	cout << "Select Username : ";
	getline(std::cin >> std::ws, doctorusername[counter]);
	cout << "Select Password : ";
	std::getline(std::cin >> std::ws, doctorpassword[counter]);
	ofstream file;
	file.open("registration doctor.txt", std::ios::app);
	file << doctorusername[counter] << endl << doctorpassword[counter] << endl;
	file.close();
	counter++;

}
void RegistrationasPatient()
{
	cout << "Select Username : ";
	getline(std::cin >> std::ws, patientusername[counter2]);
	cout << "Select Password : ";
	getline(std::cin >> std::ws, patientpassword[counter2]);
	ofstream file;
	file.open("registration patient.txt", std::ios::app);
	file << patientusername[counter2] << endl << patientpassword[counter2] << endl;
	file.close();
	counter2++;
}
bool LogInDoctor()
{
	string username;
	string passaword;
	string us;
	string pas;
	cout << "Enter Username : ";
	cin >> username;
	cout << "Enter Password : ";
	cin >> passaword;
	for (int i = 0; i < counter; i++) {
		if (doctorusername[i] == username && doctorpassword[i] == passaword)
		{
			ofstream time;
			time.open("time.txt", std::ios::app);
			time << "Doctor : " << username << endl;
			time.close();
			return true;
		}
	}
	return false;
}
bool LogInPatient()
{
	string username;
	string passaword;
	string us;
	string pas;
	cout << "Enter Username : ";
	cin >> username;
	cout << "Enter Password : ";
	cin >> passaword;
	for (int i = 0; i < counter2; i++) {
		if (patientusername[i] == username && patientpassword[i] == passaword) {
			return true;
		}
	}
	return false;
}
void Edit_Info_Doctor()
{
	string us;
	string pas;
	int p = 0;
	int flag1 = 0;
start1:
	cout << "Enter Current Username : ";
	cin >> us;
	cout << "Enter Current Password : ";
	cin >> pas;
	for (int i = 0; i < counter; i++)
	{
		if (doctorusername[i] == us && doctorpassword[i] == pas)
		{
			flag1 = 1;
			p = i;
		}
	}
	if (flag1 == 1)
	{
		cout << "Select Username : ";
		cin >> doctorusername[p];
		cout << "Select Password : ";
		cin >> doctorpassword[p];
	}
	else
	{
		cout << "\t\tWrong Usename Or Password ! \n";
		cout << "\t\tPlease Try Agian \n";
		goto start1;
	}
}
void Edit_Info_Patient()
{
	string us;
	string pas;
	int p = 0;
	int flag1 = 0;
start1:
	cout << "Enter Current Username : ";
	cin >> us;
	cout << "Enter Current Password : ";
	cin >> pas;
	for (int i = 0; i < counter2; i++)
	{
		if (patientusername[i] == us && patientpassword[i] == pas)
		{
			flag1 = 1;
			p = i;
		}
	}
	if (flag1 == 1)
	{
		cout << "Select Username : ";
		cin >> patientusername[p];
		cout << "Select Password : ";
		cin >> patientpassword[p];
	}
	else
	{
		cout << "\t\tWrong Usename Or Password ! \n";
		cout << "\t\tPlease Try Agian \n";
		goto start1;
	}
}
struct doctor_time {
	int size[100] = { 0 };
	string Time1[100];
	string day[100];
	string edit1;
	string edit2;
	string new1;
	string new2;

};
doctor_time time1;
void Add_Available_Time() {

	cout << "How Many Appointments Do You Want To Enter " << endl;
	cin >> time1.size[counter_size];
	for (int i = 0; i < time1.size[counter_size]; i++)
	{
		cout << "PLease Enter Appoiment " << "#" << i + 1 << endl;
		cout << "Enter the day: ";
		cin >> time1.day[counter_time];
		cout << "Time : ";
		cin >> time1.Time1[counter_time];
		ofstream time;
		time.open("time.txt", std::ios::app);
		time << time1.day[counter_time] << endl  << time1.Time1[counter_time] << endl;
		counter_time++;
		time.close();
	}
	counter_size++;
}
void Display_Doctors_Available_In_Certain_Appointment_Time()
{
	fstream display;
	display.open("time.txt", ios::in);
	if (display.is_open()) {
		string tp;
		while (getline(display, tp)) {
			cout << tp << "\n";
		}
		display.close();
	}
}
int main()
{
	int choise1 = 0, choise2 = 0, choise3 = 0, choise4 = 0, flag1 = 0, flag2 = 0;
start:
	cout << "\t\t\tWelcome To E7gezly \n\n";
	cout << "********************************************************************************" << endl;
	cout << "Press 1 For Docotrs \n";
	cout << "Press 2 For Patients \n";
	cout << "Enter Your Choise : ";
	cin >> choise1;
	if (choise1 == 1)
	{
	start2:
		cout << endl;
		cout << "1- Registration \n";
		cout << "2- Login \n";
		cout << "Enter Your Choise : ";
		cin >> choise2;
		if (choise2 == 1)
		{
			RegistrationasDoctor();
			goto start2;
		}
		else if (choise2 == 2)
		{
			bool status = LogInDoctor();
			if (!status)
			{
				cout << "\t\tWrong Usename Or Password ! \n";
				cout << "\t\tPlease Try Agian \n";
				goto start2;
			}
			else
			{
				cout << endl;
				cout << "\t\t\tSuccessfully Loggedin\n\n";
				flag1 = 1;

			}
		}
		if (flag1 == 1)
		{
			do
			{
				cout << endl;
				cout << "1- Add Available Time\n";
				cout << "2- Remove Available Time\n";
				cout << "3- Edit Available Time\n";
				cout << "4- View Patients With Appoiments\n";
				cout << "5- Edit Info (username,password) \n";
				cout << "6- Logout \n";
				cout << "7- To Close The Program \n";
				cout << "Enter Your Choise : ";
				cin >> choise3;
				switch (choise3) {
				case 1:
					Add_Available_Time();
					break;

				
				case 5:
					Edit_Info_Doctor();
					break;
				case 6:
					goto start;
					break;
			
				}

			} while (choise3 != 7);
		}
	}
	else if (choise1 == 2)
	{
	start3:
		cout << endl;
		cout << "1- Registration \n";
		cout << "2- Login \n";
		cout << "Enter Your Choise : ";
		cin >> choise2;
		if (choise2 == 1)
		{
			RegistrationasPatient();
			goto start3;
		}
		else if (choise2 == 2)
		{
			bool status = LogInPatient();
			if (!status)
			{
				cout << "\t\tWrong Usename Or Password ! \n";
				cout << "\t\tPlease Try Agian \n";
				goto start3;
			}
			else
			{
				cout << "\t\tSuccessfully Loggedin\n\n";
				flag2 = 1;
			}
		}
		if (flag2 == 1)
		{
			do
			{
				cout << "1- Find Doctors \n";
				cout << "2- Display Doctors Available In Certain Appointment Time \n";
				cout << "3- View Appointments\n";
				cout << "4- Edit Appointments\n";
				cout << "5- Delete Appointments\n";
				cout << "6- Clear Appointments history\n";
				cout << "7- Edit Basic Info ( username/password)\n";
				cout << "8- Logout \n";
				cout << "9- To Close The Program \n";
				cout << "Enter Your Choise : ";
				cin >> choise4;
				switch (choise4)
				{
	
				case 2:
					Display_Doctors_Available_In_Certain_Appointment_Time();
					break;
				case 7:
					Edit_Info_Patient();
					break;
				case 8:
					goto start;
				}

			} while (choise4 != 9);
		}
	}
	else
	{
		cout << "Please Enter Right Number \n";
		goto start;
	}
	return 0;
}
