//          Name: Evan Phillips
//        Course: CS3450-880 Operating Systems
//    Assignment: Program 1
// Date Assigned: 2/4/2021
//      Date Due: 2/14/2021
//        Remark: Program to properly handle command line arguments to main function. Takes 0 to 4 arguments.
//	          Users can enter multiple options with a single hyphen.

#include <iostream>
#include <array>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]){
	if(argc-1 == 0){
		cout<<"myUtility executed"<<endl;
	}
	else{
		cout<<"myUtility executed with options ";
		for(int i = 1; i <= argc-1; i++){ //for each arg in argv, excluding program name
			if(argv[i][0] == '-'){ //arguments only accepted if they start with hyphen
				for(int j = 1; j <= strlen(argv[i]) - 1; j++){
					//print each character in argument
					cout<<argv[i][j];
					if((i == argc-1) && (j == strlen(argv[i]) - 1)){ 
					//don't print 'and' if last character on last argument.
					}
					else{
						cout<<" and ";
					}
				}
			}

		}
	}

	cout<<endl;
}
