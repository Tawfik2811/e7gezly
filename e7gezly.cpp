#include<iostream>
#include<string>
#include <fstream>
#include<cmath>
#include<stdio.h>
#include <cstring>
using namespace std;
string usn;
int tm;
string doctorusername[100];
string doctorpassword[100];
int counter = 0;
int counter_time = 0;
int counter_size = 0;
string patientusername[100];
string patientpassword[100];
int counter2 = 0;
void valid1(string str)
{
    int exit=0;
  string dir,user,fname1;
  ifstream file;
 fname1="doctor_"+usn+".dta";
  file.open(fname1.c_str());

  if(!file.is_open() && file.fail())
  {
    file.close();
    return;
  }
  else
  {
    tm++;
    if(tm==3)
    {
      cout<<"\nThis username already exists\nPlease try Again.";
      file.close();
      return;
    }
    cout<<"\nThis username already exists!\nCreate a username:";
    cin>>usn;
    file.close();
    valid1(usn);
  }

}
void delet(char* name){
remove(name);
}
void valid2(string str)
{
  string dir,user,fname1;
  ifstream file;
fname1="patient_"+usn+".dta";
  file.open(fname1.c_str());
  if(!file.is_open() && file.fail())
  {
    file.close();
    return;
  }
  else
  {
    tm++;
    if(tm==3)
    {
      cout<<"\nThis username already exists\nPlease try Again.";
      file.close();
      return;
    }
    cout<<"\nThis username already exists!\nCreate a username:";
    cin>>usn;
    file.close();
    valid2(usn);
  }
}
void Registration(int choise)
{
      int exit=0;
  string ans,psd,name,fname,bio,usern,pw,line,nusn;
  ofstream fileo;
  ifstream filei;
while(exit==0){

      cout<<"\nEnter your name:";
      cin.ignore();
      getline(cin,name);
      cout<<"\nCreate a username:";
      cin>>usn;
      tm=0;
      valid1(usn);
      if(tm>=3)
      {
        break;
      }
      if(choise==1){
      cout<<"\nCreate a password:";
      cin>>psd;
      fname="doctor_"+usn+".dta";
      fileo.open(fname.c_str());
      fileo<<usn<<endl<<name<<endl<<psd<<endl;
      cout<<"\nYou are successfully registered:)";
      cout<<"\nAdd to your bio and press enter when you are done:";
      cin.ignore();
      getline(cin,bio);
      fileo<<bio<<endl;
      cout<<"\nYour bio is saved as: "<<bio;
      fileo.close();
        exit=1;}
        else{
            cout<<"\nCreate a password:";
      cin>>psd;
      fname="patient_"+usn+".dta";
      fileo.open(fname.c_str());
      fileo<<usn<<endl<<name<<endl<<psd<<endl;
      cout<<"\nYou are successfully registered:)";
      cout<<"\nAdd to your bio and press enter when you are done:";
      cin.ignore();
      getline(cin,bio);
      fileo<<bio<<endl;
      cout<<"\nYour bio is saved as: "<<bio;
      fileo.close();
        exit=1;


        }
}
}

