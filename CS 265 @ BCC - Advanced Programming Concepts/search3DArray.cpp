#include <iostream>
#include <cstring>

using namespace std;

int main(){
	const int SIZE = 11;
	const int LENGTH = 35;
	char nameIn[LENGTH];
	
	char names[SIZE][LENGTH] = {"Alejandra Cruz, 555-1223", "Joe Looney, 555-0097", "Geri Palmer, 555-8787", "Li Chen, 555-1212", "Holly Gaddis, 555-8878", "Sam Wiggins, 555-0998", 
	"Bob Kain, 555-8712", "Tim Haynes, 555-7676", "Warren Gaddis, 555-9037", "Jeam James, 555-4393", "Ron Palmer, 555-2783"};
	
	cout<<"Enter a name or partial name to search for: ";
	cin.getline(nameIn, LENGTH);
	
	for(int i = 0; i < SIZE; i++){
		if(strstr(names[i], nameIn) != NULL){
			cout<<names[i]<<endl;
		}	
	}
	
}
