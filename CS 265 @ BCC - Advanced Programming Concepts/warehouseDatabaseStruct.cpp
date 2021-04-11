#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct Inventory{
	char description[50];
	int quantity;
	double wholesale;
	double retail;
	int date;
};

int addRecord(){
	Inventory newInv;
		
		fstream invFile("inventory.dat", ios::app | ios::binary);
		if(!invFile){
			cout<<"Error opening file. Program aborting.";
			return 0;
		}
		
		cout<<"Enter the item description: ";
		cin>>newInv.description;
		
		while(true){
		
			cout<<endl<<"Enter the quantity of the item on hand: ";
			cin>>newInv.quantity;
			
			cout<<endl<<"Enter the wholesale cost of the item: ";
			cin>>newInv.wholesale;
			
			cout<<endl<<"Enter the retail cost of the item: ";
			cin>>newInv.retail;
			
			if(newInv.quantity < 0 || newInv.wholesale < 0 || newInv.retail < 0){
				cout<<endl<<"Sorry! Quantity, Retail Cost and Wholesale Cost each must be >= 0."<<endl;
			}
			
			else{
				break;
			}
		}
		
		cout<<endl<<"Enter today's date (MMDDYYYY): ";
		cin>>newInv.date;
		
		invFile.write(reinterpret_cast<char *>(&newInv), sizeof(newInv));
		
		
		
		invFile.close();
}

int viewRecord(){
	Inventory choiceInv;
	long recNum;
	int i = 0;
		
	fstream invFile("inventory.dat", ios::in | ios::binary);
	
	if(!invFile){
		cout<<"Error opening file. Program aborting.";
		return 0;
	}
	
	cout<<"Which item would you like to view? ";
	cin>>recNum;
	
	invFile.seekg(recNum * sizeof(choiceInv), ios::beg);
	invFile.read(reinterpret_cast<char *> (&choiceInv), sizeof(choiceInv));
	
	cout<<"Item Description: "<<choiceInv.description<<endl;
	cout<<"Quantity in Stock: "<<choiceInv.quantity<<endl;
	cout<<"Wholesale Price: "<<choiceInv.wholesale<<endl;
	cout<<"Retail Price: "<<choiceInv.retail<<endl;
	cout<<"Date added (MMDDYYYY): "<<choiceInv.date<<endl;;
	invFile.close();
}

int changeRecord(){
	Inventory choiceInv;
	long recNum;
	int i = 0;
		
	fstream invFile("inventory.dat", ios::in | ios::out | ios::binary);
	
	if(!invFile){
		cout<<"Error opening file. Program aborting.";
		return 0;
	}
	
	cout<<"Which item would you like to view? ";
	cin>>recNum;
	
	invFile.seekg(recNum * sizeof(choiceInv), ios::beg);
	invFile.read(reinterpret_cast<char *> (&choiceInv), sizeof(choiceInv));
	
	cout<<"Item Description: "<<choiceInv.description<<endl;
	cout<<"Quantity in Stock: "<<choiceInv.quantity<<endl;
	cout<<"Wholesale Price: "<<choiceInv.wholesale<<endl;
	cout<<"Retail Price: "<<choiceInv.retail<<endl;
	cout<<"Date added (MMDDYYYY): "<<choiceInv.date<<endl;;
	cout<<endl;
	
	cout<<"Enter the new item description: ";
		cin>>choiceInv.description;
		
		while(true){
		
			cout<<endl<<"Enter the quantity of the item on hand: ";
			cin>>choiceInv.quantity;
			
			cout<<endl<<"Enter the wholesale cost of the item: ";
			cin>>choiceInv.wholesale;
			
			cout<<endl<<"Enter the retail cost of the item: ";
			cin>>choiceInv.retail;
			
			if(choiceInv.quantity < 0 || choiceInv.wholesale < 0 || choiceInv.retail < 0){
				cout<<endl<<"Sorry! Quantity, Retail Cost and Wholesale Cost each must be >= 0."<<endl;
			}
			
			else{
				break;
			}
		}
		
		cout<<endl<<"Enter today's date (MMDDYYYY): ";
		cin>>choiceInv.date;
		
		invFile.seekg(recNum * sizeof(choiceInv), ios::beg);
		invFile.write(reinterpret_cast<char *>(&choiceInv), sizeof(choiceInv));
		
		invFile.close();
}

int main(){
	string input;
	int choice;
	
	cout<<"Welcome to the Retail Inventory. Please select an option from the menu below: \n";
	cout<<"Input 1 below to add new record.\n";
	cout<<"Input 2 below to display any record.\n";
	cout<<"Input 3 below to change any record.\n";
	cout<<"Choice: ";
	cin>>choice;
	cout<<"\n";
	
	if(choice == 1){
		addRecord();
	}
	else if(choice == 2){
		viewRecord();		
	}
	else if(choice == 3){
		changeRecord();
	}
	
}
