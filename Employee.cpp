#pragma once
#include "Person.cpp"
class Employee{
	
	private :
		int id;
		double salary;
		
	public :
	
		static int count;
		void setId(int);
		void setSalary(double);
		int getId();
		double getSalary();
	
};

void Employee::setSalary(double salary){
	
	this->salary = salary;
}

void Employee::setId(int id){
	
	this->id = id;
}

int Employee::getId(){
	return id;
}

double Employee::getSalary(){
	return salary;
}






