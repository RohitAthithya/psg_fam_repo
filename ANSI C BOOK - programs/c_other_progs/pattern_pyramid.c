#include<stdio.h>
#include<stdint.h>

main()
{
    uint16_t height;
here:
    printf("Enter the height of pyramid:\n");
    scanf("%d", &height);
    //negative numbers are not allowed as an input
    if(height < 0)
    {
        puts("enter a number > 0");
        //goto here;
        return;
    }
    for(uint16_t i = 0; i <= height; ++i)
    {
        for(uint16_t j = i; j >= 1; --j)
        {
            printf("%3d  ",j);
        }
        printf("\n");
    }
}