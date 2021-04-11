#include <iostream>
using namespace std;


double patData(int days, double rate, double medCost, double services){  //in-patient data
	double total;
	
	total = (days * rate) + medCost + services;
	
	return total;
	
}

double patData(double services, double medCost){  //out-patient data
	double total;
	
	total = services + medCost;
	
	return total;
}

int main(){
	
	int days;
	double rate;
	double medCost;
	double services;
	double total;
	int choice;
	
	while(true){
		cout<<"Enter 1 if in-patient and 0 if out-patient: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				while(true){
				
					cout<<"Enter the number of days the patient stayed: ";
					cin>>days;
					
					cout<<"Enter the daily rate of the hospital: ";
					cin>>rate;
					
					cout<<"Enter the cost of the patient's medications: ";
					cin>>medCost;
					
					cout<<"Enter the cost of the hospital services: ";
					cin>>services;
					cout<<"\n";
					
					if(days < 0 || rate < 0 || medCost < 0 || services < 0){
						cout<<"All costs must be 0 or greater. Please try again.\n";
					}
					else{
						break;
					}
				}
				total = patData(days, rate, medCost, services);
					
				cout<<"The total charges are $" << total;
				
				break;
			
			case 0:
				while(true){
				
					cout<<"Enter the cost of hospital services: ";
					cin>>services;
					
					cout<<"Enter the cost of the patient's medication: ";
					cin>>medCost;
					cout<<"\n";
					
					if(services < 0 || medCost < 0){
						cout<<"All costs must be 0 or greater. Please try again. \n";
					}
					else{
						break;
					}
				}
				
				total = patData(services, medCost);
				
				cout<<"The total charges are $" << total;
				
				break;
			
			default:
				cout<<"Invalid choice. ";
				continue;
			
		
		}
		break;
	}
		
}

