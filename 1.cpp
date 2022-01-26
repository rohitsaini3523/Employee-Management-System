#include <iostream>
#include <iomanip>
#include <fstream>
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
	int emp_id;
	int type;
	float weeklySal, da, ta, pf;

public:
	employee()
	{
		name = "-";
		address = "-";
		email_id = "-";
		mobile_no = "0";
		emp_id = 0;
	}
	int get_emp_id()
	{
		return emp_id;
	}
	int get_type()
	{
		return type;
	}
	void accept();
	void display();
	void settype(int i)
	{
		type = i;
	}
	string get_mobile()
	{
		return mobile_no;
	}
	/* 	void modify(string addr)
	{
		this->address = addr;
	} */
	virtual void calculate_salary() = 0;
};
void employee::accept()
{
	cout << "\n\t\t*******Enter Employee Details********";
	cout << "\n\t\tEnter Name: ";
	cin >> name;
	cin.ignore();
	cout << "\t\tEnter Address: ";
	getline(cin, address);
	cout << "\t\tEnter Email Id: ";
	cin >> email_id;
	cout << "\t\tEnter Mobile No: ";
	cin >> mobile_no;
	cout << "\t\tEnter Employee Id: ";
	cin >> emp_id;
}

void employee::display()
{
	cout << "\n\t\t*******Employee Details********";
	cout << "\n\t\tName\t\t:\t" << name;
	cout << "\n\t\tEmployee Id\t:\t" << emp_id;
	cout << "\n\t\tAddress		:\t" << address;
	cout << "\n\t\tEmail Id\t:\t" << email_id;
	cout << "\n\t\tMobile No\t:\t" << mobile_no;
}

//class teaching-employees
//class non-teaching-employees
//class housekeeping-employees

class teaching_Employee : public employee
{
	float basic_sal;

public:
	void calculate_salary()
	{
		basic_sal = 35000;
		da = 0.97 * basic_sal;
		ta = 0.1 * basic_sal;
		pf = 0.12 * basic_sal;
		weeklySal = (basic_sal + da + ta + pf);
	}
	void display_gross()
	{
		display();
		cout << "\n\t\tEmploy Type\t:\tTeaching";
		cout << "\n\t\tGross Salary(Weekly):\t" << weeklySal << endl;
	}
};

class non_teaching_Employee : public employee
{
	float basic_sal;

public:
	void calculate_salary()
	{
		basic_sal = 20000;
		da = 0.97 * basic_sal;
		ta = 0.1 * basic_sal;
		pf = 0.12 * basic_sal;
		weeklySal = (basic_sal + da + ta + pf);
	}
	void display_gross()
	{
		display();
		cout << "\n\t\tEmploy Type\t:\tNon-Teaching";
		cout << "\n\t\tGross Salary(Weekly):\t" << weeklySal << endl;
	}
};

