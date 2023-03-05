
#include <stdio.h>
//int balls;
int balls = 10;
//balls = 10;
int main()
{
   //extern int balls;
   extern balls;
   // balls = 5;
   
    printf("balls = %d\n", balls++);
    printf("balls = %d\n", balls++);
    printf("balls = %d\n", ++balls);

    return 0;
}
