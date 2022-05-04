#include<iostream>
#include<string>
#include <fstream>
#include<cmath>
#include<stdio.h>
#include <cstring>
using namespace std;
string  username;
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
	cin >> doctorusername[counter];
	cout << "Select Password : ";
	cin >> doctorpassword[counter];
	ofstream file;
	file.open("registration doctor name.txt", std::ios::app);
	file << doctorusername[counter] << endl;
	file.close();
	ofstream pas;
	pas.open("registration doctor pass.txt", std::ios::app);
	pas << doctorpassword[counter] << endl;
	pas.close();
	counter++;
}
void RegistrationasPatient()
{

	cout << "Select Username : ";
	cin >> patientusername[counter2];
	cout << "Select Password : ";
	cin >> patientpassword[counter2];
	ofstream file;
	file.open("registration patient name.txt", std::ios::app);
	file << patientusername[counter2] << endl;
	file.close();
	ofstream pas;
	pas.open("registration patient pass.txt", std::ios::app);
	pas << patientpassword[counter] << endl;
	pas.close();
	counter2++;
}
bool LogInDoctor()
{
	string passaword;
	string us;
	string pas;
	cout << "Enter Username : ";
	cin >> username;
	cout << "Enter Password : ";
	cin >> passaword;
	int number_of_lines1 = 0;
	std::string line1;
	std::ifstream myfile1("registration doctor name.txt");
	while (std::getline(myfile1, line1))
		++number_of_lines1;
	int count1 = 0;
	ifstream edit1;
	edit1.open("registration doctor name.txt");
	while (count1<number_of_lines1 && edit1 >> doctorusername[count1])
	{
		count1++;
	}
	edit1.close();
	int number_of_lines2 = 0;
	std::string line2;
	std::ifstream myfile2("registration doctor pass.txt");
	while (std::getline(myfile2, line2))
		++number_of_lines2;
	int count2 = 0;
	ifstream edit2;
	edit2.open("registration doctor pass.txt");
	while (count2<number_of_lines2 && edit2 >> doctorpassword[count2])
	{
		count2++;
	}
	edit2.close();
	for (int i = 0; i < number_of_lines2; i++) {
		if (doctorusername[i] == username && doctorpassword[i] == passaword)
		{

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
	int number_of_lines = 0;
	std::string line;
	std::ifstream myfile("registration patient name.txt");
	while (std::getline(myfile, line))
		++number_of_lines;
	int count = 0;
	ifstream edit1;
	edit1.open("registration patient name.txt");
	while (count<number_of_lines && edit1 >> patientusername[count])
	{
		count++;
	}
	edit1.close();
	int number_of_lines2 = 0;
	std::string line2;
	std::ifstream myfile2("registration patient pass.txt");
	while (std::getline(myfile2, line2))
		++number_of_lines2;
	int count2 = 0;
	ifstream edit2;
	edit2.open("registration patient pass.txt");
	while (count2<number_of_lines2 && edit2 >> patientpassword[count2])
	{
		count2++;
	}
	edit2.close();
	for (int i = 0; i < number_of_lines2; i++) {
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
	string newpas;
	string newname;
	int k = 0, j = 0;
	int flag = 0, flag2 = 0;
start:
	cout << "Enter Current Username : ";
	cin >> us;
	cout << "Enter Current Password : ";
	cin >> pas;
	int number_of_lines1 = 0;
	std::string line1;
	std::ifstream myfile1("registration doctor name.txt");
	while (std::getline(myfile1, line1))
		++number_of_lines1;
	int count1 = 0;
	ifstream edit1;
	edit1.open("registration doctor name.txt");
	while (count1<number_of_lines1 && edit1 >> doctorusername[count1])
	{
		count1++;
	}
	edit1.close();
	int number_of_lines2 = 0;
	string edit[100];
	std::string line2;
	std::ifstream myfile2("time.txt");
	while (std::getline(myfile2, line2))
		++number_of_lines2;
	int count2 = 0;
	ifstream edit2;
	edit2.open("time.txt");
	while (count2<number_of_lines2 && edit2 >> edit[count2])
	{
		count2++;
	}
	edit2.close();
	int number_of_lines3 = 0;
	std::string line3;
	std::ifstream myfile3("registration doctor pass.txt");
	while (std::getline(myfile3, line3))
		++number_of_lines3;
	int count3 = 0;
	ifstream edit3;
	edit3.open("registration doctor pass.txt");
	while (count3<number_of_lines3 && edit3 >> doctorpassword[count3])
	{
		count3++;
	}
	edit3.close();
	for (int i = 0; i < number_of_lines1; i++)
	{
		if (doctorusername[i] == us && doctorpassword[i] == pas)
		{
			k = i;
			flag = 1;
		}
	}
	for (int i = 0; i < number_of_lines2; i++)
	{
		if (edit[i] == us)
		{
			j = i;
			flag2 = 1;
		}
	}
	if (flag == 1)
	{
		cout << "Enter New Username : ";
		cin >> newname;
		cout << "Enter New Password : ";
		cin >> newpas;
		doctorusername[k] = newname;
		doctorpassword[k] = newpas;
		edit[j] = newname;
		edit1.open("registration doctor name.txt", ios::in);
		if (edit1.is_open())
		{
			string tp1;
			while (getline(edit1, tp1))
			{
				std::ofstream edit1;
				edit1.open("registration doctor name.txt", std::ofstream::out | std::ofstream::trunc);
				edit1.close();
			}
		}
		edit2.open("time.txt", ios::in);
		if (edit2.is_open())
		{
			string tp2;
			while (getline(edit2, tp2))
			{
				std::ofstream edit2;
				edit2.open("time.txt", std::ofstream::out | std::ofstream::trunc);
				edit2.close();
			}
		}
		edit3.open("registration doctor pass.txt", ios::in);
		if (edit3.is_open())
		{
			string tp3;
			while (getline(edit3, tp3))
			{
				std::ofstream edit3;
				edit3.open("registration doctor pass.txt", std::ofstream::out | std::ofstream::trunc);
				edit3.close();
			}
		}
		for (int i = 0; i < number_of_lines1; i++)
		{
			ofstream edit1;
			edit1.open("registration doctor name.txt", std::ios::app);
			edit1 << doctorusername[i] << endl;
			edit1.close();
		}
		for (int i = 0; i < number_of_lines3; i++)
		{
			ofstream edit3;
			edit3.open("registration doctor pass.txt", std::ios::app);
			edit3 << doctorpassword[i] << endl;
			edit3.close();
		}
		for (int i = 0; i < number_of_lines2; i++)
		{
			ofstream edit2;
			edit2.open("time.txt", std::ios::app);
			edit2 << edit[i] << endl;
			edit2.close();
		}
		cout << "Info Edited Sucssefuly\n";
	}
	else
	{
		cout << "Wrong Username Or Password\n";
		cout << "Please Try Again\n";
		cout << endl;
		goto start;
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
	ofstream time;
	time.open("time.txt", std::ios::app);
	time  << username << endl;
	time.close();
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
		time  << time1.day[counter_time] << endl << time1.Time1[counter_time] << endl;
		counter_time++;
		time.close();
	}
	counter_size++;
}
void Edit_Available_Time()
{
	int number_of_lines = 0;
	std::string line;
	std::ifstream myfile("time.txt");
	while (std::getline(myfile, line))
		++number_of_lines;
	string time[100];
	int count = 0;
	ifstream edit1;
	edit1.open("time.txt");
	while (count<number_of_lines && edit1 >> time[count])
	{
		count++;
	}
	edit1.close();
	int k = 0, m = 0, flag1 = 0, flag2 = 0, flag3 = 0, l = 0;
	cout << "Please Enter The Appoiment You Want TO Modify" << endl;
	cout << "Day : ";
	cin >> time1.edit1;
	cout << "Time : ";
	cin >> time1.edit2;
	for (int i = 0; i < number_of_lines; i++)
	{
		if (time[i] == time1.edit1 && time[i + 1] == time1.edit2)
		{
			k = i;
			flag1 = 1;
		}
	}
	if (flag1 == 1)
	{
		cout << "Enter The New Appoiment \n";
		cout << "Day :";
		cin >> time1.new1;
		cout << "Enter The New Time \n";
		cin >> time1.new2;
		time[k] = time1.new1;
		time[k + 1] = time1.new2;
		edit1.open("time.txt", ios::in);
		if (edit1.is_open())
		{
			string tp;
			while (getline(edit1, tp))
			{
				std::ofstream edit1;
				edit1.open("time.txt", std::ofstream::out | std::ofstream::trunc);
				edit1.close();
			}
		}

		for (int i = 0; i < number_of_lines; i++)
		{
			ofstream edit1;
			edit1.open("time.txt", std::ios::app);
			edit1 << time[i] << endl;
			edit1.close();
		}
	}
	else
	{
		cout << "\nThis Appoiment Doesn't Found !";
		cout << endl;
	}

}
bool Find_Doctors()
{
	int number_of_lines = 0;
	std::string line;
	std::ifstream myfile("DoctorNames.txt");
	while (std::getline(myfile, line))
	{
		++number_of_lines;
	}
	string names[100];
	int count = 0;
	ifstream find1;
	find1.open("DoctorNames.txt");
	while (count<number_of_lines && find1 >> names[count])
	{
		count++;
	}
	find1.close();
	string doctorname; int search = 0;
	cout << "Please Enter Doctor Name \n";
	cin >> doctorname;
	for (int i = 0; i < number_of_lines; i++)
	{
		if (names[i] == doctorname)
		{
			search = 1;
		}
	}
	if (search == 1)
	{
		return true;
	}
	else
		return false;
}
void Display_Doctors()
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
			if (status)
			{
				cout << endl;
				flag1 = 1;
			}
			else
			{
				goto start2;
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
				cin >> choise3;
				switch (choise3) {
				case 1:
					Add_Available_Time();
					break;

				case 3:
					Edit_Available_Time();
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
			choise2 = 2;
			RegistrationasPatient();
			goto start3;
		}
		else if (choise2 == 2)
		{
			choise2 = 1;
			bool status = LogInPatient();
			if (status)
			{
				cout << endl;
				flag2 = 1;
			}
			else
			{
				goto start2;
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
				cin >> choise4;
				switch (choise4)
				{
				case 1:
				{
					bool find = Find_Doctors();
					if (!find)
					{
						cout << "Sorry, This Doctor Is Not Available\n";
						cout << endl;
					}
					else
					{
						cout << "This Doctor Is Available\n";
						cout << endl;
					}
					break;
				}
				case 2:
					cout << endl;
					Display_Doctors();
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
