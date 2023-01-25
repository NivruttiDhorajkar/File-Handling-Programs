/*
Write a program which accept file name from user
and read data of that file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>   // file controler 
#include<string.h>


int main()
{
    char Fname[20];
    int fd = 0;     // File descriptor
    char Data[100];
    int Length = 0;

    printf("Enter the file name that you want to open\n");
    scanf("%s",&Fname);

    fd = open(Fname,O_RDWR );
    if( fd == -1)
    {
        return -1;
    }

    //read(kuthun,kashat,kiti)
    Length = read(fd,Data,13);

    printf("Data from file is \n");

    write(1,Data,Length);
    
    return 0;
}

/*
0   Standard Input Device       Keybvoard
1   Standard Output Device      Console
2   Standard error Device       Console
*/