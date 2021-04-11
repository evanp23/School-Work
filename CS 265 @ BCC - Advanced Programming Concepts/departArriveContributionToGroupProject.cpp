#include <iostream>
using namespace std;

double* departure(){
	
	double time;
	static double hm[2];
	
	while (true){
	
		cout<<"What time did you depart on the first day? (hh.mm): ";
		cin>>time;
		
		int hr = time;
		double min = time - hr;
		
		
		
		if(hr < 0){
			cout<<"Sorry, that is not a time! Please try again.\n";
		}
		else if(hr == 23 && min > 0.59){
			cout<<"Sorry, that is not a time! Please try again.\n";
			
		}
		else if(hr > 23 || min > .59){
			cout<<"Sorry, that is not a time!. Please try again.\n";
		}
		else{
			min = min * 100;
			hm[0] = hr;
			hm[1] = min;
			break;
		}
		
	}
		
		return hm;
		
}

double* arrival(){
	
	double time;
	static double hm[2];
	
	while (true){
	
		cout<<"What time did you arrive home on the last day? (hh.mm): ";
		cin>>time;
		
		int hr = time;
		double min = time - hr;
		
		
		
		if(hr < 0){
			cout<<"Sorry, that is not a time! Please try again.\n";
		}
		else if(hr == 23 && min > 0.59){
			cout<<"Sorry, that is not a time! Please try again.\n";
			
		}
		else if(hr > 23 || min > .59){
			cout<<"Sorry, that is not a time!. Please try again.\n";
		}
		else{
			min = min * 100;
			hm[0] = hr;
			hm[1] = min;
			break;
		}
		
	}
		
		return hm;
		
}

int main(){
	while (true){
	
		double** hm = new double*[2];
		
		hm[0] = departure();
		
		hm[1] = arrival();
	}
}
