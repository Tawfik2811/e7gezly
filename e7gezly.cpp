#include<iostream>
#include<string>
#include <fstream>
#include<cmath>
#include<stdio.h>
#include <cstring>
using namespace std;
int counter=0, counter2=0;
string  username;
string usernamepatient;
string doctorusername[100];
string doctorpassword[100];
string patientusername[100];
string patientpassword[100];
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
	pas << patientpassword[counter2] << endl;
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
	string line1;
	ifstream myfile1("registration doctor name.txt");
	while (getline(myfile1, line1))
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
	string line2;
	ifstream myfile2("registration doctor pass.txt");
	while (getline(myfile2, line2))
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

	string passaword;
	string us;
	string pas;
	cout << "Enter Username : ";
	cin >> usernamepatient;
	cout << "Enter Password : ";
	cin >> passaword;
	int number_of_lines = 0;
	string line;
	ifstream myfile("registration patient name.txt");
	while (getline(myfile, line))
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
	string line2;
	ifstream myfile2("registration patient pass.txt");
	while (getline(myfile2, line2))
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
		if (patientusername[i] == usernamepatient && patientpassword[i] == passaword) {
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
	string line1;
	ifstream myfile1("registration doctor name.txt");
	while (getline(myfile1, line1))
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
	string timeselected[100];
	string line2;
	ifstream myfile2("time selected.txt");
	while (getline(myfile2, line2))
		++number_of_lines2;
	int count2 = 0;
	ifstream edit2;
	edit2.open("time selected.txt");
	while (count2<number_of_lines2 && edit2 >> timeselected[count2])
	{
		count2++;
	}
	edit2.close();
	int number_of_lines3 = 0;
	string line3;
	ifstream myfile3("registration doctor pass.txt");
	while (getline(myfile3, line3))
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
	if (flag == 1)
	{
		cout << "Enter New Username : ";
		cin >> newname;
		cout << "Enter New Password : ";
		cin >> newpas;
		doctorusername[k] = newname;
		doctorpassword[k] = newpas;
		for (int i = 0; i < number_of_lines2; i++)
		{
			if (timeselected[i] == us)
			{
				timeselected[i] = newname;
			}
		}
		edit1.open("registration doctor name.txt", ios::in);
		if (edit1.is_open())
		{
			string tp1;
			while (getline(edit1, tp1))
			{
				ofstream edit1;
				edit1.open("registration doctor name.txt", std::ofstream::out | std::ofstream::trunc);
				edit1.close();
			}
		}
		edit2.open("time selected.txt", ios::in);
		if (edit2.is_open())
		{
			string tp2;
			while (getline(edit2, tp2))
			{
				ofstream edit2;
				edit2.open("time selected.txt", std::ofstream::out | std::ofstream::trunc);
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
		for (int i = 0; i < number_of_lines2; i++)
		{
			ofstream edit2;
			edit2.open("time selected.txt", std::ios::app);
			edit2 << timeselected[i] << endl;
			edit2.close();
		}
		for (int i = 0; i < number_of_lines3; i++)
		{
			ofstream edit3;
			edit3.open("registration doctor pass.txt", std::ios::app);
			edit3 << doctorpassword[i] << endl;
			edit3.close();
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
	string line1;
	ifstream myfile1("registration patient name.txt");
	while (getline(myfile1, line1))
	{
		++number_of_lines1;
	}
	int count1 = 0;
	ifstream edit1;
	edit1.open("registration patient name.txt");
	while (count1<number_of_lines1 && edit1 >> patientusername[count1])
	{
		count1++;
	}
	edit1.close();
	int number_of_lines2 = 0;
	string timeselected[100];
	string line2;
	ifstream myfile2("time selected.txt");
	while (getline(myfile2, line2))
	{
		++number_of_lines2;
	}
	int count2 = 0;
	ifstream edit2;
	edit2.open("time selected.txt");
	while (count2<number_of_lines2 && edit2 >> timeselected[count2])
	{
		count2++;
	}
	edit2.close();
	int number_of_lines3 = 0;
	string line3;
	ifstream myfile3("registration patient pass.txt");
	while (getline(myfile3, line3))
	{
		++number_of_lines3;
	}
	int count3 = 0;
	ifstream edit3;
	edit3.open("registration patient pass.txt");
	while (count3<number_of_lines3 && edit3 >> patientpassword[count3])
	{
		count3++;
	}
	edit3.close();
	for (int i = 0; i < number_of_lines1; i++)
	{
		if (patientusername[i] == us && patientpassword[i] == pas)
		{
			k = i;
			flag = 1;
		}
	}
	if (flag == 1)
	{
		cout << "Enter New Username : ";
		cin >> newname;
		cout << "Enter New Password : ";
		cin >> newpas;
		patientusername[k] = newname;
		patientpassword[k] = newpas;
		for (int i = 0; i < number_of_lines2; i++)
		{
			if (timeselected[i] == us)
			{
				timeselected[i] = newname;
			}
		}
		edit1.open("registration patient name.txt", ios::in);
		if (edit1.is_open())
		{
			string tp1;
			while (getline(edit1, tp1))
			{
				ofstream edit1;
				edit1.open("registration patient name.txt", std::ofstream::out | std::ofstream::trunc);
				edit1.close();
			}
		}
		edit2.open("time selected.txt", ios::in);
		if (edit2.is_open())
		{
			string tp2;
			while (getline(edit2, tp2))
			{
				ofstream edit2;
				edit2.open("time selected.txt", std::ofstream::out | std::ofstream::trunc);
				edit2.close();
			}
		}
		edit3.open("registration patient pass.txt", ios::in);
		if (edit3.is_open())
		{
			string tp3;
			while (getline(edit3, tp3))
			{
				std::ofstream edit3;
				edit3.open("registration patient pass.txt", std::ofstream::out | std::ofstream::trunc);
				edit3.close();
			}
		}
		for (int i = 0; i < number_of_lines1; i++)
		{
			ofstream edit1;
			edit1.open("registration patient name.txt", std::ios::app);
			edit1 << patientusername[i] << endl;
			edit1.close();
		}
		for (int i = 0; i < number_of_lines3; i++)
		{
			ofstream edit3;
			edit3.open("registration patient pass.txt", std::ios::app);
			edit3 << patientpassword[i] << endl;
			edit3.close();
		}
		for (int i = 0; i < number_of_lines2; i++)
		{
			ofstream edit2;
			edit2.open("time selected.txt", std::ios::app);
			edit2 << timeselected[i] << endl;
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
struct doctor_time {
	int size = 0;
	string Time1[100];
	string day[100];
	string edit1;
	string edit2;
	string new1;
	string new2;
	string deleted1;
	string deleted2;

};
doctor_time time1;
void Add_Available_Time() {
	cout << "How Many Appointments Do You Want To Add " << endl;
	cin >> time1.size;
	ofstream size;
	size.open("size.txt", std::ios::app);
	size << time1.size << endl;
	size.close();
	for (int i = 0; i < time1.size; i++)
	{
		cout << "PLease Enter Appoiment " << "#" << i + 1 << endl;
		cout << "Day : ";
		cin >> time1.day[i];
		cout << "Time : ";
		cin >> time1.Time1[i];
		ofstream time;
		time.open("time.txt", std::ios::app);
		time << time1.Time1[i] << endl;
		time.close();
		ofstream day;
		day.open("day.txt", std::ios::app);
		day << time1.day[i] << endl;
		day.close();
	}

}
void Delete_Appoiments_Doctor()
{
	int found1 = 0, found2 = 0;
	cout << "PLease Enter Appoiment You Want To Delete" << endl;
	cout << "Day : ";
	cin >> time1.deleted1;
	cout << "Time : ";
	cin >> time1.deleted2;
	int number_of_lines1 = 0;
	string line1;
	ifstream myfile1("time.txt");
	while (getline(myfile1, line1))
		++number_of_lines1;
	string time[100];
	int count = 0;
	ifstream edit1;
	edit1.open("time.txt");
	while (count<number_of_lines1 && edit1 >> time[count])
	{
		count++;
	}
	edit1.close();
	int number_of_lines2 = 0;
	std::string line2;
	std::ifstream myfile2("day.txt");
	while (getline(myfile2, line2))
		++number_of_lines2;
	string day[100];
	int count2 = 0;
	ifstream edit2;
	edit2.open("day.txt");
	while (count2<number_of_lines2 && edit2 >> day[count2])
	{
		count2++;
	}
	edit2.close();
	int flag1 = 0, k = 0;
	for (int i = 0; i < number_of_lines2; i++)
	{
		if (time[i] == time1.deleted2 && day[i] == time1.deleted1)
		{
			k = i;
			flag1 = 1;
		}
	}
	if (flag1 == 1)
	{
		time[k] = '0';
		day[k] = '0';
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
		for (int i = 0; i < number_of_lines1; i++)
		{
			ofstream edit1;
			edit1.open("time.txt", std::ios::app);
			edit1 << time[i] << endl;
			edit1.close();
		}
		edit2.open("day.txt", ios::in);
		if (edit2.is_open())
		{
			string tp2;
			while (getline(edit2, tp2))
			{
				std::ofstream edit2;
				edit2.open("day.txt", std::ofstream::out | std::ofstream::trunc);
				edit2.close();
			}
		}
		for (int i = 0; i < number_of_lines2; i++)
		{
			ofstream edit2;
			edit2.open("day.txt", std::ios::app);
			edit2 << day[i] << endl;
			edit2.close();
		}
		cout << "Appointment Deleted Successfully\n\n";
	}
	else
	{
		cout << "\nThis Appoiment Doesn't Found !\n";

	}
}
void Edit_Available_Time_Doctor()
{
	int number_of_lines1 = 0;
	string line1;
	ifstream myfile1("time.txt");
	while (getline(myfile1, line1))
		++number_of_lines1;
	string time[100];
	int count = 0;
	ifstream edit1;
	edit1.open("time.txt");
	while (count<number_of_lines1 && edit1 >> time[count])
	{
		count++;
	}
	edit1.close();
	int number_of_lines2 = 0;
	std::string line2;
	std::ifstream myfile2("day.txt");
	while (getline(myfile2, line2))
		++number_of_lines2;
	string day[100];
	int count2 = 0;
	ifstream edit2;
	edit2.open("day.txt");
	while (count2<number_of_lines2 && edit2 >> day[count2])
	{
		count2++;
	}
	edit2.close();
	int number_of_lines3 = 0;
	string timeselected[100];
	string line3;
	ifstream myfile3("time selected.txt");
	while (getline(myfile3, line3))
		++number_of_lines3;
	int count3 = 0;
	ifstream edit3;
	edit3.open("time selected.txt");
	while (count3<number_of_lines3 && edit3 >> timeselected[count3])
	{
		count3++;
	}
	edit3.close();
	int k = 0, flag1 = 0;
	cout << "Please Enter The Appoiment You Want To Modify" << endl;
	cout << "Day : ";
	cin >> time1.edit1;
	cout << "Time : ";
	cin >> time1.edit2;
	int flag3 = 0;
	for (int i = 0; i < number_of_lines3; i++)
	{
		if (timeselected[i] == time1.edit1 && timeselected[i + 1] == time1.edit2)
		{
			flag3 = 1;
		}
	}
	if (flag3 = 1)
	{
		cout << "You Cannot Change This Appointment Because It Is Already Booked\n\n";
	}
	else
	{
		for (int i = 0; i < number_of_lines2; i++)
		{
			if (time[i] == time1.edit2 && day[i] == time1.edit1)
			{
				k = i;
				flag1 = 1;
			}
		}
		if (flag1 == 1)
		{

			cout << "Enter The New Appoiment \n";
			cout << "Day : ";
			cin >> time1.new1;
			cout << "Time : ";
			cin >> time1.new2;
			day[k] = time1.new1;
			time[k] = time1.new2;
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
			for (int i = 0; i < number_of_lines1; i++)
			{
				ofstream edit1;
				edit1.open("time.txt", std::ios::app);
				edit1 << time[i] << endl;
				edit1.close();
			}
			edit2.open("day.txt", ios::in);
			if (edit2.is_open())
			{
				string tp2;
				while (getline(edit2, tp2))
				{
					std::ofstream edit2;
					edit2.open("day.txt", std::ofstream::out | std::ofstream::trunc);
					edit2.close();
				}
			}
			for (int i = 0; i < number_of_lines2; i++)
			{
				ofstream edit2;
				edit2.open("day.txt", std::ios::app);
				edit2 << day[i] << endl;
				edit2.close();
			}
		}
		else
		{
			cout << "\nThis Appoiment Doesn't Found !";
			cout << endl;
		}
	}
}
bool Find_Doctors()
{
	int number_of_lines = 0;
	string line;
	ifstream myfile("registration doctor name.txt");
	while (getline(myfile, line))
	{
		++number_of_lines;
	}
	string names[100];
	int count = 0;
	ifstream find1;
	find1.open("registration doctor name.txt");
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
void book()
{

	int number_of_lines5 = 0;
	string timeselected[100];
	string line5;
	ifstream myfile5("time selected.txt");
	while (getline(myfile5, line5))
	{
		++number_of_lines5;
	}
	int count5 = 0;
	ifstream edit5;
	edit5.open("time selected.txt");
	while (count5<number_of_lines5 && edit5 >> timeselected[count5])
	{
		count5++;
	}
	edit5.close();
	int number_of_lines = 0;
	std::string line1;
	std::ifstream myfile1("size.txt");
	while (std::getline(myfile1, line1))
		++number_of_lines;
	int size[100];
	string docname;
	int count1 = 0;
	ifstream size1;
	size1.open("size.txt");
	while (count1<number_of_lines && size1 >> size[count1])
	{
		count1++;
	}
	size1.close();
	int number_of_lines1 = 0;
	std::string line2;
	std::ifstream myfile2("time.txt");
	while (std::getline(myfile2, line2))
		++number_of_lines1;
	string time[100];
	int count2 = 0;
	ifstream edit1;
	edit1.open("time.txt");
	while (count2<number_of_lines1 && edit1 >> time[count2])
	{
		count2++;
	}
	edit1.close();
	int number_of_lines3 = 0;
	string line3;
	ifstream myfile3("registration doctor name.txt");
	while (getline(myfile3, line3))
	{
		++number_of_lines3;
	}
	string name[100];
	int count3 = 0;
	ifstream name1;
	name1.open("registration doctor name.txt");
	while (count3<number_of_lines3 && name1 >> name[count3])
	{
		count3++;
	}
	int number_of_lines4 = 0;
	string line4;
	std::ifstream myfile4("day.txt");
	while (getline(myfile4, line4))
		++number_of_lines4;
	string day[100];
	int count4 = 0;
	ifstream edit4;
	edit4.open("day.txt");
	while (count4<number_of_lines4 && edit4 >> day[count4])
	{
		count4++;
	}
	edit4.close();
	string time2;
	string day2;
	int test;
	cout << "Enter The Time You Want To Book\n";
	cout << "Day : ";
	cin >> day2;
	cout << "Time : ";
	cin >> time2;
	int flag1 = 0;
	for (int i = 0; i < number_of_lines5; i++)
	{
		if (timeselected[i] == day2 && timeselected[i + 1] == time2)
		{
			flag1 = 1;
		}
	}
	if (flag1 == 1)
	{
		cout << "This One Is Already Booked\n\n";
	}
	else
	{
		int k = 0, j = 0, m = 0, flag = 0;
		for (int i = 0; i < number_of_lines3; i++)
		{
			while (k < size[j])
			{
				if (time[m] == time2 && day[m] == day2)
				{
					cout << " Doctor : " << name[i] << " Is Avilabel\n" << endl;
					flag = 1;
				}
				k++;
				m++;
			}
			j++;
			k = 0;
		}
		if (flag == 0)
		{
			cout << "This Appoiment Not Avalibale\n\n";
		}
		else
		{
			cout << "To Confirm The Booking Process, Please Press 1\n";
		start1:
			cin >> test;
			if (test == 1) {
				cout << "Please Enter The Doctor's Name\n";
				cin >> docname;
				ofstream file;
				file.open("time selected.txt", std::ios::app);
				file << docname << endl << usernamepatient << endl << day2 << endl << time2 << endl;
				file.close();
				cout << "Booking Done\n\n";
				ofstream file1;
				file1.open("doctor selected.txt", std::ios::app);
				file1 << docname << endl;
				file1.close();
				ofstream file2;
				file2.open("time selected1.txt", std::ios::app);
				file2 << time2 << endl;
				file2.close();
				ofstream file3;
				file3.open("day selected.txt", std::ios::app);
				file3 << day2 << endl;
				file3.close();

			}
			else {
				cout << "Please Enter A Valid Number\n\n";
				goto start1;
			}
		}
	}
}
void View_Appointment_Doctor()
{
	int number_of_lines3 = 0;
	string line3;
	ifstream myfile3("time selected.txt");
	while (getline(myfile3, line3))
	{
		++number_of_lines3;
	}
	string name[100];
	int count3 = 0;
	ifstream name1;
	name1.open("time selected.txt");
	while (count3<number_of_lines3 && name1 >> name[count3])
	{
		count3++;
	}
	for (int i = 0; i < number_of_lines3; i++)
	{
		if (name[i] == username)
		{
			cout << "Patient : " << name[i + 1] << endl;
			cout << "Day : " << name[i + 2] << endl;
			cout << "Time : " << name[i + 3] << endl;
		}
	}
}
void View_Appointment_Patient() {
	int number_of_lines3 = 0;
	string line3;
	ifstream myfile3("time selected.txt");
	while (getline(myfile3, line3))
	{
		++number_of_lines3;
	}
	string name[100];
	int count3 = 0;
	ifstream name1;
	name1.open("time selected.txt");
	while (count3<number_of_lines3 && name1 >> name[count3])
	{
		count3++;
	}
	for (int i = 0; i < number_of_lines3; i++)
	{
		if (name[i] == usernamepatient)
		{
			cout << "Doctor : " << name[i - 1] << endl;
			cout << "Day : " << name[i + 1] << endl;
			cout << "Time : " << name[i + 2] << endl;
		}
	}

}
void Edit_Appointment_Patient() {
	int number_of_lines1 = 0;
	string line1;
	ifstream myfile1("time selected1.txt");
	while (getline(myfile1, line1))
		++number_of_lines1;
	string time[100];
	int count = 0;
	ifstream edit1;
	edit1.open("time selected1.txt");
	while (count<number_of_lines1 && edit1 >> time[count])
	{
		count++;
	}
	edit1.close();
	int number_of_lines2 = 0;
	std::string line2;
	std::ifstream myfile2("day selected.txt");
	while (getline(myfile2, line2))
		++number_of_lines2;
	string day[100];
	int count2 = 0;
	ifstream edit2;
	edit2.open("day selected.txt");
	while (count2<number_of_lines2 && edit2 >> day[count2])
	{
		count2++;
	}
	edit2.close();
	int number_of_lines3 = 0;
	string doctor[100];
	string line3;
	ifstream myfile3("doctor selected.txt");
	while (getline(myfile3, line3))
		++number_of_lines3;
	int count3 = 0;
	ifstream edit3;
	edit3.open("doctor selected.txt");
	while (count3<number_of_lines3 && edit3 >> doctor[count3])
	{
		count3++;
	}
	edit3.close();
	int number_of_lines4 = 0;
	string doctorall[100];
	string line4;
	ifstream myfile4("registration doctor name.txt");
	while (getline(myfile4, line4))
		++number_of_lines4;
	int count4 = 0;
	ifstream edit4;
	edit4.open("registration doctor name.txt");
	while (count4<number_of_lines4 && edit4 >> doctorall[count4])
	{
		count4++;
	}
	edit4.close();
	int number_of_lines5 = 0;
	string timeall[100];
	string line5;
	ifstream myfile5("time.txt");
	while (getline(myfile5, line5))
		++number_of_lines5;
	int count5 = 0;
	ifstream edit5;
	edit5.open("time.txt");
	while (count5<number_of_lines5 && edit5 >> timeall[count5])
	{
		count5++;
	}
	edit5.close();
	int number_of_lines6 = 0;
	string dayall[100];
	string line6;
	ifstream myfile6("day.txt");
	while (getline(myfile6, line6))
		++number_of_lines6;
	int count6 = 0;
	ifstream edit6;
	edit6.open("day.txt");
	while (count6<number_of_lines6 && edit6 >> dayall[count6])
	{
		count6++;
	}
	edit6.close();
	int k = 0, flag1 = 0, D = 0, T = 0, D2 = 0;
	string timeEdit, dayEdit, doctorEdit, newTime, newDay, newDoctor;
	cout << "Please Enter The Appoiment You Want To Modify" << endl;
	cout << "Doctor : "; cin >> doctorEdit;
	cout << "Day : ";   cin >> dayEdit;
	cout << "Time : ";  cin >> timeEdit;
	for (int i = 0; i < number_of_lines2; i++)
	{
		if (time[i] == timeEdit && day[i] == dayEdit && doctor[i] == doctorEdit)
		{
			k = i;
			flag1 = 1;
		}
	}
	if (flag1 == 1)
	{

		cout << "Enter The New Appoiment \n";
		cout << "Doctor: "; cin >> newDoctor;
		cout << "Day : ";   cin >> newDay;
		cout << "Time : ";  cin >> newTime;
		for (int j = 0; j < number_of_lines4; j++) {
			if (newDoctor == doctorall[j])
				D = 1;
		}
		for (int j = 0; j < number_of_lines5; j++) {
			if (newTime == timeall[j])
				T = 1;
		}
		for (int j = 0; j < number_of_lines6; j++) {
			if (newDay == dayall[j])
				D2 = 1;
		}
		if (D == 1 && T == 1 && D2 == 1) {
			cout << "Edit Successfull" << endl;
			day[k] = newDay;
			time[k] = newTime;
			doctor[k] = newDoctor;
			edit3.open("doctor selected.txt", ios::in);
			if (edit3.is_open())
			{
				string tp;
				while (getline(edit3, tp))
				{
					std::ofstream edit1;
					edit3.open("doctor seleceted.txt", std::ofstream::out | std::ofstream::trunc);
					edit3.close();
				}
			}
			for (int i = 0; i < number_of_lines3; i++)
			{
				ofstream edit1;
				edit1.open("doctor selected.txt", std::ios::app);
				edit1 << doctor[i] << endl;
				edit1.close();
			}
			edit2.open("day selected.txt", ios::in);
			if (edit2.is_open())
			{
				string tp2;
				while (getline(edit2, tp2))
				{
					std::ofstream edit2;
					edit2.open("day selected.txt", std::ofstream::out | std::ofstream::trunc);
					edit2.close();
				}
			}
			for (int i = 0; i < number_of_lines2; i++)
			{
				ofstream edit2;
				edit2.open("day selected.txt", std::ios::app);
				edit2 << day[i] << endl;
				edit2.close();
			}
			edit1.open("time selected1.txt", ios::in);
			if (edit1.is_open())
			{
				string tp3;
				while (getline(edit1, tp3))
				{
					std::ofstream edit1;
					edit1.open("time selected1.txt", std::ofstream::out | std::ofstream::trunc);
					edit1.close();
				}
			}
			for (int i = 0; i < number_of_lines1; i++)
			{
				ofstream edit1;
				edit1.open("time selected1.txt", std::ios::app);
				edit1 << time[i] << endl;
				edit1.close();
			}
			ifstream edit6("time selected.txt", ios::in);
			if (edit6.is_open())
			{
				string tp6;
				while (getline(edit6, tp6))
				{
					std::ofstream edit6;
					edit6.open("time selected.txt", std::ofstream::out | std::ofstream::trunc);
					edit6.close();
				}
			}
			for (int i = 0; i < number_of_lines1; i++)
			{
				ofstream edit6;
				edit6.open("time selected.txt", std::ios::app);
				edit6 << doctor[i] << endl << usernamepatient << endl << day[i] << endl << time[i];
				edit6.close();
			}
		}
		else {
			cout << "something is wrong" << endl;
		}

	}
	else
	{
		cout << "\nThis Appoiment Doesn't Found !";
		cout << endl;
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
				case 2:
					Delete_Appoiments_Doctor();
					break;
				case 3:
					Edit_Available_Time_Doctor();
					break;
				case 4:
					View_Appointment_Doctor();
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
			if (!status)
			{
				cout << "\t\tWrong Usename Or Password ! \n";
				cout << "\t\tPlease Try Agian \n";
				goto start3;
			}
			else
			{
				cout << endl;
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
					book();
					break;
				case 3:
					View_Appointment_Patient();
					break;
				case 4:
					Edit_Appointment_Patient();
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
