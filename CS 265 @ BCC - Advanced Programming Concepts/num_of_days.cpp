#include <iostream>
using namespace std;

int daysOnTrip(){
	int days;
	
	while(true){
		cout<<"How many days did you spend on the trip? ";
		cin>>days;
		if(days < 1){
			cout<<"The number of days must be 1 or greater. Please try again.\n";
		}
		else{
			break;
		}
	}
	
	return days;
}

int main(){
	int test = daysOnTrip();
	
	cout<<test;
}


