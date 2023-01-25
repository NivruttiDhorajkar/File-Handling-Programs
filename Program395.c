/*
write a program which Accept file name from user and 
read the data and count capital charcters.
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
    int iCnt = 0;
    int iCount = 0;

    printf("Enter the file name that you want to open\n");
    scanf("%s",&Fname);

    fd = open(Fname,O_RDONLY);

    if(fd == -1)   
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((Length = read(fd,Data,sizeof(Data))) != 0)
    {
       for(iCnt=0; iCnt<Length; iCnt++)
       {
            if(Data[iCnt] >='A' && Data[iCnt] <= 'Z')
            {
                iCount++;
            }  
       } 
    }

    printf("Number of capital letters are : %d\n",iCount);

    close(fd);
    
    return 0;
}
