#include <iostream>
#include<cstring>
using namespace std;

int stringlen(char * whatLen){
	int length;
	
	length = strlen(whatLen);
	
	return length;
}
int main(){
	const int SIZE = 50;
	int length;
	char whatLen[SIZE];
	
	cout<<"Please input a string no more than 50 characters: ";
	cin.getline(whatLen, SIZE);
	
	length = stringlen(whatLen);
	
	cout<<"The string contains "<<length<<" characters.";
}
