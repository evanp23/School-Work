#include <iostream>
#include "container.h"
using namespace std;

class Stack:Container{
	friend ostream& operator<<(ostream& out, Stack &s);
public:
	Stack();
	//implements container

	bool push(int newVal);
	//precondition: stack is not full
	//postcondition: calls insertBack() from container class

	bool pop();
	//precondition: stack is not empty
	//postcondition: calls deleteBack() from container class

	int top();
	//precondition: stack is not empty
	//postcondition: calls new function from container returnLast()

	bool empty();
	//calls isEmpty() from container class.

	bool full();
	//calls isFull() from container class.

	int size();
	//calls size() from container class

	void clear();
	//precondition: stack is not empty
	//postcondition: calls deleteBack() from container class for every item in stack.
private:
	Container st;

};

Stack::Stack(){
}

ostream &operator<<(ostream& out, Stack &s){
	out<<"Size of stack: "<<s.size()<<endl;
	out<<s.st<<endl;
	if(s.empty()){
		out<<"Stack is empty."<<endl;
	}

	return out;
}

bool Stack::push(int newVal){
	if(full()){
		return false;
	}
	else{
		cout<<"Pushing "<<newVal<<"..."<<endl;
		st.insertBack(newVal);
	}
}

bool Stack::pop(){
	if(empty()){
		return false;
	}
	else{
		cout<<"Popping "<<top()<<"..."<<endl;
		st.deleteBack();
	}
}

int Stack::top(){
	if(empty()){
		return false;
	}
	else{
		return st.returnLast();
	}
}

bool Stack::empty(){
	if(st.isEmpty()){
		return true;
	}
	else{
		return false;
	}
}

bool Stack::full(){
	if(st.isFull()){
		return true;
	}
	else{
		return false;
	}
}

int Stack::size(){
	return st.size();
}

void Stack::clear(){
	while(!empty()){
		pop();
	}
}


int main(){
	Stack s;

	cout<<"Pushing 4 values:"<<endl;
	s.push(16);
	s.push(32);
	s.push(64);
	s.push(128);

	cout<<endl;
	cout<<s;

	cout<<"Pop 4 values: "<<endl;
	s.pop();
	s.pop();
	s.pop();
	s.pop();

	cout<<endl;
	cout<<s;

}
