#include<stdio.h>

main()
{
    int n1, n2;

    scanf("%d %d", &n1, &n2);

    fflush(stdout);//trigger for stdout to work: print all the stuff
    printf("Average of the two is:%d\n", (n1 + n2) / 2);

    printf("Enter any char to exit...");

    //this is to read all the CHARs in std i/p buffer until \n, so that typing
    //another character makes the program exit//return from main to OS
    while(getchar() == '\n');
    getchar();
}