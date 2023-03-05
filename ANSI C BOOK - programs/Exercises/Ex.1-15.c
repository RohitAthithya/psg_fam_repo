#include <stdio.h> 
/* print Fahrenheit-Celsius table 
for fahr = 0, 20, ..., 300; floating-point version */ 

int fahrToCel(int fahr)
{
return ( (5.0/9.0) * (fahr-32.0) ); 
}
main() 
{ 
float fahr, celsius; 
float lower, upper, step; 
lower = 0; /* lower limit of temperatuire scale */ 
upper = 300; /* upper limit */ 
step = 20; /* step size */ 

fahr = lower; 
printf("\tFahrenheit\t-\tCelsius\n");
while (fahr <= upper) { 
celsius = fahrToCel(fahr)
printf("%6.0f  \t -\t%6.2f\n", fahr, celsius); 
fahr = fahr + step; 
} 
} 
