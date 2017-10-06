#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include "Employee.cpp"

using namespace std;

class Person : public Employee{

private:

	string name;
	int age;
	string department;
	
public:

	//function declaration

	void readData();
	void listData();
	void searchData();
	void searchDepart();
	void editData();
	void deleteData();
	void addFile();

};

	//function definiton

void Person::readData(){					//input new record

	system("cls");
	
	char ch;
	
	int id;
	double salary;

	ofstream fout("data.csv", ios::app);

	cout << "id : ";
	cin  >> id;
	cout << "name : ";
	cin  >> name;
	cout << "age : ";
	cin  >> age;
	cout << "department : ";
	cin  >> department;
	cout << "salary : ";
	cin  >> salary;
	
	Person::setId(id);
	Person::setSalary(salary);

	cout << "\n	Do you wish to save the above provided credentials? (y/n)	:	";
	cin >> ch;

	if (ch == 'y')
	{
		
		fout<<Person::getId()<<','<<name<<','<<age<<','<<department<<','<<Person::getSalary()<<" \n";
		fout.close();
	}
	else
		readData();
}

void Person::listData(){	//prints all employees

	system("cls");
	ifstream fin("data.csv", ios::in);

	if (!fin.is_open()) cout << "ERROR: File Open" << '\n';
	
	string line,dummyLine;				
	getline(fin, dummyLine);	// for ignoring first line

	cout << "\nId		name		age		department	salary		\n";
	while (!fin.eof()){
		getline(fin,line,',');
		cout<<line<<"\t\t";
	}
	getch();
	fin.close();
}

void Person::searchData(){

	bool check = false;
	system("cls");

	string code;
	string id, name, age, department, salary;

	ifstream fin("data.csv", ios::in);

	if (!fin.is_open()) cout << "ERROR: File Open" << '\n';

	cout << "Enter ID : ";
	cin >> code;

	while (!fin.eof())
	{
		while (fin.good())
		{

			getline(fin, id, ',');
			getline(fin, name, ',');
			getline(fin, age, ',');
			getline(fin, department, ',');
			getline(fin, salary, '\n');

			if (id == code)
			{
				cout << "\nId		name		age		department		salary		\n";
				cout << "\n" << id << "\t\t" << name << "\t\t" << age << "\t\t" << department << "\t\t\t" << salary << "\n";
				check = true;
			}
		}

	}
	if (!check) cout << "\n No employee available.";
	getch();
}

void Person::searchDepart(){

	bool check = false;
	system("cls");

	string depart;
	string id, name, age, department, salary;

	ifstream fin("data.csv", ios::in);

	if (!fin.is_open()) cout << "ERROR: File Open" << '\n';

	cout << "Enter Department : ";
	cin >> depart;
	
	cout << "\nId		name		age		department	salary		\n";
	while (!fin.eof())
	{
		while (fin.good())
		{

			getline(fin, id, ',');
			getline(fin, name, ',');
			getline(fin, age, ',');
			getline(fin, department, ',');
			getline(fin, salary, '\n');

			if (department == depart)
			{

				if (fin.eof()) break; //preventing repeat of last line
				cout << "\n" << id << "\t\t" << name << "\t\t" << age << "\t\t" << department << "\t\t\t" << salary << "\n";
				check = true;
			}
		}

	}
	if (!check) cout << "\n No employee available.";
	getch();
}

void Person::editData()
{
	system("cls");

	bool flag = false; //check


	ifstream fin("data.csv");
	ofstream temp("temp.csv"); // temp file for input of every employee except the one user wants to delete

	string code;

	string id, name, age, department, salary;

	int ccode;
	unsigned long long int sal;

	cout << "Enter Id : ";
	cin >> code;

	while (!fin.eof())
	{

		while (fin.good())
		{

			getline(fin, id, ',');
			getline(fin, name, ',');
			getline(fin, age, ',');
			getline(fin, department, ',');
			getline(fin, salary, '\n');

			if (code != id)
			{
				if (fin.eof()) break; //preventing repeat of last line
				temp << id << ',' << name << ',' << age << ',' << department << ',' << salary << endl;
			}
			if (id == code)
			{ // if user entered correct name, x=1 for later output message that the user data has been deleted

				system("cls");
				cout << "ID matched\n";
				getch();
				cout << "id : ";
				cin >> ccode;
				Person::setId(ccode);
				cout << "name : ";
				cin >> this->name;
				cout << "age : ";
				cin >> this->age;
				cout << "department : ";
				cin >> this->department;
				cout << "salary : ";
				cin >> sal;
				Person::setSalary(sal);

				temp << Person::getId() << ',' << this->name << ',' << this->age << ',' << this->department << ',' << Person::getSalary() << endl;

				flag = true;
			}
		}
	}
	fin.clear(); // clear eof and fail bits
	fin.close();
	temp.close();
	remove("data.csv");
	rename("temp.csv", "data.csv");

	if (flag == false){ // x was set to 0 at start, so if it didn't change, it means user entered the wrong name
		cout << "Not matched." << endl;
	}
	else{ // x is not 0, it means user entered the correct name, print message that employee data has been deleted
		cout << "Employee Updated" << endl;
		getch();
	}
}

void Person::deleteData()
{
	system("cls");

	bool flag = false; //check


	ifstream fin("data.csv");
	ofstream temp("temp.csv"); // temp file for input of every employee except the one user wants to delete

	string code;
	char op;

	string id, name, age, department, salary;

	cout << "Enter Id : ";
	cin >> code;

	while (!fin.eof())
	{

		while (fin.good())
		{

			getline(fin, id, ',');
			getline(fin, name, ',');
			getline(fin, age, ',');
			getline(fin, department, ',');
			getline(fin, salary, '\n');

			if (code != id)
			{

				if (fin.eof()) break; //preventing repeat of last line
				temp << id << ',' << name << ',' << age << ',' << department << ',' << salary << endl;

			}
			if (id == code)
			{ // if user entered correct name, x=1 for later output message that the user data has been deleted
				flag = true;
			}
		}
	}
	fin.clear(); // clear eof and fail bits
	fin.close();
	temp.close();
	remove("data.csv");
	rename("temp.csv", "data.csv");

	if (flag == false){ // x was set to 0 at start, so if it didn't change, it means user entered the wrong name
		cout << "Not matched." << endl;
	}
	else{ // x is not 0, it means user entered the correct name, print message that employee data has been deleted
		cout << "data has been deleted." << endl;
		getch();
	}
}

void Person::addFile(){
	
	system("cls");
	
	char file[20];
	
	ofstream fin("data.csv", ios::app);
	ifstream fa;
	
	if(!fin.is_open())cout<<"ERROR:OPEN FILE!";
	
	cout<<"Enter file name : ";
	cin>>file;
	
	fa.open(file);
	
	string dummyline,line;
	getline(fa,dummyline);
	
	if(!fa.is_open())cout<<"ERROR :"<<file<<" not found";getch();
	
	while(fa.good()){
		
		getline(fa,line);
		if(fa.eof())break;
		fin<<line<<endl;
	}
		cout<<"Record added!\n";getch();
		
	fin.close();
	fa.close();
	//temp.close();
	
}

