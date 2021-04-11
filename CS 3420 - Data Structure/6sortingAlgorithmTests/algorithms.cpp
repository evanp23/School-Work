//		Course: CS3420-01 Data Structures
//		  Name: Phillips, Evan
//	    Assignment: P5, Sorting Algorithms
//	 Date Assigned: 10/2020
//	      Date Due: 11/24/20
//	Date Handed In: 10/30/20
//		Remark: Program tests three different sorting algorithms on a vector and records time
//			they take at varying sizes of said vector. Bubble, Selection and Insertion Tested.

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>

using namespace std;


template <class T>
void fillVector(vector<T>& vobj, int n){
	//  Precondition: value n: # of objects to be stored in the vector object must be passed to the function
	// Postcondition: vobj is loaded with n objects of T-type. In this problem, n random integers 		
	
	for(int i = 0; i < n; i++){
		int randVal = rand() % 100;
		vobj.insert(vobj.begin()+i, randVal);
	}
}


template <class T>
void displayVector(vector<T>& vobj){
	// Postcondition: if (vobj.size() >= 10), only the first ten values stored in vobj are displayed
	
	int n; //set to 10 if vector size >= 10, set to vector size otherwise.
	
	if(vobj.size() >= 10){
		n = 10;	
	}
	else{
		n = vobj.size();
	}
	
	for (int i = 0; i < n; i++){
        cout << vobj[i] << " "; 
    }
}

void bubbleSort(vector<int> &vobj){
// Postcondition: contents of vobj are sorted in ascending order
	bool swapped = false;
	
	for(int i = 0; i < vobj.size() - 1; i++){
		
			for(int j = 0; j < vobj.size() - 1; j++){
				if(vobj[j]> vobj[j+1]){
					swap(vobj[j], vobj[j+1]);
					swapped = true;
				}
				
			}
			
			if(!swapped){
				break;
			}
	}
}

void selectionSort(vector<int> &vobj){
// Postcondition: contents of vobj are sorted in ascending order
	int mindex; //index of minimum value found
	
	for(int i = 0; i < vobj.size()-1; i++){
		mindex = i;
		for(int j = i+1; j < vobj.size(); j++){
			if(vobj[j] < vobj[mindex]){
				mindex = j;
			}
		}
		
		swap(vobj[mindex], vobj[i]);
	}
}

void insertionSort(vector<int> &vobj){
// Postcondition: contents of vobj are sorted in ascending order
	int idx, j;
	
	for(int i = 1; i < vobj.size(); i++){
		idx = vobj[i];
		j = i - 1;
		
		while(j >= 0 && vobj[j] > idx){
			vobj[j + 1] = vobj[j];
			j -= 1;
		}
		
		vobj[j + 1] = idx;
	}


}



int main(){
	
	srand(time(0));
	double sortTime;
	
	int items;
	
	cout<<"How many items: ";
	cin>> items;
	cout<<endl;
	
	cout<<"Insertion Sort."<<endl<<endl;

	vector<int> alpha;
	fillVector(alpha, items);
	
	cout<<"Before:"<<endl;
	displayVector(alpha);
	cout<<endl;
	
	clock_t t1, t2;
	
	//take time before sort
	t1 = clock();
	
	//run sorting algorithm
	insertionSort(alpha);
	
	//take time after sort
	t2 = clock();
	
	sortTime = ((double)(t2-t1))/CLOCKS_PER_SEC;
	
	cout<<endl<<"Time Taken: "<< sortTime << " seconds."<<endl;
	
	cout<<endl<<"Sorted Vector: "<<endl;
	
	displayVector(alpha);
	cout<<endl;
	
}