class housekeeping_Employee : public employee
{
	float basic_sal;

public:
	int set_type()
	{
		type = 3;
	}
	void calculate_salary()
	{
		basic_sal = 15000;
		da = 0.97 * basic_sal;
		ta = 0.1 * basic_sal;
		pf = 0.12 * basic_sal;
		weeklySal = (basic_sal + da + ta + pf);
	}
	void display_gross()
	{
		display();
		cout << "\n\t\tEmployee Type\t:\tHouse-Keeping";
		cout << "\n\t\tGross Salary(Weekly):\t" << weeklySal << endl;
	}
};
void ADMINCONTROLS()
{
	int choice;
	int ch1;
	int t_emp;
	do
	{
		cout << "\n\n\n\n\t\t**************MENU***************\n";
		cout << "\t\t1.Add New Employee\n\t\t2.Search Employee By Emp_id";
		cout << "\n\t\t3.Display all Employ By types\n\t\t";
		cout << "4.Delete Employee by Emp_id\n\t\t5.Exit\n\t\tChoice : ";
		cin >> choice;
		if (choice == 1)
		{
			do
			{
				system("cls");
				cout << "\n\n\n\n\t\t***********ADD MENU***************\n";
				cout << "\n\t\tSelect Type of Employee\n";
				cout << "\t\t1.Teaching\n\t\t2.Non-Teaching\n\t\t3.House-Keeping\n\t\t4.Back\n\t\tChoice:";
				cin >> ch1;
				if (ch1 == 1)
				{
					teaching_Employee t;
					t.accept();
					t.settype(ch1);
					cout << "\nEnter Details Are: \n";
					t.display();
					fstream file;
					file.open("Data.txt", ios::app|ios::binary);
					file.write((char *)&t, sizeof(t));
					cout << "\n\t\tEmployee Created Successfully!";
					file.close();
				}
				else if (ch1 == 2)
				{
					non_teaching_Employee nt;
					nt.accept();
					nt.settype(ch1);
					cout << "\nEnter Details Are: \n";
					nt.display();
					fstream file;
					file.open("Data.txt", ios::app|ios::binary);
					file.write((char *)&nt, sizeof(nt));
					cout << "\n\t\tEmployee Created Successfully!";
					file.close();
				}
				else if (ch1 == 3)
				{
					housekeeping_Employee h;
					h.accept();
					h.settype(ch1);
					cout << "\nEnter Details Are: \n";
					h.display();
					fstream file;
					file.open("Data.txt", ios::app|ios::binary);
					file.write((char *)&h, sizeof(h));
					cout << "\n\t\tEmployee Created Successfully!";
					file.close();
				}
				sleep(1);
			} while (ch1 != 4);
		}
		else if (choice == 2)
		{
			int flag = 1;
			int k;
			cout << "\n\n\n\n\t\t********Search MENU***************\n";
			cout << "\n\t\tEnter Employee Emp_id: ";
			cin >> k;
			ifstream f1("Data.txt",ios::binary);
			f1.seekg(0, ios::beg);
			employee *e;
			teaching_Employee t1;
			e = &t1;
			while (f1.read((char *)&t1, sizeof(t1)))
			{
				if (t1.get_emp_id() == k)
				{
					flag = 0;
					e->calculate_salary();
					t1.display_gross();
				}
			}
			if (flag == 1)
			{
				cout << "\n\t\tEmployee Not Found";
			}
			f1.close();
			sleep(3);
			system("cls");
		}
		else if (choice == 3)
		{
			int m;
			system("cls");
			cout << "\n\n\n\n\t\t********Display MENU***************\n";
			cout << "\t\tSelect Employee type\n";
			cout << "\t\t1.Teaching\n\t\t2.Non teaching\n\t\t3.Housekeeping\n\t\t4.Back\n\t\tChoice: ";
			cin >> m;
			ifstream f1("Data.txt",ios::binary);
			f1.seekg(0, ios::beg);
			employee *e;
			teaching_Employee t1;
			e = &t1;
			while (f1.read((char *)&t1, sizeof(t1)))
			{
				if (t1.get_type() == m)
				{
					e->calculate_salary();
					//t1.display();
					t1.display_gross();
				}
			}
			f1.close();
			sleep(3);
			system("cls");
		}
		else if (choice == 4)
		{
			int flag = 0;
			int k;
			cout << "\n\t\tEnter Employee Emp_id to be deleted: ";
			cin >> k;
			fstream f("Data.txt",ios::binary);
			fstream f1("Temp.txt", ios::app|ios::binary);
			f.seekg(0, ios::beg);
			teaching_Employee t;
			while (f.read((char *)&t, sizeof(t)))
			{
				if (t.get_emp_id() != k)
				{
					f1.write((char *)&t, sizeof(t));
				}
				else
				{
					flag = 1;
				}
			}
			if (flag == 0)
			{
				cout << "\n\t\tEmployee Not Found";
			}
			else
			{
				cout << "\n\t\tRecord Deleted!";
			}
			f.close();
			f1.close();
			remove("Data.txt");
			rename("Temp.txt", "Data.txt");
			system("cls");
		}
		if (choice == 5)
		{
			return;
		}
	} while (choice != 5);
}
int admin()
{
	string userid = "Admin";
	char password[10] = "1234";
	string inputuserid, inputpassword;
	system("cls");
	cout << "\n\n\n\n\t\t**************Employee Management System***************\n";
	cout << "\t\t**\t\tEnter User Id: ";
	cin >> inputuserid;
	cout << "\t\t**\t\tEnter Password: ";
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
			return 1;
		}
		else if (password != inputpassword)
		{
			cout << "\n\t\tWrong Password\n";
			sleep(2);
			return 0;
		}
		sleep(1);
	}
	else
	{
		cout << "\n\n\t\tWrong User Id or Password!!!!";
		sleep(2);
		return 0;
	}
}
void employe()
{
	int flag = 1;
	int k;
	cout << "\n\n\n\n\t\t********Search MENU***************\n";
	cout << "\n\t\tEnter Employee Emp_id: ";
	cin >> k;
	fstream f1("Data.txt",ios::binary);
	f1.seekg(0, ios::beg);
	employee *e;
	teaching_Employee t1;
	e = &t1;
	while (f1.read((char *)&t1, sizeof(t1)))
	{
		if (t1.get_emp_id() == k)
		{
			flag = 0;
			e->calculate_salary();
			t1.display_gross();
		}
	}
	if (flag == 1)
	{
		cout << "\n\t\tEmployee Not Found";
	}
	f1.close();
	sleep(3);
}

void LOGIN()
{
	int ch;
	do
	{
		system("cls");
		cout << "\n\n\n\n\t\t**************LOGIN***************\n";
		cout << "\t\t**\t" << setw(8) << "1.Employ\t\t**\n\t\t**\t" << setw(8) << "2.Admin\t\t\t**\n\t\t**\t" << setw(8) << "3.Exit\t\t\t**\n\t\t**\t" << setw(8) << "INPUT CHOICE: ";
		cin >> ch;
		cout << "\n\t\t**********************************\n";
		int n = 3;
		if (ch == 1)
		{
			cout << "\t\tConnecting ..";
			while (n--)
			{
				cout << "..";
			}
			sleep(2);
			system("cls");
			employe();
		}
		else if (ch == 2)
		{
			cout << "\t\tConnecting ..";
			while (n--)
			{
				cout << "..";
			}
			sleep(2);
			system("cls");
			if (admin() == 1)
			{
				ADMINCONTROLS();
			}
			else if (admin() == 0)
			{
				continue;
			}
		}
		else if (ch == 3)
		{
			cout << "\n\t\t\t******Exiting*******\n";
			exit(0);
		}
		else
		{
			cout << "\n\t\t**********INVALID CHOICE*********";
			sleep(2);
		}
	} while (ch != 3);
}
int main()
{
	LOGIN();
	getch();
	return 0;
}