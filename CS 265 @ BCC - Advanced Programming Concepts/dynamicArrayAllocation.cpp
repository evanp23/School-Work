#include <iostream>
using namespace std;

int *alloc(int size){
	
	int allocArr[size];
	
	return allocArr;
}

int main(){
	int size = 5;
	
	int *arr = alloc(size);
	
	for(int i = 0; i < 5; i++){
		arr[i] = 5;
		cout<<arr[i];
	}
	
	
}
