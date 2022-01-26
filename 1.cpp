#include <iostream>
#include<iomanip>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
using namespace std;

class employee
{
protected:
	string name;
	string address;
	string email_id;
	string mobile_no;
	string emp_id;
	float weeklySal, da, ta, pf;

public:
	void accept();
	void display();
	virtual float calculate_salary() = 0;
};
void employee::accept()
{
	cout << "\nEmployee Details\n";
	cout << "Enter Name: ";
	cin >> name;
	cin.ignore();
	cout << "Enter Address: ";
	getline(cin, address);
	cout << "Enter Email Id: ";
	cin >> email_id;
	cout << "Enter Mobile No: ";
	cin >> mobile_no;
	cout << "Enter Employee Id: ";
	cin >> emp_id;
}

void employee::display()
{
	cout << "\n*******Employee Details********";
	cout << "\nName\t\t:\t" << name;
	cout << "\nEmployee Id\t:\t" << emp_id;
	cout << "\nAddress		:\t" << address;
	cout << "\nEmail Id\t:\t" << email_id;
	cout << "\nMobile No\t:\t" << mobile_no;
}

//class teaching-employees
//class non-teaching-employees
//class housekeeping-employees

class teaching_Employee : public employee
{
	float basic_sal;

public:
	float calculate_salary()
	{
		basic_sal = 35000;
		da = 0.97 * basic_sal;
		ta = 0.1 * basic_sal;
		pf = 0.12 * basic_sal;
		weeklySal = (basic_sal + da + ta + pf);
		return weeklySal;
	}
	void display_gross()
	{
		display();
		cout << "\nEmploy Type\t:\tTeaching";
		cout << "\nGross Salary(Weekly):\t" << calculate_salary() << endl;
	}
};

class non_teaching_Employee : public employee
{
	float basic_sal;

public:
	float calculate_salary()
	{
		basic_sal = 20000;
		da = 0.97 * basic_sal;
		ta = 0.1 * basic_sal;
		pf = 0.12 * basic_sal;
		weeklySal = (basic_sal + da + ta + pf);
		return weeklySal;
	}
	void display_gross()
	{
		display();
		cout << "\nEmploy Type\t:\tNon-Teaching";
		cout << "\nGross Salary(Weekly):\t" << calculate_salary() << endl;
	}
};

class housekeeping_Employee : public employee
{
	float basic_sal;

public:
	float calculate_salary()
	{
		basic_sal = 15000;
		da = 0.97 * basic_sal;
		ta = 0.1 * basic_sal;
		pf = 0.12 * basic_sal;
		weeklySal = (basic_sal + da + ta + pf);
		return weeklySal;
	}
	void display_gross()
	{
		display();
		cout << "\nEmployee Type\t:\tHouse-Keeping";
		cout << "\nGross Salary(Weekly):\t" << calculate_salary() << endl;
	}
};

int admin()
{
	string userid = "Admin";
	char password[10] = "1234";
	string inputuserid, inputpassword;
	system("cls");
	cout << "\n\n\n\n\t\t**************Employee Management System***************\n";
	cout<< "**\t\tEnter User Id: ";
	cin >> inputuserid;
	cout << "**\t\tEnter Password: ";
	cin >> inputpassword;
	int n = 3;
	char ch;
	cout << "\t\tConnecting ..";
	while (n--)
	{
		cout << "..";
	}
	cout << endl;
	if (userid == inputuserid)
	{
		if (password == inputpassword)
		{
			cout << "\n\t\tLogin Successfully!";
			sleep(2);
			return 0;
		}
		else if (password != inputpassword)
		{
			cout << "\n\t\tWrong Password\n";
			sleep(2);
			return 1;
		}
		sleep(1);
	}
	else
	{
		cout << "\n\n\t\tWrong User Id or Password!!!!";
		sleep(2);
		return 1;
	}
}
void employe()
{
	cout << "Employe!";
	sleep(2);
}
void ADMINCONTROLS()
{

}
void LOGIN()
{
	int ch;
	do
	{
		system("cls");
		cout << "\n\n\n\n\t\t**************LOGIN***************\n";
		cout << "\t\t**\t"<<setw(8)<<"1.Employ\t\t**\n\t\t**\t"<<setw(8)<<"2.Admin\t\t\t**\n\t\t**\t"<<setw(8)<<"3.Exit\t\t\t**\n\t\t**\t"<<setw(8)<<"INPUT CHOICE: ";
		cin >> ch;
		cout << "\n\t\t**********************************\n";
		int n = 3;
		cout << "\t\tConnecting ..";
		while (n--)
		{
			cout << "..";
		}
		sleep(2);
		if(ch==1)
		{
			system("cls");
			employe();
		}
		else if(ch==2)
		{
			system("cls");
			if(admin()==0)
			{
				ADMINCONTROLS();
			}
			else if (admin()==1)
			{
				continue;
			}
		}	
		else if(ch==3)
		{
			cout << "\n\t\t******Exiting*******\n";
			exit(0);
		}
		else
		{
			cout << "\n\t\t**********INVALID CHOICE*********" ;
			sleep(2);
		}
	} while (ch != 3);
}
int main()
{
	LOGIN();

	/* housekeeping_Employee h;
	non_teaching_Employee nt;
	teaching_Employee t;
	h.accept();
	nt.accept();
	t.accept();
	h.display_gross();
	nt.display_gross();
	t.display_gross(); */

	getch();
	return 0;
}