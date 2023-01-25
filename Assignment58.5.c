/*
Write a program which accepts file name from user and 
one count from user user and read that number of characters from starting point.

Input : Demo.txt
        12
Output : Display first 12 charcters from Demo.txt
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

void DisplayN(char fName[], int No)
{
    int fd = 0;
    int iCnt = 0;
    int iLength = 0;
    char Data[100];

    fd = open(fName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return ;
    }
    else
    {
        printf("File is succesfully opened\n");
    }

    iLength = read(fd,Data,No);

    printf("Data from file is:\n");

    write(1,Data,iLength);
    
}

int main()
{
    char fName[20];
    int iValue = 0;

    printf("Enter the file name that u want to open\n");
    scanf("%s",&fName);

    printf("Enter the number of counts that u want to display charcters\n");
    scanf("%d",&iValue);

    DisplayN(fName,iValue);

    return 0;
}