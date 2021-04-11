//	   Course: CS3420-001 Data Structure
//  	     Name: Evan Phillips
//     Assignment: P3
//       Date Due: 9/25/2020
// Date handed in: 10/8/2020
//         Remark: Program that implements the template container class and date class. The container class creates an array with ability
//		   to be modified and printed via ostream.

#include <iostream>
#include "dynCont.h"
#include "dateT.h"
using namespace std;

int main(){
	
	//DATE CONTAINER
	date bday1 = date(12, 9, 1997);
	date date2 = date(11,21,1957);
	date date3 = date(12,15,1959);
	
	cout<<"Creating container to store dates..."<<endl;
	
	container <date>dateContainer;
	
	cout<<"insertBack(date):"<<endl;
	bool insMe = dateContainer.insertBack(bday1);
	cout<<dateContainer<<endl;

	cout<<"insertFront(date):"<<endl;
	insMe = dateContainer.insertFront(date2);
	cout<<dateContainer<<endl;
	
	cout<<"insertFront(date):"<<endl;
	insMe = dateContainer.insertFront(date3);
	cout<<dateContainer<<endl;
	
	cout<<"Testing if container is full:"<<endl;
	if(dateContainer.isFull()){
		cout<<"Container is full."<<endl;
		cout<<endl;
	}
	
	cout<<"Using deleteFront() and deleteBack() items from date container:"<<endl;
	bool delDate = dateContainer.deleteBack();
	cout<<dateContainer<<endl;
	
	delDate = dateContainer.deleteFront();
	cout<<dateContainer<<endl;
	
	delDate = dateContainer.deleteFront();
	cout<<dateContainer<<endl;
	
	//CHAR CONTAINER
	char firstChar = 'a';
	char secondChar = 'b';
	char thirdChar = 'c';
	
	cout<<"Creating container to store chars..."<<endl;
	
	container<char> charContainer;
	cout<<"insertBack(firstChar):"<<endl;
	bool insChar = charContainer.insertBack(firstChar);
	cout<<charContainer<<endl;
	
	cout<<"insertFront(secondChar):"<<endl;
	insChar = charContainer.insertFront(secondChar);
	cout<<charContainer<<endl;
	
	cout<<"insertFront(thirdChar):"<<endl;
	insChar = charContainer.insertFront(thirdChar);
	cout<<charContainer<<endl;
	
	cout<<"Testing if container is full:"<<endl;
	if(charContainer.isFull()){
		cout<<"Container is full."<<endl;
		cout<<endl;
	}
	
	cout<<"Using clear() to delete items from char container:"<<endl;
	charContainer.clear();
	cout<<charContainer<<endl;
	
	
	
}
