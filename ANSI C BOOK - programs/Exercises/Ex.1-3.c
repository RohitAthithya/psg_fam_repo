/* print Fahrenheit-Celsius table 
for fahr = 0, 20, ..., 300; floating-point version */ 
//Note that we use The syntax, keywords and the learnings that is known or made upto this point of the reading.

#include <stdio.h> 

main() 
{ 
    float fahr, celsius; 
    float lower, upper, step; 
    lower = 0; /* lower limit of temperatuire scale */ 
    upper = 300; /* upper limit */ 
    step = 20; /* step size */ 

    fahr = lower; 
    printf("\tFahrenheit\t-\tCelsius\n");
    while (fahr <= upper) 
    { 
        celsius = (5.0/9.0) * (fahr-32.0); 
        printf("%6.0f  \t -\t%6.2f\n", fahr, celsius); 
        fahr = fahr + step; 
    } 
} 
