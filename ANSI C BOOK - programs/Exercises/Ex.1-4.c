#include<stdio.h>

main()
{
    float celsius;
    float fahr;
    float upper, lower, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("celsius\t\tFahrenheit\n");
    while(celsius <= upper)
    {
        fahr = (9.0/5) * (celsius + 32.0);
        printf("%6.0f\t\t%6.0f\n",celsius, fahr);
        celsius += step;
    }

}
