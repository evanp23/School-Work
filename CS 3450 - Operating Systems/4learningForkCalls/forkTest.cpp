//Name: Evan Phillips
//Course: CS3450 - 880
//Program: P4
//Date Assigned: 3/26/2021
//Date Due: 4/6/2021
//Remark: Program to investigate and make use of fork(), exec(), and wait() functions.

#include <iostream>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main(){

	int id = fork();

	if(id != 0){ //Parent Process

		wait(&id); //Wait for child process

		//output pid
		cout<<"This is the parent process exiting after waiting for child. Pid: " << getpid()<<endl;

	}else{//child process

		//outputpid
		cout<<"This is the child process with pid: "<<getpid()<<endl;

		cout<<endl<<"Copying..."<<endl;

		//run my copy program
		execl("copy", "./copy", "source", "target", NULL);

	}
}
