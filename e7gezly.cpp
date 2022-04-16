#include<iostream>
#include<string>
#include <fstream>
#include<cmath>
using namespace std;
string doctorusername[100];
string doctorpassword[100];
int counter = 0;
void Registrationasdoctor()
{

	cout << "Select Username : ";
	cin >> doctorusername[counter];
	cout << "Select Password : ";
	cin >> doctorpassword[counter];
	ofstream file;
	file.open("registration doctor.txt", std::ios::app);
	file << doctorusername[counter] << endl << doctorpassword[counter] << endl;
	file.close();
	counter++;
}
bool LogIn()
{
	string us;
	string pas;
	int flag1 = 0;
	cout << "Enter Username : ";
	cin >> us;
	cout << "Enter Password : ";
	cin >> pas;
	for (int i = 0; i < counter; i++)
	{
		if (doctorusername[i] == us && doctorpassword[i] == pas)
		{
			flag1 = 1;
		}
	}
	if (flag1 == 1)
	{
		return true;
	}
	else
		return false;
}
struct doctor_time {
	int size;
	int Time1[100];
	int Time2[100];
	int deleted1;
	int deleted2;
	int edit1;
	int edit2;
	int new1;
	int new2;

};
doctor_time time1;
void Add_Available_Time() {

	cout << "How Many Appointments Do You Want To Enter " << endl;
	cin >> time1.size;
	for (int i = 0; i < time1.size; i++)
	{
		cout << "PLease Enter Appoiment " << "#" << i + 1 << endl;
		cout << "From : ";
		cin >> time1.Time1[i];
		cout << "To : ";
		cin >> time1.Time2[i];
	}
}
void Delete_Appoiments()
{
	int found1 = 0, found2 = 0;
	cout << "PLease Enter Appoiment You Want To Delete" << endl;
	cout << "From : ";
	cin >> time1.deleted1;
	cout << "To : ";
	cin >> time1.deleted2;
	for (int i = 0; i < time1.size; i++)
	{
		if (time1.Time1[i] == time1.deleted1)
		{
			for (int j = i; j < (time1.size - 1); j++)
				time1.Time1[j] = time1.Time1[j + 1];
			found1++;
			i--;
			time1.size--;
		}
	}
	for (int i = 0; i < time1.size; i++)
	{
		if (time1.Time2[i] == time1.deleted2)
		{
			for (int j = i; j < (time1.size - 1); j++)
				time1.Time2[j] = time1.Time2[j + 1];
			found2++;
			i--;
			time1.size--;
		}
	}
	if (found1 == 0 && found2 == 0)
		cout << "\nThis Appoiment Doesn't Found !";
	else
		cout << "\nAppoiment Deleted Successfully!";
	cout << endl;
}
void Edit_Appoiment()
{
	int k = 0, m = 0, flag1 = 0, flag2 = 0;
	cout << "Please Enter The Appoiment You Want TO Modify" << endl;
	cout << "From : ";
	cin >> time1.edit1;
	cout << "To : ";
	cin >> time1.edit2;
	for (int i = 0; i < time1.size; i++)
	{
		if (time1.Time1[i] == time1.edit1)
		{
			k = i;
			flag1 = 1;
		}

	}
	for (int i = 0; i < time1.size; i++)
	{
		if (time1.Time2[i] == time1.edit2)
		{
			m = i;
			flag2 = 1;
		}

	}
	if (flag1 == 1 && flag2 == 1)
	{
		cout << "Enter The New Appoiment \n";
		cout << "From : ";
		cin >> time1.new1;
		cout << "To : ";
		cin >> time1.new2;
		time1.Time1[k] = time1.new1;
		time1.Time2[m] = time1.new2;
	}
	else
		cout << "\nThis Appoiment Doesn't Found !";
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
int main()
{
	int choise1, flag = 0, choise2 = 0, choise3 = 0, choise4 = 0;
	cout << "\t\tWelcome To E7gezly \n\n";
	cout << "*********************" << endl;
start:
	cout << "1- Registration \n";
	cout << "2- Login \n";

	cout << "Enter Your Choise : ";
	cin >> choise1;
	if (choise1 == 1)
	{
		Registrationasdoctor();
		goto start;
	}
	else if (choise1 == 2)
	{
		bool status = LogIn();
		if (!status)
		{
			cout << "\t\tWrong Usename Or Password ! \n";
			cout << "\t\tPlease Try Agian \n";
			goto start;
		}
		else
		{
			cout << "\t\tSuccessfully Loggedin\n\n";
			flag = 1;

		}
	}

	if (flag == 1)
	{
		cout << "Press 1 For Docotrs \n";
		cout << "Press 2 For Patients \n";
		cin >> choise2;
	}
	if (choise2 == 1)
	{
		do
		{
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
			case 2:
				Delete_Appoiments();
				break;
			case 3:
				Edit_Appoiment();
				break;
			case 6:
				goto start;
				break;
			}

		} while (choise3 != 7);
	}
	else if (choise2 == 2)
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
				bool find = Find_Doctor();
				if (!find)
				{
					cout << "Sorry, This Doctor Is Not Available\n";
				}
				else
				{
					cout << "This Doctor Is Available\n";
				}
				break;
			case 8:
				goto start;
				break;
			}

		} while (choise4 != 9);
	}
	return 0;
}

