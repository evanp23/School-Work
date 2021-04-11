//	   Course: CS3420-001 Data Structure
//  	 Name: Evan Phillips
//		Header file for template container class. Container can store any data type and can be modified and printed via ostream operator.

#include <iostream>
using namespace std;

template <class T>
class container{

	template <typename U>
	friend ostream& operator<<(ostream& out, container <T>&cobj);
	//Postcondition: displays the contents of the container object cobj.
public:
	container();

	bool isEmpty();
	//return true if n < 0 (array is empty), return false otherwise.

	bool isFull();
	//return true if n + 1 = CAPACITY (array is full), return false otherwise.

	int size();
	//return n+1 (number of elements in array)

	int capacity();
	//return constant CONTAINER

	bool insertBack(T val);
	//precondition: array is not full. if array is full, returns false.
	//else, n incremented by 1, val inserted into arr[n], returns true.

	bool deleteBack();
	//precondition: array is not empty. If array is empty, returns false.
	//else, n decremented by 1, effectively forgetting about last element in array, "deleting" it.

	bool insertFront(T val);
	//precondition: array is not full. If array is full, returns false.
	//else, each value in array shifted to right one, val inserted in arr[0], return true.

	bool deleteFront();
	//precondition: array is not empty. If array is empty, returns false.
	//else, each element shifted left by one, writing over front element. n decremented by 1, "deleting"
	//	remaining back element.


	static const int CAPACITY = 3;
	T arr[CAPACITY];
	int n = -1;

};

template <typename T>
ostream &operator<<(ostream& out, container<T>&cobj){ //returns stream for printing
	if(cobj.isEmpty()){
		out<<"Container is empty."<<endl;
	}

	else{
		out<<"Container Capacity: "<<cobj.CAPACITY<<endl; //print capacity
		out<<"The container currently contains "<<cobj.size()<<" element(s):"<<endl; //print size
		for(int i=0; i <= cobj.n; i++){ //iterate array and print each object
			out<<cobj.arr[i]<<" ";
		}
		cout<<endl;
	}
	return out;
}

template <class T>
container<T>::container(){
}

template <class T>
bool container<T>::isEmpty(){
	if(n < 0){
		return true;
	}

	else{
		return false;
	}
}

template <class T>
bool container<T>::isFull(){
	if((n + 1) == CAPACITY){
		return true;
	}

	else{
		return false;
	}
}

template <class T>
int container<T>::size(){
	return n+1;
}

template <class T>
int container<T>::capacity(){
	return CAPACITY;
}

template <class T>
bool container<T>::insertBack(T val){
	if(isFull()){
		return false;
	}

	else{
		n = n+1;
		arr[n] = val;
		return true;
	}
}

template <class T>
bool container<T>::deleteBack(){
	if(isEmpty()){
		return false;
	}

	else{
		n = n-1; //back element is "deleted"
		return true;
	}
}

template <class T>
bool container<T>::insertFront(T val){
	if(isFull()){
		return false;
	}

	else{
		for(int i = n; i >= 0; i--){
			arr[i+1] = arr[i]; //iterate and move each element to the right by one
		}   				//to make space for next front element
		arr[0] = val;
		n = n + 1;
		return true;
	}
}

template <class T>
bool container<T>::deleteFront(){
	if(isEmpty()){
		return false;
	}

	else{
		for(int i = 0; i <=n; i++){  //iterate and move each element to the left by one
			arr[i] = arr[i+1];	//to effectively delete the front element
		}
		n = n-1;
		return true;
	}
}
