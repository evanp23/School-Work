//	   Course: CS3420-001 Data Structure
//  	 Name: Evan Phillips
//		Header file for template container class. Container can store any data type and can be modified and printed via ostream operator.

#include <iostream>
using namespace std;

template <class T>
class container{
	
	template <class U>
	friend ostream &operator<<(ostream &out, container <U>&cobj);
	//Postcondition: displays the contents of the container object cobj.
public:
	container();
	
	~container();

	bool isEmpty();
	//return true if n < 0 (array is empty), return false otherwise.

	bool isFull();
	//return true if n + 1 = CAPACITY (array is full), return false otherwise.

	int size();
	//return n+1 (number of elements in array)

	int capacity();
	//return constant CONTAINER

	bool insertBack(T &val);
	//precondition: array is not full. if array is full, returns false.
	//else, n incremented by 1, val inserted into arr[n], returns true.

	bool deleteBack();
	//precondition: array is not empty. If array is empty, returns false.
	//else, n decremented by 1, effectively forgetting about last element in array, "deleting" it.

	bool insertFront(T &val);
	//precondition: array is not full. If array is full, returns false.
	//else, each value in array shifted to right one, val inserted in arr[0], return true.

	bool deleteFront();
	//precondition: array is not empty. If array is empty, returns false.
	//else, each element shifted left by one, writing over front element. n decremented by 1, "deleting"
	//	remaining back element.
	
	void clear();
	//postcondition: all elements in arr of calling comtainer object are cleared and
	//the dynamic memory is released back to "heap"


private:
	void allocate(T* &temp);
	//postcondition: if Capacity = 0, allocate a single location; otherwise the current capacity is doubled.
	
	T* arr;
	int Capacity;
	int n;

};

template <class U>
ostream &operator<<(ostream& out, container <U>&cobj){ //returns stream for printing
	int arrSize = cobj.size();

	if(cobj.isEmpty()){
		out<<"Container is empty."<<endl;
	}

	else{
		out<<"Container Capacity: "<<cobj.Capacity<<endl; //print capacity
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
	Capacity = 3;
	n=-1;
	allocate(arr);
}

template <class T>
container<T>::~container(){
	delete arr;
	cout<<"Destructor called."<<endl;
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
	if((n + 1) == Capacity){
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
	return Capacity;
}

template <class T>
bool container<T>::insertBack(T &val){
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
bool container<T>::insertFront(T &val){
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

template <class T>
void container<T>::clear(){
	delete [] arr;
	n=-1;   //to satisfy isEmpty().
}

template <class T>
void container<T>::allocate(T* &temp){
	temp = new T[Capacity];
}