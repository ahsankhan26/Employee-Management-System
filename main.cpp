#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "Person.cpp"
using namespace std;

int main(){
	char op='y';
	
	Person p;
	
	do{
		system("cls");
		cout<<"\t\t EMPLOYEE MANAGEMENT SYSTEM\n\n"
			<<"\t\t 1. Add New Record\n"
			<<"\t\t 2. Display all Record(s)\n"
			<<"\t\t 3. Search Record\n"
			<<"\t\t 4. Search by Department \n"
			<<"\t\t 5. Edit Record \n"
			<<"\t\t 6. Delete Record \n"
			<<"\t\t 7. Add New File \n"
			<<"\t\t 0. Exit \n";
			
		cin>>op;
		
		switch(op){
			
			case '1' : p.readData()     ; break;
			case '2' : p.listData()     ; break;
			case '3' : p.searchData()   ; break;
			case '4' : p.searchDepart() ; break;
			case '5' : p.editData()     ; break;
			case '6' : p.deleteData()   ; break;
			case '7' : p.addFile()      ; break;
			case '0' : exit(1)          ; break;
			
		
			
		}
		
	}while(op!='n' || op!='N');
	
	return 0;
}

