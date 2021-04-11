#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <stdlib.h>

using namespace std;


// the distribute function
void distribute(const vector<int> &v, queue<int> digitQueue[ ], int power)
{
	// loop through the vector, inserting each element into the appropriate queue
	for (int i = 0; i < v.size( ); i++)
		digitQueue[(v[i] / power) % 10].push(v[i]);
}

// the collect function
void collect(queue<int> digitQueue[ ], vector<int> &v)
{
	int i = 0, digit;
	for (digit = 0; digit < 10; digit++)		// scan digitQueue [0] thru [9]
		while (!digitQueue[digit].empty( )) {		// collect numbers from each queue
		     v[i] = digitQueue[digit].front( );
		     digitQueue[digit].pop( );
		     i++;
		}
}

// radixSort function, vector v is the container for the list of integers to be sorted, d is the number of digits in the largest integer in the list.
void radixSort (vector<int> &v, int d)
{
	int i, power = 1;
	queue<int> digitQueue[10];
	
	for (i = 0; i < d; i++) {
		distribute(v, digitQueue, power);
		collect(digitQueue, v);
		power *= 10;
	}
}

int main(){
	srand(time(0));
	int randVal;
	
	vector <int> vec;
	
	for(int i = 0; i < 10; i ++){
		vec.push_back(rand()%1000);
	}
	
	cout<<"Unsorted list: "<<endl;
	
	for(int i = 0; i < vec.size(); i++){
		cout<<vec.at(i)<<" ";
	}
	
	cout<<endl;
	
	radixSort(vec, 10);
	
	cout<<"Sorted: "<<endl;
	
	for(int i = 0; i < vec.size(); i++){
		cout<<vec.at(i)<<" ";
	}
	
	
}
