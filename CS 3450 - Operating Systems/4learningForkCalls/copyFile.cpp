// Program: copies the contents of a source file (named source) to a target file (name target)
// Objectives: to learn UNIX system calls open(), create(), read(), write(), and exit()
// Source code name: copyFile.cpp
// Executable file name: copy
// Command line entry: ./copy source target
// Name: Evan Phillips
// Date Assigned: 2/23/2021
// Date Due: 2/27/2021

#include <iostream>
#include <unistd.h>	  
#include <fcntl.h>	

using namespace std;

void copy(int, int);
//  Precondition: accepts file descriptors for the source and target text files, respectively.
// Postcondition: the contents of source file have been copied to the target file

const int SIZE = 100;	// upper limit of characters that can be read per each read() system call
char buffer[SIZE] = "";	// store characters read from source file then transfer them to target file 

int main(int argc, char* argv[])
{
    int fd_source, fd_target; 	
    if (argc != 3) 			    {
        cout << "Need exactly three C-strings in the command line!" << endl;
        exit(1);			   
	}

    fd_source = open(argv[1], O_RDONLY);	 
								
    if (fd_source == -1) 			
    {
        cout << "Cannot open " << argv[0] << " file!" << endl;
        exit(1);
    }

    fd_target = creat(argv[2], 0666);  
    if (fd_target == -1) 			
    {
        cout << "Cannot create " << argv[2] << " file!" << endl;
        exit(1);
    }

    copy(fd_source, fd_target);	

    exit(0);
}

void copy(int source, int target) 
{
    int count, n = 0, total = 0;

    cout << "size of buffer = " << sizeof(buffer) << endl;

    count = read(source, buffer, sizeof(buffer));  
									  

    while (count > 0)		
    {
	

        write(target, buffer, count);
        
        count = read(source, buffer, sizeof(buffer));

	total += sizeof(buffer);

    }
    cout << "Total characters read: " << total << endl;
}

