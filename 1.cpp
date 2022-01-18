/* A company pays its employees on a weekly basis. The employees are of 
three types: teaching employees, non-teaching employees and housekeeping 
employees. Consider the appropriate formula to calculate the salary of each type 
of employee. Use late binding functionality to implement an OO application */

#include<iostream>
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



int main()
{

    return 0;
}