#include <iostream>
using namespace std;

double* departure(){
	
	double time;
	double hm[2];
	
	while (true){
	
		cout<<"What time did you depart on the first day? (hh.mm): ";
		cin>>time;
		
		int hr = time;
		double min = time - hr;
		
		min *= 100;
		hm[0] = hr;
		hm[1] = min;
		
		
		if(hr < 0){
			cout<<"Sorry, that is not a time! Please try again.\n";
		}
		else if(hr == 23 && min > 59){
			cout<<"Sorry, that is not a time! Please try again.\n";
			
		}
		else if(hr > 23 || min > 59){
			cout<<"Sorry, that is not a time!. Please try again.\n";
		}
		else{
			
			
			break;
		}
		
	}
		
		return hm;
		
}

int main(){
	while (true){
		double* time;
		time = departure();
		cout<< time[1];
		
		
		
		//double** time = departure(hm[0]);
		//cout<<time[0][1];
	}
}
