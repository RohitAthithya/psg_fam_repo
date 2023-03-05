#include<stdio.h>
//extern int balls;
//int balls;


main()
{
    int balls;
    extern int balls;
    balls = -10;
    //{
    //    extern int balls;
    //    printf("%d", ++balls);
    //}
    
    printf("%d", ++balls);
}

int balls = 'd'; 