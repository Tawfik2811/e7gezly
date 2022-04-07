#include<iostream>
#include<string>
#include<cmath>
using namespace std;
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
	
	cout << "How Many Appointments Do You Want To Enter " <<endl;
	cin >> time1.size;
	for (int i = 0; i < time1.size; i++)
	{
		cout << "PLease Enter Appoiment " << "#" << i + 1<<endl;
		cout << "From : ";
		cin >> time1.Time1[i];
		cout << "To : ";
		cin >> time1.Time2[i];
	}
}
void Delete_Appoiments()
{
	int found1=0,found2=0;
	cout << "PLease Enter Appoiment You Want To Delete" << endl;
	cout << "From : ";
	cin >> time1.deleted1;
	cout << "To : ";
	cin >> time1.deleted2;
	for (int i = 0; i < time1.size; i++)
	{
		if (time1.Time1[i] ==time1.deleted1)
		{
			for (int j = i; j < (time1.size - 1); j++)
				time1.Time1[j] = time1.Time1[j + 1];
			found1++;
			i--;
			time1.size --;
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
	if (found1 == 0&&found2==0)
		cout << "\nThis Appoiment Doesn't Found !";
	else
		cout << "\nAppoiment Deleted Successfully!";
	cout << endl;
}
void Edit_Appoiment()
{
	int k=0,m=0,flag1=0,flag2=0;
	cout << "Please Enter The Appoiment You Want TO Modify" << endl;
	cout << "From : ";
	cin >> time1.edit1;
	cout << "To : ";
	cin >> time1.edit2;
	for (int i = 0; i <time1.size; i++)
	{
		if (time1.Time1[i] == time1.edit1)
		{
			k = i;
			flag1= 1;
		}
		
	}
	for (int i = 0; i < time1.size; i++)
	{
		if (time1.Time2[i] == time1.edit2)
		{
			m= i;
			flag2 = 1;
		}

	}
	if (flag1 == 1&&flag2==1)
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

int main()
{
	
	Add_Available_Time();
 Delete_Appoiments();
	Edit_Appoiment();
	




	return 0;
}
