//Name: Evan Phillips
//Assignment: CS 3450-880 Program 3
//Date Assigned: 3/9/21
//Date Due: 3/18/21
//Remark: Program to test and handle a failed system call.


#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

using namespace std;

int main(){

	int ch;

	ch = chmod("nonExist", 0677);

	if(ch == -1){
		cout<<"error = " << errno << endl;
		perror("main");
	}

}
