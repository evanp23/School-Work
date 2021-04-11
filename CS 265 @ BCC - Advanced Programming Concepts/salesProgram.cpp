#include <iostream>
using namespace std;

double getSales(string division){
	
	double sales;
	
	while(true){
	
		cout<<"Please enter the quarterly sales of the "<< division << " division: ";
		cin>>sales;
		cout<<"\n";
		
		if(sales < 0.00){
			cout<<"The sales amount must be $0.00 or greater\n";
		}
		else{
			break;
		}
	}
	return sales;
}

void findHighest(double nesales, double sesales, double nwsales, double swsales){
	
	string div [] = {"Northeast", "Southeast", "Northwest", "Southwest"};
	double sales [] = {nesales, sesales, nwsales, swsales};
	double high = sales[0];
	int highPos;
	
	for(int x = 0; x <=3; x++){
		if(sales[x] > high){
			high = sales[x];
			highPos = x;
		}
		
	}
	
	cout<<div[highPos] << " $" << high;
	
}

int main(){
	string div [] = {"Northeast", "Southeast", "Northwest", "Southwest"};
	double divSales [4];
	
	for(int x = 0; x <=3; x++){
		divSales[x] = getSales(div[x]);
	}
	
	findHighest(divSales[0], divSales[1], divSales[2], divSales[3]);
}
