/*
write a program which accept file name from user and create another file
and copy that first file data into created file.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>   // file controler 
#include<string.h>


int main()
{
    char Fname1[20];
    char Fname2[20];
    int fdSource = 0;     // File descriptor
    int fdDest = 0;
    char Data[100];
    int Length = 0;

    printf("Enter the file name which contains data:\n");
    scanf("%s",&Fname1);

    fdSource= open(Fname1,O_RDONLY);

    if(fdSource == -1)   
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("Enter the file name that you want to create:\n");
    scanf("%s",&Fname2);

    fdDest = creat(Fname2,0777);

    if(fdDest == -1)
    {
        printf("Unable to create new file\n");
        return -1; 
    }
    
    while((Length = read(fdSource,Data,sizeof(Data))) != 0)
    {
        write(fdDest,Data,Length);
    }

    close(fdSource);
    close (fdDest);
    
    return 0;
}
