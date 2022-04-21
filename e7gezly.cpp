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
void Registrationas(string user[], string pas[], int& count)
{

	cout << "Select Username : ";
	cin >> user[count];
	cout << "Select Password : ";
	cin >> pas[count];
	count++;
}
bool LogIn(string user[], string pas[], int& count)
{
	int search = 0;
	string username;
	string password;
	cout << "Enter Username : ";
	cin >> username;
	cout << "Enter Password : ";
	cin >> password;
	for (int i = 0; i < count; i++) {
		if (user[i] == username && pas[i] == password)
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
void Edit_Info(string user[], string pas[], int& count)
{
	string username;
	string password;
	int p = 0;
	int flag1 = 0;
start1:
	cout << "Enter Current Username : ";
	cin >> username;
	cout << "Enter Current Password : ";
	cin >> password;
	for (int i = 0; i < counter; i++)
	{
		if (user[i] == username && pas[i] == password)
		{
			flag1 = 1;
			p = i;
		}
	}
	if (flag1 == 1)
	{
		cout << "Select Username : ";
		cin >> user[p];
		cout << "Select Password : ";
		cin >> pas[p];
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
		
		counter_time++;
	}
	counter_size++;
}
void Edit_Appoiment()
{
	int k = 0, flag1 = 0, flag2 = 0, l = 0;
	cout << "Please Enter The Appointment You Want TO Modify" << endl;
	cout << "Day : ";
	cin >> time1.edit1;
	cout << "Time : ";
	cin >> time1.edit2;
	for (int i = 0; i < counter_time; i++)
	{
		if (time1.Time1[i] == time1.edit2)
		{
			k = i;
			flag1 = 1;
		}

	}
	for (int i = 0; i < counter_time; i++)
	{
		if (time1.day[i] == time1.edit1)
		{
			l = i;
			flag2 = 1;
		}

	}
	if (flag1 == 1 && flag2 == 1 )
	{
		cout << "Enter The New Appoiment \n";
		cout << "Day :";
		cin >> time1.new1;
		cout << "Time : ";
		cin >> time1.new2;
		time1.Time1[k] = time1.new1;
		time1.day[l] = time1.new2;
	}
	else
		cout << "\nThis Appoiment Doesn't Found !";
	cout << endl;
}
bool Find_Doctor()
{
	string doctorname; int search = 0;
	cout << "Please Enter Doctor Name \n";
	cin >> doctorname;
	for (int i = 0; i < counter; i++)
	{
		if (doctorusername[i] == doctorname)
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
void Display_Doctors_Available_In_Certain_Appointment_Time()
{
	int j = 0; int k = 0, m = 0;
	for (int i = 0; i < counter; i++)
	{

		cout << "Doctor : " << doctorusername[i] << endl;
		while (k < time1.size[j])
		{
			cout << "Day : " << time1.day[m] << endl;
			cout << "Time : " << time1.Time1[m] << endl;
			k++;
			m++;
		}
		j++;
		k = 0;
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
			Registrationas(doctorusername, doctorpassword, counter);
			goto start2;
		}
		else if (choise2 == 2)
		{
			bool status = LogIn(doctorusername, doctorpassword, counter);
			if (!status)
			{
				cout << "\t\tWrong Usename Or Password ! \n";
				cout << "\t\tPlease Try Agian \n";
				goto start2;
			}
			else
			{
				cout << endl;
				cout << "\t\tSuccessfully Loggedin\n\n";
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
				cin >> choise3;
				switch (choise3) {
				case 1:
					Add_Available_Time();
					break;

				case 3:
					Edit_Appoiment();
					break;
				case 5:
					Edit_Info(doctorusername, doctorpassword, counter);
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
			Registrationas(patientusername, patientpassword, counter2);
			goto start3;
		}
		else if (choise2 == 2)
		{
			bool status = LogIn(patientusername, patientpassword, counter2);
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
				cin >> choise4;
				switch (choise4)
				{
				case 1:
				{
					bool find = Find_Doctor();
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
					Display_Doctors_Available_In_Certain_Appointment_Time();
					break;
				case 7:
					Edit_Info(patientusername, patientpassword, counter2);
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