bool LogIn(int choise)
{

        string ans,psd,name,fname,bio,usern,pw,line,usn;
  ofstream fileo;
  ifstream filei;

int exit=0;
 while(exit==0)
  {
    if(choise==2){
    cout<<"Enter your username:";
      cin>>usn;
      cout<<"\nEnter your password:";
      cin>>psd;
      fname="doctor_"+usn+".dta";
      filei.open(fname.c_str());
      if(!filei.is_open() && filei.fail())
      {
        cout<<"\nYou are not registered, please register before logging in.\n";
        filei.close();
        break;
        }
      getline(filei,usern);
      getline(filei,name);
      getline(filei,pw);
      if(usn==usern && psd==pw)
      {
        cout << "\t\tSuccessfully Loggedin\n\n";

        cout<<"\nhello doctor:"<<name<<"\nhope felling great today:\n";

        exit=1;

      }
      else{
        cout<<"\nWrong username or password!\nPlease try Again.\n";
    return false;
      }
      cout<<endl;
      return true;
      }
      else{
      cout<<"Enter your username:";
      cin>>usn;
      cout<<"\nEnter your password:";
      cin>>psd;
      fname="patient_"+usn+".dta";
      filei.open(fname.c_str());
      if(!filei.is_open() && filei.fail())
      {
        cout<<"\nYou are not registered, please register before logging in.\n";
        filei.close();
        break;
      }
      getline(filei,usern);
      getline(filei,name);
      getline(filei,pw);
      if(usn==usern && psd==pw)
      {
        cout<<"\nhello patient:"<<name<<"\nhope felling good soon:\n";

        exit=1;
      }
      else{
        cout<<"\nWrong username or password!\nPlease try Again.\n";
        return false;
      }
      cout<<endl;
      return true;


      }
}
	return false;
}
void Edit_Info(int choise)
{
            string ans,psd,name,fname,bio,usern,pw,line,usn;
  ofstream fileo;
  ifstream filei;
int exit=0;
while(exit==0){

    cout<<"Enter your old username:";
    cin>>usn;
      cout<<"\nEnter your old password:";
      cin>>psd;
if(choise==1){
      fname="doctor_"+usn+".dta";
    filei.open(fname.c_str());
      if(!filei.is_open() && filei.fail())
      {
        cout<<"\nWrong username or password!\nPlease try Again.\n";
        filei.close();
        exit=1;
    }
      getline(filei,usern);
      getline(filei,name);
      getline(filei,pw);
      getline(filei,line);
      filei.close();
      if(usn==usern && psd==pw)
      {
        cout<<"your old data:\n";
        cout<<"User-name:"<<usern<<endl;
        cout<<"password:"<<pw<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Bio:"<<line<<endl;
        cout<<"enter your new data\n";
        remove(fname.c_str());
        Registration(1);
        exit=1;

      }
      else{
        cout<<"\nWrong username or password!\nPlease try Again.\n";
      }
}
      else{
      fname="patient_"+usn+".dta";
    filei.open(fname.c_str());
      if(!filei.is_open() && filei.fail())
      {
        cout<<"\nWrong username or password!\nPlease try Again.\n";
        filei.close();
        exit=1;
    }
      getline(filei,usern);
      getline(filei,name);
      getline(filei,pw);
      getline(filei,line);
      filei.close();
      if(usn==usern && psd==pw)
      {
        cout<<"your old data:\n";
        cout<<"User-name:"<<usern<<endl;
        cout<<"password:"<<pw<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Bio:"<<line<<endl;
        cout<<"enter your new data\n";
        remove(fname.c_str());
        Registration(1);
        exit=1;

      }
      else{
        cout<<"\nWrong username or password!\nPlease try Again.\n";
      }
      }
      }
}
struct doctor_time {
	int size[100];
	int Time1[100];
	int Time2[100];
	string day[100];
	int deleted1;
	int deleted2;
	int edit1;
	int edit2;
	string edit3;
	int new1;
	int new2;
string new3;

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
		cout << "From : ";
		cin >> time1.Time1[counter_time];
		cout << "To : ";
		cin >> time1.Time2[counter_time];
		counter_time++;
	}
	counter_size++;
}
void Edit_Appoiment()
{
	int k = 0, m = 0, flag1 = 0, flag2 = 0, flag3 = 0, l = 0;
	cout << "Please Enter The Appoiment You Want TO Modify" << endl;
	cout << "Day : ";
	cin >> time1.edit3;
	cout << "From : ";
	cin >> time1.edit1;
	cout << "To : ";
	cin >> time1.edit2;
	for (int i = 0; i < counter_time; i++)
	{
		if (time1.Time1[i] == time1.edit1)
		{
			k = i;
			flag1 = 1;
		}

	}
	for (int i = 0; i < counter_time; i++)
	{
		if (time1.Time2[i] == time1.edit2)
		{
			m = i;
			flag2 = 1;
		}

	}
	for (int i = 0; i < counter_time; i++)
	{
		if (time1.day[i] == time1.edit3)
		{
			l= i;
			flag3 = 1;
		}

	}
	if (flag1 == 1 && flag2 == 1 && flag3 == 1)
	{
		cout << "Enter The New Appoiment \n";
		cout << "Day :";
		cin >> time1.new3;
		cout << "From : ";
		cin >> time1.new1;
		cout << "To : ";
		cin >> time1.new2;
		time1.Time1[k] = time1.new1;
		time1.Time2[m] = time1.new2;
		time1.day[l] = time1.new3;
	}
	else
		cout << "\nThis Appoiment Doesn't Found !";
		cout<<endl;
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
	int j = 0; int k = 0,m=0;
	for (int i = 0; i < counter; i++)
	{

		cout << "Doctor : " << doctorusername[i] << endl;
		while (k < time1.size[j])
		{
			cout << "Day : " << time1.day[m]<<endl;
			cout << "From : " << time1.Time1[m] << endl;
			cout << "To : " << time1.Time2[m] << endl;
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
            Registration(choise2);
			goto start2;

		}
		else if (choise2 == 2)
		{
			bool status = LogIn(choise2);
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
					Edit_Appoiment();
					break;
				case 5:
					Edit_Info(1);
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
		    choise2=2;
            Registration(choise2);
			goto start3;
		}
		else if (choise2 == 2)
		{
		    choise2=1;
			bool status = LogIn(choise2);
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
				}
				case 2:
					Display_Doctors_Available_In_Certain_Appointment_Time();
					break;
				case 7:
					Edit_Info(2);
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
