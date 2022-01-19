/* A company pays its employees on a weekly basis. The employees are of 
three types: teaching employees, non-teaching employees and housekeeping 
employees. Consider the appropriate formula to calculate the salary of each type 
of employee. Use late binding functionality to implement an OO application */

#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<unistd.h>
using namespace std;

class employee
{
protected:
	string name;
	string address;
	string email_id;
	string mobile_no;
	string emp_id;

public:
	void accept();
	void display();
};
void employee::accept()
{
	cout << "\nEmployee Details\n";
	cout << "Enter Name:";
	cin >> name;
	cin.ignore();
	cout << "Enter Address:";
	getline(cin, address);
	cout << "Enter Email Id:";
	cin >> email_id;
	cout << "Enter Mobile No:";
	cin >> mobile_no;
	cout << "\nEnter Employee Id:";
	cin >> emp_id;
}

void employee::display()
{
	cout << "\nEmployee Details";
	cout << "\nName:" << name;
	cout << "\nEmployee Id:" << emp_id;
	cout << "\nAddress:" << address;
	cout << "\nEmail Id:" << email_id;
	cout << "\nMobile No:" << mobile_no;
}

//class teaching-employees
//class non-teaching-employees 
//class housekeeping-employees

void admin()
{
	string userid = "Admin";
	char password[10] = "1234";
	string inputuserid, inputpassword;
	system("cls");
	cout << "\n\n\n\n\t\tEmployee Management System\n"
		 << "Enter User Id: ";
	cin >> inputuserid;
	cout << "\nEnter Password: ";
	cin >> inputpassword;
	int n = 3;
	cout << "Connecting ..";
	while(n--)
	{
		cout << "..";
	}
	cout << endl;
	if (userid == inputuserid)
	{
		if(password == inputpassword)
			cout << "Login Successfully!";
		else if (password != inputpassword)
		{
			cout << "Wrong Password\n";
			sleep(2);
			admin();
		}
		sleep(1);
	}
	else
	{
		cout << "\n\n\t\tWrong User Id or Password!!!!";
		sleep(2);
		admin();
	}
}

int main()
{
	admin();
	
	employee E;
	E.accept();
	E.display();
	fstream f;
	f.open("Data.txt",ios::out|ios::app);
	f.write((char *)&f, sizeof(f));
	f.close();
	getch();
	return 0;
}